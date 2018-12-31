package Algoritmos;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class PiFunction {
	static int max (int a, int b) {
		return Math.max(a, b);
	}

	static int [] prefix_function(char[] s) {
	    int n = s.length,j;
	    int pi[] = new int[n];
	    pi[0] = 0;
	    for (int i = 1; i < n; i++) {
	        j = pi[i-1];
	        while (j > 0 && s[i] != s[j])
	            j = pi[j-1];
	        if (s[i] == s[j])
	            j++;
	        pi[i] = j;
	    }
	    return pi;
	}
	/**
	 * Calcula la función prefijo hasta 
	 * @param s
	 * @param n
	 * @return
	 */
	static int [] prefix_function(char[] s, int n) {
	    int j;
	    int pi[] = new int[n];
	    pi[0] = 0;
	    for (int i = 1; i < n; i++) {
	        j = pi[i-1];
	        while (j > 0 && s[i] != s[j])
	            j = pi[j-1];
	        if (s[i] == s[j])
	            j++;
	        pi[i] = j;
	    }
	    return pi;
	}
	static List<Integer> kmp(String s, String p){
		String S = p+"#"+s;
		int[] pi = prefix_function(S.toCharArray());
		int m = p.length();
		List<Integer> rta = new ArrayList<>();
		for(int i =0; i<pi.length; i++) {
			if(pi[i]==m) {
				rta.add(i-2*m);
			}
		}
		return rta;
	}
	/**
	 * calcula cuantas veces aparece com substring cada prefijo de s
	 * @param s
	 * @return
	 */
	static int[] prefix_occurrences (String s) {
		int n = s.length();
		int[] ans = new int[n+1];
		int []pi = prefix_function(s.toCharArray());
		for (int i = 0; i < n; i++) {
		    ans[pi[i]]++;
		}
		for (int i = n-1; i > 0; i--) {
		    ans[pi[i-1]] += ans[i];
		}
		for (int i = 0; i <= n; i++) {
		    ans[i]++;
		}
		return ans;
	}
	
	/**
	 * Cuantas veces parace cada prefijo de t como substring de s
	 * @param s
	 * @return
	 */
	static int[] prefix_occurrences (String s, String t) {
		String S = t+"#"+s;
		int n = S.length();
		int[] ans = new int[n+1];
		int []pi = prefix_function(S.toCharArray());
		int m = t.length();
		for (int i = m+1; i < n; i++) {
			
		    ans[pi[i]]++;
		}
		for (int i = n-1; i >=m+1; i--) {
		    ans[pi[i-1]] += ans[i];
		}
		for (int i = m+1; i <= n; i++) {
		    ans[i]++;
		}
		return ans;
	}
	
	static int num_substrings(String s) {
		char[] cs = s.toCharArray();
		char[] cst = new char[cs.length];
		int pi[];
		int rta = 1,maxi;
		for(int i=1; i<cs.length; i++) {
			for(int j =0; j<=i; j++) {
				cst[j] = cs[i-j];
			}
			pi = prefix_function(cst, i+1);
			maxi =0;
			for(int j =0; j<=i; j++) {
				maxi = max(maxi, pi[j]);
			}
			rta+=i+1-maxi;
		}
		return rta;
	}
	/**
	 * Halla el menor String tal que al concatenarlo consigomismo varias veces resulta en s
	 * @param s
	 * @return
	 */
	static String string_compresing(String s) {
		int [] pi = prefix_function(s.toCharArray());
		int n = pi.length,k = n-pi[n-1];
		if(n%k==0) {
			return s.substring(0,k);
		}
		return s;
	}
	public static void main(String[] args) throws Exception{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String s = bf.readLine();
		//String p = bf.readLine();
		//List<Integer> rta = kmp(s,p);
		//for(Integer i:rta) {
		//	System.out.println(i);
		//}
		System.out.println(string_compresing(s));


	}
}
