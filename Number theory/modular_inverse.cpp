#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
typedef long long ll;
//Usando exponenciación binaria

ll expo(ll b, ll e){
    ll rta = 1;
    while(e){
        if(e&1){
            rta*=b;
            rta%=MOD;
        }
        b = (b*b)%MOD;
        e>>=1;
    }
    return rta;
}
ll inv(ll a){
    //si mos no es primo es fi(MOD)-1;
    return expo(a,MOD-2);
}

//Precalcula todos los inversos en un rango

ll inversos[MOD];

void calc(){
    enversos[1]=1;
    for(int i = 2; i<MOD; i++){
        inversos[i] =   (MOD-(MOD/i)*inversos[MOD%i]%MOD)%MOD;
    }
}


