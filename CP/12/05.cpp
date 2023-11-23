#include <iostream>
#include <algorithm>

using namespace std;

char s[5],n[5],
     s2[5],
     type,type2,
     score,
     same[4], state;

void adjacent(char s[]) {
	  auto it = adjacent_find(s, s + 5);
    rotate(it, it + 2, s + 5);
}
int readData() {
	state = !state;
	int i = 0;
	while(i<5) {
		if(!(cin >> n[i] >> s[i]))
		   exit(0);
		   
	  int j = 2;
	  for(char c : "23456789TJQKA") {
	    if(c == s[i]){
	      s[i] = j;
	      break;
	    }
	    j++;
	  }
		i++;
	}
	
	sort(s,s+5);
	
	int mid = s[2],
	    diff = 1,
	    isFlush = 1, 
	    isStraight = 1;
	
	i = 0;
	while(i<4) {
		 int t = s[i+1] - s[i];
		 if(t != 1 && (i != 3 || s[i+1] != 14))
		 	   isStraight = 0;
		 	   
		 if(t)
		   diff++;
		 if(n[i] != n[i+1])
		   isFlush = 0;
		 same[i] = !t;
		 i++;
	}
	int sc = 0, ty = 0;
	if(isFlush && isStraight)
	  ty = 9;
	else if (sc = (diff == 2 && (!same[0] || !same[3]) ? mid : 0))
	  ty = 8;
	else if(sc = (diff == 2 ? (same[1] ? s[0] : s[4]) : 0))
	  ty = 7;
	else if(isFlush)
	  ty = 6;
	else if(isStraight)
	  ty = 5;
	else if(sc = ((same[1] && same[2]) || (same[1] && s[0] == s[2]) || (same[2] && s[2] == s[4]) ? mid : 0))
	  ty = 4;
	else if (diff == 3) {
		adjacent(s);
		adjacent(s);
    ty = 3;
	}
	else if(diff == 4) {
		adjacent(s);
	  ty = 2;
	}
	else ty = 1;
	if(state) {
		i = 0;
		while(i<5) {
		   s2[i] = s[i];
		   i++;
	  }
		score = sc;
		type = ty;
		return 0;
	} else {
		type2 = ty;
		
	  if(type == 8 || type == 7 || type == 4) {
      return score != sc ? score > sc : 2;
	  }
	  
	  i = 5;
	  while(i--) {
		  if(s2[i] != s[i])
		    return s2[i] > s[i];
	  }
		return 2;
	}
}

int main()
{
	while(1) {
		  readData(); 
		  int cp = readData();
		  string s[] = {"B wins\n","A wins\n","Tie\n"};
		  cout << s[(type == type2) ? cp : (type > type2)];
  }
}
