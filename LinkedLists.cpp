#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int data;
	struct NODE *next;
};

void listTraversal(struct NODE * ptr){
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
} 

int main(){
	struct NODE * head;
	struct NODE * second;
	struct NODE * third;
	head = (struct NODE *)malloc(sizeof(struct NODE));
	second = (struct NODE *)malloc(sizeof(struct NODE));
	third = (struct NODE *)malloc(sizeof(struct NODE));
	//Linking first and second nodes
	head->data = 7;
	head->next = second;
	//Linking second and third nodes
	second->data = 11;
	second->next = third;
	//End of the list
	third->data = 15;
	third->next = NULL;
	listTraversal(head); 
	return 0;
}