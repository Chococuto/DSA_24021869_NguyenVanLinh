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

// Duyet xuoi
void display(List L) {
    for (int i = 0; i < L.n; i++)
        cout << L.a[i] << " ";
    cout << endl;
}

// Duyet nguoc
void displayReverse(List L) {
    for (int i = L.n - 1; i >= 0; i--)
        cout << L.a[i] << " ";
    cout << endl;
}

// Truy cap phan tu tai vi tri i
int get(List L, int i) {
    if (i < 0 || i >= L.n) {
        cout << "Vi tri khong hop le!\n";
        return -1;
    }
    return L.a[i];
}

// Chen dau
void insertFirst(List &L, int x) {
    if (L.n == MAX) return;

    for (int i = L.n; i > 0; i--)
        L.a[i] = L.a[i - 1];

    L.a[0] = x;
    L.n++;
}

// Chen cuoi
void insertLast(List &L, int x) {
    if (L.n == MAX) return;

    L.a[L.n] = x;
    L.n++;
}

// Chen tai vi tri i
void insertAt(List &L, int x, int i) {
    if (L.n == MAX || i < 0 || i > L.n) return;

    for (int j = L.n; j > i; j--)
        L.a[j] = L.a[j - 1];

    L.a[i] = x;
    L.n++;
}

// Xoa dau
void deleteFirst(List &L) {
    if (L.n == 0) return;

    for (int i = 0; i < L.n - 1; i++)
        L.a[i] = L.a[i + 1];

    L.n--;
}

// Xoa cuoi
void deleteLast(List &L) {
    if (L.n == 0) return;

    L.n--;
}

// Xoa tai vi tri i
void deleteAt(List &L, int i) {
    if (i < 0 || i >= L.n) return;

    for (int j = i; j < L.n - 1; j++)
        L.a[j] = L.a[j + 1];

    L.n--;
}

int main() {
    List L;
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

    cout << "Phan tu tai vi tri 2: " << get(L, 2) << endl;

    deleteFirst(L);
    cout << "Sau khi xoa dau: ";
    display(L);

    deleteLast(L);
    cout << "Sau khi xoa cuoi: ";
    display(L);

    deleteAt(L, 1);
    cout << "Sau khi xoa vi tri 1: ";
    display(L);

    cout << "Duyet nguoc: ";
    displayReverse(L);

    return 0;
}
