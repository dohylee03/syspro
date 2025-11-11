#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "book.h"

int main(int argc, char *argv[])
{
	int fd, s;
	struct book record;
	if((fd = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(2);
	}
	do {
		printf("--bookquery--\n0: list of all books, 1: list of available books ) ");
		if(scanf("%d", &s) == 1){
			if (lseek(fd, 0, SEEK_SET) == -1){
				perror("error");
				continue;
			}

			if (s == 0 || s == 1){
				printf("\n%-3s %-8s %-8s %-8s %-3s %-8s\n", "ID", "bookname", "author", "year", "numofborrow", "borrow\n");

				while (read(fd, &record, sizeof(record)) == sizeof(record)){
					if (record.id == 0) continue;

					if(s == 0){
						printf("%-3d %-8s %-8s %-8d %-3d %-8s\n", record.id, record.name, record.writer, record.since, record.bcount, record.status);
					}
					else{
						if(strcmp(record.status, "True") == 0){
								printf("%-3d %-8s %-8s %-8d %-3d %-8s\n", record.id, record.name, record.writer, record.since, record.bcount, record.status);
								}
					}
				}
			}
		
		}
	}

	while (1);

	close(fd);
	exit(0);
}
