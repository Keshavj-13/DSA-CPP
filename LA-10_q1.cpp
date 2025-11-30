#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    vector<int> nums;
    nums = {1,2,3,1};
    int n;

    unordered_set<int> seen;
    bool dup = false;
    for (int x : nums) {
        if (seen.count(x)) { dup = true; break; }
        seen.insert(x);
    }

    cout << (dup ? "true" : "false") << '\n';
    return 0;
}
