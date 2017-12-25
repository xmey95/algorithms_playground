#include <iostream>

using namespace std;

template <class H> struct Node {
        H x;
        int color;
        Node<H> *left, *right, *parent;
};

template <class H> class RBTree {
private:
Node<H> *root;
static const int BLACK = 0;
static const int RED = 1;

RBTree<H> *insert_node(H x){
        Node<H> *tmp = this->root;
        Node<H> *parent = NULL;

        while(tmp!=NULL) {
                parent = tmp;
                if(x < tmp->x) {
                        tmp = tmp->left;
                }
                else{
                        tmp = tmp->right;
                }
        }
        Node<H> *nuovo = new struct Node<H>;
        nuovo->x = x;
        nuovo->left = NULL;
        nuovo->right = NULL;
        nuovo->color = RED;
        if(parent == NULL) {
                this->root = nuovo;
                return this;
        }
        nuovo->parent = parent;
        if(x < parent->x) {
                parent->left = nuovo;
        }
        else{
                parent->right = nuovo;
        }
        return this;
}

void preorder_visit(Node<H> *p){
        if(p!=NULL) {
                cout << p->x << " " << printC(p->color) << endl;
                preorder_visit(p->left);
                preorder_visit(p->right);
        }
}

void postorder_visit(Node<H> *p){
        if(p!=NULL) {
                postorder_visit(p->left);
                postorder_visit(p->right);
                cout << p->x << " " << printC(p->color) << endl;
        }
}

void inorder_visit(Node<H> *p){
        if(p!=NULL) {
                inorder_visit(p->left);
                cout << p->x << " " << printC(p->color) << endl;
                inorder_visit(p->right);
        }
}

char printC(int color){
        if(color == 0) {
                return 'B';
        }
        else if(color == 1) {
                return 'R';
        }
        else{
                return 'X';
        }
}

void InsertFixup(Node<H> *p){
        if(p->parent != NULL && p->parent->color == BLACK) {
                return;
        }
        if(p == root) {
                p->color = BLACK;
                return;
        }
        Node<H>* parent = p->parent;
        Node<H>* nonno = parent->parent;
        Node<H>* zio = nonno->left;
        if(nonno->left == parent) {
                zio = nonno->right;
        }
        if(zio->color == RED) {
                parent->color = BLACK;
                zio->color = BLACK;
                nonno->color = RED;
                InsertFixup(nonno);
                return;
        }
        if(parent == nonno->left) {
                if(p == parent->right) {
                        leftRotate(parent);
                        parent = p;
                        p = parent->left;
                }
                rightRotate(nonno);
        }
        else{
                if(p == parent->left) {
                        rightRotate(parent);
                        parent = p;
                        p = parent->right;
                }
                leftRotate(nonno);
        }
        parent->color = BLACK;
        nonno->color = RED;
        return;
}

RBTree<H>* leftRotate(Node<H>* p){
        Node<H>* right = p->right;
        Node<H>* parent = p->parent;
        p->right = right->left;
        right->left = p;
        if(parent != NULL) {
                if(parent->right == p) {
                        parent->right = right;
                }
                else {
                        parent->left = right;
                }
        }
        else{
                root = right;
        }
        p->parent = right;
        right->parent = parent;
        return this;
}

RBTree<H>* rightRotate(Node<H>* p){
        Node<H>* left = p->left;
        Node<H>* parent = p->parent;
        p->left = left->right;
        left->right = p;
        if(parent != NULL) {
                if(parent->left == p) {
                        parent->left = left;
                }
                else {
                        parent->right = left;
                }
        }
        else{
                root = left;
        }
        p->parent = left;
        left->parent = parent;
        return this;
}

public:
RBTree() {
        root = NULL;
}

Node<H> *search(H key){
        Node<H> *tmp = root;
        while(tmp!=NULL && tmp->x!=key) {
                if(key>tmp->x)
                        tmp = tmp->right;
                else tmp = tmp->left;
        }
        return tmp;
}

RBTree<H> *insert(H key){
        insert_node(key);
        Node<H> *n = this->search(key);
        InsertFixup(n);
        return this;
}

void print(){
        cout << "PREORDER:" << endl;
        preorder_visit(this->root); cout << endl;
        cout << "POSTORDER:" << endl;
        postorder_visit(this->root); cout << endl;
        cout << "INORDER:" << endl;
        inorder_visit(this->root); cout << endl;
}
};

int main(){
        RBTree<int>* prova = new RBTree<int>();
        prova->insert(4)->insert(5)->insert(3)->insert(40)->print();
        return 0;
}
