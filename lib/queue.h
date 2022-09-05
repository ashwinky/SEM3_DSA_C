#ifndef SEM3_DSA_C_QUEUE_H
#define SEM3_DSA_C_QUEUE_H

#include <stdbool.h>

struct Queue;

struct Queue* createQueue(unsigned capacity);

bool isFull(struct Queue* queue);

bool isEmpty(struct Queue* queue);

void dequeue(struct Queue* queue, int item);

void enqueue(struct Queue* queue, int item);

int at(struct Queue* queue, int index);

#endif  // SEM3_DSA_C_QUEUE_H
