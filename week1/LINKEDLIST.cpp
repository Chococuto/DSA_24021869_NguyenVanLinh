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

// Chen dau
void insertFirst(LinkedList &L, int x) {
    Node *p = createNode(x);
    p->next = L.head;
    L.head = p;
}

// Chen cuoi
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

// Chen tai vi tri i
void insertAt(LinkedList &L, int x, int i) {
    if (i < 0) return;

    if (i == 0) {
        insertFirst(L, x);
        return;
    }

    Node *q = L.head;

    for (int j = 0; j < i - 1 && q != NULL; j++)
        q = q->next;

    if (q == NULL) return;

    Node *p = createNode(x);
    p->next = q->next;
    q->next = p;
}

// Truy cap
Node* get(LinkedList L, int i) {
    Node *p = L.head;

    for (int j = 0; j < i && p != NULL; j++)
        p = p->next;

    return p;
}

// Xoa dau
void deleteFirst(LinkedList &L) {
    if (L.head == NULL) return;

    Node *p = L.head;
    L.head = L.head->next;
    delete p;
}

// Xoa cuoi
void deleteLast(LinkedList &L) {
    if (L.head == NULL) return;

    if (L.head->next == NULL) {
        delete L.head;
        L.head = NULL;
        return;
    }

    Node *p = L.head;

    while (p->next->next != NULL)
        p = p->next;

    delete p->next;
    p->next = NULL;
}

// Xoa tai vi tri i
void deleteAt(LinkedList &L, int i) {
    if (i < 0 || L.head == NULL) return;

    if (i == 0) {
        deleteFirst(L);
        return;
    }

    Node *p = L.head;

    for (int j = 0; j < i - 1 && p != NULL; j++)
        p = p->next;

    if (p == NULL || p->next == NULL) return;

    Node *q = p->next;
    p->next = q->next;
    delete q;
}

// Duyet xuoi
void display(LinkedList L) {
    Node *p = L.head;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

// Duyet nguoc bang de quy
void reverse(Node *p) {
    if (p == NULL) return;

    reverse(p->next);
    cout << p->data << " ";
}

void displayReverse(LinkedList L) {
    reverse(L.head);
    cout << endl;
}

int main() {
    LinkedList L;
    init(L);

    insertLast(L, 10);
    insertLast(L, 20);
    insertLast(L, 30);
    insertFirst(L, 5);

    cout << "Danh sach: ";
    display(L);

    insertAt(L, 15, 2);
    cout << "Sau khi chen: ";
    display(L);

    Node *p = get(L, 2);
    if (p != NULL)
        cout << "Phan tu vi tri 2: " << p->data << endl;

    deleteFirst(L);
    cout << "Xoa dau: ";
    display(L);

    deleteLast(L);
    cout << "Xoa cuoi: ";
    display(L);

    deleteAt(L, 1);
    cout << "Xoa vi tri 1: ";
    display(L);

    cout << "Duyet nguoc: ";
    displayReverse(L);

    return 0;
}
