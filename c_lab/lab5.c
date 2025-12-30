#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

int count() {
    struct node *temp;
    int i = 1;
    if (head == NULL) return 0;
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
        i++;
    }
    return i;
}

struct node *create(int value) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf(" Memory allocation failed\n");
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void insert_begin(int value) {
    struct node *newnode = create(value);
    if (head == NULL) head = newnode;
    else {
        newnode->next = head;
        head = newnode;
    }
}

void delete_begin() {
    struct node *temp;
    if (head == NULL) {
        printf("deletion is not possible");
    } else {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_end() {
    struct node *temp1, *temp2;
    if (head == NULL) {
        printf("deletion is not possible");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        temp1 = head;
        while (temp1->next != NULL) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = NULL;
        free(temp1);
    }
}

void delete_pos(int pos) {
    struct node *temp1, *temp2;
    int i = count(), c = 1;
    if (pos == 1) delete_begin();
    else if (pos > i) printf("Deletion is not possible");
    else {
        temp1 = head;
        while (c < pos) {
            temp2 = temp1;
            temp1 = temp1->next;
            c++;
        }
        temp2->next = temp1->next;
        free(temp1);
    }
}

void delete_spec_value(int key) {
    struct node *temp1 = head, *temp2 = NULL;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (temp1 != NULL && temp1->data == key) {
        head = temp1->next;
        free(temp1);
        return;
    }
    while (temp1 != NULL && temp1->data != key) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if (temp1 == NULL) return;
    temp2->next = temp1->next;
    free(temp1);
}

void display() {
    struct node *temp;
    if (head == NULL) printf("list is empty");
    else {
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void main() {
    int ch, pos, value, key;
    do {
        printf("\n1.insert begin\n2.delete begin\n3.delete end\n4.delete position\n5.delete key\n6.display\n7.exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: scanf("%d", &value); insert_begin(value); break;
            case 2: delete_begin(); break;
            case 3: delete_end(); break;
            case 4: scanf("%d", &pos); delete_pos(pos); break;
            case 5: scanf("%d", &key); delete_spec_value(key); break;
            case 6: display(); break;
        }
    } while (ch != 7);
}