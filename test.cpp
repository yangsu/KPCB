#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char const *argv[]) {
  BoundedQueue q(50000000);
  bool success;
  int count = 0;
  for (int i = 0; i < 60000000; ++i) {
    success = q.enqueue(i);
    count += (success) ? 1 : 0;
  }
  printf("enqueued %d\n", count);
  count = 0;
  int result;
  for (int i = 0; i < 60000000; ++i) {
    success = q.dequeue(&result);
    if (i % 10000000 == 0)
      printf("%d\n", result);
    count += (success) ? 1 : 0;
  }
  printf("dequeued %d\n", count);
  return 0;
}