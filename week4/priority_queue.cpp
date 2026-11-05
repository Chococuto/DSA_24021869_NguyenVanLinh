#include <iostream>
#include <algorithm>
using namespace std;

class PriorityQueue {
    int a[100]; // Mảng lưu các phần tử của Heap
    int n = 0;  // Số lượng phần tử hiện tại

    // Đẩy phần tử lên trên khi thêm mới (Push)
    void siftUp(int i) {
        while (i > 0 && a[(i - 1) / 2] < a[i]) {
            swap(a[(i - 1) / 2], a[i]);
            i = (i - 1) / 2;
        }
    }

    // Kéo phần tử xuống dưới khi lấy ra (Pop)
    void siftDown(int i) {
        while (2 * i + 1 < n) {
            int largest = i;
            int left = 2 * i + 1, right = 2 * i + 2;

            if (left < n && a[left] > a[largest]) largest = left;
            if (right < n && a[right] > a[largest]) largest = right;

            if (largest == i) break;
            swap(a[i], a[largest]);
            i = largest;
        }
    }

public:
    // Thêm phần tử vào hàng đợi
    void push(int x) {
        a[n] = x;
        siftUp(n);
        n++;
    }

    // Xem phần tử lớn nhất (ưu tiên nhất) ở đỉnh
    int top() {
        return a[0];
    }

    // Xóa phần tử lớn nhất khỏi hàng đợi
    void pop() {
        a[0] = a[n - 1]; // Đưa phần tử cuối lên đỉnh
        n--;
        if (n > 0) siftDown(0); // Vá lại đống
    }

    // Kiểm tra hàng đợi có rỗng không
    bool isEmpty() {
        return n == 0;
    }
};

int main() {
    PriorityQueue pq;

    // Thêm các phần tử vào
    int values[] = {30, 10, 50, 20, 40};
    for (int x : values) {
        pq.push(x);
    }

    cout << "Lay ra theo thu tu uu tien (tu lon den be):\n";
    while (!pq.isEmpty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
