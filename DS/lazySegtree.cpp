#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
const int MAXN = 1e5+5;
int a[MAXN],t[4*MAXN],lazy[4*MAXN];
//funcion para construir el segtree
void build(int v,int tl,int tr){
	memset(lazy,0,sizeof(lazy));
	if(tl==tr)
		t[v]=a[tl];
	else{
		int tm = (tl+tr)/2;
		build(v*2,tl,tm);
		build(v*2+1,tm+1,tr);
		t[v]=max(t[v*2],t[v*2+1]);

	}

}
//funcion para propagar el valor a los hijos del nodo.
void push(int v){
	t[v*2]=lazy[v];
	lazy[v*2]=lazy[v];
	t[v*2+1]=lazy[v];
	lazy[v*2+1]=lazy[v];
	lazy[v]=0;
}
//funcion para hacer update de un rango con un valor dado.
void update(int v,int tl, int tr, int l, int r,int val){
	if(l>r)
		return;
	if(l==tl&&tr==r){
		t[v]=val;
		lazy[v]=val;
	}
	else{
		//solo es necesario propagar el valor si existe un valor lazy guardado.
		if(lazy[v]!=0)
			push(v);
		int tm=(tl+tr)/2;
		update(v*2,tl,tm,l,min(tm,r),val);
		update(v*2+1,tm+1,tr,max(l,tm+1),r,val);
		t[v]=max(t[v*2],t[v*2+1]);
	}
}
//funcion para realizar range query.
int query(int v, int tl, int tr, int l, int r){
	if(l>r)
		return -INF;
	if(tl==l&&tr==r){
		return t[v];

	}
	if(lazy[v]!=0)
		push(v);
	int tm = (tl+tr)/2;
	return max(query(v*2,tl,tm,l,min(r,tm)),query(v*2+1,tm+1,tr,max(tm+1,l),r));
}
int n,m,i,j;
int main(){
	while(scanf("%d%d",&n,&m)==2&&n+m){
		for(int i = 0; i<n; i++){
			a[i]=i;
		}
		build(1,0,n-1);
		printf("%d\n",query(1,0,n-1,0,n-1));
		update(1,0,n-1,n/2,n-1,0);
		printf("%d\n",query(1,0,n-1,0,n-1));
	}
        return 0;
}


