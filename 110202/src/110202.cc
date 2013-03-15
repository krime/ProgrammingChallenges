#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

class Card {
public:
  int  r; // rank
  char s; // suit

  // Constructor
  Card():r(0),s(0) {}
  Card(int rank, char suit):r(rank),s(suit) {}
  Card(char rank, char suit):r(0),s(suit) {
    switch(rank) {
    case'T':r=8;break;
    case'J':r=9;break;
    case'Q':r=10;break;
    case'K':r=11;break;
    case'A':r=12;break;
    default:r=rank-'2';break;
    }
  }

  // Copy Controls
  // Copy Constructor
  Card(const Card &c):r(c.r),s(c.s) {}
  // Assignment Operator
  const Card &operator=(const Card &c) {
    r=c.r;
    s=c.s;
    return *this;
  }
  // Compatible Assignment Operator
  Card &operator=(Card &c) {
    r=c.r;
    s=c.s;
    return *this;
  }
  // Destructor
  ~Card(){}

  // Comparison Operator
  bool operator==(const Card &c) const {return this->r==c.r;}
  bool operator!=(const Card &c) const {return this->r!=c.r;}
  bool operator>(const Card &c) const {return this->r>c.r;}
  bool operator<(const Card &c) const {return this->r<c.r;}
  int operator-(const Card &c) const {return this->r-c.r;}
  friend ostream& operator<<(ostream &sout, const Card &c) {
    char rank=' ';
    switch(c.r) {
    case 8:rank='T';break;
    case 9:rank='J';break;
    case 10:rank='Q';break;
    case 11:rank='K';break;
    case 12:rank='A';break;
    default:rank='2'+c.r;
    }
    sout<<rank<<c.s;
    return sout;
  }
  friend istream& operator>>(istream &sin, Card &c) {
    sin>>c.r>>c.s;
    return sin;
  }
};

class Dealer {
public:
  static Dealer getInstance() {
    return single;
  }
  // Destructor
  ~Dealer(){}

  bool SameSuit(Card cards[], int n);
  void SortRank(Card cards[], int n);
  int GetHand(Card cards[], int n);
  int Judgement(Card c1[], int n1, Card c2[], int n2);
  void DisplayHand(int h) {
    string hands;
    switch(h) {
    case HAND_HIGH_CARD:
      hands="High Card";break;
    case HAND_PAIR:
      hands="Pair";break;
    case HAND_2_PAIRS:
      hands="2 Pairs";break;
    case HAND_3_OF_A_KIND:
      hands="3 of a Kind";break;
    case HAND_STRAIGHT:
      hands="Straight";break;
    case HAND_FLUSH:
      hands="Flush";break;
    case HAND_FULL_HOUSE:
      hands="Full House";break;
    case HAND_4_OF_A_KIND:
      hands="4 of a Kind";break;
    case HAND_STRAIGHT_FLUSH:
      hands="Straight Flush";
    default:exit(1);
    }
    cout<<hands<<endl;
  }

  enum {WIN,LOSE,TIE};
  enum {
    HAND_HIGH_CARD,
    HAND_PAIR,
    HAND_2_PAIRS,
    HAND_3_OF_A_KIND,
    HAND_STRAIGHT,
    HAND_FLUSH,
    HAND_FULL_HOUSE,
    HAND_4_OF_A_KIND,
    HAND_STRAIGHT_FLUSH
  };
private:
  // Constructor
  Dealer(){}

  static Dealer single;
};

bool Dealer::SameSuit(Card cards[], int n) {
  if (n!=5) exit(1);
  char suit=cards[0].s;
  for (int i=1;i<5;i++) if (cards[i].s!=suit) return false;
  return true;
}

void Dealer::SortRank(Card cards[], int n) {
  if (n!=5) exit(1);
  for (int i=0;i<5;i++)
    for (int j=i+1;j<5;j++)
      if (cards[i]>cards[j]) {
        Card t=cards[i];
        cards[i]=cards[j];
        cards[j]=t;
      }
}

