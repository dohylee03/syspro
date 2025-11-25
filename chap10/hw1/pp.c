#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
void push(struct node *top, int data);
int pop(struct node *top);
void printStack(struct node *top);

int main() {
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->next = NULL;

	int input;
	int result;

	while (1){
		result = scanf("%d", &input);

		if (result != 1 || input <= 0){
			while(getchar() != '\n');

			printf("print stack\n");
			printStack(head);
			break;
		}
		else {
			push(head, input);
		}
	}
	return 0;
}

void push(struct node *top, int data){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = top->next;
	top->next = newNode;
}

int pop(struct node *top){
	if (top->next == NULL){
		printf("Stack is Empty\n");
		return -1;
	}

	struct node *delNode = top->next;
	int returnData = delNode->data;

	top->next = delNode->next;

	free(delNode);
	return returnData;
}
void printStack(struct node *top){
	struct node *curr = top -> next;
	if(curr == NULL){
		printf("Stack is Empty\n");
		return;
	}

	while (curr != NULL){
		printf("%d \n", curr->data);
		curr = curr->next;
	}
}

