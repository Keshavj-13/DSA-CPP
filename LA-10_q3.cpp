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
        nums = {2,3,2,4,3,2};
        cerr << "No input detected; using sample [2,3,2,4,3,2].\n";
    }

    unordered_map<int,int> freq;
    vector<int> order;
    for (int x : nums) {
        if (!freq.count(x)) order.push_back(x);
        freq[x]++;
    }

    for (int x : order) {
        cout << x << " -> " << freq[x] << (freq[x] == 1 ? " time" : " times") << '\n';
    }
    return 0;
}