int Dealer::GetHand(Card cards[], int n) {
  if (n!=5) exit(1);
  if (SameSuit(cards,n)) {
    SortRank(cards, n);
    if (cards[4]-cards[0]==4) return HAND_STRAIGHT_FLUSH;
    else return HAND_FLUSH;
  } else {
    SortRank(cards, n);
    if (cards[0]==cards[1]) {
      if (cards[0]==cards[2]) {
        if (cards[0]==cards[3]) return HAND_4_OF_A_KIND;
        else if (cards[3]==cards[4]) return HAND_FULL_HOUSE;
        else return HAND_3_OF_A_KIND;
      } else {
        if (cards[2]==cards[3]) {
          if (cards[2]==cards[4]) return HAND_FULL_HOUSE;
          else return HAND_2_PAIRS;
        } else if (cards[3]==cards[4]) return HAND_2_PAIRS;
        else return HAND_PAIR;
      }
    } else {
      if (cards[1]==cards[2]) {
        if (cards[1]==cards[3]) {
          if (cards[1]==cards[4]) return HAND_4_OF_A_KIND;
          else return HAND_3_OF_A_KIND;
        } else if (cards[3]==cards[4]) return HAND_2_PAIRS;
        else return HAND_PAIR;
      } else {
        if (cards[2]==cards[3]) {
          if (cards[2]==cards[4]) return HAND_3_OF_A_KIND;
          else return HAND_PAIR;
        } else {
          if (cards[3]==cards[4]) return HAND_PAIR;
          else if (cards[4]-cards[0]==4) return HAND_STRAIGHT;
          else return HAND_HIGH_CARD;
        }
      }
    }
  }
}

int Dealer::Judgement(Card c1[], int n1, Card c2[], int n2) {
  int h1=GetHand(c1,n1);
  int h2=GetHand(c2,n2);
  int k1=0,k2=0;
  if (h1>h2) return WIN;
  else if (h1<h2) return LOSE;
  else {
    switch(h1) {
    case HAND_HIGH_CARD:
    case HAND_FLUSH:
      for (int i=4;i>=0;i--) {
        if (c1[i]>c2[i]) return WIN;
        else if (c1[i]<c2[i]) return LOSE;
        else continue;
      }
      return TIE;
    case HAND_PAIR:
      for (int i=0;i<4;i++)
        if (c1[i]==c1[i+1]) {
          k1=i;
          break;
        }
      for (int i=0;i<4;i++)
        if (c2[i]==c2[i+1]) {
          k2=i;
          break;
        }
      if (k1!=3) {
        Card t=c1[3];
        c1[3]=c1[k1];
        c1[k1]=t;
        t=c1[4];
        c1[4]=c1[k1+1];
        c1[k1+1]=t;
      }
      if (k2!=3) {
        Card t=c2[3];
        c2[3]=c2[k2];
        c2[k2]=t;
        t=c2[4];
        c2[4]=c2[k2+1];
        c2[k2+1]=t;
      }
      if (c1[4]>c2[4]) return WIN;
      else if (c1[4]<c2[4])return LOSE;
      else {
        for (int i=2;i>=0;i--)
          if (c1[i]>c2[i]) return WIN;
          else if (c1[i]<c2[i]) return LOSE;
          else continue;
        return TIE;
      }
    case HAND_2_PAIRS:
      if (c1[2]!=c1[3]&&c1[2]!=c1[1]) {
        Card t=c1[0];
        c1[0]=c1[2];
        c1[2]=t;
      } else if (c1[4]!=c1[3]) {
        Card t=c1[0];
        c1[0]=c1[4];
        c1[4]=c1[2];
        c1[2]=t;
      }
      if (c2[2]!=c2[3]&&c2[2]!=c2[1]) {
        Card t=c2[0];
        c2[0]=c2[2];
        c2[2]=t;
      } else if (c2[4]!=c2[3]) {
        Card t=c2[0];
        c2[0]=c2[4];
        c2[4]=c2[2];
        c2[2]=t;
      }
      if (c1[4]>c2[4]) return WIN;
      else if (c1[4]<c2[4]) return LOSE;
      else {
        if (c1[2]>c2[2]) return WIN;
        else if (c1[2]<c2[2]) return LOSE;
        else {
          if (c1[0]>c2[0]) return WIN;
          else if (c1[0]<c2[0]) return LOSE;
          else return TIE;
        }
      }
    case HAND_3_OF_A_KIND:
    case HAND_4_OF_A_KIND:
    case HAND_FULL_HOUSE:
      if (c1[2]>c2[2]) return WIN;
      else return LOSE;
    case HAND_STRAIGHT:
    case HAND_STRAIGHT_FLUSH:
      if (c1[4]>c2[4]) return WIN;
      else if (c1[4]<c2[4]) return LOSE;
      else return TIE;
    }
  }
  return TIE;
}

int main(int argc, char* argv[]) {
  string input;
  Dealer dealer=Dealer::getInstance();
  while (getline(cin,input)) {
    Card c1[5],c2[5];
    for (int i=0;i<5;i++)
      c1[i]=Card(input[i*3],input[i*3+1]);
    for (int i=5;i<10;i++)
      c2[i-5]=Card(input[i*3],input[i*3+1]);
    int d = dealer.Judgement(c1,5,c2,5);
    switch(d) {
    case Dealer::WIN:cout<<"Black wins."<<endl;break;
    case Dealer::LOSE:cout<<"White wins."<<endl;break;
    case Dealer::TIE:cout<<"Tie."<<endl;break;
    }
  }
  return 0;
}
