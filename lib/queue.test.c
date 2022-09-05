#include "queue.h"

#include <stdio.h>

#include "utils.h"

TEST("queue", {
  UNIT("at", {
    struct Queue* queue = createQueue(5);
    int values[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
      enqueue(queue, values[i]);
    }

    for (int i = 0; i < 5; i++) {
      ASSERT(at(queue, i), values[i]);
    }
  });

  UNIT("enqueue", {
    struct Queue* queue = createQueue(5);
    int values[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
      enqueue(queue, values[i]);
    }

    for (int i = 0; i < 5; i++) {
      ASSERT(at(queue, i), values[i]);
    }
  });

  UNIT("dequeue", {
    struct Queue* queue = createQueue(5);
    int values[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
      enqueue(queue, values[i]);
    }

    for (int i = 0; i < 5; i++) {
      ASSERT(at(queue, i), values[i]);
    }
  });

  UNIT("isFull", {
    struct Queue* queue = createQueue(5);
    int values[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
      enqueue(queue, values[i]);
    }

    ASSERT(isFull(queue), true);
  });

  UNIT("isEmpty", {
    struct Queue* queue = createQueue(5);
    int values[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
      enqueue(queue, values[i]);
    }

    ASSERT(isEmpty(queue), false);
  });
})