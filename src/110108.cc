#include <cstdio>
#include <cstdlib>
#include <cstring>

#define byte int
#define bool char
#define TRUE 1
#define FALSE 0
#define DEBUG 0

typedef struct c_selector {
  byte m_votes;
  char* m_name;
  byte* m_list;
} t_selector;

typedef struct c_selection {
  byte* m_votes;
  byte  m_num;
} t_selection;

t_selector g_st[20];
t_selection g_stm[20];
char g_names[20][80];
byte g_votes[21][1000];
byte g_lists[20][1000];
bool g_elims[20];

int compare(const void* st_a, const void* st_b) {
  return *(((t_selection*)st_b)->m_votes)-*(((t_selection*)st_a)->m_votes);
}

int diff(const void* st_a, const void* st_b) {
  return ((t_selection*)st_a)->m_num-((t_selection*)st_b)->m_num;
}

int main() {
  int v_test=0, v_sctr=0, v_vote=0;
  int i,j,k,l;
  char input[80];
  char* pin;
  int min, max, mini, maxi;
  bool f_fin, f_elim, f_win;

  scanf("%d", &v_test);
  while (getchar()!='\n');
  while (v_test--) {
    memset(g_names, 0, 20*80*sizeof (char));
    memset(g_votes, 0, 21*1000*sizeof (byte));
    memset(g_lists, 0, 20*1000*sizeof (byte));
    memset(g_st, 0, 20*sizeof (t_selector));
    memset(input, 0, 80*sizeof (char));
    memset(g_elims, 0, 20*sizeof (bool));
    
    for (i=0;i<20;i++) {
      g_stm[i].m_votes = &g_st[i].m_votes;
      g_stm[i].m_num   = i;
    }

    scanf("%d", &v_sctr);
    while (getchar()!='\n');
    for (i=0;i<v_sctr;i++) {
      gets(input);
      strcpy(g_names[i], input);
      g_st[i].m_name = g_names[i];
    }
    memset(input, 0, 80*sizeof(char));
    for (i=0;;i++) {
      if (!gets(input)||!input[0]||input[0]=='\r') break;
      for (j=0,pin=input;j<v_sctr;j++) {
        sscanf(pin, "%d", &g_votes[j][i]);
        pin=&pin[strcspn(pin," ")+1];
      }
      g_votes[20][i]=0;
    }
    v_vote=i;
    for (i=0;i<v_vote;i++) {
      int i_top = g_votes[20][i];
      int i_sel = g_votes[i_top][i]-1;
      int i_vot = g_st[i_sel].m_votes;
      g_lists[i_sel][g_st[i_sel].m_votes++]=i;
    }
    for (i=0;i<v_sctr;i++) {
      g_st[i].m_list = g_lists[i];
    }
    qsort(g_stm, v_sctr, sizeof(t_selection), compare);

    int n_sctr=v_sctr;
    while (TRUE) {
      f_elim = FALSE;
      if (*(g_stm[0].m_votes)*2>v_vote) {
        printf("%s\n", g_st[g_stm[0].m_num].m_name);
        if (v_test)
          puts("");
        break;
      } else {
        for (i=n_sctr-1;i>=0;i--) {
          if (*(g_stm[i].m_votes)==-1) continue;
          else if (*(g_stm[i].m_votes)==*(g_stm[0].m_votes)) {
            f_elim = FALSE;
            break;
          } else if (*(g_stm[i].m_votes)==*(g_stm[i-1].m_votes)) {
            continue;
          } else {
            f_elim = TRUE;
            break;
          }
        }
        if (f_elim) {
          for (j=n_sctr-1;j>=i;j--) {
            int n_no=g_stm[j].m_num;
            g_elims[n_no]=TRUE;
          }
          for (j=n_sctr-1;j>=i;j--) {
            int n_no=g_stm[j].m_num;
            for (k=0;k<g_st[n_no].m_votes;k++) {
              int n_vote = g_st[n_no].m_list[k];
              int n_top = g_votes[20][n_vote];
              while (g_elims[g_votes[n_top][n_vote]-1]) g_votes[n_top++][n_vote]=0;
              g_votes[20][n_vote]=n_top;
              int n_sel = g_votes[n_top][n_vote]-1;
              g_lists[n_sel][g_st[n_sel].m_votes++]=n_vote;
            }
            g_st[n_no].m_votes=-1;
          }
          n_sctr=i;
          qsort(g_stm, n_sctr, sizeof(t_selection), compare);
        } else {
          qsort(g_stm, n_sctr, sizeof(t_selection), diff);
          for (j=0;j<n_sctr;j++) printf("%s\n", g_st[g_stm[j].m_num].m_name);
          if (v_test)
            puts("");
          break;
        }
      }
    }
  }

  return 0;
}
