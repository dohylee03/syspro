#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int opt;
	char **ptr;
	extern char **environ;
	
	while((opt = getopt(argc, argv, "uge:ip")) != -1){
		switch(opt){
			case 'u':
				printf("real user ID: %d\n", getuid());
				printf("effective user ID: %d\n", geteuid());
				break;
			case 'g':
				printf("real group ID: %d\n", getgid());
				printf("effective group ID: %d\n", getegid());
			case 'i':
				printf("process ID: %d\n", getpid());
				break;
			case 'p':
				printf("parent process ID: %d\n", getppid());
				break;
			case 'e':
				if (optarg != NULL){
					char *value = getenv(optarg);
					if(value != NULL){
						printf("%s=%s\n", optarg, value);
					}
					else {
						printf("can't find\n", optarg);
					}
				} else{
					printf("all list:\n");
					for(int i = 0; environ[i] != NULL; i++){
						printf("%s\n", environ[i]);
					}
				}
				break;
			default:
				fprintf(stderr, "How to use: %s\n", argv[0]);
				exit(EXIT_FAILURE);
		}

		if(argc == 1){
			fprintf(stderr, "How to use: %s\n", argv[0]);
		}


	exit(0);
	}
}
