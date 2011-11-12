#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char const *argv[]) {
  BoundedQueue q(268435456);
  bool success;
  int count = 0;
  for (int i = 0; i < 268435456; ++i) {
    success = q.enqueue(i);
    count += (success) ? 1 : 0;
  }
  printf("enqueued %d\n", count);
  count = 0;
  int result;
  for (int i = 0; i < 268435456; ++i) {
    success = q.dequeue(&result);
    count += (success) ? 1 : 0;
  }
  printf("dequeued %d\n", count);
  return 0;
}