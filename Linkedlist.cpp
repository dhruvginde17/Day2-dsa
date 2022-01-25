// C program to find middle of linked list
#include<stdio.h>
#include<stdlib.h>
 
struct Node
{
    int data;
    struct Node* next;
};
 
void printMiddle(struct Node *head)
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = head;
 
    if (head!=NULL)
    {
        while (ptr2 != NULL && ptr2->next != NULL)
        {
            ptr2 = ptr2->next->next;
            ptr1 = ptr1->next;
        }
        printf("The middle element is [%d]\n\n", ptr1->data);
    }
}
 
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
 
    new_node->data = new_data;
 
    new_node->next = (*head_ref);
 
    (*head_ref) = new_node;
}
 
void printList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
 
int main()
{
    struct Node* head = NULL;
    int i;
 
    for (i=10; i>0; i--)
    {
        push(&head, i);
        printList(head);
        printMiddle(head);
    }
 
    return 0;
}
