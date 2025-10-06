//C program to find the 2nd kth smallest element in a binary search tree



#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}


Node* insertNode(Node* root, int key) {
    if (root == NULL) {
        root = createNode(key);
    } else if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else {
        root->right = insertNode(root->right, key);
    }
    return root;
}


void find2ndKthSmallest(Node* root, int k) {
    static int count = 0;
   static int prevKey = -1;

    if (root == NULL) {
        return;
    }

    find2ndKthSmallest(root->left, k);

    count++;
    if (count == k) {
        prevKey = root->key;
    } else if (count == k + 1) {
        printf("The 2nd %dth smallest element is: %d\n", k, root->key);
        return;
    }

    find2ndKthSmallest(root->right, k);
}


void printInOrder(Node* root) {
    if (root) {
        printInOrder(root->left);
        printf("%d ", root->key);
        printInOrder(root->right);
    }
}

int main() {
    Node* root = NULL;


    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);


    printf("In-order traversal: ");
    printInOrder(root);
    printf("\n");

    int k = 2;
    find2ndKthSmallest(root, k);

    return 0;
}





*delete a node from algorithm


#include<stdio.h>
#include<stdlib.h>
#define size 100
typedef struct tree
{
    int data;
    struct tree* rchild;
    struct tree* lchild;
}node;
int arr[size];
int index=0;
node*root=NULL;
node*memalloc(int d)
{
    node*new=(node*)malloc(sizeof(node));
    if(new==NULL)
    {
        printf("can't allocate memory");
        exit(1);
    }
    new->data=d;
    new->rchild=NULL;
    new->lchild=NULL;
    return new;
}
void insertfront (int ele)
{
    node*new=memalloc(ele);
    if(root==NULL)
    {
        root =new;
        return;
    }
    node*temp=root;
    node*parent = NULL;
    while(temp!=NULL){
        parent = temp;
        if(ele>temp->data){
            temp=temp->rchild;
    }else if(ele < temp->data)
        {
            temp=temp->lchild;
        }
        else{
          printf("duplicates are not allowed");
          return;
        }
    }
    if(ele>parent->data)
        {
        parent->rchild=new;
        }
    else
    {
      parent->lchild=new;
    }
}
void inorder(node *ptr){
    if(ptr==NULL)
        return;
    inorder(ptr->lchild);
    arr[index++]=ptr->data;
    inorder(ptr->rchild);
}

node* finf_min(node *ptr)
{
    while(ptr && ptr->lchild !=NULL)
        ptr=ptr->lchild;
        return ptr;
}

node* delete_node(node *ptr,int key){
 if(ptr==NULL){
    printf("tree is empty\n");
    return;
 }
{
if (key < ptr->data){
    ptr->lchild=delete_node(ptr->lchild,key);//left child delete
}
else if(key >ptr->data){
    ptr->rchild=delete_node(ptr->rchild,key);//right child delete
}
else if(ptr->lchild==NULL && ptr->rchild==NULL){//if no child
        free(ptr);
    return NULL;
}

else if(ptr->lchild==NULL){
    node *temp=ptr->rchild;
    free(ptr);
    return temp;
}
else if(ptr->rchild==NULL){
 node *temp=ptr->lchild;
 free(ptr);
 return temp;
}
else{
    node *temp=find_min(ptr->rchild);
    ptr->data=temp->data;
    ptr->rchild=delete_node(ptr->rchild,temp->data);
}

 }
  return ptr;
}
void check_bst(node *ptr)
{
    index=0;
    inorder(ptr);
    printf("inorder array:\n");
    for(int i=0;i<index;++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    for(int i=0;i<index-1;++i)
    {
        if(arr[i]>=arr[i+1])
        {
            printf("not binary search tree\n");
            return;
        }
    }
    printf("it is a binary search tree\n");
}
int main()
{
    insertfront(5);
    insertfront(3);
    insertfront(1);
    insertfront(15);
    check_bst(root);
    printf("enter node to be deleted\n");
    delete_node(root,key);
}
















