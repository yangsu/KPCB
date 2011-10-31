#include "queue.h"
#include <stdlib.h>
#include <string.h>
BoundedQueue::BoundedQueue(int n) {
  bound = n;
  size = blockSize = 0;
  base = head = tail = 0;
}

BoundedQueue::~BoundedQueue() {
  free(base);
}

bool BoundedQueue::enqueue(int n) {
  if (size < bound) {
    if (size == 0) {
      base = (int*)malloc(sizeof(int));
      head = base;
      tail = base;
      blockSize = 1;
    }
    if (size == blockSize) {
      int doublesize = blockSize * 2;
      int boundSize = bound*sizeof(int);
      blockSize = (doublesize > boundSize) ? boundSize : doublesize;
      int* temp = (int*)malloc(blockSize*sizeof(int));
      
      memcpy(temp, head, size*sizeof(int));
      free(base);
      base = temp;
      head = base;
      tail = base + size;
    }
    *tail = n;
    ++tail;
    ++size;
    return true;
  }
  return false;
}

bool BoundedQueue::dequeue(int* ptr) {
  if (size > 0) {
    *ptr = *head;
    ++head;
    --size;
    return true;
  }
  return false;
}