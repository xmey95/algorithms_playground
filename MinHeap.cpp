#include <iostream>

using namespace std;

template <class H> class Heap {
  public:
    virtual Heap<H>* enqueue(H x) = 0;
    virtual H* top() = 0;
    virtual Heap<H>* extract() = 0;
    virtual Heap<H>* buildheap(H *v, H len) = 0;
    virtual void print() = 0;
};

template <class H> class MinHeap : public Heap<H> {
  private:
    H **A;
    int heapsize;
    int len;

    int left(int i){
      return i<<1;
    }

    int right(int i){
      return (i<<1)|1;
    }

    int parent(int i){
      return i>>1;
    }

    int compare(H*a, H*b){
      return (*b)-(*a);
    }

    void scambia(int i, int j){
      H* tmp = this->A[i];
      this->A[i] = this->A[j];
      this->A[j] = tmp;
    }

    void heapify(int i){
      if(i>heapsize) return;
      int l = left(i);
      int r = right(i);
      int min = i;
      if(l<=heapsize && compare(A[min], A[l])<0) min=l;
      if(r<=heapsize && compare(A[min], A[r])<0) min=r;
      if(min==i) return;
      scambia(i,min);
      heapify(min);
    }

  public:
    MinHeap(H* v, int len_arr){
      A = new H*[50];
      heapsize = 0;
      len = 50;
      buildheap(v, len_arr);
    }

    Heap<H>* enqueue(H x) {
      if(heapsize >= len) {
        return NULL;
      }
      heapsize += 1;
      A[heapsize] = new H(x);

      int i = heapsize;
      while(i > 0 && compare(A[i], A[parent(i)])>0) {
        scambia(i, parent(i));
        i = parent(i);
      }
      return this;
    }

    H* top() {
      if(heapsize == 0){
        return NULL;
      }
      return A[1];
    }

    Heap<H>* extract() {
      if(heapsize == 0){
        return NULL;
      }
      scambia(1,heapsize);
      heapsize--;
      heapify(1);
      return this;
    }

    Heap<H>* buildheap(H *v, H len) {
      for(int i = 0; i < len; i++){
        heapsize += 1;
        A[heapsize] = new H(v[i]);
      }
      for(int i = heapsize/2; i > 0; i--){
        heapify(i);
      }

      return this;
    }

    void print() {
      cout << "HEAP : ";
      for(int i=1; i<=heapsize; i++)
      cout << *A[i] << " ";
      cout << endl;
    }
};

int main(){
  int arr[9] = {5, 3, 2, 8, 6, 1, 13, 4, 14};
  MinHeap<int> *B = new MinHeap<int>(arr, 9);
  B->print();
  B->enqueue(7)->enqueue(10)->enqueue(12);
  B->print();
  B->extract()->extract();
  B->print();
  return 0;
}
