#include <bits/stdc++.h>
using namespace std;
#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)
#define C(p0, r) P(p0), double r
#define PP(pp) pair<point,point> &pp
#define EPS 1e-9
#define MAXN 200005
// se puede definir un punto como un numero complejo
typedef complex<double> point;
// dot product a.x*b.x+a.y*b.y
double dot(P(a), P(b)) { return real(conj(a) * b); }
// cross product a.x*b.y-b.x*a.y
double cross(P(a), P(b)) { return imag(conj(a) * b); }
double cross(P(a),P(b),P(c)){ return cross(b-a,c-a);}
double ccw(P(a), P(b), P(c)) { return cross(b - a, c - b); }
point hull[MAXN];
//convex hull
bool cmp(const point &a, const point &b) {
  return abs(real(a) - real(b)) > EPS ?
    real(a) < real(b) : imag(a) < imag(b); }
int convex_hull(vector<point> p) {
  int n = (int)p.size();
  sort(p.begin(), p.end(), cmp);
  int h = -1;
  for(int i = 0; i<n; i++){
        while(h>=1&&cross(hull[h-1],hull[h],p[i])<=0)--h;
        hull[++h]=p[i];
  }
  int th = h;
  for(int i = n-2; i>=0; i--){
        while(h>th&&cross(hull[h-1],hull[h],p[i])<=0)--h;
        hull[++h]=p[i];
  }
  return h;
}
double dist(point a, point b){return sqrt(dot(b-a,b-a));}
//distancia de el punto p al segmento formado por(a,b)
double dist2(point p,point a, point b){
        point v1 = b-a, v2 = p-a;
        return fabs(cross(v1,v2))/dist(a,b);
}

int main(){
	vector<point>v;
	int h = convex_hull(v);
	int q = 1;
	double ans= 1e10;
	//rotating calipers O(n)
	for(int i = 0; i<h; i++){
		while(cross(hull[i],hull[(i+1)%h],hull[(q+1)%h])>cross(hull[i],hull[(i+1)%h],hull[q]))
			q = (q+1)%h;	
		ans = min(ans,dist2(hull[q],hull[i],hull[(i+1)%h]));

	}
	printf("%lf\n",ans);
	return 0;
}


