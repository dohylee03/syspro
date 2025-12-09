#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	int pid1, pid2, pid3, pid4, pid5, pid6, pid7;
	pid1 = fork();
	if(pid1 == 0){
		printf("Hello\n");
		pid2 = fork();
		if(pid2 == 0){
			printf("Hello\n");
			pid5 = fork();
			if(pid5 == 0){
				printf("Hello\n");
				pid6 = fork();
				if(pid6 == 0){
				}
			}
		}
		pid3 = fork();
		if(pid3 == 0){
		}
		pid4 = fork();
		if(pid4 == 0){
			pid7 = fork();
			if(pid7 == 0){
			}
		}
	}
	return 0;
}

