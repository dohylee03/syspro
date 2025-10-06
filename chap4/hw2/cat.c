#include <stdio.h>
#include <string.h>

void display_file(const char *filename, int n_flag, long *line_num_ptr) {
    FILE *file;
    char buffer[4096];

    file = fopen(filename, "r");
    if (file == NULL) {
        perror(filename);
        return;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (n_flag) {
            printf("%6ld\t%s", *line_num_ptr, buffer);
            (*line_num_ptr)++;
        } else {
            printf("%s", buffer);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    int n_option = 0;
    long line_number = 1;

    if (argc < 2) {
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            n_option = 1;
            break;
        }
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            continue;
        }
        display_file(argv[i], n_option, &line_number);
    }

    return 0;
}
