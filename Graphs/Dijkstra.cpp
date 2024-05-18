#include<bits/stdc++.h>
using namespace std;



int main(){

    int V, e, s;

    cout << "Enter number of Vertices: ";
    cin >> V;

    cout << "Enter number of Edges: ";
    cin >> e; 
    
    cout << "Enter the source vertex: ";
    cin >> s;

    vector<int> shortestPath(V, INT_MAX);
    shortestPath[s] = 0;

    vector<vector<pair<int,int>>> graph(V);
    graph.clear();

    cout << "Enter source destination weight\n";

    for(int i = 0 ; i < e; i++){
        int u, v, w; cin >> u >> v >> w;

        graph[u].emplace_back(v, w);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, s);

    while(!pq.empty()){

        auto [d, u] = pq.top(); pq.pop();

        if(d > shortestPath[u]) continue;

        for(auto &[v, w] : graph[u]){
            if(shortestPath[u] + w >= shortestPath[v]) continue;
            shortestPath[v] = shortestPath[u] + w;
            pq.emplace(shortestPath[v], v);
        }
    }

    for(int u = 0 ; u < V ; u++){
        cout << "Source: " << s << "    Destination: " << u << "    Distance: " << shortestPath[u] << endl;
    }


    return 0;
}