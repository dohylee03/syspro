#include <stdio.h>
int main(){
	alarm(5);
	printf("Looop start\n");
	short i = 0;
	while(1){
		sleep(1);
		i++;
		printf("%d second\n", i);
	}
	printf("end\n");
}
