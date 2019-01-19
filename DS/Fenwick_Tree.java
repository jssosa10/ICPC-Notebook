public class Fenwick_Tree {

	int[] bit;  // binary indexed tree
	int n;

	void init(int pn) {
		n = pn;
		bit = new int[n];
	}
	int sum(int r) {
		int ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			ret += bit[r];
		return ret;
	}
	void add(int idx, int delta) {
		for (; idx < n; idx = idx | (idx + 1)) {
			bit[idx] += delta;
		}
	}
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
	void init(int[] a) {
		init(a.length);
		for (int i = 0; i < a.length; i++)
			add(i, a[i]);
	}
}

