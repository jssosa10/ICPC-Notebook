#include <bits/stdc++.h>
using namespace std;

#define MAX 1010

int par[MAX];

int findRoot(int x){
	return par[x] < 0 ? x : (par[x] = findRoot(par[x]));
}

void merge(int a , int b){
	a = findRoot(a);
	b = findRoot(b);
	if(a == b) return;
	if(par[b] < par[a]) swap(a, b);

	par[a] += par[b];
	par[b] = a;
}

bool sameSet(int a , int b){
   return findRoot(a)==findRoot(b);
}

int main(){
	memset(par , -1 , sizeof(par));

}
