#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

main(int argc, char *argv[])
{
	int fd1, fd2, n, a;
	char buf[BUFSIZ], savedtext[100];
	if ((fd1 = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(2);
	}
	if ((fd2 = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644)) == -1){
		perror(argv[2]);
		exit(3);
	}
	for (int i = 0; i < 10; i++){
			read((fd1, buf, 1));
			if (buf == 0){
				break;
			}
			savedtext[i] = buf;
	}
	while((n = read(fd1, buf, BUFSIZ)) >0)
		write(fd2, buf, n);
	printf("%s\n", savedtext);
	exit(0);
}
