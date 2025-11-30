#include <iostream>
#include <vector>
#include <unordered_map>

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
        nums = {4,5,1,2,0,4};
        cerr << "No input detected; using sample [4,5,1,2,0,4].\n";
    }

    unordered_map<int,int> freq;
    for (int x : nums) freq[x]++;
    int ans = INT_MIN;
    bool found = false;
    for (int x : nums) {
        if (freq[x] == 1) { ans = x; found = true; break; }
    }

    if (found) cout << ans << '\n';
    else cout << "No non-repeating element found" << '\n';
    return 0;
}
