#include <bits/stdc++.h>

using namespace std;



//retorna un arreglo con 3 elementos x,y,gcd(a,b) tq ax+by = gcd(a,b)

int* ExtendedEuclides(int a, int b){

    int r0,r1,r2;

    int s0,s1,s2;

    int t0,t1,t2;

    int q;

    r0 = a; r1 = b;

    s0 = 1; s1 =0;

    t0 = 0; t1 = 1;

    do{

        q = r0/r1;

        r2 = r0-(q*r1);

        s2 = s0-(q*s1);

        t2 = t0-(q*t1);


        
r0 = r1; s0 = s1; t0 = t1;

        r1 = r2; s1 = s2; t1 = t2;

    }while(r2!=0);

    int  rta[3];

    rta[0] = r0;

    rta[1] = s0;

    rta[2] = t0;

    return &rta[0];

}



int main(){

    int a, b;

    int * rta;

    while(scanf("%d %d", &a, &b)!=EOF){

        rta = ExtendedEuclides(a,b);

        printf("%d %d %d\n",rta[0],rta[1],rta[2]);

    }

}