#include <iostream>
using namespace std;


template <typename T>
struct nodo {
    T valor;
    nodo<T>* next;
    nodo(T v, nodo<T> *n = NULL) {
        valor = v;
        next = n;
    }
};


template <typename T>
struct cola {
    nodo<T>* head;
    nodo<T>* tail;
    cola();
    void push(T);
    bool pop(T&);
};

int main()
{
    std::cout << "Cola\n";

    cola<int> C;

    C.push(10);
    C.push(10);
    C.push(10);
    C.push(10);

    int x;

    for (int i=0; i < 10; i++) {
        C.pop(x);
        cout << x;
    }
}


template<typename T>
cola<T>::cola() {
    tail = NULL;
    head = tail;
}

template<typename T>
void cola<T>::push(T v) {

    if (!tail) {
        tail = new nodo<T>(v, tail);
    }
    else {
        tail->next = new nodo<T>(v, tail->next);
        tail = tail->next;
    }
    
    if (!head) {
        head = tail;
    }

}

template<typename T>
bool cola<T>::pop(T &v) {
    if (!head) {
        cout << "Vacio\n";
        v = -1;
        return false;
    }
    else {
        nodo <T> * tmp = head;
        v = head->valor;
        head = head->next;
        delete tmp;
        return true;
    }
}
