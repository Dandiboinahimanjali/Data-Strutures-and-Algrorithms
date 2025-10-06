/**program for create a Depth first Search(DFS)*/

#include <stdio.h>
#include <stdlib.h>

int v = 3;

// Declare head as a global variable
typedef struct sll {
    int vertex;
    int visited;
    struct sll* link;
} node;
node* head = NULL;

void initialize_array(int arr[v][v]) {
    int i, j;
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            arr[i][j] = 0;
        }
    }
}

void add_edges(int arr[v][v], int i, int j) {
    arr[i][j] = 1;
    arr[j][i] = 1;
}

void display(int arr[v][v]) {
    int i, j;
    for (i = 0; i < v; i++) {
        printf("%d:\t", i);
        for (j = 0; j < v; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

node* memalloc(int vertex) {
    node* new = (node*) malloc(sizeof(node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->vertex = vertex;
    new->visited = 0;
    new->link = NULL;
    return new;
}

void insertfront(int vertex) {
    node* new = memalloc(vertex);
    if (head == NULL) {
        head = new;
        return;
    }
    new->link = head;
    head = new;
}

int is_visited(int vertex) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->vertex == vertex) {
            return temp->visited;
        }
        temp = temp->link;
    }
    return 0;
}

void mark_visited(int vertex) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->vertex == vertex) {
            temp->visited = 1;
            return;
        }
        temp = temp->link;
    }
}

#define size 3
int stack[size];
int top = -1;

void push(int d) {
    if (top == size - 1) {
        printf("Stack is full\n");
    } else {
        stack[++top] = d;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

void dfs_traversal(int adjacency_matrix[][v], int start_vertex) {
    push(start_vertex);
    insertfront(start_vertex);
    while (top != -1) {
        int current = pop();
        if (!is_visited(current)) {
            printf("%d ", current);
            mark_visited(current);
        }
        for (int i = v - 1; i >= 0; i--) {
            if (adjacency_matrix[current][i] == 1 && !is_visited(i)) {
                insertfront(i);
                push(i);
            }
        }
    }
}

int main() {
    int adjacency_matrix[v][v];
    initialize_array(adjacency_matrix);
    add_edges(adjacency_matrix, 0, 1);
    add_edges(adjacency_matrix, 1, 2);
    printf("Display adjacency matrix:\n");
    display(adjacency_matrix);
    printf("DFS Traversal: ");
    dfs_traversal(adjacency_matrix, 0);
    printf("\n");
    return 0;
}
















