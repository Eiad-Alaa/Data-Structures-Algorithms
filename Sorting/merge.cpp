#include <bits/stdc++.h>
using namespace std;


void merge(vector<int> &v, int lo, int hi)
{
    int mid = lo + (hi - lo) / 2;
    vector<int> right, left;
    for (int i = lo; i <= mid; i++)
    {
        left.push_back(v[i]);
    }
    for (int i = mid + 1; i <= hi; i++)
    {
        right.push_back(v[i]);
    }
    int r, l, sorted_idx;
    r = l = 0;
    sorted_idx = lo;
    while (l < left.size() && r < right.size())
    {
        if (left[l] <= right[r])
        {
            v[sorted_idx] = left[l];
            l++;
        }
        else
        {
            v[sorted_idx] = right[r];
            r++;
        }
        sorted_idx++;
    }
    while (l < left.size())
    {
        v[sorted_idx] = left[l];
        l++;
        sorted_idx++;
    }
    while (r < right.size())
    {
        v[sorted_idx] = right[r];
        r++;
        sorted_idx++;
    }
    right.clear();
    left.clear();
}

void merge_sort(vector<int> &v, int lo, int hi)
{
    if (lo >= hi)
        return;
    int mid = lo + (hi - lo) / 2;
    merge_sort(v, lo, mid);
    merge_sort(v, mid + 1, hi);
    merge(v, lo, hi);
}