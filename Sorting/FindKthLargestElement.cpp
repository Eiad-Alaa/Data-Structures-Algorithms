#include <bits/stdc++.h>

#include "quick.cpp"

using namespace std;

int findKthLargestElement(vector<int>& v, int k) {
    int target = v.size() - k;
    int l = 0, r = v.size() - 1;

    int pivotIdx = 0;
    while (l <= r) {
        pivotIdx = partition(v, l, r);

        if (pivotIdx < target) {
            l = pivotIdx + 1;
        } else if (pivotIdx > target) {
            r = pivotIdx - 1;
        } else {
            break;
        }
    }

    return v[pivotIdx];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << findKthLargestElement(v, k) << endl;
}