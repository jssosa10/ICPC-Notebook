#include <bits/stdc++.h>
using namespace std;

#define A 26
#define pb push_back

struct node{
    int hijos[A];
    int indice;
    node(){
        indice = -1;
        memset(hijos, -1, sizeof(hijos));
    }
};

vector<node> trie = {node()};

int ti(char c){
    return c-'a';
}

void add(string s, int ind){
    int n = s.size();
    int v = 0;
    for(int i = n-1; i>= 0; i--){
        if( trie[v].hijos[ti(s[i])]==-1){
            trie[v].hijos[ti(s[i])]=trie.size();
            trie.pb(node());
        }
        v =  trie[v].hijos[ti(s[i])];
    }
    trie[v].indice =ind;
}

int main(){
    cout<<"holi";
}
