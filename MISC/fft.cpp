#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int,int> pii;
typedef pair<int,bool> pib;

#define cd  complex<double>


const double PI = acos(-1);
cd mI (0,-1);

vector<pii> cambios;
map<pib, cd > raices;


void bit_reverse(int n){

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j){
            cambios.pb({i,j});
        }

    }

}

void calc_r(int n){

    for(int len = 2; len<=n; len<<=1){
        double ang = 2*PI/len;
        cd wlen1(cos(ang), sin(ang));
        raices[{len, false}]=wlen1;
        wlen1.imag(wlen1.imag()*-1.0);
        raices[{len,true}]=wlen1;
    }
}

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for(pii p: cambios){
        swap(a[p.first], a[p.second]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        //double ang = 2 * PI / len * (invert ? -1 : 1);

        cd wlen = raices[{len,invert}];
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    bit_reverse(n);
    calc_r(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

//vector que retorna las posiciones donde hace match el patron p en el string s
//ambos son vectores de letras minusculas. Se debe cambiar el metodo de multiply para que los vectores
//de entrada sean de cd. p puede tener wildcards, corresponde al char en WC.
vector<int> find_pattern(string s, string p){
    int n,m;
    n = s.size(), m = p.size();
    vector<cd > a(n);
    vector<cd > b(m);

    double alpha=0;
    bool k;
    int wcs =0;
    for(int i =0; i<n; i++){
        alpha = (2.0*PI*(s[i]-'a'))/26.0;
        cd w (cos(alpha),sin(alpha));
        a[i]= w;
    }

    for(int i =0; i<m; i++){
        if(p[m-i-1]==WC){
            k=0;
            wcs++;
        }
        else{
            k=1;
        }
        alpha = (2.0*PI*(p[m-i-1]-'a'))/26.0;
        cd w (cos(alpha)*k,-sin(alpha)*k);
        b[i]= w;
    }
    vector<double> c = multiply(a,b);
    vector<int> rta;
    wcs = m-wcs;
    for(int i =m-1;  i<n; i++){
        double x = c[i];
        double diff = x-wcs;
        if(abs(diff)<EPS){
            rta.pb(i-(m-1)+1);
        }

    }
    return rta;
}



