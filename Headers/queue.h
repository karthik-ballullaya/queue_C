#include <stdint.h>
#include "appconst.h"

#ifndef QUEUE_CONTENT_TYPE
#define QUEUE_CONTENT_TYPE int32_t
#endif

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct _queue_ Queue;

struct _queue_ {
  uint32_t          size;
  uint32_t          count;
  uint32_t          front;
  uint32_t          rear;
  QUEUE_CONTENT_TYPE           data[Q_LEN];
};

typedef struct _queue_result_ QueueResult;

struct _queue_result_ {
  QUEUE_CONTENT_TYPE          data;
  uint32_t         status;
};


Queue               queue_new(uint32_t);
uint8_t             queue_full(const Queue *);
uint8_t             queue_empty(const Queue *);
Queue*              queue_add(Queue *, QUEUE_CONTENT_TYPE, QueueResult *);
Queue*              queue_delete(Queue *, QueueResult *);
uint32_t            queue_length(Queue *);


#endif