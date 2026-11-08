#include <iostream>
using namespace std;

template <typename Key, typename Value>
class LinkedListST {
private:
    struct Node {
        Key key;
        Value val;
        Node* next;
        Node(Key k, Value v, Node* n) : key(k), val(v), next(n) {}
    };
    Node* head = nullptr;

public:
    ~LinkedListST() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Tìm kiếm: O(N)
    Value* get(Key key) {
        for (Node* x = head; x != nullptr; x = x->next) {
            if (x->key == key) return &(x->val);
        }
        return nullptr; // Không tìm thấy
    }

    // Thêm hoặc cập nhật: O(N)
    void put(Key key, Value val) {
        for (Node* x = head; x != nullptr; x = x->next) {
            if (x->key == key) {
                x->val = val; // Đã tồn tại -> cập nhật value
                return;
            }
        }
        head = new Node(key, val, head); // Chưa có -> chèn vào đầu danh sách
    }

    // Xóa: O(N)
    void remove(Key key) {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr != nullptr) {
            if (curr->key == key) {
                if (prev == nullptr) head = curr->next;
                else prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};
