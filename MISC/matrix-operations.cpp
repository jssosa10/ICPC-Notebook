#include <bits/stdc++.h>
using namespace std;
#define N 2
#define M 1000000009
//estructura de una matriz.
struct matrix {
	long long m[N][N];
	matrix(){ memset(m,0,sizeof(m));}
	matrix operator *(matrix b){
		matrix c = matrix();
		for (int i = 0; i < N; ++i)
			for (int k = 0; k < N; ++k)
			    for (int j = 0; j < N; ++j)
				c.m[i][j] = (((c.m[i][j]%M) +((m[i][k]%M) * (b.m[k][j]%M))) % M);
	    	return c;
	}

};
// funcion para la matriz identidad
matrix unit(){
	matrix c = matrix();
	for(int i = 0;i<N; i++)
		c.m[i][i]=1;
	return c;
}
// fast matrix MOD pow
matrix modPow(matrix m,int n){
  if ( n == 0 )
    return unit(); // the unit matrix - that is 1 for principal diagonal , otherwise 0
  matrix half = modPow(m,n/2);
  matrix out = half * half;
  if ( n % 2 )
    out = out * m;
  return out; 
}
int main(){
	matrix fib=matrix();
	matrix bs = matrix();
	fib.m[0][1]=1;
	fib.m[1][0]=1;
	fib.m[1][1]=1;
	bs.m[0][0]=1;
	bs.m[0][1]=1;
	fib = modPow(fib,48);
	fib = bs*fib;
	printf("%lld\n",fib.m[0][1]);
        return 0;
}


