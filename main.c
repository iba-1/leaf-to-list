//
// Created by Dario on 14/03/16.
//
#include <stdio.h>
#include <stdlib.h>


typedef struct tree
{
    int value;
    struct tree * left;
    struct tree * right;
}t_tree;

typedef struct list
{
    int value;
    struct list * next;
}t_list;


void visit_list(t_list **ptrptr);
void list_insertion(t_list **, int);
void visit_leaf(t_tree *, t_list**);
t_tree* new_node();



int main()
{

    t_tree * ptr;
    t_list *ptrptr = NULL;

    //è possibile inserire in runtime più nodi, basta mettere new_node dentro un while(!data) e chiedere se inserire a dx o sx
    t_tree *root = new_node();
    root->left = new_node();
    root->right = new_node();
    root->left->left = new_node();
    //root->left->right = new_node();*/
    root->right->left = new_node();
    root->right->right = new_node();


    visit_leaf(root, &ptrptr);
    visit_list(&ptrptr);

}

//THOSE 2 FUNCTIONS ARE THE CORE OF LEAFTOLIST, NOW CONSTRUCT THE MAIN

void list_insertion(t_list **ptrptr, int value)
{
    if(*ptrptr != NULL)
    {
        while(*ptrptr != NULL)
        {
            ptrptr = &((*ptrptr)->next);
        }
        if(*ptrptr != NULL)
        {
            t_list* tmp_ptr;
            tmp_ptr = *ptrptr;
            *ptrptr = (t_list*)malloc(sizeof(t_list));
            (*ptrptr)->value = value;
            (*ptrptr)->next = tmp_ptr;
        }
        else
        {
            *ptrptr = (t_list*)malloc(sizeof(t_list));
            (*ptrptr)->value = value;
            (*ptrptr)->next = NULL;
        }
    }
    else
    {
            printf("\nList is empty, will insert %d at beginning\n", value);
            *ptrptr = (t_list*)malloc(sizeof(t_list));
            (*ptrptr)->value = value;
            (*ptrptr)->next = NULL;
    }
}

void visit_leaf(t_tree * ptr, t_list ** ptrptr)
{
    if(ptr->left == NULL && ptr->right == NULL)
    {
        printf("\nLeaf value = %d\nI'm going to put it in your list\n", ptr->value);
        list_insertion(ptrptr, ptr->value);
    }
    else
    {
        if(ptr->left != NULL)
        {
            visit_leaf(ptr->left, ptrptr);
        }
        if(ptr->right != NULL)
        {
            visit_leaf(ptr->right, ptrptr);
        }
    }
}

t_tree* new_node()
{
    int data = 0;
    printf("Insert value\n");
    scanf("%d", &data);

    t_tree * tree = (t_tree *)malloc(sizeof(t_tree));

    tree->value = data;
    tree->left = NULL;
    tree->right = NULL;

    return(tree);
}

void visit_list(t_list **ptrptr)
{
    while((*ptrptr) != NULL)
    {
        printf(" %d", (*ptrptr)->value);
        ptrptr = &((*ptrptr)->next);
    }
}
