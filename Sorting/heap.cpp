#include <bits/stdc++.h>
using namespace std;

void max_heapify(vector<int> &A, int i, int n)
{
    int firstChild = i * 2 + 1;
    int secondChild = i * 2 + 2;
    int mx = i;

    if (firstChild < n && A[mx] < A[firstChild])
        mx = firstChild;

    if (secondChild < n && A[mx] < A[secondChild])
        mx = secondChild;

    if (i != mx)
    {
        swap(A[i], A[mx]);
        max_heapify(A, mx, n);
    }
}

void build_max_heap(vector<int> &A, int n){
    for(int i = n/2 - 1; i >= 0 ; i--){
        max_heapify(A, i, n);
    }
}

void heapSort(vector<int> &A){
    build_max_heap(A, A.size());

    for(int i = A.size() - 1 ; i >= 0 ; i--){
        swap(A[0], A[i]);
        max_heapify(A, 0, i);
    }
}

#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int main(){
    fast;

    int n; cin >> n;

    vector<int> A(n);

    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
    }

    heapSort(A);

    for(auto a : A){
        cout << a << " ";
    }
}
