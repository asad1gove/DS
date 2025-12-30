
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next = NULL;
    struct node * prev = NULL;

};

struct node *head = NULL;
struct node *create(int data){
    struct node*newnode = ( struct node* ) malloc (sizeOf(struct node));
    if( newnode == NULL){
        printf("failed");
        exit(1);
    }
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next= NULL;
    return newnode;
}

struct node* insert_end(int val){
    struct node * newnnode = create(val);
    if(head == NULL){
        head = newnode;
        return head;
    }
    struct node * current= head;
    while(current->next != NULL){
        current = current ->next;
    }
    current ->next = newnode;
    newnode->prev = current;
    return head;


}

struct node *insert_left(int val,int key){
    struct node *newnode = create(val);
    if (head==NULL){
        head= newnode;
        return head;
    }

    struct node*curr= head;
    while(curr->next!=NULL && curr -> data != key){
        curr = curr->next;
    }


};





void deleteValue(int value) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)

        temp->next->prev = temp->prev;

    free(temp);
    printf("Node with value %d deleted.\n", value);
}
