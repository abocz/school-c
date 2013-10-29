/* 
	Computational Model using Linked List
	Simulating Airport stops and tranversion	
	
	Author: Andrew Bocz
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
/* Structure used to build Linked List */
struct node{
    int val;
    struct node *next;
};
/* Pointers for the list */
struct node *head = NULL;
struct node *curr = NULL;
/* Creates the linked list */
struct node* create_list(int val){
    printf("\n creating list with the first stop as [%d]\n",val);
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("\n Node creation failure \n");
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;
    head = curr = ptr;
    return ptr;
}
/* Prints the string of the stop */
void printStop(int n){
	char strings[8][3];
	strcpy(strings[0], "ATL");
	strcpy(strings[1], "CHI");
	strcpy(strings[2], "NYC");
	strcpy(strings[3], "LAX");
	strcpy(strings[4], "SFO");
	strcpy(strings[5], "MIA");
	strcpy(strings[6], "DEN");
	strcpy(strings[7], "LAS");
	strcpy(strings[8], "HNL");
	int i;
	for(i=0;i<3;i++)
		printf("%c",strings[n-1][i]);
	
}
/* Adds list nodes */
struct node* add_node(int val, bool add_to_end){
    if(head==NULL){
        return (create_list(val));
    }
    if(add_to_end)
        printf("\n Adding stop to end of list with value [%d]\n",val);
		
    else
        printf("\n Adding stop to beginning of list with value [%d]\n",val);
	printStop(val);
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;
    if(add_to_end){
        curr->next = ptr;
        curr = ptr;
    }
    else{
        ptr->next = head;
        head = ptr;
    }
    return ptr;
}
/* Function for searching the Linked List */
struct node* search_in_list(int val, struct node **prev){
    struct node *ptr = head;
    struct node *tmp = NULL;
    bool found = false;
    printf("\n Searching the list for value [%d] \n",val);
    while(ptr != NULL){
        if(ptr->val == val){
            found = true;
            break;
        }
        else{
            tmp = ptr;
            ptr = ptr->next;
        }
    }
    if(true == found){
        if(prev)
            *prev = tmp;
        return ptr;
    }
    else{
        return NULL;
    }
}

/* Function for deleting a node */
int delete_node(int val){
    struct node *prev = NULL;
    struct node *del = NULL;
    printf("\n Deleting stop [%d] from list\n",val);
    del = search_in_list(val,&prev);
    if(del == NULL){
        return -1;
    }
    else{
        if(prev != NULL){
            prev->next = del->next;
		}
        if(del == curr){
            curr = prev;
        }
        else if(del == head){
            head = del->next;
        }
    }
    free(del);
    del = NULL;
    return 0;
}
int main() { 
	int input=1;
	int input2=1;
	
	
	printf(" ~~ Flight Stop System ~~ \nThis program only accepts number input\nBuild a list of stops by choosing a number.");  
	while(input2 != 0){
		/* List of flight stops */
		printf("\nPlease press a number to select a stop:\n 1 Atlanta(ATL), GA\n 2 Chicago(CHI), IL\n 3 New York City(NYC), NY\n 4 Los Angeles(LAX), CA\n 5 San Francisco(SFO), CA\n 6 Miami(MIA),FL\n 7 Denver(DEN), CO\n 8 Las Vegas(LAS), NV\n 9 Honolulu(HNL), HI\n");
		/* Begin user input */
		scanf("%d", &input);
		/* Invalid Input */
		if(input>9||input<1){
			printf("\n Invalid number");
			input2= 0;
		}
		/* Prints the number typed */
		printf("\n%d:",input);
		printStop(input);
		;
		/* User Text Interface */
		printf("\nDo you want to add or delete this flight stop from the list?");
		printf("\nTo add as a flight stop, press 1. To delete as a flight stop press 2.\n To Exit press 0");
		printf("\n");
		scanf("%d", &input2);
		if(input2==1){
		   add_node(input,true); 
		   printf("\nYou added the stop to the list\n");
		}
		else if(input2==2){
		   delete_node(input);
		   printf("\nYou deleted the stop from the list\n");
		}
		else if(input2==0){
			input2 = 0;
		}
		else{
			printf("\nInvalid input, please press either 1, 2, or 0\n");
		}
	}
	/* Exit Code */
	int f = 0;
    struct node *ptr = head;
    printf("\n  ~~List of Stops~~ \n  ~~In Order~~ \n");
    while(ptr != NULL){
        printf("\n   [%d]: ",ptr->val);
		printStop(ptr->val);
        ptr = ptr->next;
        f++;
    }
	printf("\n Total: %d stops", f);
	printf("\n  ~~List End~~ \n");

	return 0;
}
