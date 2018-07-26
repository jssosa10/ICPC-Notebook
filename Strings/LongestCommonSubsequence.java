package Algoritmos;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class LongestCommonSubsequence {

	static int L[][];
	static char X[];
	static char Y[];
	//Halla la longitd de la subsecuencia comun más larga
	static int max(int a, int b) {
		return Math.max(a, b);
	}
	static int lcs1(String s1, String s2) {
		X = s1.toCharArray();
		Y = s2.toCharArray();
		int m = X.length, n = Y.length;
		L = new int[m+1][n+1];
		
		/*
		 * Se llena la matriz L. L[i][j] = lcs(X[0...i-1],Y[0...j-1])
		 */
		for(int i=0; i<=m; i++) {
			for(int j =0; j<=n; j++) {
				if(j==0 || i==0) {
					L[i][j] = 0;
				}
				else if (X[i-1]==Y[j-1]) {
					L[i][j] = L[i-1][j-1]+1;
				}
				else {
					L[i][j] = max(L[i-1][j],L[i][j-1]);
				}
			}
		}
		return L[m][n];
	}
	//Reconstruye la subsecuencia comun más larga
	static String lcs2(String s1, String s2) {
		int index = lcs1(s1,s2);
		System.out.println(index);
		char [] rta = new char[index];
		int i =X.length,  j = Y.length;
		while(i>0 && j>0 && index>0) {
			if(X[i-1]==Y[j-1]) {
				
				rta[index-1] = X[i-1];
				i--; j--; index--;
			}
			else if(L[i-1][j]>L[i][j-1]) {
				i--;
			}
			else {
				j--;
			}
		}
		return new String(rta);
		
	}
	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String s1 = bf.readLine();
		String s2 = bf.readLine();
		String lcs = lcs2(s1,s2);
		System.out.println(lcs);
	}
}
