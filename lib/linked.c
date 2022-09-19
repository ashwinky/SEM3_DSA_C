#include "linked.h"

#include <stdio.h>
#include <stdlib.h>

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

Node *insertTail(Node *head, int data) {
  Node *temp = head;

  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = createNode(data);

  return head;
}

Node *insertHead(Node *head, int data) {
  Node *newNode = createNode(data);

  newNode->next = head;

  return newNode;
}

Node *insertAtIndex(Node *head, int data, int index) {
  Node *newNode = createNode(data);
  Node *temp = head;

  for (int i = 0; i < index - 1; i++) {
    temp = temp->next;
  }

  newNode->next = temp->next;
  temp->next = newNode;

  return head;
}

int readTail(Node *head) {
  Node *temp = head;

  while (temp->next != NULL) {
    temp = temp->next;
  }

  return temp->data;
}

int readHead(Node *head) { return head->data; }

int readAtIndex(Node *head, int index) {
  Node *temp = head;

  for (int i = 0; i < index; i++) {
    temp = temp->next;
  }

  return temp->data;
}

Node *deleteTail(Node *head) {
  Node *temp = head;

  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  free(temp->next);
  temp->next = NULL;

  return head;
}

Node *deleteHead(Node *head) {
  Node *temp = head;

  head = head->next;
  free(temp);

  return head;
}

Node *deleteAtIndex(Node *head, int index) {
  Node *temp = head;

  for (int i = 0; i < index - 1; i++) {
    temp = temp->next;
  }

  Node *temp2 = temp->next;

  temp->next = temp->next->next;
  free(temp2);

  return head;
}

Node *findNode(Node *head, int data) {
  Node *temp = head;

  while (temp->data != data) {
    temp = temp->next;
  }

  return temp;
}

void printNodes(Node *head) {
  Node *temp = head;

  printf("List { ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("}\n");
}
