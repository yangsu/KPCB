/**
  * KPCB Engineering Fellows Program - Challenge Problem Attempt
  * Applicant: Yang Su  
  * Email: yang.su@duke.edu
  */
class BoundedQueue {
public:
/**
  * constructor - class should provide one method for object creation that takes
  * an integer to set the size of the queue.
  */
  BoundedQueue(int n);
  ~BoundedQueue();
  
  /** 
    * enqueue - function should take an integer and store it in the queue if the
    * queue isn't full. The function should properly handle the case where the
    * queue is already full.
    * 
    * returns true if the number n is enqueued successfully, false
    * otherwise
    */
  bool enqueue(int n);
  /** 
    * dequeue - function should return an integer if one is currently stored in
    * the queue. The function should properly handle the case where the queue is
    * empty.
    *
    * returns true if the queue is not empty and the number at the front of the
    * queue is correctly dequeued and copied into the memory location pointed to
    * by the argument int pointer. returns false otherwise and ptr is untouched
    */
  bool dequeue(int* ptr);
  
private:
  int size;
  int blockSize;
  int bound;
  int* base;
  int* head;
  int* tail;
};