#include <cstdio>
#include <cstdlib>
#include <cstring>

void surround(int mr, int mc, int row, int col, int* mine);

int main(int argc, char** argv) {
	int row, col;
	int i=0,j=0,k=0,l=0;
	int coord[10000][2];
	int mine[10000];
	
	char c;
	while (scanf("%d %d", &row, &col) != EOF) {
		while (getchar()!='\n') continue;
		if (!row&&!col) break;
		memset(mine, 0, 10000);
		memset(coord, 0, 20000);
		l = 0;

		for (i=0; i<row; i++) {
			for (j=0; j<col; j++) {
				c = getchar();
				if (c=='.') mine[i*col+j]=0;
				else if (c=='*') {
					mine[i*col+j]='*'-'0';
					coord[l][0]=i;
					coord[l][1]=j;
					l++;
				}
			}
			while (getchar()!='\n') continue;
		}
		if (k>0) puts("");
		printf("Field #%d:\n", ++k);

		for (i=0; i<l; i++) {
			surround(coord[i][0], coord[i][1], row, col, mine);
		}

		for (i=0; i<row; i++) {
			for (j=0; j<col; j++)
				putchar(mine[i*col+j]+'0');
			puts("");
		}
	}
	return 0;
}

/* **... */
/* ..... */
/* .*... */

void surround(int mr, int mc, int row, int col, int* mine) {
	if (mr>0) {
		if (mc>0 && mine[(mr-1)*col+mc-1] != '*'-'0')
			mine[(mr-1)*col+mc-1] ++;
		if (mine[(mr-1)*col+mc] != '*'-'0')
			mine[(mr-1)*col+mc] ++;
		if (mc<col-1 && mine[(mr-1)*col+mc+1] != '*'-'0')
				mine[(mr-1)*col+mc+1] ++;
	}
	if (mr<row-1) {
		if (mc>0 && mine[(mr+1)*col+mc-1] != '*'-'0')
			mine[(mr+1)*col+mc-1] ++;
		if (mine[(mr+1)*col+mc] != '*'-'0')
			mine[(mr+1)*col+mc] ++;
		if (mc<col-1 && mine[(mr+1)*col+mc+1] != '*'-'0')
			mine[(mr+1)*col+mc+1] ++;
	}
	if (mc>0 && mine[mr*col+mc-1] != '*'-'0')
		mine[mr*col+mc-1] ++;
	if (mc<col-1 && mine[mr*col+mc+1] != '*'-'0')
		mine[mr*col+mc+1] ++;
}
