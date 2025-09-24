//Linkedlist in C
#include<stdio.h>
#include<stdlib.h>
typedef struct dll
{
    int data;
    struct dll *nlink;
    struct dll *plink;
}node;
node *head =NULL;
node *memalloc(int d)
{
    node *new=(node*)malloc(sizeof(node));
    if(new==NULL)
 {
     printf("memory is not allocated");
     exit(1);
 }
 new->data=d;
 new->plink=NULL;
 new->nlink=NULL;
 return new;
}
void insertfront(int d)
{
    node *new=memalloc(d);
    if(head ==NULL)
    {
        head =new;
        return;
    }
    new->nlink=head;
    head->plink=new;
    head=new;
}
void insertend(int d)
{
    node *new=memalloc(d);
    if(head==NULL)
    {
        head =new;
        return;
    }
    node *temp=head;
    while(temp->nlink !=NULL)
    {
        temp=temp->nlink;
    }
    temp->nlink=new;
    new->plink=temp;
}
void deletefront()
{
    if(head == NULL)
    {
        printf("list is empty");
        return;
    }
    printf("%d got deleted :\n ",head->data);
    head =head->nlink;
    free(head->plink);
}
void deleteend()
{
    if(head ==NULL)
    {
        printf("list is empty");
        return;
    }
    node *temp=head;
    while(temp->nlink !=NULL)
    {
        temp=temp->nlink;
    }
    temp->plink->nlink=NULL;
    free(temp);
}
void display()
{
    if(head==NULL)
    {
        printf("list is empty");
        return;
    }
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%d \t",temp->data);
        temp=temp->nlink;
    }
printf("\n");
}
int main()
{
    insertfront(10);
    insertfront(20);

    printf("displaying all nodes of list\n");
    display();
    insertend(30);
    printf("displaying all nodes of list\n");
    display();
    deletefront();
    printf("displaying all nodes of list\n");
    display();
    deleteend();
    printf("displaying all nodes of list\n");
    display();
}


