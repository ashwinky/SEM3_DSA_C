#include "linked.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

LinkedList *createLinkedList() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  list->size = 0;

  list->head = NULL;
  list->tail = NULL;

  list->_garbage = NULL;
  list->_garbage_size = 0;

  return list;
}

Node *createNode(LinkedList *list, int data) {
  Node *node = NULL;
  if (list->_garbage_size > 0) {
    node = list->_garbage;
    list->_garbage = list->_garbage->next;
    list->_garbage_size--;
  } else {
    node = (Node *)malloc(sizeof(Node));
  }

  node->data = data;
  node->next = NULL;

  return node;
}

Node *insertTail(LinkedList *list, int data) {
  Node *node = createNode(list, data);

  if (list->size == 0) {
    list->head = node;
  } else {
    list->tail->next = node;
  }

  list->tail = node;
  list->size++;
  return node;
}

Node *insertHead(LinkedList *list, int data) {
  Node *node = createNode(list, data);

  if (list->size == 0) {
    list->tail = node;
  } else {
    node->next = list->head;
  }

  list->head = node;
  list->size++;
  return node;
}

Node *insertAtIndex(LinkedList *list, int data, int index) {
  if (index < 0 || index > list->size) {
    D(printf("Index out of bounds"));
    return NULL;
  } else if (index == 0) {
    return insertHead(list, data);  // insert at head
  } else if (index == list->size) {
    return insertTail(list, data);  // insert at tail
  }

  Node *node = createNode(list, data);
  Node *prev = list->head;

  for (int i = 0; i < index - 1; i++) {
    prev = prev->next;
  }

  node->next = prev->next;
  prev->next = node;
  list->size++;

  return node;
}

int readTail(LinkedList *list) {
  if (list->size == 0) {
    D(printf("List is empty"));
    return -1;
  }

  return list->tail->data;
}

int readHead(LinkedList *list) {
  if (list->size == 0) {
    D(printf("List is empty"));
    return -1;
  }

  return list->head->data;
}

int readAtIndex(LinkedList *list, int index) {
  if (index < 0 || index >= list->size) {
    D(printf("Index out of bounds"));
    return -1;
  }

  Node *node = list->head;

  for (int i = 0; i < index; i++) {
    node = node->next;
  }

  return node->data;
}

Node *deleteTail(LinkedList *list) {
  if (list->size == 0) {
    D(printf("List is empty"));
    return NULL;
  }

  Node *node = list->tail;

  if (list->size == 1) {
    list->head = NULL;
    list->tail = NULL;
  } else {
    Node *prev = list->head;

    for (int i = 0; i < list->size - 2; i++) {
      prev = prev->next;
    }

    prev->next = NULL;
    list->tail = prev;
  }

  list->size--;

  node->next = list->_garbage;
  list->_garbage = node;
  list->_garbage_size++;

  return node;
}

Node *deleteHead(LinkedList *list) {
  if (list->size == 0) {
    D(printf("List is empty"));
    return NULL;
  }

  Node *node = list->head;

  if (list->size == 1) {
    list->head = NULL;
    list->tail = NULL;
  } else {
    list->head = list->head->next;
  }

  list->size--;

  node->next = list->_garbage;
  list->_garbage = node;
  list->_garbage_size++;

  return node;
}

Node *deleteAtIndex(LinkedList *list, int index) {
  if (index < 0 || index >= list->size) {
    D(printf("Index out of bounds"));
    return NULL;
  } else if (index == 0) {
    return deleteHead(list);  // delete head
  } else if (index == list->size - 1) {
    return deleteTail(list);  // delete tail
  }

  Node *prev = list->head;

  for (int i = 0; i < index - 1; i++) {
    prev = prev->next;
  }

  Node *node = prev->next;
  prev->next = node->next;
  list->size--;

  node->next = list->_garbage;
  list->_garbage = node;
  list->_garbage_size++;

  return node;
}

Node *findNode(LinkedList *list, int data) {
  Node *node = list->head;

  for (int i = 0; i < list->size; i++) {
    if (node->data == data) {
      return node;
    }

    node = node->next;
  }

  return NULL;
}

void printNodes(LinkedList *list) {
  Node *node = list->head;

  printf("LIST{%d}", list->size);

  for (int i = 0; i < list->size; i++) {
    printf(" -> [%d: %d]", i, node->data);
    node = node->next;
  }

  // print _garbage nodes
  node = list->_garbage;
  printf("\n\t_GARBAGE");
  int j = 0;
  while (node != NULL) {
    printf(" -> [%d: %d]", j, node->data);
    node = node->next;
    j++;
  }

  printf("\n");
}
