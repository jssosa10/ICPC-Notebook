package Algoritmos;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


public class Knapsack_TopBottom {

	//Maximo numero de elementos
	static int N;
	//Tamanho de la maleta
	static int S;

	static int DP [][];
	static List<Obj> elem;
	
	static class Obj{
		int tam;
		
		int val;
		
		public Obj(int pt, int pv) {
			tam = pt;
			val = pv;
		}
	}
	static int max(int a, int b) {
		return Math.max(a, b);
	}
	static void clearMat() {
		for(int j=0; j<=S; j++) {
			for(int i=0; i<=N; i++) {
				DP[i][j]=-1;
			}
		}
	}
		static int dp(int n,int s) {
			if(DP[n][s]!=-1) {
				return DP[n][s];
			}
			else if(n== 0 || s == 0) {
				return DP[n][s] =0;	
			}
			else {
				Obj o = elem.get(n-1);
				if(s<o.tam) {
					return DP[n][s] = dp(n-1,s);
				}
				else {
					int a = dp(n-1,s);
					int t = o.tam;
					int b = dp(n-1,s-t);
					int v = o.val;
					return DP[n][s] = max(a,b+v);
				}
			}
		}
	
	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String[] data = bf.readLine().split(" ");
		S = Integer.parseInt(data[0]);
		N = Integer.parseInt(data[1]);
		DP = new int[N+1][S+1];
		elem = new ArrayList<>(N);
		for(int i =0; i<N; i++) {
			data = bf.readLine().split(" ");
			Obj o = new Obj(Integer.parseInt(data[0]), Integer.parseInt(data[1]));
			elem.add(o);
		}
		clearMat();
		int rta = dp(N,S);
		System.out.println(rta);
		
		
	}
}
