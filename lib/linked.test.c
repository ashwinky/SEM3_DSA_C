#include "linked.h"

#include <stdio.h>

#include "utils.h"

TEST("linked list", {
  UNIT("add node", {
    Node *head = NULL;

    head = createNode(1);

    ASSERT(readHead(head), 1);
    ASSERT(readTail(head), 1);
  });

  UNIT("read tail", {
    Node *head = createNode(0);
    head = insertTail(head, 1);
    head = insertTail(head, 2);

    ASSERT(readTail(head), 2);
  });

  UNIT("read head", {
    Node *head = createNode(1);
    head = insertTail(head, 2);
    head = insertTail(head, 3);

    ASSERT(readHead(head), 1);
  });

  UNIT("read at index", {
    Node *head = createNode(1);
    head = insertTail(head, 2);
    head = insertTail(head, 3);

    ASSERT(readAtIndex(head, 1), 2);
  });

  UNIT("insert at tail", {
    Node *head = createNode(0);

    for (int i = 1; i < 5; i++) {
      head = insertTail(head, i);
    }

    for (int i = 0; i < 5; i++) {
      ASSERT(readAtIndex(head, i), i);
    }
  });

  UNIT("insert at head", {
    Node *head = createNode(0);

    for (int i = 1; i < 5; i++) {
      head = insertHead(head, i);
    }

    for (int i = 0; i < 5; i++) {
      ASSERT(readAtIndex(head, i), 4 - i);
    }
  });

  UNIT("insert at index", {
    Node *head = createNode(0);

    for (int i = 1; i < 5; i++) {
      head = insertTail(head, i);
    }

    head = insertAtIndex(head, 5, 2);

    int nums[] = {0, 1, 5, 2, 3, 4};

    for (int i = 0; i < 6; i++) {
      ASSERT(readAtIndex(head, i), nums[i]);
    }
  });

  UNIT("delete from tail", {
    Node *head = createNode(0);

    for (int i = 1; i < 5; i++) {
      head = insertTail(head, i);
    }

    head = deleteTail(head);

    for (int i = 0; i < 4; i++) {
      ASSERT(readAtIndex(head, i), i);
    }
  });

  UNIT("delete from head", {
    Node *head = createNode(0);

    for (int i = 1; i < 5; i++) {
      head = insertTail(head, i);
    }

    head = deleteHead(head);

    for (int i = 0; i < 4; i++) {
      ASSERT(readAtIndex(head, i), i + 1);
    }
  });

  UNIT("delete from index", {
    Node *head = createNode(0);

    for (int i = 1; i < 5; i++) {
      head = insertTail(head, i);
    }

    head = deleteAtIndex(head, 2);

    int nums[] = {0, 1, 3, 4};

    for (int i = 0; i < 4; i++) {
      ASSERT(readAtIndex(head, i), nums[i]);
    }
  });
})
