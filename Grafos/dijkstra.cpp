#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define INF 1000000000
vector<pair<int,int>> g[MAXN];
int n,s,t;
int dijkstra(int source,int target){
    int dist[MAXN];
    for(int  i =0; i<MAXN; i++)
        dist[i]=INF;
    priority_queue<pair<int,int>> pq;
    dist[source]=0;
    pq.push({0.source});
    while(!pq.empty()){
        pair<int,int> act = pq.top();
        pq.pop();
        int u = act.second;
        int d = -act.first;
        if(d>dist[u])continue;
        for(int i =0; i<(int)g[u].size(); i++){
            int w = g[u][i].second;
            int v = g[u][i].first;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({-dist[v],v});
                //podemos recuperar el camino si en este paso. actulizamos un arreglo de padres
                //par[v]=u;
            }
        }
    }
    return dist[target];
}
int main(){
    int minn = dijkstra(s,t);
    return 0;
}