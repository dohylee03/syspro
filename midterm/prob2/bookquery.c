#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "book.h"

int main(argc, char *argv[])
{
	int fd, s;
	char c;
	struct student record;
	if((fd = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(2);
	}
	do {
		printf("--bookquery--\n0: list of all books, 1: list of available books ) ");
		if(scanf("%d", &s) ==
