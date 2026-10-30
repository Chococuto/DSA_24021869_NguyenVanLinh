#include <iostream>
using namespace std;

struct Node {
    int k;
    char v;
    Node *l = nullptr, *r = nullptr;
};

Node* findMax(Node* t) {
    while (t && t->r) t = t->r;
    return t;
}

void insert(Node*& t, int k, char v) {
    if (!t) t = new Node{k, v};
    else if (k < t->k) insert(t->l, k, v);
    else insert(t->r, k, v);
}

void removeMax(Node*& t) {
    if (!t) return;
    if (!t->r) {
        Node* d = t;
        t = t->l;
        delete d;
    } else removeMax(t->r);
}

void preorder(Node* t) {
    if (!t) return;
    cout << "(" << t->k << "," << t->v << ") ";
    preorder(t->l);
    preorder(t->r);
}

int main() {
    Node* root = nullptr;
    insert(root, 7, 'D');
    insert(root, 3, 'B');
    insert(root, 9, 'C');
    insert(root, 2, 'F');
    insert(root, 5, 'A');
    insert(root, 8, 'E');

    Node* m = findMax(root);
    if (m) cout << m->k << "," << m->v << "\n";

    insert(root, 4, 'G');
    preorder(root);
    cout << "\n";

    removeMax(root);
    preorder(root);
    return 0;
}
