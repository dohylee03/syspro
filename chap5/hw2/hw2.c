#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define MAX_LINES 100
#define MAXLEN 100

int main(int argc, char *argv[]){
	FILE *fp;
	char lines[MAX_LINES][MAXLEN];
	int line_count = 0;
	if((fp = open(argv[1], O_RDONLY)) == -1)
		printf("File Open Error\n");
	else printf("file Read Sucess\n");

	while (fgets(lines[line_count], MAXLEN, fp) != NULL){
		line_count++;
	}

	fclose(fp);
	for (int i = line_count - 1; i >= 0; i--){
		printf("%s", lines[i]);
	}

	return 0;
}

