#include <vector>
#include <cstdlib>
#include <chrono>
#include <iostream>

using namespace std;

int partition(vector<int>& v, int l, int r) {
    int pivotIdx = rand() % (r - l + 1) + l;

    swap(v[l], v[pivotIdx]);
    pivotIdx = l;

    int saveIdx = pivotIdx + 1;

    for (int i = pivotIdx + 1; i <= r; i++) {
        if (v[i] <= v[pivotIdx]) {
            swap(v[i], v[saveIdx++]);
        }
    }

    swap(v[pivotIdx], v[saveIdx - 1]);
    pivotIdx = saveIdx - 1;

    return pivotIdx;
}

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