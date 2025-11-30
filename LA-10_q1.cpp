#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums;
    int n;
    if (cin >> n) {
        nums.resize(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];
    } else {
        // Sample: nums = [1,2,3,1]
        nums = {1,2,3,1};
        cerr << "No input detected; using sample [1,2,3,1].\n";
    }

    unordered_set<int> seen;
    bool dup = false;
    for (int x : nums) {
        if (seen.count(x)) { dup = true; break; }
        seen.insert(x);
    }

    cout << (dup ? "true" : "false") << '\n';
    return 0;
}
