package Algoritmos;


import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Knapsack_BottonTop {

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
	static void dp() {
		Obj o;
		int t,v;
		for(int j=0; j<=S; j++) {
			for(int i =0; i<=N; i++) {
				if(j== 0 || i==0) {
					DP[i][j]=0;
				}
				else {
					o = elem.get(i-1);
					t = o.tam; v = o.val;
					if(t>j) {
						DP[i][j] = DP[i-1][j];
					}
					else {
						DP[i][j] = max(DP[i-1][j], DP[i-1][j-t]+v);
					}
					
				}
				
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
		dp();
		int rta = DP[N][S];
		System.out.println(rta);
		
		
	}
}
