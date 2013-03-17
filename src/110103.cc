#include <cstdio>
#include <cstdlib>

#define N 1000

int comp(const void *a, const void *b);

int main(int argc, char** argv) {
	int stu[N];   /* Each expense of each student */
  int stu_1, stu_2;
	int st=0;   	/* Total Students               */
	int sum=0;    /* Total Expense                */
	int avg1=0;   /* Average Expense              */
	int avg2=0;   /* Average Expense              */
	int i=0;      /* Counter                      */
	int topExp=0; /* Over expense                 */
	int exch1=0;  /* Total avg1                   */
  int exch2=0;

	while (scanf("%d", &st) != EOF) {
		if (!st) break;
		exch1 = exch2 = avg1 = avg2 = 0;
		sum = 0;
		for (i=0; i<st; i++) {
			scanf("%d.%d", &stu_1, &stu_2);
      stu[i]=stu_1*100+stu_2;
			sum += stu[i];
		}
		
		topExp = sum%st;
		avg1 = sum/st;
    if (topExp)
      avg2 = avg1+1;
    else
      avg2 = avg1;

		qsort(stu, st, sizeof(int), comp);

    for (i=0; stu[i]<avg1; i++)
      exch1+=avg1-stu[i];

    for (i=st-1; stu[i]>avg2; i--)
      exch2+=stu[i]-avg2;
    
    if (exch1>exch2)
      printf("$%d.%02d\n", exch1/100, exch1%100);
    else
      printf("$%d.%02d\n", exch2/100, exch2%100);
	}
	return 0;
}

int comp(const void *a,const void *b) {
	return *(int*)a-*(int*)b;
}
