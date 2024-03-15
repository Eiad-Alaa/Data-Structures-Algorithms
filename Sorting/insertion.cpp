#include <bits/stdc++.h>
using namespace std;


void insertion_sort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++) 
    {
        int j = i;
        while (v[j] < v[j - 1] && j > 0)
        {
            swap(v[j], v[j - 1]);
            j--;
        }
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

//     insertion_sort(v);

//     cout << "AFTER SORTING: ";
//     for (int i = 0; i < n; i++) {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }