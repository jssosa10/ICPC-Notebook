#include <bits/stdc++.h>
using namespace std;
//funcion para calcular el prefix function de un string
//prefix("abcabcabc")={0,0,0,1,2,3,1,2,3}
vector<int> pi_function(string s){
	int n = (int)s.length();
	vector<int> pi(n);
	for(int i =1; i<n; i++){
		int j = pi[i-1];
		while(j>0&&s[i]!=s[j])
			j=pi[j-1];
		if(s[i]==s[j])
			j++;
		pi[i]=j;
	}
	return pi;
}

//Las entradas del atomata son (old_pi,c)->new_pi
void compute_automaton(string s, vector<vector<int>>& aut) {
    s += '#';
    int n = s.size();
    vector<int> pi = pi_function(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            int j = i;
            while (j > 0 && 'a' + c != s[j])
                j = pi[j-1];
            if ('a' + c == s[j])
                j++;
            aut[i][c] = j;
        }
    }
}

int main(){
	string p;
       	string t;
	cin>>t>>p;
	int len = (int)p.length();
	// hacer kmp es igual a halla la prefix function de p+"#"+s y calcular y un match es equivalente a pi[i]=len(p)
	string kmp = p+"#"+t;
	vector<int> pi = pi_function(kmp);
	for(int i = 0; i<(int)pi.size();i++)
		printf("%d ",pi[i]);
	int ans = 0;
	for(int i = len+1; i<(int)pi.size(); i++)
		if(pi[i]==len)
			ans++;
	printf("%d\n",ans);
        return 0;
}


