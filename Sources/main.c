#include <stdlib.h>
#include <assert.h>
#include "appconst.h"
#include "queue.h"

void test_queue_new() {
  Queue q1 = queue_new(10);
  assert(q1.size == 10 && queue_empty(&q1));
  q1 = queue_new(-1);
  assert(q1.size == Q_LEN);
  q1 = queue_new(Q_LEN + 1);
  assert(q1.size == Q_LEN);
}

void test_queue_add() {
  Queue q1 = queue_new(2);
  Queue *queue = &q1;
  QueueResult r1, *result;
  result = &r1;
  queue_add(queue, 10, result);
  assert(result->status == QUEUE_OK && result->data == 10);
  queue_add(queue, 20, result);
  queue_add(queue, 30, result);
  assert(result->status == QUEUE_FULL && queue_full(queue));
  assert(queue->front == 0 && queue->rear == 0 && queue_length(queue) == 2);
}

void test_queue_delete() {
  Queue q1 = queue_new(2);
  Queue *queue = &q1;
  QueueResult r1, *result;
  result = &r1;
  queue_add(queue, 10, result);
  queue_delete(queue, result);
  assert(result->status == QUEUE_OK && result->data == 10);
  assert(queue->front == 1 && queue->rear == 1 && queue_length(queue) == 0);
  queue_add(queue, 20, result);
  queue_add(queue, 30, result);
  queue_delete(queue, result);
  queue_delete(queue, result);
  assert(result->status == QUEUE_OK && result->data == 30);
  queue_delete(queue, result);
  assert(result->status == QUEUE_EMPTY);
  assert(queue->front == 1 && queue->rear == 1 && queue_length(queue) == 0);
}

int main(void) {
  test_queue_new();
  test_queue_add();
  test_queue_delete();
  return 1;
}