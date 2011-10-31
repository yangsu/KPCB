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
    */
  bool enqueue(int n);
  /** dequeue - function should return an integer if one is currently stored in
    * the queue. The function should properly handle the case where the queue is
    * empty.
    */
  bool dequeue(int* ptr);
  
  struct __attribute__((__packed__)) node
  {
    int value;
    node* next;
    node(int n) {value = n;}
  };
private:
  
  node* head;
  node* tail;
  int size;
  int bound;
};