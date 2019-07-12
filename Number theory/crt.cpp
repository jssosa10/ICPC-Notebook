int t;
int x , y , d; // variablas determinadas por extendedEuclid(a , b); d = gcd(a , b).
ll a[MAX] , n[MAX];

//guarda solución de ax + by = gcd(a , b) en las variables globales.
void extendedEuclid(int a , int b)

int main()
{
   cin >> t;
   for(int i = 0 ; i < t ; ++i)
      cin >> a[i] >> n[i];

   ll ca = a[0] , cn = n[0]; 
   for(int i = 1 ; i < t ; ++i){
      extendedEuclid(cn, n[i]);

      if((ca - a[i])%d != 0)
         return cout << "no solution\n" , 0;

      ca = ca + x*(a[i]-ca)/d*cn;
      cn = cn*n[i]/d;
   }

   cout << ca << " " << cn << '\n';

   return 0;
}
