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

    vector<int> dist(V, INT_MAX);
    dist[s] = 0;

    vector<int> parent(V, s);

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

        if(d > dist[u]) continue;

        for(auto &[v, w] : graph[u]){

            if(dist[u] + w >= dist[v]) continue;
            
            dist[v] = dist[u] + w;
            pq.emplace(dist[v], v);
            parent[v] = u;
        }
    }

    for(int u = 0 ; u < V ; u++){
        cout << "Source: " << s << "    Destination: " << u << "    Distance: " << dist[u];

        stack<int> shortestPath;
        shortestPath.push(u);
        int p = u;

        while(p != s){
            shortestPath.push(parent[p]);
            p = parent[p];
        }

        cout << "    Shortest Path: " <<shortestPath.top();
        shortestPath.pop();
        while(!shortestPath.empty()){
            cout << "-->" << shortestPath.top();
            shortestPath.pop(); 
        }
        cout << endl;
    }


    return 0;
}