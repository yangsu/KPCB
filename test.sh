#/bin/sh
BQOUT="bq.out"
STLQOUT="stlq.out"

g++ queue.cpp -c -o queue.a

g++ queue.a storagetest.cpp -o storage
echo "timing storage :"
time ./storage

g++ queue.a correctnesstest.cpp -o correctness
echo "testing correctness :"
for i in {0..20}; do
  echo "queue bound size "$i
  ./correctness $i $BQOUT $STLQOUT
  diff $BQOUT $STLQOUT
done

rm queue.a storage correctness $BQOUT $STLQOUT