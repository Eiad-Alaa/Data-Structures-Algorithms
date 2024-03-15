#include <bits/stdc++.h>

#include "selection.cpp"
#include "insertion.cpp"
#include "merge.cpp"
#include "hybrid.cpp"
#include "quick.cpp"

#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

// Add new sorting types between START & END
enum SORT_TYPE {
    START,  // ignore

    MERGE,
    SELECTION,
    INSERTION,
    HYBRID,
    QUICK,
    HEAP,

    END     // ignore
};

string enum_to_str(SORT_TYPE type) {
    switch (type) {
        case MERGE:
            return "MERGE";
        case SELECTION:
            return "SELECTION";
        case INSERTION:
            return "INSERTION";
        case HYBRID:
            return "HYBRID";
        case QUICK:
            return "QUICK";
        case HEAP:
            return "HEAP";
        default:
            return "UNDEFINED";
    }
}

double measure(vector<int>& v, SORT_TYPE type) {
    chrono::high_resolution_clock::time_point start, end;
    
    switch (type) {
        case SELECTION:
            start = chrono::high_resolution_clock::now();
            selection_sort(v);
            end = chrono::high_resolution_clock::now();
            break;
        case INSERTION:
            start = chrono::high_resolution_clock::now();
            insertion_sort(v);
            end = chrono::high_resolution_clock::now();
            break;
        case MERGE:
            start = chrono::high_resolution_clock::now();
            merge_sort(v, 0, v.size() - 1);
            end = chrono::high_resolution_clock::now();
            break;
        case HYBRID:
            start = chrono::high_resolution_clock::now();
            hybrid_sort(v, 0, v.size() - 1, 30);
            end = chrono::high_resolution_clock::now();
            break;
        case QUICK:
            start = chrono::high_resolution_clock::now();
            quick_sort(v);
            end = chrono::high_resolution_clock::now();
            break;
        // case HEAP:
    }

    return chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
}

int main() {
    fast;
    freopen("input.txt", "r", stdin);

    for (int s = SORT_TYPE::START + 1; s < SORT_TYPE::END; s++) {
        SORT_TYPE type = static_cast<SORT_TYPE>(s);

        cout << enum_to_str(type) << " SORT:" << endl;

        int t;
        cin >> t;

        while (t--) {
            long long n;
            cin >> n;

            vector<int> v(n);

            for (int i = 0; i < n; i++) {
                cin >> v[i];
            }

            double time = measure(v, type);
            cout << "N: " << n << ", TIME TAKEN: " << time << " ms" << endl;
        }
        cout << endl;

        fseek(stdin, 0, SEEK_SET);      // return to the beginning of the input file
    }

    return 0;
}