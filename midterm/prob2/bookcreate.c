#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "book.h"

int main(int argc, char *argv[])
{
	int fd;
	struct book record;
	if((fd = open(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0640)) == -1 ){
		perror(argv[1]);
		exit(2);
	}
	printf("%-3s %-8s %-8s %-8s %-3s %-8s\n", "BookID", "Name", "Writer", "Since", "Bcount", "status");
	while (scanf("%d %s %s %d %d %s", &record.id, &record.name, &record.writer, &record.since, &record.bcount, &record.status) == 6){
		lseek(fd, (record.id - START_ID) * sizeof(record), SEEK_SET);
		write(fd, (char *) &record, sizeof(record));
	}
	close(fd);
	exit(0);
}

