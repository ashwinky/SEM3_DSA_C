#ifndef SEM3_DSA_C_LINKED_H
#define SEM3_DSA_C_LINKED_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *createNode(int data);

Node *insertTail(Node *head, int data);
Node *insertHead(Node *head, int data);
Node *insertAtIndex(Node *head, int data, int index);

int readTail(Node *head);
int readHead(Node *head);
int readAtIndex(Node *head, int index);

Node *deleteTail(Node *head);
Node *deleteHead(Node *head);
Node *deleteAtIndex(Node *head, int index);

Node *findNode(Node *head, int data);
void printNodes(Node *head);

#endif  // SEM3_DSA_C_LINKED_H
