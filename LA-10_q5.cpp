#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input format (optional): n values... pos
    // where pos is 0-based index of node to which tail connects (-1 for no cycle)
    int n;
    vector<int> vals;
    int pos = -1;
    if (cin >> n) {
        vals.resize(n);
        for (int i = 0; i < n; ++i) cin >> vals[i];
        if (!(cin >> pos)) pos = -1;
    } else {
        // sample: 1->2->3->4->2 (pos = 1)
        vals = {1,2,3,4}; pos = 1;
        cerr << "No input detected; using sample list 1->2->3->4 with tail connecting to index 1 (0-based).\n";
    }

    vector<Node*> nodes;
    for (int v : vals) nodes.push_back(new Node(v));
    for (size_t i = 0; i + 1 < nodes.size(); ++i) nodes[i]->next = nodes[i+1];
    if (pos >= 0 && pos < (int)nodes.size()) nodes.back()->next = nodes[pos];

    // detect cycle using unordered_set of pointers
    unordered_set<Node*> seen;
    Node* cur = nodes.empty() ? nullptr : nodes[0];
    bool hasCycle = false;
    while (cur) {
        if (seen.count(cur)) { hasCycle = true; break; }
        seen.insert(cur);
        cur = cur->next;
    }

    cout << (hasCycle ? "true" : "false") << '\n';

    // cleanup (avoid leaking if no cycle)
    if (!hasCycle) {
        for (Node* p : nodes) delete p;
    } else {
        // If cycle exists, avoid double-delete — just delete unique nodes tracked in set
        for (Node* p : seen) delete p;
    }
    return 0;
}
