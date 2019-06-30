#include <bits/stdc++.h>
using namespace std;

//Las contantes a continuación se usan para RMQ, no para suffix array
//MAXN maximo tamanho de string
#define MAXN 2000000
//El K debe ser tq K>=log2(MAX)+1;
#define K 25


int LOG[MAXN+1];
int st[MAXN][K];

vector<int> LCP;
vector<int> rev_P;

void init_sparse(){
    LOG[1] = 0;
    for (int i = 2; i <= MAXN; i++){
        LOG[i] = LOG[i/2] + 1;
    }

    memset(st,0,sizeof(st));
    int N = LCP.size();
    for (int i = 0; i < N; i++){
        st[i][0] = LCP[i];
    }

    for (int j = 1; j <= K; j++){
        for (int i = 0; i + (1 << j) <= N; i++){
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int i, int j){
    int L = min(rev_P[0], rev_P[i]), R = max(rev_P[0],rev_P[i])-1;
    int j = LOG[R - L + 1];
    return  min(st[L][j], st[R - (1 << j) + 1][j]);
}



vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
     vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

int main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> p =suffix_array_construction(s);
    LCP = lcp_construction(s, p);
    rev_P.resize(n-1);
    for(int i =0; i<n; i++){
        rev_P[p[i]]=i;
    }
    init_sparse();

    //Retorna el LCP de los sufijos que empiezan en i y j. query(i,j) = query(j,i)
    query(i,j);
}
