#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int num;
	printf("type num of childs : ");
	scanf("%d", &num);
	int pid[20] = {};
	int child = 0;
	for (int i = 1; i <= num; i++){
		pid[i] = fork();
		if (pid[i] == 0){
			printf("[Child %d] : Started! pid=%d, sleep=%d\n", i, getpid(), i);
			child = getpid();
			sleep(i);
			printf("[Child %d] : Killed! pid=%d, sleep=%d\n", i, getpid(), i);
			exit(i);
		}
	}
	sleep(num+1);
	printf("parent killed - last child id = %d\n", child);

	return 0;
}
