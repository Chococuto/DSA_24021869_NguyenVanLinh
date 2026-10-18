#include <iostream>
using namespace std;

#define MAX 100

struct List {
    int a[MAX];
    int n;
};

void init(List &L) {
    L.n = 0;
}

void insertLast(List &L, int x) {
    if (L.n == MAX) return;
    L.a[L.n] = x;
    L.n++;
}

void deleteLast(List &L) {
    if (L.n == 0) return;
    L.n--;
}

void deleteFirst(List &L) {
    if (L.n == 0) return;
    for (int i = 0; i < L.n - 1; i++)
        L.a[i] = L.a[i + 1];
    L.n--;
}

void display(List L) {
    for (int i = 0; i < L.n; i++)
        cout << L.a[i] << " ";
    cout << endl;
}

//  STACK (LIFO) 
struct Stack {
    List L;
};

void init(Stack &S) {
    init(S.L);
}

bool push(Stack &S, int x) {
    if (S.L.n == MAX) return false;
    insertLast(S.L, x);
    return true;
}

bool pop(Stack &S, int &x) {
    if (S.L.n == 0) return false;
    x = S.L.a[S.L.n - 1];
    deleteLast(S.L);
    return true;
}

bool top(Stack S, int &x) {
    if (S.L.n == 0) return false;
    x = S.L.a[S.L.n - 1];
    return true;
}

void display(Stack S) {
    display(S.L);
}

//  QUEUE (FIFO) 
struct Queue {
    List L;
};

void init(Queue &Q) {
    init(Q.L);
}

bool enqueue(Queue &Q, int x) {
    if (Q.L.n == MAX) return false;
    insertLast(Q.L, x);
    return true;
}

bool dequeue(Queue &Q, int &x) {
    if (Q.L.n == 0) return false;
    x = Q.L.a[0];
    deleteFirst(Q.L);
    return true;
}

bool front(Queue Q, int &x) {
    if (Q.L.n == 0) return false;
    x = Q.L.a[0];
    return true;
}

void display(Queue Q) {
    display(Q.L);
}

int main() {
    Stack S;
    Queue Q;
    init(S);
    init(Q);
    int x;

    cout << "=== STACK BANG LIST ===\n";
    push(S, 10);
    push(S, 20);
    push(S, 30);
    cout << "Stack: "; display(S);
    if (top(S, x)) cout << "Top: " << x << endl;
    if (pop(S, x)) cout << "Pop: " << x << endl;
    cout << "Stack sau pop: "; display(S);

    cout << "\n=== QUEUE BANG LIST ===\n";
    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    cout << "Queue: "; display(Q);
    if (front(Q, x)) cout << "Front: " << x << endl;
    if (dequeue(Q, x)) cout << "Dequeue: " << x << endl;
    cout << "Queue sau dequeue: "; display(Q);

    return 0;
}
