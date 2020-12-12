#include "queue.h"
#include "queue_stack.h"

Stack stack_new(uint32_t size) {
  return queue_new(size);
}

Stack * stack_push(Stack *stack, int32_t element, StackResult *res) {
  uint32_t len = queue_length(stack);
  stack = queue_add(stack, element, res);

  for (uint32_t i = 0; i < len; i++) {
    stack = queue_delete(stack, res);
    stack = queue_add(stack, res->data, res);
  }
  return stack;
}

Stack * stack_pop(Stack * stack, StackResult * res) {
  return queue_delete(stack, res);
}