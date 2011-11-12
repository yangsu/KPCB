#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include "queue.h"
using namespace std;

FILE* bqout, *stlqout;
BoundedQueue* bq;
queue<int>* stlq;
int bound;

void e(int i) {
  if (bq->enqueue(i)) {
    fprintf(bqout, "enqueue %d\n", i);
    fprintf(stlqout, "enqueue %d\n", i);
    stlq->push(i);
  }
}

void d() {
  int result;
  if (bq->dequeue(&result)) {
    fprintf(bqout, "dequeue %d\n", result);
    fprintf(stlqout, "dequeue %d\n", stlq->front());
    stlq->pop();
  }
}
void ed(int i) {
  e(i);
  d();
}

int main(int argc, char const *argv[]) {
  if (argc < 4)
    printf("Please specify queue bound and FILEnames for the outputs of both boundedqueue and stl queue\n");
  else {
    bound = atoi(argv[1]);
    bqout = fopen(argv[2], "w+");
    stlqout = fopen(argv[3], "w+");
    bq = new BoundedQueue(bound);
    stlq = new queue<int>;
    
    srand(0);
    int cc = rand() % 2;
    int num = rand() % 100000;
    for (unsigned int i = 0; i < 1000000; ++i) {
      switch (cc) {
        case 0:
          e(num);
          break;
        case 1:
          d();
          break;
        case 2:
        default:
          ed(num);
          break;
      }
      cc = rand() % 2;
      num = rand() % 100000;
    }
    
    delete bq;
    delete stlq;
    fclose(bqout);
    fclose(stlqout);
  }

  return 0;
}