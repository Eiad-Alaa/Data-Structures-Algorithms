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