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
