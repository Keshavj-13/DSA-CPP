#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> A, B;
    int n, m;
    if (cin >> n >> m) {
        A.resize(n); B.resize(m);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < m; ++i) cin >> B[i];
    } else {
        A = {1,2,3,4};
        B = {3,4,5,6};
        cerr << "No input detected; using sample A=[1,2,3,4], B=[3,4,5,6].\n";
    }

    unordered_set<int> s(A.begin(), A.end());
    set<int> common; // ordered, unique
    for (int x : B) if (s.count(x)) common.insert(x);

    bool first = true;
    for (auto it = common.begin(); it != common.end(); ++it) {
        if (!first) cout << ", ";
        cout << *it;
        first = false;
    }
    cout << '\n';
    return 0;
}
