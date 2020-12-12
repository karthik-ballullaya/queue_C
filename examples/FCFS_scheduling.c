#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "appconst.h"
#include "queue.h"
#include "processnode.h"

void test_FCFS_scheduling();
void FCFS_scheduling(Queue*, QueueResult*, ProcessResult*);

int main() {
  test_FCFS_scheduling();
}

void FCFS_scheduling(Queue* queue, QueueResult* queue_result, ProcessResult * result) {
  Node *processnode;
  uint32_t time = 0;
  queue_delete(queue, queue_result);
  processnode = (Node *)queue_result->data;
  for (uint32_t i = 0; queue_result->status == QUEUE_OK; i++) {
    if (time > processnode->arrival_time) {  
      result[i].waiting_time = time - processnode->arrival_time;
    } else {
      result[i].waiting_time = 0;
    }
    result[i].turn_around_time = result[i].waiting_time + processnode->execution_time;
    time += processnode->execution_time + 1;
    queue_delete(queue, queue_result);
    processnode = (Node *) queue_result->data;
  }
}

void test_FCFS_scheduling() {
  Queue q = queue_new(4), *queue;
  QueueResult queue_result;
  ProcessResult res[4];
  Node n1 = { 0, 0, 5, 1 }, n2 = { 0, 1, 1, 1 }, n3 = { 0, 8, 10, 1 }, n4 = { 0, 10, 5, 1 };
  queue = &q;
  queue = queue_add(queue, &n1, &queue_result);
  queue = queue_add(queue, &n2, &queue_result);
  queue = queue_add(queue, &n3, &queue_result);
  queue = queue_add(queue, &n4, &queue_result);
  FCFS_scheduling(queue, &queue_result, res);
  assert(res[0].turn_around_time == 5 && res[0].waiting_time == 0);
  assert(res[1].turn_around_time == 6 && res[1].waiting_time == 5);
  assert(res[2].turn_around_time == 10 && res[2].waiting_time == 0);
  assert(res[3].turn_around_time == 14 && res[3].waiting_time == 9);
}