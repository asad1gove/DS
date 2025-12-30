#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int data){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL){
        printf("\n memory allocation failed\n");
        return;
    }
    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;

};

struct node* insert(struct node*root, int value){
    if (root == NULL){
        return create(value);
    }
    if( value < root->data){
        root->left = insert(root->left, value);
    }
    else if( value >root->data){
        root ->right= insert(root->right, value);
    }
    return root;
};

void  inorder(struct node*root){
    if (root != NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void  preorder(struct node*root){
    if (root != NULL){
        printf("%d\t",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

void  postorder(struct node*root){
    if (root != NULL){
        inorder(root->left);
        inorder(root->right);
        printf("%d\t",root->data);
    }
}


void display(struct node*root){
    inorder(root);
}

void main() {
    struct node* root = NULL;
    int choice,value;

    do{
        printf("\n***main menu***\n");
        printf("1. insert node \n 2. Inorder traversal \n 3. preorder traversal \n 4. postorder traversal\n 5. display\n 6. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1 :
            printf("\n enter value to insert:");
            scanf("%d",&value);
            root = insert(root,value);
            break;
        case 2:
            printf("\n inorder:");
            inorder(root);
            break;
        case 3:
            printf("\n preorder:");
            preorder(root);
            break;
        case 4:
            printf("\n postorder:");
            postorder(root);
            break;
        case 5:
            display(root);
        case 6:
            break;
        default:
            printf("\n enter valid choice");
        }
    }while(choice != 6);
}



