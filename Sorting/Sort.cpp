#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void insertion_sort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++) 
    {
        int j = i;
        while (v[j] < v[j - 1] && j > 0)
        {
            // cout<<v[j]<<" ";
            swap(v[j], v[j - 1]);
            j--;
        }
    }
    // cout<<"\n";
}

void insertion_hybrid_sort(vector<int> &v, int lo, int hi)
{
    for (int i = lo + 1; i <= hi; i++)
    {
        int j = i;
        while (v[j] < v[j - 1] && j > 0)
        {
            swap(v[j], v[j - 1]);
            j--;
        }
    }
}

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

void merge(vector<int> &v, int lo, int hi)
{
    int mid = lo + (hi - lo) / 2;
    vector<int> right, left;
    for (int i = lo; i <= mid; i++)
    {
        left.pb(v[i]);
    }
    for (int i = mid + 1; i <= hi; i++)
    {
        right.pb(v[i]);
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

int main()
{
    fast;
    vector<int> x = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    hybrid_sort(x, 0, x.size() - 1, 4);
    for (auto i : x)
        cout << i << " ";
    return 0;
}
