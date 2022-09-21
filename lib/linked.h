#ifndef SEM3_DSA_C_LINKED_H
#define SEM3_DSA_C_LINKED_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct LinkedList {
  int size;
  Node *head;
  Node *tail;

  Node *_garbage;
  int _garbage_size;

} LinkedList;

LinkedList *createLinkedList();
Node *createNode(LinkedList *list, int data);

Node *insertTail(LinkedList *list, int data);
Node *insertHead(LinkedList *list, int data);
Node *insertAtIndex(LinkedList *list, int data, int index);

int readTail(LinkedList *list);
int readHead(LinkedList *list);
int readAtIndex(LinkedList *list, int index);

Node *deleteTail(LinkedList *list);
Node *deleteHead(LinkedList *list);
Node *deleteAtIndex(LinkedList *list, int index);

Node *findNode(LinkedList *list, int data);
void printNodes(LinkedList *list);

#endif  // SEM3_DSA_C_LINKED_H
