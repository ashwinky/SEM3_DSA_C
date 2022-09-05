#include "queue.h"

#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

#include "utils.h"

struct Queue {
  int front, rear, size;
  unsigned capacity;
  int* array;
};

struct Queue* createQueue(unsigned capacity) {
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;
  queue->rear = capacity - 1;  // This is important, see the enqueue
  queue->array = (int*)malloc(queue->capacity * sizeof(int));
  return queue;
}

bool isFull(struct Queue* queue) { return (queue->size == queue->capacity); }

bool isEmpty(struct Queue* queue) { return (queue->size == 0); }

void dequeue(struct Queue* queue, int item) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return;
  }
  item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size = queue->size - 1;
  D(printf("%d dequeued from queue \n", item));
}

void enqueue(struct Queue* queue, int item) {
  if (isFull(queue)) {
    printf("Queue is full\n");
    return;
  }

  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;
  D(printf("%d enqueued to queue\n", item));
}

int at(struct Queue* queue, int index) {
  if (index >= queue->size) {
    printf("Index out of bounds\n");
    return -1;
  }
  return queue->array[(queue->front + index) % queue->capacity];
}
