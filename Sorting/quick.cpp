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

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     int n;
//     cout << "Enter N: ";
//     cin >> n;

//     vector<int> v(n);
//     for (int i = 0; i < n; i++) {
//         cin >> v[i];
//     }

//     quick_sort(v);

//     cout << "AFTER SORTING: ";
//     for (int i = 0; i < n; i++) {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }