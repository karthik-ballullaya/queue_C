#include <stdint.h>

#ifndef PROCESS_NODE_H_INCLUDED
#define PROCESS_NODE_H_INCLUDED

typedef struct _process_node_ Node;
struct _process_node_ {
  uint32_t          process_id;
  uint32_t          arrival_time;
  uint32_t          execution_time;
  uint32_t          priority;
};

typedef struct _process_result_ ProcessResult;
struct _process_result_ {
  uint32_t          turn_around_time;
  uint32_t          waiting_time;
};

#endif