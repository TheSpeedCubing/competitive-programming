#include <bits/stdc++.h>

using namespace std;

struct User {
  int id,
      correctCount, 
      WA[1024] = {},
      time,
      order;
  User(int id): id(id) {}
  
  string toString() {
  	 return to_string(id)  +" "+to_string(correctCount) +" "+to_string(time) + "\n"; 
  }
};

int userCount, questionCount, stopDisplay, stopComp, id, questionID, submitTime, f;
char state, e;
string s, s2;

vector < User * > db;

void comp(bool b) {
  sort(db.begin(), db.end(), [b](const User * u1,
    const User * u2) {
    if (u1 -> correctCount != u2 -> correctCount)
      return u1 -> correctCount > u2 -> correctCount;
    if (u1 -> time != u2 -> time)
      return u1 -> time < u2 -> time;
    return (b ? u1 -> id < u2 -> id : u1 -> order > u2 -> order);
  });
}

int main() {

  while (cin >> userCount >> questionCount >> stopDisplay >> stopComp) {
    if (f++)
      cout << "\n";

    map < int, User * > users;
    db.clear();
    cin.ignore();

    int order = 0;
    while (getline(cin, s)) {
      if (s == "^^^")
        break;
      stringstream ss(s), rms;
      ss >> id >> questionID >> submitTime >> state >> e;
      if (!users.count(id)) {
        User * u = new User(id);
        users[id] = u;
        db.push_back(u);
      }
      User * u = users[id];
      if (submitTime <= stopComp) {
        if (u -> WA[questionID] != -1) {
          if (state == 'A') {
            u -> order = order;
            u -> correctCount++;
            u -> time += (submitTime + u -> WA[questionID]);
            u -> WA[questionID] = -1;
          } else {
            u -> WA[questionID] += 20;
          }
        }
      }

      order++;

      comp(0);

      u = db[0];
      if (state == 'A')
        if (submitTime <= stopDisplay) {
          if (u->toString() != s2) {
            s2 = u->toString();
            cout << s2;
          }
        }
    }
    cout << "**********\n";
    comp(1);
    for (User * u : db) {
      cout << u -> toString();
    }
  }
}