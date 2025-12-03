#include <stdio.h>
#include <signal.h>
typedef void (*sighandler_t)(int);

sighandler_t my_signal(int signo, sighandler_t handler){
	struct sigaction act, old_act;
	act.sa_handler = handler;

	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	if (sigaction(signo, &act, &old_act) < 0) {
		return SIG_ERR;
	}

	return old_act.sa_handler;
}

void alarmHandler();
int main(){
	if(my_signal(SIGALRM, alarmHandler) == SIG_ERR){
		perror("Signal error");
		return 1;
	}

	alarm(5);
	short i = 0;
	while (1){
		sleep(1);
		i++;
		printf("%d second\n", i);
	}
	printf("end\n");
	return 0;
}

void alarmHandler(int signo)
{
	printf("Wake up\n");
	exit(0);
}

