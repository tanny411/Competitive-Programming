#include <stdio.h>
#include <algorithm>
using namespace std;
#define maxL (500>>5)+1
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5] |= 1<<(x&31))
int main() {
		// xor gauss
		int row = Pt, col = n, arb = 0;
		for(int r = 0, c = 0; r < row && c < col; c++) {
			int k = r;
			for(int j = r + 1; j < row; j++)
				if(f[j][c])	k = j;
			for(int j = 0; j < col; j++)
				swap(f[r][j], f[k][j]);

			if(f[r][c] == 0) {arb++;continue;}

			for(int j = 0; j < row; j++) {
				if(r == j)	continue;
				if(f[j][c]) {
					for(int k = col; k >= c; k--)
						f[j][k] = f[j][k] ^ f[r][k];
				}
			}
			r++;
		}
	return 0;
}

