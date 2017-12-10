# algorithms_playground

An Implementation of Heap Structure with Heapsort and RB Tree in C++

## Heap

A binary Heap is a data structure based on an almost complete binary tree (all its levels except the last one are complete) with the property that the key on each node is greater / less or equal to the key of children. Heaps are implemented in memory as an array where the root is stored in the index element 1 and the two children are stored in position elements 2i (left) and 2i + 1 (right).

### Heapify

Heapify is a function with the purpose of maintaining the heap property. If finds a major / minor child of the root, exchanges the root with the major / minor of her children. It is necessary to apply recursively the function to the modified subtree.

```
void heapify(int i){
  if(i > heapsize){
    return;
  }
  int l = left(i);
  int r = right(i);
  int max = i;

  if(l <= heapsize && compare(A[max],A[l])>0){
    max = l;
  }

  if(r <= heapsize && compare(A[max],A[r])>0){
    max = r;
  }

  if(max == i){
    return;
  }
  scambia(i, max);
  heapify(max);
}
```

### BuildHeap

BuildHeap uses the heapify function to transform any array of n elements into a heap. Work on the elements of the tree that are not leaves by operating from right to left of the array.

```
void buildheap(){
  for(int i = heapsize / 2; i>0; i--){
    heapify(i);
  }
  return;
}
```

### HeapSort

Heapsort orders an array according to the following steps:

- Transforms the array into a heap with buildheap.

- Takes the value contained in the root and puts it at the end.

- Reduces the heap size by 1.

- Restore the heap property with heapify.

- Repeat the procedure until the heap size is reduced to 2.

```
void heapsort(){
  for(int i = heapsize; i > 1; i--){
    scambia(i,1);
    heapsize--;
    heapify(1);
  }
  return;
}
```
