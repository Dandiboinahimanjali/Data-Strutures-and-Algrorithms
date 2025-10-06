/**CREATE CLL USING DOUBLE LINKED LIST*/
#include <stdio.h>
#include <stdlib.h>
typedef struct cll
{
    int data;
    struct cll* nlink;
    struct cll* plink;
}node;
node *head=NULL;
node *memalloc(int d)
{
    node* new = (node*)malloc(sizeof(node));
    if (new==NULL)
    {
        printf("Memory is not allocated\n");
        exit(1);
    }
    new->data =d;
    new->nlink = NULL;
    new->plink = NULL;
    return new;
}
void insertfront(int d)
{
    node* new = memalloc(d);
    if(head==NULL)
    {
        head=new;
        new->nlink = head;
        new->plink = head;

    }
        node*tail = head->plink;
         new->nlink = head;
        new->plink= tail;
        tail->nlink = new;
        head->plink = new;
        head = new;
}
void display()
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    printf("Display the nodes:\n");
    node *temp=head;
    do
    {
    printf("%d\t",temp->data);
    temp=temp->nlink;
    }while(temp!=head);
    printf("\n");
}
void insertend(int d)
{
    node* new = memalloc(d);
    if (head == NULL)
    {
        head = new;
        new->nlink = new;
        new->plink = new;
    }
        node* tail = head->plink;
        new->nlink = head;
        new->plink = tail;
        tail->nlink = new;
        head->plink = new;
}
void deletefront(int d)
{
    node* new = memalloc(d);
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->nlink == head)
    {
        free(head);
        head = NULL;
    }
        node* tail = head->plink;
        node* temp = head;
        head =head->nlink;
        head->plink = tail;
        tail->nlink = head;
        free(temp);
}
void deleteend(int d)
{
    node* new = memalloc(d);
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->nlink == head)
    {
        free(head);
        head = NULL;
    }
        node* tail = head->plink;
        node* temp = tail;
        tail->plink->nlink = head;
        head->plink = tail->plink;
        free(temp);
}
int main() {
    insertfront(10);
    insertfront(20);
    insertfront(30);
    printf("Nodes after insertfront:\n");
    display();
    printf("\n");
    insertend(100);
    printf("Nodes after insertend:\n");
    display();
    deletefront(30);
    printf("Nodes after deletefront:\n");
    display();
    deleteend(100);
    printf("Nodes after deleteend:\n");
    display();
    return 0;
}
