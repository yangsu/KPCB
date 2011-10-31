#include "queue.h"
BoundedQueue::BoundedQueue(int n) {
  bound = n;
  size = 0;
  head = tail = 0;
}

BoundedQueue::~BoundedQueue() {
  node* temp;
  while (head != 0) {
    temp = head->next;
    delete head;
    head = temp; 
  }
  size = 0;
}

bool BoundedQueue::enqueue(int n) {
  if (size < bound) {
    if (size == 0) {
      head = new node(n);
      tail = head;
    }
    else {
      tail->next = new node(n);
      tail = tail->next;
    }
    size++;
    return true;
  }
  return false;
}

bool BoundedQueue::dequeue(int* ptr) {
  if (size > 0) {
    node* temp = head;
    head = head->next;
    *ptr = temp->value;
    tail = (size == 1) ? 0 : tail;
    delete temp;
    --size;
    return true;
  }
  return false;
}