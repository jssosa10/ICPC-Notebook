#include <bits/stdc++.h>
using namespace std;
#define MAXN 400
// podmeos guardar la matriz de adyacencia aparte como g[MAXN][MAXN] si no queremos dañar el grafo original.
int n,dist[MAXN][MAXN];
int main(){
    // FW dist[i][j] minima distancia del nodo i al nodo j.
    for(int k = 0; k<n; k++)
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
<<<<<<< HEAD
    return 0;
=======
>>>>>>> f662d64fcacd40fb95093e69328ad55b959b3660
}
