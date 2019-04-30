#include <stdio.h>

struct LNode {
    int data;
    struct Node *next;
};

typedef struct LNode Node;

void push(Node *head, int arr[], int l) {
    Node *curr = head;
    Node *new;
    curr->data = arr[0];
    for(int i=1; i< l; i++) {
        new = (Node*)malloc(sizeof(Node));
        new->next = NULL;
        new->data = arr[i];
        curr->next = new;
        curr = new;
    }
}
Node* merge(Node *l1, Node *l2) {
    Node *n, *head;
    
    if (l1->data > l2->data) {
        n = l2; l2 = l2->next;
    } else {
        n = l1; l1 = l1->next;
    }
    head = n;
    while(l1 != NULL && l2 != NULL) {
        if (l1->data > l2->data) {
            n->next = l2;
            l2 = l2-> next;
        } else {
            n->next = l1;
            l1 = l1->next;
        }
        n = n->next;
    }
    if (l1 != NULL) n->next = l1;
    if (l2 != NULL) n->next = l2;
    return head;
}

void print(Node* n) {
    while(n) printf("%d ", n->data), n=n->next;
}

int main(int argc, char const *argv[])
{
    Node l1 , l2;
    int arr[] = {1,2,3,4,5};
    int arr2[] = {1, 7, 8, 9};
    push(&l1, arr, 5);
    print(&l1);
    push(&l2, arr2, 4);
    print(&l2);
    printf("\n");
    Node *n = merge(&l1, &l2);
    print(n);
    return 0;
}
