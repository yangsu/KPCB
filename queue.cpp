#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"

#define INITIAL_SIZE 1

BoundedQueue::BoundedQueue(int n) {
  bound = n;
  size = 0;
  
  base = (int*)malloc(INITIAL_SIZE*sizeof(int));
  head = base;
  tail = base;
  blockSize = 1;
}

BoundedQueue::~BoundedQueue() {
  free(base);
}

bool BoundedQueue::enqueue(int n) {
  if (size < bound) {
    if (size == blockSize) {
      int c1 = base + blockSize - head;
      int c2 = size - c1;

      blockSize = blockSize << 1;
      blockSize = (blockSize > bound) ? bound : blockSize;
      int* temp = (int*)malloc(blockSize*sizeof(int));
      
      memcpy(temp, head, c1*sizeof(int));
      memcpy(temp + c1, base, c2*sizeof(int));

      free(base);
      base = temp;
      head = base;
      tail = base + size;
    }
    *tail = n;
    tail = (tail >= base + blockSize - 1) ? base : tail + 1;
    ++size;
    return true;
  }
  return false;
}

bool BoundedQueue::dequeue(int* ptr) {
  if (size > 0) {
    *ptr = *head;
    head = (head >= base + blockSize - 1) ? base : head + 1;
    --size;
    return true;
  }
  return false;
}