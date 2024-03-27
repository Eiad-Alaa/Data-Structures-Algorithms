){
    fast;

    int n; 
    cout << "Enter N: ";
    cin >> n;

    vector<int> A(n);

    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
    }

    heapSort(A);

    cout << "AFTER SORTING: ";
    for(auto a : A){
        cout << a << " ";
    }
}