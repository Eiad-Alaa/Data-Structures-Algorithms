#include <bits/stdc++.h>

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

void quick_sort(vector<int>& v, int l, int r) {
    if (l >= r)     return;

    int pivotIdx = partition(v, l, r);

    quick_sort(v, l, pivotIdx - 1);
    quick_sort(v, pivotIdx + 1, r);
}

void quick_sort(vector<int>& v) {
    quick_sort(v, 0, v.size() - 1);
}