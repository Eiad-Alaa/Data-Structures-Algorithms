#include <bits/stdc++.h>

#include "merge.cpp"

using namespace std;

void insertion_hybrid_sort(vector<int> &v, int lo, int hi)
{
    for (int i = lo + 1; i <= hi; i++)
    {
        int j = i;
        while (v[j] < v[j - 1] && j > lo)
        {
            swap(v[j], v[j - 1]);
            j--;
        }
    }
}

void hybrid_sort(vector<int> &v, int lo, int hi, int k)
{
    int mid = lo + (hi - lo) / 2;

    int left_size, right_size;
    left_size = mid - lo + 1;
    right_size = hi - mid;
    
    if (left_size > k)
        merge_sort(v, lo, mid);
    else
        insertion_hybrid_sort(v, lo, mid);

    if (right_size > k)
        merge_sort(v, mid + 1, hi);
    else
        insertion_hybrid_sort(v, mid + 1, hi);

    merge(v, lo, hi);
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

//     hybrid_sort(v, 0, v.size() - 1, 30);

//     cout << "AFTER SORTING: ";
//     for (int i = 0; i < n; i++) {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }