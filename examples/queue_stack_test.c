#include <assert.h>
#include <stdlib.h>
#include "queue_stack.h"

void test_stack(void) {
  Stack s = stack_new(10), *stack = &s;
  StackResult res;
  stack_push(stack, 10, &res);
  stack_push(stack, 20, &res);
  stack_push(stack, 30, &res);
  stack_pop(stack, &res);
  assert(res.data == 30);
  stack_pop(stack, &res);
  assert(res.data == 20);
}

int main(void) {
  test_stack();
}