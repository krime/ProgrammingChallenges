#include <cstdio>
#include <cstdlib>
#include <cstring>

#define check(ST1, ST2, X, Y)   \
  for (i=1; ST1; i++) {         \
    ch=board[X][Y];             \
    if (ch=='.') continue;      \
    else if (ST2) return 1+cap; \
    else break;                 \
  }
  
int testCheck(char board[8][9], int x, int y, int cap) {
  int i=0, j=0;
  int dx=0, dy=0;
  int cl=cap*('A'-'a');
  char k=board[x][y];
  char ch=0;
  int knj[8][2]={{ 1, 2},{ 2, 1},{ 2,-1},{ 1,-2},
                 {-1,-2},{-2,-1},{-2, 1},{-1, 2}};

  // Check of Knight
  for (i=0; i<8; i++) {
    dx=x-knj[i][0];
    dy=y-knj[i][1];
    if (dx<0||dx>7||dy<0||dy>7) continue;
    ch=board[dx][dy];
    if (ch=='n'+cl) return 1+cap;
    else continue;
  }
#define Check_Rook ch=='r'+cl||ch=='q'+cl
  check(i<=x, Check_Rook, x-i, y);
  check(i<8-x, Check_Rook, x+i, y);
  check(i<=y, Check_Rook, x, y-i);
  check(i<8-y, Check_Rook, x, y+i);
#define Check_Bishop ch==('b'+cl)||ch==('q'+cl)
  check(i<=x&&i<=y, Check_Bishop||(i==1&&ch=='p'&&!cap), x-i, y-i);
  check(i<8-x&&i<8-y, Check_Bishop||(i==1&&ch=='P'&&cap), x+i, y+i);
  check(i<=x&&i<8-y, Check_Bishop||(i==1&&ch=='p'&&!cap), x-i, y+i);
  check(i<8-x&&i<=y, Check_Bishop||(i==1&&ch=='P'&&cap), x+i, y-i);
  
  return 0;
}

int main(int argc, char** argv) {
  char board[8][9];
  char rl[9];
  int i=0, j=0, x=0, y=0, unfin=1, check=0;
  int counter=0;
  const char* king[3]={"no", "white", "black"};
  char ch;

  do {
    counter++;
    memset(board, 0, sizeof (board));
    memset(rl, 0, sizeof (rl));
    unfin=0;
    check=0;
    
    for (i=0; i<8; i++) {
      scanf("%s", rl);
      rl[8]='\0';
      strcpy(board[i], rl);
    }
    
    for (i=0; i<8; i++) {
      for (j=0; j<8; j++) {
        if (board[i][j]!='.') {
          unfin=1;
          if (board[i][j]=='k') {check=testCheck(board, i, j, 1);if (check) break;}
          if (board[i][j]=='K') {check=testCheck(board, i, j, 0);if (check) break;}
        }
      }
      if (check) break;
    }
    if (unfin) printf("Game #%d: %s king is in check.\n", counter, king[check]);
  } while (unfin);
  return 0;
}
