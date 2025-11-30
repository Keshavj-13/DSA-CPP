#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

int main() {
    vector<int> A, B;
    int n, m;
    A = {1,2,3,4};
    B = {3,4,5,6};

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
