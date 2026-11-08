#include <iostream>
using namespace std;

template <typename Key, typename Value>
class ArrayST {
private:
    Key* keys;
    Value* vals;
    int n = 0;
    int capacity;

public:
    ArrayST(int cap = 1000) : capacity(cap) {
        keys = new Key[capacity];
        vals = new Value[capacity];
    }

    ~ArrayST() {
        delete[] keys;
        delete[] vals;
    }

    // Binary Search: Trả về vị trí của key (hoặc số phần tử nhỏ hơn key) - O(log N)
    int rank(Key key) {
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (key < keys[mid]) hi = mid - 1;
            else if (key > keys[mid]) lo = mid + 1;
            else return mid;
        }
        return lo;
    }

    // Tìm kiếm: O(log N)
    Value* get(Key key) {
        if (n == 0) return nullptr;
        int i = rank(key);
        if (i < n && keys[i] == key) return &vals[i];
        return nullptr;
    }

    // Thêm hoặc cập nhật: O(N)
    void put(Key key, Value val) {
        int i = rank(key);
        if (i < n && keys[i] == key) {
            vals[i] = val; // Đã tồn tại -> cập nhật value
            return;
        }
        // Dịch các phần tử phía sau sang phải 1 ô để chèn
        for (int j = n; j > i; j--) {
            keys[j] = keys[j - 1];
            vals[j] = vals[j - 1];
        }
        keys[i] = key;
        vals[i] = val;
        n++;
    }

    // Xóa: O(N)
    void remove(Key key) {
        if (n == 0) return;
        int i = rank(key);
        if (i == n || keys[i] != key) return; // Không có key trong bảng
        // Dịch các phần tử phía sau sang trái 1 ô
        for (int j = i; j < n - 1; j++) {
            keys[j] = keys[j + 1];
            vals[j] = vals[j + 1];
        }
        n--;
    }
};
