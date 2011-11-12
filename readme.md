KPCB Engineering Fellows Program - Challenge Problem
====================================================
Applicant: Yang Su  
Email: yang.su@duke.edu  
Language C++  

Problem:  
--------
Using only primitive types, implement a bounded queue to store integers. The data structure should be optimized for algorithmic runtime, memory usage, and memory throughput. No external libraries should be imported and/or used. The solution should be delivered in one class that provides the following functions:

* **constructor** - class should provide one method for object creation that takes an integer to set the size of the queue.
* **enqueue** - function should take an integer and store it in the queue if the queue isn't full. The function should properly handle the case where the queue is already full.
* **dequeue** - function should return an integer if one is currently stored in the queue. The function should properly handle the case where the queue is empty.

Solution:
---------
In order to save memory and allow for easy enqueuing and dequeuing of numbers from the queue, the BoundedQueue class is implemented so the numbers are stored in a contiguous memory block. The block starts out at size of 1 (storage for 1 int that is) and doubles in size every time the current block runs out of memory up to the max size specified when the BoundedQueue was constructed. Each time the size doubles, a new chunk of memory is allocated, the contents are then copied to the new block and the pointers updated, and the old block is discarded. 

* **queue.h** - heading for the BoundedQueue Class
* **queue.cpp** - implementation details of the BoundedQueue Class
  * use *INITIAL_SIZE* to adjust the initial size of a new BoundedQueue. Default is 1
* **test.cpp** - a simple test that enqueues and dequeues a large number of elements to test if the the program produces the correct output

to run test:

    g++ queue.cpp test.cpp -o test; time ./test