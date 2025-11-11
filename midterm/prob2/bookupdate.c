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

	do{
		printf("\n--bookupdate--\n");
		printf("0 bookID: borrow book, 1 bookID: return book) ");

		if (scanf("%d", &target_id) != 1){
			continue;}

		
