#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "book.h"

typedef struct Node {
    struct book data;
    struct Node *next;
} Node;

void insert_sorted(Node **head_ref, struct book new_record) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    new_node->data = new_record;
    new_node->next = NULL;

    if (*head_ref == NULL || new_node->data.since < (*head_ref)->data.since) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } 
    else {
        Node *current = *head_ref;
        while (current->next != NULL && 
               current->next->data.since < new_node->data.since) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void print_list(Node *head, int mode) {
    Node *temp = head;
    
    printf("%-3s %-8s %-8s %-8s %-3s %-8s\n", 
           "ID", "Name", "Writer", "Since", "Bcnt", "Status");
    printf("--- -------- -------- -------- --- --------\n");

    while (temp != NULL) {
        struct book record = temp->data; 
        if (mode == 0) {
            printf("%-3d %-8s %-8s %-8d %-3d %-8s\n", 
                   record.id, record.name, record.writer, 
                   record.since, record.bcount, record.status);
        } else {
            if (strcmp(record.status, "True") == 0) {
                printf("%-3d %-8s %-8s %-8d %-3d %-8s\n", 
                       record.id, record.name, record.writer, 
                       record.since, record.bcount, record.status);
            }
        }
        temp = temp->next;
    }
}

void free_list(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void clear_input_buffer() {
    while (getchar() != '\n');
}

int main(int argc, char *argv[]) {
    int fd;
    struct book record;
    int mode; 

    Node *head = NULL; 

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <DB_FILE>\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_RDONLY)) == -1){
        perror(argv[1]);
        exit(2);
    }
    while (read(fd, &record, sizeof(record)) == sizeof(record)) {
        if (record.id == 0) continue; 
        insert_sorted(&head, record);
    }
    close(fd); 

    do {
        printf("--bookquery--\n");
        printf("0: List of all books, 1: list of available books ) ");

        if (scanf("%d", &mode) != 1) {
            clear_input_buffer(); 
            continue;
        }

        if (mode == 2) { 
            break; 
        }

        if (mode != 0 && mode != 1) {
            continue;
        }

        print_list(head, mode);

    } while (1); 

    free_list(head);

    return 0;
}
