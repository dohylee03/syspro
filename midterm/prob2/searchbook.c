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
	char search_name[40];
	int found;

	if(argc<2){
		fprintf(stderr, "HOW TO USE : %s <DBFILE>\n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(2);
	}

	printf("Input name of book )");

	while (scanf("%39s", search_name) == 1){
		found = 0;
		if (lseek(fd, 0, SEEK_SET) == -1){
			perror("lseek (rewind to start) error");
			continue;
		}

		while (read(fd, &record, sizeof(record)) == sizeof(record)){
			if (record.id == 0) continue;

			if(strcmp(record.name, search_name) == 0){
				printf("%-3d %-8s %-8s %-8d %-3d %-8s\n",record.id, record.name, record.writer, record.since, record.bcount, record.status);

				found =1;
				break;
			}
		}
		if(found == 0){
			printf("not found book name : '%s'\n", search_name);
		}

		printf("\nInput name of book )");
	}

	close(fd);
	exit(0);
}
