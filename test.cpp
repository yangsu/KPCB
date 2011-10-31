#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main(int argc, char const *argv[]) {
  BoundedQueue q(50000000);
  printf("%d %d %d\n", (int)sizeof(struct BoundedQueue::node), (int)sizeof(BoundedQueue::node*),(int)sizeof(int));
  bool success;
  int count = 0;
  for (int i = 0; i < 60000000; ++i) {
    success = q.enqueue(i);
    count += (success) ? 1 : 0;
    sleep(1000);
  }
  printf("enqueued %d\n", count);
  count = 0;
  int result;
  for (int i = 0; i < 60000000; ++i) {
    success = q.dequeue(&result);
    count += (success) ? 1 : 0;
    
  }
  printf("dequeued %d\n", count);
  return 0;
}