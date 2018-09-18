#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN],t[4*MAXN];
void build(int v, int tl, int tr){
	if(tl==tr)
		t[v]=a[tl];
	else{
		int tm = (tl+tr)/2;
		build(v*2,tl,tm);
		build(v*2+1,tm+1,tr);
		//depende la operación a realizar.
		t[v]=t[v*2]+t[v*2+1];
	}
}
int get(int v, int tl, int tr, int l, int r){
	if(l>r)
		//retornar valor neutro de la opéración.
		return 0;
	if(tl==l&&tr==r)
		return t[v];		
	int tm = (tl+tr)/2;
	return get(v*2,tl,tm,l,min(r,tm))+get(v*2,tm+1,tr,max(tm+1,l),r);
		
}
void update(int v,int tl, int tr, int pos, int new_val){
	if(tl==tr)
		t[v]=new_val;
	else{
		int tm  = (tl+tr)/2;
		if(pos<=tm)
			update(v*2,tl,tm,pos,new_val);
		else
			update(v*2+1,tm+1,tr,pos,new_val);
		t[v]=t[v*2]+t[v*2+1];
	}
}
int main(){
	int n=100,val=0,pos=5,i=2,j=3;
	//leer arreglo
	//construir el segtree
	build(1,0,n-1);
	int res = get(1,0,n-1,i,j);
	update(1,0,n-1,pos,val);
	res = get(1,0,n-1,0,10);
	printf("%d\n",res);


}


