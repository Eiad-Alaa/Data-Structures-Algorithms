#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph;
vector<bool> taken;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

void process(int u){
    taken[u] = 1;

    for(auto &[v, w] : graph[u]){
        if(!taken[v])
            pq.push({w, {v, u}});
    }
}

int main(){

    int V, e;

    cout << "Enter number of Vertices: ";
    cin >> V;

    cout << "Enter number of Edges: ";
    cin >> e; 

    graph.assign(V, vector<pair<int,int>>());

    cout << "Enter source destination weight\n";

    for(int i = 0 ; i < e; i++){
        int u, v, w; cin >> u >> v >> w;

        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    
    cout << "Enter the source s: ";
    int s; cin >> s;

    taken.assign(V, 0);
    process(s);
    int cost = 0;
    int numTaken = 0;

    vector<pair<int, pair<int, int>>> MST(V);
    MST.clear();

    while(!pq.empty()){
        auto [w, inPair] = pq.top(); auto [u, v] = inPair;
        pq.pop();

        if(taken[u]) continue;
        
        MST.push_back({u, {v, w}});

        cost += w;
        numTaken++;

        process(u);
        if(numTaken == v-1) break; //for optimization
    }

    //dfs for printing the mst?
    cout << "Cost: " << cost << endl;

    cout << "The MST:" << endl;

    for(auto &[u, vw] : MST){
        auto [v, w] = vw;
        
        cout << "U: " << u << "    V: " << v << "    W: " << w << endl;
    }
    
    return 0;
}