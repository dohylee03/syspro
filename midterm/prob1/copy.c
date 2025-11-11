#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	if (argc != 4){
		exit(1);
	}

	int option = atoi(argv[1]);
	char *source_path = argv[2];
	char *dest_path = argv[3];

	if (option < 0 || option > 2){
		fprintf(stderr, "Error");
		exit(1);
	}
	FILE *src_file = fopen(source_path, "r");
	if (src_file == NULL){
		perror("ERROR");
		exit(1);
	}

	FILE *dest_file = fopen(dest_path, "w");
	if	(dest_file == NULL){
		perror("Error");
		fclose(src_file);
		exit(1);
	}
	int ch;
	while ((ch = fgetc(src_file))!=EOF){
		int transformed_ch;

		switch (option) {
			case 0:
				transformed_ch = ch;
				break;
			case 1:
				transformed_ch = tolower(ch);
				break;
			case 2:
				transformed_ch = toupper(ch);
				break;
		}

		if (fputc(transformed_ch, dest_file) == EOF){
			perror("ERROR");
			fclose(src_file);
			fclose(dest_file);
			exit(1);
		}
	}

	fclose(src_file);
	fclose(dest_file);
	return 0;
}
