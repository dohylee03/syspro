#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define MAXLINE 10
#define MAX_LEN 100

int main(int argc, char *argv[])
{
	int fd, line_count = 0;
	char savedText[MAXLINE][MAX_LEN];
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		printf("File Open Error\n");
	else {
		printf("File Read Sucess : %d\n", fd + 1);
		printf("Total line : %d", fd +1);
	}
	while (line_count < 10 && MAXLINE && fgets(savedText[line_count], MAX_LEN, fd)){
		savedText[line_count][strcspn(savedText[line_count], "\n")] = '\0';
		line_count++;
	}
	char user_input[MAX_LEN];
	printf("Plz 'Enter' the line to select :");
	fgets(user_input, MAX_LEN, stdin);
	user_input[strcspn(user_input, "\n")] = '\0';

	if (strcmp(user_input, "*") == 0){
		for (int i = 0; i < line_count; i++){
			printf("%d: %s\n", i + 1, savedText[i]);
		}
	}

	else if(strchr(user_input, '-')){
		int start, end;
		if(sscanf(user_input, "%d-%d", &start, &end) == 2){
			for (int i = start; i <= end; i++){
				printf("%d: %s\n", i, savedText[i - 1]);
			}
		}
	}
	else if (strchr(user_input, ',')){
		char *token = strtok(user_input,", ");
		while (token != NULL){
			int line_num = atoi(token);
			if (line_num >= 1 && line_num <= line_count){
				printf("%d: %s\n", line_num, savedText[line_num - 1]);
			}
			token = strtok(NULL, ", ");
		}
	}
	else{
		int line_num = atoi(user_input);
		if (line_num >= 1 && line_num <= line_count){
			printf("%d: %s\n", line_num, savedText[line_num - 1]);
		}
	}

	close(fd);
	exit(0);
}

