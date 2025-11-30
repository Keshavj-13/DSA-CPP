#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> nums;
    int n;
    nums = {2,3,2,4,3,2};

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
