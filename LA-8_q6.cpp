#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// Simple Max-Heap implementation using a vector
class MaxHeap {
    vector<int> a;
    void siftUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (a[p] < a[i]) {
                swap(a[p], a[i]);
                i = p;
            } else break;
        }
    }
    void siftDown(int i) {
        int n = (int)a.size();
        while (true) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int largest = i;
            if (l < n && a[l] > a[largest]) largest = l;
            if (r < n && a[r] > a[largest]) largest = r;
            if (largest == i) break;
            swap(a[i], a[largest]);
            i = largest;
        }
    }
public:
    MaxHeap() = default;
    MaxHeap(const vector<int>& vals) { for (int v : vals) push(v); }
    void push(int x) { a.push_back(x); siftUp((int)a.size() - 1); }
    void pop() {
        if (a.empty()) return;
        a[0] = a.back(); a.pop_back();
        if (!a.empty()) siftDown(0);
    }
    int top() const { return a.empty() ? INT_MIN : a[0]; }
    bool empty() const { return a.empty(); }
    int size() const { return (int)a.size(); }
};

// Simple Min-Heap implementation using a vector
class MinHeap {
    vector<int> a;
    void siftUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (a[p] > a[i]) {
                swap(a[p], a[i]);
                i = p;
            } else break;
        }
    }
    void siftDown(int i) {
        int n = (int)a.size();
        while (true) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int smallest = i;
            if (l < n && a[l] < a[smallest]) smallest = l;
            if (r < n && a[r] < a[smallest]) smallest = r;
            if (smallest == i) break;
            swap(a[i], a[smallest]);
            i = smallest;
        }
    }
public:
    MinHeap() = default;
    MinHeap(const vector<int>& vals) { for (int v : vals) push(v); }
    void push(int x) { a.push_back(x); siftUp((int)a.size() - 1); }
    void pop() {
        if (a.empty()) return;
        a[0] = a.back(); a.pop_back();
        if (!a.empty()) siftDown(0);
    }
    int top() const { return a.empty() ? INT_MAX : a[0]; }
    bool empty() const { return a.empty(); }
    int size() const { return (int)a.size(); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> vals;
    // If input provided: first integer is n followed by n values
    int n;
    if (cin >> n) {
        vals.resize(n);
        for (int i = 0; i < n; ++i) cin >> vals[i];
    } else {
        // No input: use a sample set
        vals = {5, 1, 3, 4, 2, 10, 7};
        cerr << "No input detected; using sample values.\n";
    }

    MaxHeap maxh;
    MinHeap minh;
    for (int v : vals) { maxh.push(v); minh.push(v); }

    cout << "Max-heap pop order: ";
    while (!maxh.empty()) { cout << maxh.top() << ' '; maxh.pop(); }
    cout << '\n';

    cout << "Min-heap pop order: ";
    while (!minh.empty()) { cout << minh.top() << ' '; minh.pop(); }
    cout << '\n';

    // Compare with STL priority_queue
    priority_queue<int> stlMax(vals.begin(), vals.end());
    priority_queue<int, vector<int>, greater<int>> stlMin(vals.begin(), vals.end());

    cout << "STL max priority_queue pop order: ";
    while (!stlMax.empty()) { cout << stlMax.top() << ' '; stlMax.pop(); }
    cout << '\n';

    cout << "STL min priority_queue pop order: ";
    while (!stlMin.empty()) { cout << stlMin.top() << ' '; stlMin.pop(); }
    cout << '\n';

    return 0;
}
