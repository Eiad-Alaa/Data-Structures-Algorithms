#include <bits/stdc++.h>
using namespace std;

#include "selection.cpp"
#include "insertion.cpp"
#include "merge.cpp"
#include "hybrid.cpp"

#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);




int main()
{
    fast;
    vector<int> x = {2,6,2,1,4,7,6,3,5,8,41,2};
    hybrid_sort(x,0,x.size()-1,9);
    for(auto i : x)
    cout<<i<<" ";
    return 0;
}

