int x , y , d;

void extendedEuclid(int a , int b){
   if(b == 0) { x = 1 ; y = 0 ; d = a ; return; }
   extendedEuclid(b , a%b);

   int x1 = y;
   int y1 = x - (a/b)*y;
   x = x1;
   y = y1;
}

bool diophantine(int a , int b , int c){
	extendedEuclid(a , b);

	if(c%d != 0)
		return false;

	int m = c/d;
	x*=m;
	y*=m;

	//all equations k*(b/gcd , -a/gcd)
}