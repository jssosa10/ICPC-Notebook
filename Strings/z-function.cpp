#include <bits/stdc++.h>
using namespace std;
//funcion para calcular la z function de un string
vector<int> z_function(string s){
	int n = (int) s.length();
	vector<int> z(n);
	for(int i=1,l=0,r=0; i<n; i++){
		if(i<=r)
			z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]])
			++z[i];
		if(i+z[i]-1>r)
			l=i,r=i+z[i]-1;
	}
	return z;
}
int main(){
	string s("abcabcabc");
	vector<int> z = z_function(s);
	//z == {0,0,0,6,0,0,3,0,0}
	for(int i = 0; i<(int)z.size(); i++)
		printf("%d ",z[i]);
        return 0;
}


