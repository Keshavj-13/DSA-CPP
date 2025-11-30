#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

int main() {
    int n;
    vector<int> vals;
    vals = {1,2,3,4,-1,2};
    n = (int)vals.size();

    if (n == 0) { cout << "No Duplicates" << '\n'; return 0; }

    vector<TreeNode*> nodes(n, nullptr);
    for (int i = 0; i < n; ++i) {
        if (vals[i] != -1) nodes[i] = new TreeNode(vals[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (!nodes[i]) continue;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n) nodes[i]->left = nodes[l];
        if (r < n) nodes[i]->right = nodes[r];
    }

    TreeNode* root = nodes[0];
    unordered_set<int> seen;
    bool dup = false;
    // BFS traversal and check duplicates
    queue<TreeNode*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        TreeNode* u = q.front(); q.pop();
        if (!u) continue;
        if (seen.count(u->val)) { dup = true; break; }
        seen.insert(u->val);
        if (u->left) q.push(u->left);
        if (u->right) q.push(u->right);
    }

    if (dup) cout << "Duplicates Found" << '\n';
    else cout << "No Duplicates" << '\n';

    // cleanup allocated nodes
    for (TreeNode* p : nodes) if (p) delete p;
    return 0;
}
