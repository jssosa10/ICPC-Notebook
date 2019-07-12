int n;
bool prime[MAX];

//Si x es primo prime[x] = true
void sieve(){
	memset(prime , 1 , sizeof(prime));
	for(int i = 4 ; i <= n ; i += 2)
      prime[i] = false;

	for(int i = 3 ; i*i <= n ; i += 2)
      if(prime[i])
         for(int j = i*i ; j <= n ; j += i)
            prime[j] = false;
}