#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void addq(struct node *head, struct node *tail, int data);
int delete(struct node *head, struct node *tail);
void printQueue(struct node *head);

int main(){
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->next = NULL;

	struct node *tail = head;
	int input;
	int result;

	while(1){
		result = scanf("%d", &input);
		if (result != 1 || input <= 0){
			while(getchar() != '\n');
			printf("print queue\n");
			printQueue(head);
			break;
		}
		else{
			addq(head, tail, input);
		}
	}

	return 0;
}

void addq(struct node *head, struct node *tail, int data){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;

	struct node *curr = head;
	while (curr->next != NULL){
		curr = curr->next;
	}

	curr->next = newNode;
}
int delete(struct node *head, struct node *tail){
	if (head->next == NULL){
		printf("Queue is Empty\n");
		return -1;
	}

	struct node *delNode = head->next;
	int returnData = delNode->data;

	head->next = delNode->next;

	free(delNode);
	return returnData;
}

void printQueue(struct node *head){
	struct node *curr = head->next;

	if(curr == NULL){
		printf("Queue is Empty\n");
		return;
	}
	while (curr != NULL){
		printf("%d\n", curr->data);
		curr = curr->next;
	}
}
