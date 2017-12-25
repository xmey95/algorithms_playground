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

template <class H> class MaxHeap : public Heap<H> {
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

int compare(H*a, H*b){
        return (*b)-(*a);
}

void heapify(int i){
        if(i>heapsize) return;
        int l = left(i);
        int r = right(i);
        int max = i;
        if(l<=heapsize && compare(A[max], A[l])>0) {
                max = l;
        }
        if(r<=heapsize && compare(A[max], A[r])>0) {
                max = r;
        }
        if(max == i) {
                return;
        }
        scambia(i,max);
        heapify(max);
}

public:
MaxHeap(H* v, int len_arr){
        heapsize = 0;
        len = 50;
        A = new H*[len];
        buildheap(v, len_arr);
}

Heap<H>* enqueue(H x){
        if(heapsize>=len) {
                return NULL;
        }
        heapsize++;
        A[heapsize] = new H(x);
        int i = heapsize;
        while(i>0 && compare(A[i], A[parent(i)])<0) {
                scambia(i, parent(i));
                i = parent(i);
        }
        return this;
}

H* top(){
        if(heapsize == 0) {
                return NULL;
        }
        return A[1];
}

Heap<H>* extract(){
        if(heapsize == 0) {
                return NULL;
        }
        scambia(1, heapsize);
        heapsize--;
        heapify(1);
        return this;
}

Heap<H>* buildheap(H *v, H len){
        for(int i = 0; i < len; i++) {
                heapsize++;
                A[heapsize] = new H(v[i]);
        }
        for(int i = heapsize / 2; i > 0; i--) {
                heapify(i);
        }
        return this;
}

void print(){
        cout << "HEAP: ";
        for(int i = 1; i<=heapsize; i++) {
                cout << *A[i] << " ";
        }
        cout << endl;
        return;
}
};

int main(){
        int arr[9] = {5, 3, 2, 8, 6, 1, 13, 4, 14};
        MaxHeap<int> *B = new MaxHeap<int>(arr, 9);
        B->print();
        B->enqueue(7)->enqueue(10)->enqueue(12);
        B->print();
        B->extract()->extract();
        B->print();
        return 0;
}
