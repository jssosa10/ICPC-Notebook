#include <bits/stdc++.h>

using namespace std;


//definir según problema

const int N_MAX = 10005;

const int S_MAX = 10005;


int DP[N_MAX+1][S_MAX+1];


struct Obj{

    int tam;

    int val;

}elem[N_MAX];



int dp(int n, int s){

    if(DP[n][s]!=-1){

        return DP[n][s];

    }

    else if(n == 0 || s == 0){

       return DP[n][s]=0;

    }

    else{

         Obj o = elem[n-1];

         if(s-o.tam<0){

             return DP[n][s] = dp(n-1,s);

         }

         else{

             return DP[n][s] = max(dp(n-1,s),dp(n-1,s-o.tam)+o.val);

         }

    }

}



int main(){

    int N,S,rta;

    scanf("%d %d", &S, &N);

    for(int i = 0; i<N; i++){

        Obj o;

        scanf("%d %d", &o.tam, &o.val );

        elem[i] =o;

    }

    memset(DP,-1,sizeof(DP));

    rta = dp(N,S);

    printf("%d",rta);

    return 0;

}
