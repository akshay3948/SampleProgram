#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct DLinkListNode {
	int value;
	struct DLinkListNode *next;
	struct DLinkListNode *prev;
};


struct DLinkListNode *addToDList(struct DLinkListNode *head, int data){
	struct DLinkListNode *node = (struct DLinkListNode*)malloc(sizeof(struct DLinkListNode));
	node->value = data;
	node->prev = NULL;
	node->next = NULL;
	if(head == NULL){
		head = node;
		return head;
	}

	// if the data is less than head value;
	if(head->value > data){
		node->next = head;
		head->prev = node;
		head = node;
		return head;
	}
	
	struct DLinkListNode *temp_head = head;
	// add data to the list at correct location
	while(temp_head->next != NULL){
		if(temp_head->value > data){
			node->next = temp_head;
			node->prev = temp_head->prev;
			temp_head->prev->next = node;
			break;
		}
		temp_head = temp_head->next;
	}

	// adding data as the last element
	if(temp_head->next == NULL){
		temp_head->next = node;
		node->prev = temp_head;
	}

	return head;
}

void printDLink(struct DLinkListNode *head){
	struct DLinkListNode *node = head;
	if(node == NULL){	
		return;
	}

	// print all the items
	while(node != NULL){
		printf("%d\t", node->value);
		node = node->next;
	}
	printf("\n");
}

struct DLinkListNode *reverseDList(struct DLinkListNode *head){
	struct DLinkListNode *new_head = NULL;
	struct DLinkListNode *prev_node = NULL;
	if(head == NULL){
		return head;
	}
	
	// if there is only one element
	if(head->next == NULL){
		return head;
	}

	while(head->next != NULL){
		// attach to updated node;
		if(prev_node != NULL){	
			prev_node->next = new_head;
			prev_node->prev = NULL;
			if(new_head != NULL){
				new_head->prev = prev_node;
			}
			new_head = prev_node;
		}
		prev_node = head;
		head = head->next;
	}
	// reverse last and 2nd last
	if(head->next == NULL){
		prev_node->next = new_head;
		prev_node->prev = NULL;
		if(new_head != NULL){
			new_head->prev = prev_node;
		}
		new_head = prev_node;

		// attach last element
		head->next = new_head;
		head->prev = NULL;
		new_head->prev = head;
		new_head = head;
	}
	return new_head;
}

struct DLinkListNode *deleteItem(struct DLinkListNode *head, int data){
	struct DLinkListNode *node = head;
	struct DLinkListNode *temp_head = head;
	if(head == NULL){
		return head;
	}
	if(head->value == data){
		node = head;
		head = head->next;
		head->prev = NULL;
		node->next = NULL;
		free(node);
		return head;
	}
	
	while(temp_head->next != NULL){
		if(temp_head->value == data){
			node = temp_head;
			temp_head->prev->next = temp_head->next;
			node->next = NULL;
			node->prev = NULL;
			free(node);
			break;
		}
		temp_head = temp_head->next;
	}
	
	if(temp_head->next == NULL){
		if(temp_head->value == data){
			node = temp_head;
			temp_head->prev->next = NULL;
			node->prev = NULL;
			free(node);
		}
	}
	return head;
}

int main(int argc, char *argv[]){
	int len = strlen(argv[1]);
	char str[len];
	strcpy(str, argv[1]);
	
	struct DLinkListNode *head;
	unsigned int i = 0;
	for(i; i < len; i++){
		head = addToDList(head, str[i]);
	}
	
	printDLink(head);
	head = reverseDList(head);
	printDLink(head);
	head = deleteItem(head, 'a');
	printDLink(head);
	return 0;
}
