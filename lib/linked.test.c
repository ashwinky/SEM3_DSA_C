#include "linked.h"

#include <stdio.h>

#include "utils.h"

TEST("linked list", {
  UNIT("create linked list", {
    LinkedList *list = createLinkedList();
    ASSERT(list->size, 0);
    ASSERT(list->head, NULL);
    ASSERT(list->tail, NULL);
    ASSERT(list->_garbage, NULL);
    ASSERT(list->_garbage_size, 0);
  });

  UNIT("add new node to list", {
    LinkedList *list = createLinkedList();
    Node *node = createNode(list, 10);

    ASSERT(node->data, 10);
    ASSERT(node->next, NULL);
  });

  UNIT("read data at tail", {
    LinkedList *list = createLinkedList();

    for (int i = 1; i <= 3; i++) {
      insertTail(list, i * 10);
    }

    ASSERT(readTail(list), 30);
  });

  UNIT("read data at head", {
    LinkedList *list = createLinkedList();

    for (int i = 1; i <= 3; i++) {
      insertTail(list, i * 10);
    }

    ASSERT(readHead(list), 10);
  });

  UNIT("read data at index", {
    LinkedList *list = createLinkedList();

    for (int i = 1; i <= 3; i++) {
      insertTail(list, i * 10);
    }

    for (int i = 1; i <= 3; i++) {
      ASSERT(readAtIndex(list, i - 1), i * 10);
    }
  });

  UNIT("insert node at tail", {
    LinkedList *list = createLinkedList();

    for (int i = 1; i <= 3; i++) {
      insertTail(list, i * 10);
    }

    ASSERT(list->size, 3);

    for (int i = 1; i <= 3; i++) {
      ASSERT(readAtIndex(list, i - 1), i * 10);
    }

    ASSERT(list->tail->data, 30);
  });

  UNIT("insert node at head", {
    LinkedList *list = createLinkedList();

    for (int i = 1; i <= 3; i++) {
      insertHead(list, i * 10);
    }

    ASSERT(list->size, 3);

    for (int i = 1; i <= 3; i++) {
      ASSERT(readAtIndex(list, i - 1), (4 - i) * 10);
    }

    ASSERT(list->head->data, 30);
  });

  UNIT("insert node at index", {
    LinkedList *list = createLinkedList();

    for (int i = 1; i <= 3; i++) {
      insertTail(list, i * 10);
    }

    insertAtIndex(list, 40, 1);

    ASSERT(list->size, 4);

    ASSERT(readAtIndex(list, 1), 40);
  });

  UNIT("delete node from tail", {
    LinkedList *list = createLinkedList();

    for (int i = 1; i <= 3; i++) {
      insertTail(list, i * 10);
    }

    deleteTail(list);

    ASSERT(list->size, 2);

    ASSERT(readAtIndex(list, 1), 20);

    ASSERT(list->_garbage->data, 30);
    ASSERT(list->_garbage_size, 1);
  });

  UNIT("delete node from head", {
    LinkedList *list = createLinkedList();

    for (int i = 1; i <= 3; i++) {
      insertTail(list, i * 10);
    }

    deleteHead(list);

    ASSERT(list->size, 2);

    ASSERT(readAtIndex(list, 0), 20);

    ASSERT(list->_garbage->data, 10);
    ASSERT(list->_garbage_size, 1);
  });

  UNIT("delete node from index", {
    LinkedList *list = createLinkedList();

    for (int i = 1; i <= 3; i++) {
      insertTail(list, i * 10);
    }

    deleteAtIndex(list, 1);

    ASSERT(list->size, 2);

    ASSERT(readAtIndex(list, 1), 30);

    ASSERT(list->_garbage->data, 20);
    ASSERT(list->_garbage_size, 1);
  });

  UNIT("find node", {
    LinkedList *list = createLinkedList();

    for (int i = 1; i <= 3; i++) {
      insertTail(list, i * 10);
    }

    Node *node = findNode(list, 20);

    ASSERT(node->data, 20);
  });

  UNIT("print nodes", {
    LinkedList *list = createLinkedList();

    for (int i = 1; i <= 8; i++) {
      insertTail(list, i * 10);
    }

    for (int i = 1; i <= 4; i++) {
      deleteHead(list);
    }

    printNodes(list);
  });
})
