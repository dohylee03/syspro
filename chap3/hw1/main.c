#include <stdio.h>
#include "copy.h"

#define MAX_STRINGS 5
char line[MAXLINE];
char longest[MAXLINE];

int main(){
	char strings[MAX_STRINGS][MAXLINE];

	for(int i=0;i<MAX_STRINGS; i++){
		fgets(strings[i], MAXLINE, stdin);
		strings[i][strcspn(strings[i], "\n")] = 0;
	}

	sort_strings(strings, MAX_STRINGS);

	for (int i = 0; i < MAX_STRINGS; i++){
		printf("%s\n", strings[i]);
	}
	return 0;
}

void sort_strings(char strings[MAX_STRINGS][MAXLINE], int count){
	char temp[MAXLINE];
	for (int i=0;i<count - 1; i++){
		for(int j=0; j<count-i-1;j++){
			if(strlen(strings[j]) < strlen(strings[j+1])) {
				copy(strings[j], temp);
				copy(strings[j+1], strings[j]);
				copy(temp, strings[j+1]);
				
			}	
		}	
	}
}
