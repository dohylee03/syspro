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

	while (1) {
		scanf("%d", &input);

		if (input <= 0){
			printf("\n[
