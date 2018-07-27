#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define OUTPUT out

FILE *out = fopen("output.txt", "w");

typedef struct node {
	int num;
	struct node* next;
} node;



int main(void) {
	node* temp;

	float a = GetTickCount();

	node* start = (node*)malloc(sizeof(node));
	start->num = 1;
	start->next = NULL;
	for (int i = 2;i <= 100;i ++) {
		temp = (node*)malloc(sizeof(node));
		temp->num = i;
		temp->next = start->next;
		start->next = temp;
	}
	
	int c;
	for (int i = 1;i <= 500000000;i++) {
//		i = i; //1504
		c = temp->num; // 800

	}
	float b = GetTickCount();

	fprintf(OUTPUT, "%f", b - a);
}