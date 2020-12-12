#include <stdlib.h>
#include <assert.h>
#include "queue.h"

Queue queue_new(uint32_t size) {
  size = (size < Q_LEN) ? size: Q_LEN;
  Queue queue = { size, 0, 0, 0, {0} };
  return queue;
}

uint8_t queue_full(const Queue *queue) {
  assert(queue != NULL);
  return (queue->count == queue->size);
}

uint8_t queue_empty(const Queue *queue) {
  assert(queue != NULL);
  return (queue->count == 0);
}

Queue* queue_add(Queue *queue, QUEUE_CONTENT_TYPE data, QueueResult *result) {
  assert(queue != NULL);
  if (queue->count < queue->size) {
    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % queue->size;
    queue->count++;
    result->status = QUEUE_OK;
    result->data = data;
  } else {
    result->status = QUEUE_FULL;
  }
  return queue;
}

Queue* queue_delete(Queue* queue, QueueResult* result) {
  assert(queue != NULL);
  if (queue->count != 0) {
    result->data = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    queue->count--;
    result->status = QUEUE_OK;
  } else {
    result->status = QUEUE_EMPTY;
  }
  return queue;
}

uint32_t queue_length(Queue *queue) {
  assert(queue != NULL);
  return queue->count;
}