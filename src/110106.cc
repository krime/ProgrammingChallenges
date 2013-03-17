#include <cstdio>
#include <cstdlib>
#include <cstring>

#define RAM 1000
#define REG 10

int reg[REG], ram[RAM];
int amount=0;

void record();

int main(int argc, char** argv) {
  int i=0;
  char ins[4];

  memset(reg, 0, sizeof(reg));
  memset(ram, 0, sizeof(ram));

  scanf("%d", &amount);
  while (getchar() != '\n') continue;
  while (getchar() != '\n') continue;

  while (amount) {
    memset(ins, 0, sizeof(ins));
    ins[0]=getchar();
    if (ins[0]=='\n') {
      record();
      i=0;
      memset(reg, 0, sizeof(reg));
      memset(ram, 0, sizeof(ram));
      continue;
    }
    if (ins[0]=='\r') continue;
    if (ins[0]==EOF) {
      record();
      break;
    }
    
    ins[1]=getchar();
    ins[2]=getchar();
    ins[3]='\0';
    
    while (getchar()!='\n') continue;
    ram[i++]=atoi(ins);
  }
  return 0;
}

void record() {
  int j=0, rt=0, a=0, b=0;
  
  while (1) {
    if (ram[j]==100) {
      rt ++;
      break;
    }

    a=ram[j]/10%10;
    b=ram[j]%10;
    
    switch (ram[j]/100) {
    case 2:reg[a] = b;break;
    case 3:reg[a] += b;reg[a] %= 1000;break;
    case 4:reg[a] *= b;reg[a] %= 1000;break;
    case 5:reg[a] = reg[b];break;
    case 6:reg[a] += reg[b];reg[a] %= 1000;break;
    case 7:reg[a] *= reg[b];reg[a] %= 1000;break;
    case 8:reg[a] = ram[reg[b]];break;
    case 9:ram[reg[b]] = reg[a];break;
    case 0:if (reg[b]) j=reg[a]-1;break;
    }
    rt++;
    j++;
  }
  printf("%d\n", rt);
  amount --;
  if (amount) puts("");
}
