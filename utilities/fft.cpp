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

