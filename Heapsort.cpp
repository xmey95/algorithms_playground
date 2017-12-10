#include <iostream>

using namespace std;

template <class H> class HeapSort {
  private:
    H** A;
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

    void scambia(int i, int j){
      H* tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
      return;
    }

    int compare(H* a, H* b){
      return (*b) - (*a);
    }

    void heapify(int i){
      if(i > heapsize){
        return;
      }
      int l = left(i);
      int r = right(i);
      int max = i;

      if(l <= heapsize && compare(A[max], A[l])>0){
        max = l;
      }

      if(r <= heapsize && compare(A[max], A[r])>0){
        max = r;
      }
      if(max == i){
        return;
      }
      scambia(i,max);
      heapify(max);
    }

    void buildheap(){
      for(int i = heapsize / 2; i>0; i--){
        heapify(i);
      }
      return;
    }

    void heapsort(){
      for(int i = heapsize; i > 1; i--){
        scambia(i,1);
        heapsize--;
        heapify(1);
      }
      return;
    }

  public:
    HeapSort(H *v, int len_arr){
      heapsize = 0;
      len = len_arr;
      A = new H*[len_arr + 1];
      for(int i = 0; i < len_arr; i++){
        heapsize++;
        A[heapsize] = new H(v[i]);
      }
      buildheap();
      heapsort();
      int index = 1;
      for(int i = 0; i < len_arr; i++){
        v[i] = *A[index];
        index++;
      }
    }
};

template <class H> void Heapsort(H *v, int size){
  HeapSort<H> *B = new HeapSort<H>(v, size);
}

int main(){
  int A[10] = {5, 3, 2, 8, 6, 1, 13, 4, 14, 9};
  Heapsort(A,10);
  for(int i=0; i<10; i++) cout << A[i] << " ";
  cout << endl;
  float B[10] = {2.1, 7.3, 2.9, 9.2, 3.8, 1.2, 8.3, 7.1, 10.2, 6.5};
  Heapsort(B,10);
  for(int i=0; i<10; i++) cout << B[i] << " ";
  cout << endl;
  char C[10] = {'f', 'g', 's', 't', 'a', 'c', 'i', 'e', 'q', 'r'};
  Heapsort(C,10);
  for(int i=0; i<10; i++) cout << C[i] << " ";
  cout << endl;
  return 0;
}
