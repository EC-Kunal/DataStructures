#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int data;
	struct NODE * next;
};
void show(struct NODE * ptr){
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
}
struct NODE * insertatFirst(struct NODE *head, int data){
	struct NODE * ptr = (struct NODE *)malloc(sizeof(struct NODE));
	ptr->next = head;
	ptr->data = data;
	return ptr;
}
struct NODE * insertInBetween(struct NODE * head,int data,int index){
	struct NODE * ptr = (struct NODE *)malloc(sizeof(struct NODE));
	struct NODE * p = head;
	int i=0;
	while(i!=index-1){
	p = p->next;	
	i++;
	}
		ptr->data = data;
		ptr->next = p->next;
		p->next = ptr;	
		return head;
}
struct NODE * insertatEnd(struct NODE * head,int data){
	struct NODE * ptr = (struct NODE *)malloc(sizeof(struct NODE));
	struct NODE * p = head;
	while(p->next!=NULL){
		p = p->next;
	}
	ptr->data = data;
	p->next = ptr;
	ptr->next = NULL;
	return head;
}
struct NODE * inserafterNode(struct NODE * head,struct NODE * prevNode,int data){
	struct NODE * ptr = (struct NODE *)malloc(sizeof(struct NODE));
	struct NODE * p = head;
	ptr->data = data;
	ptr->next = prevNode->next;
	prevNode->next = ptr;
	return head;
}
int main(){
	struct NODE * head;
	struct NODE * second;
	struct NODE * third;
	struct NODE * fourth;
	head = (struct NODE*)malloc(sizeof(struct NODE));
	second = (struct NODE*)malloc(sizeof(struct NODE));
	third = (struct NODE*)malloc(sizeof(struct NODE));
	fourth = (struct NODE*)malloc(sizeof(struct NODE));

	head->data = 10;
	head->next = second;
	second->data = 15;
	second->next = third;
	third->data = 20;
	third->next = fourth;
	fourth->data = 25;
	fourth->next = NULL;
	printf("Original Linked List: \n");
	show(head); 
	// head = insertatFirst(head,05);
	// printf("\nInsertion in starting: \n");
	// show(head);
	// head = insertInBetween(head,100,1);
	// printf("\nInsertion in between: \n");
	// show(head);
	// head = insertatEnd(head,100);
	// printf("\nInsertion at end: \n");
	// show(head);
	head = inserafterNode(head,second,200);
	printf("\nInsertion after a given Node: \n");
	show(head);
	return 0;
}