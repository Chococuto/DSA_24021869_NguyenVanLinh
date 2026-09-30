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

// Chen dau
void insertFirst(DoublyList &L, int x) {
    Node *p = createNode(x);

    if (L.head == NULL) {
        L.head = L.tail = p;
        return;
    }

    p->next = L.head;
    L.head->prev = p;
    L.head = p;
}

// Chen cuoi
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

// Truy cap
Node* get(DoublyList L, int i) {
    Node *p = L.head;

    for (int j = 0; j < i && p != NULL; j++)
        p = p->next;

    return p;
}

// Chen tai vi tri i
void insertAt(DoublyList &L, int x, int i) {
    if (i < 0) return;

    if (i == 0) {
        insertFirst(L, x);
        return;
    }

    Node *q = get(L, i);

    // Neu i nam ngay sau phan tu cuoi
    if (q == NULL) {
        Node *p = L.head;
        int count = 0;

        while (p != NULL) {
            count++;
            p = p->next;
        }

        if (i == count)
            insertLast(L, x);

        return;
    }

    Node *p = createNode(x);

    p->prev = q->prev;
    p->next = q;

    q->prev->next = p;
    q->prev = p;
}

// Xoa dau
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

// Xoa cuoi
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

// Xoa tai vi tri i
void deleteAt(DoublyList &L, int i) {
    Node *p = get(L, i);

    if (p == NULL) return;

    if (p == L.head) {
        deleteFirst(L);
        return;
    }

    if (p == L.tail) {
        deleteLast(L);
        return;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;

    delete p;
}

// Duyet xuoi
void display(DoublyList L) {
    Node *p = L.head;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

// Duyet nguoc
void displayReverse(DoublyList L) {
    Node *p = L.tail;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->prev;
    }

    cout << endl;
}

int main() {
    DoublyList L;
    init(L);

    insertLast(L, 10);
    insertLast(L, 20);
    insertLast(L, 30);
    insertFirst(L, 5);

    cout << "Danh sach: ";
    display(L);

    insertAt(L, 15, 2);
    cout << "Sau khi chen 15 vao vi tri 2: ";
    display(L);
Node *p = get(L, 2);

    if (p != NULL)
        cout << "Phan tu vi tri 2: " << p->data << endl;

    deleteFirst(L);
    cout << "Sau khi xoa dau: ";
    display(L);

    deleteLast(L);
    cout << "Sau khi xoa cuoi: ";
    display(L);

    deleteAt(L, 1);
    cout << "Sau khi xoa vi tri 1: ";
    display(L);

    cout << "Duyet xuoi: ";
    display(L);

    cout << "Duyet nguoc: ";
    displayReverse(L);

    return 0;
}
