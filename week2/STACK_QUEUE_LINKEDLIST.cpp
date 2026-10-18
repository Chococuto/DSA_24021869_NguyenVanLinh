#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct LinkedList {
    Node *head;
};

void init(LinkedList &L) {
    L.head = NULL;
}

Node* createNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void insertFirst(LinkedList &L, int x) {
    Node *p = createNode(x);
    p->next = L.head;
    L.head = p;
}

void insertLast(LinkedList &L, int x) {
    Node *p = createNode(x);
    if (L.head == NULL) {
        L.head = p;
        return;
    }
    Node *q = L.head;
    while (q->next != NULL)
        q = q->next;
    q->next = p;
}

void deleteFirst(LinkedList &L) {
    if (L.head == NULL) return;
    Node *p = L.head;
    L.head = L.head->next;
    delete p;
}

void display(LinkedList L) {
    Node *p = L.head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void clear(LinkedList &L) {
    while (L.head != NULL)
        deleteFirst(L);
}

// STACK (LIFO)
struct Stack {
    LinkedList L;
};

void init(Stack &S) {
    init(S.L);
}

void push(Stack &S, int x) {
    insertFirst(S.L, x);
}

bool pop(Stack &S, int &x) {
    if (S.L.head == NULL) return false;
    x = S.L.head->data;
    deleteFirst(S.L);
    return true;
}

bool top(Stack S, int &x) {
    if (S.L.head == NULL) return false;
    x = S.L.head->data;
    return true;
}

void display(Stack S) {
    display(S.L);
}

// QUEUE (FIFO)
struct Queue {
    LinkedList L;
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

    cout << "=== STACK BANG LINKEDLIST ===\n";
    push(S, 10);
    push(S, 20);
    push(S, 30);
    cout << "Stack: "; display(S);
    if (top(S, x)) cout << "Top: " << x << endl;
    if (pop(S, x)) cout << "Pop: " << x << endl;
    cout << "Stack sau pop: "; display(S);

    cout << "\n=== QUEUE BANG LINKEDLIST ===\n";
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
