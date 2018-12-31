package Algoritmos;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/**
 * Este algoritmos mira si un patron aparece ne otro string y die cuantas veces lo hace
 * @author HP
 *
 */
public class Rabin_Karp {
	/**
	 * 
	 * @param s el string que se recibe
	 * @param t el patron a buscar
	 * @return 
	 */
	static List<Integer> rabin_karp(char[] S, char[] P){
		long prime  = 31;
		long m = 1000000009;
		int s = S.length, p = P.length;
		long [] potencias = new long[Math.max(s, p)];
		long hashT=0, cur_h;
		long [] hashS = new long [s+1];
		List<Integer> ocurrencias = new ArrayList<>();
		potencias[0] = 1;
		for(int i =1; i<potencias.length; i++) {
			potencias[i] = (potencias[i-1]*prime)%m;
		}
		hashS[0] = 0;
		for(int i = 0; i<s; i++) {
			hashS[i+1] = (hashS[i]+(S[i]-'a'+1)*potencias[i])%m;
		}
		for(int i =0; i<p; i++) {
			hashT =(hashT+(P[i]-'a'+1)*potencias[i])%m;
		}
		for(int i=0;i<s-p+1; i++) {
			cur_h = (hashS[i+p] + m - hashS[i]) % m;
			if (cur_h == hashT * potencias[i] % m) {
				ocurrencias.add(i);
			}
		}
		return ocurrencias;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String s,p;
		s = bf.readLine();
		p = bf.readLine();
		List<Integer> rta = rabin_karp(s.toCharArray(), p.toCharArray());
		System.out.println(rta.size());
	}
}
