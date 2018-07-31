#include <bits/stdc++.h>

using namespace std;

//Ajusar según problema

const int N_MAX = 100000;

const int S_MAX = 100000;

int N,S;
int DP [S_MAX+1];

struct Obj{

    int tam;

    int val;

}elem[N_MAX];


void dp(){

    Obj o;

    int t,v;

    for(int i=0; i<N; i++){

        for(int j=S; j>0; j--){

            o = elem[i];

            t = o.tam;

            v = o.val;

            if(j-t>=0){

                DP[j] = max(DP[j],DP[j-t]+v);
   
            }

        }

    }

}

int main(){

    scanf("%d %d", &S, &N);

    for(int i=0; i<N; i++){

        Obj o;

        scanf("%d %d", &o.tam, &o.val);

        elem[i]=o;

    }

    memset(DP, 0, sizeof(DP));

    dp();

    printf("%d", DP[S]);

}