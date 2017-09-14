#ifdef SINGLYLINKED_H
/* Author : Sayooj K Karun
   Description : This is the header file for singly linked list.
*/
#define SINGLYLINKED_H

#include <stdio.h>
#include <stdlib.h>

#define LIST_EMPTY_ERR		-1
#define LIST_EL_NOT_FOUND	-2
#define LIST_HEAD_REMOVED	1
#define LIST_AD_ON_TOP		2
#define LIST_AD_ON_BTM		3
#define LIST_EL_REM		4
#define LIST_LAST_EL_REM	5

typedef struct Lnode {
	int data;
	struct Lnode *next;
} node ;

node *head = NULL, *temp = NULL;

node *createNode(int data);
int insertTop(int data);
int traverseList(void);
int insertBottom(int data);
int deleteList (int data);



/* This is used to create node which can be inserted to list */
node *createNode(int data) {
	temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}
/* This function will insert data to the top of the list */
int insertTop(int data) {
	node *newNode = NULL;
	newNode = createNode(data);
	if(head == NULL) {
		head = newNode;
		printf("added as head\n");
		return 0;
	}
	newNode->next = head;
	head = newNode;
	return 0;
}
/* this function is used to traverse and print the data in list */
int traverseList() {
	node *tra = head;
	if(head == NULL){
		printf("empty list\n");
		return -1;
	}
	while(tra != NULL) {
		printf("DATA---- %d\n", tra->data);
		tra = tra->next;
	}
		return 0;
}
/* This function is used to insert data to the bottom of singly linked
  list */
int insertBottom(int data) {
	node *btm = NULL, *tra = NULL;
	btm = createNode(data);
	if(head == NULL) {
		printf("Adding As head");
		return 0;
	}
	tra = head;
	while(tra->next !=NULL) {
		tra = tra->next;
	}
	tra->next = btm; 
}

/* This function is used to delete data from the list */
int deleteList (int data) {
	node *temp = NULL;
	node *prev = NULL;
	node *tra = head;
	if(head->data == data) {
		head = head->next;
	}
	while(tra != NULL) {
		if(tra->next != NULL) {
			if(tra->data == data) {
				temp = tra->next;
				tra->next = NULL;
				tra = temp;
				return 0;
			}
		}
		else {
			if(tra->data == data) {
				prev->next = NULL;
				free(tra);
				return 0;
			}
		}
		prev = tra;
		tra = tra->next;
	}
	return -1;
}

#endif
