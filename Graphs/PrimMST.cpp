#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph;
vector<bool> taken;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void process(int u){
    taken[u] = 1;

    for(auto &[v, w] : graph[u]){
        if(!taken[v]) 
            pq.emplace(w, v);
    }
}

int main(){

    int v, e;

    cout << "Enter number of Vertices: ";
    cin >> v;

    cout << "Enter number of Edges: ";
    cin >> e; 

    graph.assign(v, vector<pair<int,int>>());

    cout << "Enter source destination weight\n";

    for(int i = 0 ; i < e; i++){
        int u, v, w; cin >> u >> v >> w;

        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    
    cout << "Enter the source s: ";
    int s; cin >> s;

    taken.assign(v, 0);
    process(s);
    int cost = 0;
    int numTaken = 0;

    // vector<vector<pair<int, int>>> MST(v);

    while(!pq.empty()){
        auto [w, u] = pq.top(); pq.pop();
        
        if(taken[u]) continue;
        
        // MST[u].emplace_back(v, w);

        cost += w;
        numTaken++;

        process(u);
        if(numTaken == v-1) break; //for optimization
    }

    //dfs for printing the mst?
    cout << "Cost: " << cost << endl;

    return 0;
}