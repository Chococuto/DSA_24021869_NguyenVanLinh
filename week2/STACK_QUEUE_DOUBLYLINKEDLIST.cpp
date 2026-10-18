#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

struct DoublyList {
    Node *head;
    Node *tail;
};

void init(DoublyList &L) {
    L.head = NULL;
    L.tail = NULL;
}

Node* createNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void insertLast(DoublyList &L, int x) {
    Node *p = createNode(x);
    if (L.tail == NULL) {
        L.head = L.tail = p;
        return;
    }
    p->prev = L.tail;
    L.tail->next = p;
    L.tail = p;
}

void deleteFirst(DoublyList &L) {
    if (L.head == NULL) return;
    Node *p = L.head;
    if (L.head == L.tail) {
        L.head = L.tail = NULL;
    } else {
        L.head = L.head->next;
        L.head->prev = NULL;
    }
    delete p;
}

void deleteLast(DoublyList &L) {
    if (L.tail == NULL) return;
    Node *p = L.tail;
    if (L.head == L.tail) {
        L.head = L.tail = NULL;
    } else {
        L.tail = L.tail->prev;
        L.tail->next = NULL;
    }
    delete p;
}

void display(DoublyList L) {
    Node *p = L.head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void clear(DoublyList &L) {
    while (L.head != NULL)
        deleteFirst(L);
}

//  STACK (LIFO) 
struct Stack {
    DoublyList L;
};

void init(Stack &S) {
    init(S.L);
}

void push(Stack &S, int x) {
    insertLast(S.L, x);
}

bool pop(Stack &S, int &x) {
    if (S.L.tail == NULL) return false;
    x = S.L.tail->data;
    deleteLast(S.L);
    return true;
}

bool top(Stack S, int &x) {
    if (S.L.tail == NULL) return false;
    x = S.L.tail->data;
    return true;
}

void display(Stack S) {
    display(S.L);
}

// QUEUE (FIFO)
struct Queue {
    DoublyList L;
};

void init(Queue &Q) {
    init(Q.L);
}

void enqueue(Queue &Q, int x) {
    insertLast(Q.L, x);
}

bool dequeue(Queue &Q, int &x) {
    if (Q.L.head == NULL) return false;
    x = Q.L.head->data;
    deleteFirst(Q.L);
    return true;
}

bool front(Queue Q, int &x) {
    if (Q.L.head == NULL) return false;
    x = Q.L.head->data;
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

    cout << "=== STACK BANG DOUBLYLINKEDLIST ===\n";
    push(S, 10);
    push(S, 20);
    push(S, 30);
    cout << "Stack: "; display(S);
    if (top(S, x)) cout << "Top: " << x << endl;
    if (pop(S, x)) cout << "Pop: " << x << endl;
    cout << "Stack sau pop: "; display(S);

    cout << "\n=== QUEUE BANG DOUBLYLINKEDLIST ===\n";
    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    cout << "Queue: "; display(Q);
    if (front(Q, x)) cout << "Front: " << x << endl;
    if (dequeue(Q, x)) cout << "Dequeue: " << x << endl;
    cout << "Queue sau dequeue: "; display(Q);

    clear(S.L);
    clear(Q.L);
    return 0;
}
