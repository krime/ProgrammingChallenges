#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 103
/* 8*(s+2)+7*/

void print_line_1(int s, int n, char* buf, const char* sepr);
void print_line_2(int s, int n, char* buf, const char* sepr);
void print_line_3(int s, int n, char* buf, const char* sepr);
void print_stick_1(int s, int n, char* buf, const char* sepr);
void print_stick_2(int s, int n, char* buf, const char* sepr);

int main(int argv, char** argc) {
  int s=0, n=0, c=0, i=0;
  char buf1[MAX], buf2[MAX], buf3[MAX], buf4[MAX], buf5[MAX];
  int digit[8];
  
  while (scanf("%d %d", &s, &n) != EOF) {
    if (!s&&!n) break;
    memset(buf1, 0, MAX);
    memset(buf2, 0, MAX);
    memset(buf3, 0, MAX);
    memset(buf4, 0, MAX);
    memset(buf5, 0, MAX);
    memset(digit, 0, 8);
    c=0;
        
    do {
      digit[c++] = n%10;
      n /= 10;
    } while (n);
    
    for (i=c-1; i>=1; i--) {
      print_line_1(s, digit[i], buf1, " ");
      print_stick_1(s, digit[i], buf2, " ");
      print_line_2(s, digit[i], buf3, " ");
      print_stick_2(s, digit[i], buf4, " ");
      print_line_3(s, digit[i], buf5, " ");
    }
      print_line_1(s, digit[0], buf1, "");
      print_stick_1(s, digit[0], buf2, "");
      print_line_2(s, digit[0], buf3, "");
      print_stick_2(s, digit[0], buf4, "");
      print_line_3(s, digit[0], buf5, "");

    printf("%s\n", buf1);
    for (i=0; i<s; i++)
      printf("%s\n", buf2);
    printf("%s\n", buf3);
    for (i=0; i<s; i++)
      printf("%s\n", buf4);
    printf("%s\n", buf5);
    puts("");
  }
  return 0;
}

void print_line_1(int s, int n, char* buf, const char* sepr) {
  int i=0;
  const int len=s+2;
  char temp[len];
  memset(temp, 0, len);
  
  strcpy(temp, " ");
  switch(n) {
  case 1:
  case 4:
    for (i=0; i<s; i++) strcat(temp, " ");
    break;
  default:
    for (i=0; i<s; i++) strcat(temp, "-");
    break;
  }
  strcat(temp, " ");
  strcat(temp, sepr);
  strcat(buf, temp);
}

void print_line_2(int s, int n, char* buf, const char* sepr) {
  int i=0;
  const int len=s+2;
  char temp[len];
  memset(temp, 0, len);
  
  strcpy(temp, " ");
  switch(n) {
  case 1:
  case 7:
  case 0:
    for (i=0; i<s; i++) strcat(temp, " ");
    break;
  default:
    for (i=0; i<s; i++) strcat(temp, "-");
    break;
  }
  strcat(temp, " ");
  strcat(temp, sepr);
  strcat(buf, temp);
}

void print_line_3(int s, int n, char* buf, const char* sepr) {
  int i=0;
  const int len=s+2;
  char temp[len];
  memset(temp, 0, len);

  strcpy(temp, " ");
  switch(n) {
  case 1:
  case 4:
  case 7:
    for (i=0; i<s; i++) strcat(temp, " ");
    break;
  default:
    for (i=0; i<s; i++) strcat(temp, "-");
    break;
  }
  strcat(temp, " ");
  strcat(temp, sepr);
  strcat(buf, temp);
}

void print_stick_1(int s, int n, char* buf, const char* sepr) {
  int i=0;
  const int len=s+2;
  char temp[len];
  memset(temp, 0, len);
  
  switch(n) {
  case 1:
  case 2:
  case 3:
  case 7:
    strcat(temp, " ");
    for (i=0; i<s; i++) strcat(temp, " ");
    strcat(temp, "|");
    break;
  case 5:
  case 6:
    strcat(temp, "|");
    for (i=0; i<s; i++) strcat(temp, " ");
    strcat(temp, " ");
    break;
  default:
    strcat(temp, "|");
    for (i=0; i<s; i++) strcat(temp, " ");
    strcat(temp, "|");
    break;
  }
  strcat(temp, sepr);
  strcat(buf, temp);
}

void print_stick_2(int s, int n, char* buf, const char* sepr) {
  int i=0;
  const int len=s+2;
  char temp[len];
  memset(temp, 0, len);
  
  switch(n) {
  case 1:
  case 3:
  case 4:
  case 5:
  case 7:
  case 9:
    strcat(temp, " ");
    for (i=0; i<s; i++) strcat(temp, " ");
    strcat(temp, "|");
    break;
  case 2:
    strcat(temp, "|");
    for (i=0; i<s; i++) strcat(temp, " ");
    strcat(temp, " ");
    break;
  default:
    strcat(temp, "|");
    for (i=0; i<s; i++) strcat(temp, " ");
    strcat(temp, "|");
    break;
  }
  strcat(temp, sepr);
  strcat(buf, temp);
}
