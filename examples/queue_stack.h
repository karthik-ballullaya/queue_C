#include "queue.h"

#ifndef QUEUE_STACK_H_INCLUDED
#define QUEUE_STACK_H_INCLUDED

typedef struct _queue_ Stack;
typedef struct _queue_result_ StackResult;

Stack   stack_new(uint32_t);
Stack * stack_push(Queue *, int32_t, QueueResult *);
Stack * stack_pop(Queue *, QueueResult *);

#endif