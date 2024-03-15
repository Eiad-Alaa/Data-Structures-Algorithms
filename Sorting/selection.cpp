#include <bits/stdc++.h>
using namespace std;



void selection_sort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int mn_idx = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[mn_idx])
            {
                mn_idx = j;
            }
        }
        if (i != mn_idx)
            swap(v[i], v[mn_idx]);
    }
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

//     selection_sort(v);

//     cout << "AFTER SORTING: ";
//     for (int i = 0; i < n; i++) {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }