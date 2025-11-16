#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "book.h"

int compare_books(const void *a, const void *b){
	struct book *bookA = (struct book *)a;
	struct book *bookB = (struct book *)b;

	return (bookA->bcount - bookB->bcount);
}

void clear_input_buffer(){
	while (getchar() != '\n');
}
int main(int argc, char *argv[]){
	int fd;
	struct book *records = NULL;
	int mode;
	int count = 0;
	long file_size;

	if ((fd = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(2);
	}

	file_size = lseek(fd, 0, SEEK_END);
	if (file_size == -1){
		perror("lseek (to end) error");
		close(fd);
		exit(3);
	}
	count = file_size / sizeof(struct book);
	if (count == 0){
		printf(" data file is empty.\n");
		close(fd);
		exit(0);
	}

	if (lseek(fd, 0 , SEEK_SET) == -1){
		close(fd);
		exit(4);
	}
	records = (struct book *)malloc(file_size);
	if (records == NULL){
		close(fd);
		exit(5);
	}

	if(read(fd, records, file_size) != file_size){
		perror("file read error");
		free(records);
		close(fd);
		exit(6);
	}

	close(fd);

	qsort(records, count, sizeof(struct book), compare_books);

	printf("--bookquery--\n");
	do {
		printf("0: list of all books, 1: list of available books ) ");

		if(scanf("%d", &mode) != 1){
			clear_input_buffer();
			continue;
		}

		if (mode == 2){
			break;
		}
		if (mode != 0 && mode != 1){
			continue;
		}

		printf("%-3s %8-s %-8s %-8s %-3s %-8s\n", "id", "Name", "author", "year", "numofborrow", "borrow");

		for (int i = 0; i< count; i++){
			struct book record = records[i];

			if (record.id == 0) continue;

			if (mode == 0){
				printf("%-3d %-8s %-8s %-8d %-3d %-8s\n", record.id, record.name, record.writer, record.since, record.bcount, record.status);
			}
			else{
				if (strcmp(record.status, "True") == 0 ){
					printf("%-3d %-8s %-8s %-8d %-3d %-8s\n", record.id, record.name, record.writer, record.since, record.bcount, record.status);
				}
			}
		}
	}while (1);

	free(records);
	return 0;
}
