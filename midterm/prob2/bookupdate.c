#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "book.h"

int main(int argc, char *argv[])
{
	int fd;
	struct book record;
	int target_id, action;
	long offset;

	if ((fd = open(argv[1], O_RDWR)) == -1){
		perror(argv[1]);
		exit(2);
	}


	printf("\n--bookupdate--\n");
	printf("0 bookID: borrow book, 1 bookID: return book) ");
	while (scanf("%d %d", &action, &target_id) ==2){

		if (action != 0 && action != 1){
			printf("error\n");
			continue;
		}

		offset = (long)(target_id - START_ID) * sizeof(struct book);

		if (lseek(fd, offset, SEEK_SET) == -1){
			perror("lseek (seek to record) error");
			continue;
		}
		if (read(fd, &record, sizeof(record)) < sizeof(record)){
			printf(" ERROR\n");
			continue;
		}

		if (action == 0){
			if (strcmp(record.status, "True") == 0){
				record.bcount++;
				strcpy(record.status, "False");
				printf("You've got bellow book..\n", record.id, record.name);
			}
			else{
				printf("You cannot borrow below book since it has been booked.\n", record.id, record.name);
				continue;
			}

		}
		else {
			if (strcmp(record.status, "False") == 0){
				strcpy(record.status, "True");
				printf("You've returned bellow book..\n",record.id, record.name);
			}
		}

		if (lseek(fd, offset, SEEK_SET) == -1) {
			perror("lseek (rewind to write) error");
			continue;
		}

		if (write(fd, &record, sizeof(record)) == -1){
			perror("write (update) error");
		}


	}

	close(fd);
	exit(0);
}
