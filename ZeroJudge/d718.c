#include <stdio.h>
#include <string.h>
#define MAX_TEAMS 1001
#define MAX_MEMBERS 1100 // 1000 won't work, unknown reason
#define MAX_QUEUE_SIZE 2000000

int belong[2000000];
int teamQueue[MAX_TEAMS][MAX_MEMBERS];
int teamHead[MAX_TEAMS];
int teamTail[MAX_TEAMS];
int mainQueue[MAX_QUEUE_SIZE];
int mainHead = 0, mainTail = 0;

void enqueue(int x) {
    int team = belong[x];
    if (team == 0) {
        mainQueue[mainTail++] = 20010911 + x;
        return;
    }
    if (teamHead[team] == teamTail[team]) {
        mainQueue[mainTail++] = team;
    }
    teamQueue[team][teamTail[team]++] = x;
}

void dequeue(){
    if(mainHead < mainTail) {
        int frontTeam = mainQueue[mainHead];
        if(frontTeam >= 20010911){
            printf("%d\n", frontTeam - 20010911);
            mainHead++;
            return;
        }
        int member = teamQueue[frontTeam][teamHead[frontTeam]];
        printf("%d\n", member);
        teamHead[frontTeam]++;
        if(teamHead[frontTeam] == teamTail[frontTeam]){
            mainHead++;
            teamHead[frontTeam] = 0;
            teamTail[frontTeam] = 0;
        }
    }
}

int main(){
    int n, i, j, tn, x;
    char s[100];
    int k = 0;
    while(scanf("%d", &n) == 1) {
        memset(belong, 0, sizeof(belong));
        memset(teamHead, 0, sizeof(teamHead));
        memset(teamTail, 0, sizeof(teamTail));
        mainHead = 0;
        mainTail = 0;
        for(i = 1; i <= n; i++) {
            scanf("%d", &tn);
            for(j = 0; j < tn; j++) {
                scanf("%d", &x);
                belong[x] = i;
            }
        }
        printf("Line #%d\n", ++k);
        while(scanf("%s", s) && s[0] != 'S') {
            if (s[0] == 'E') {
                scanf("%d", &x);
                enqueue(x);
            } else if(s[0] == 'D') {
                dequeue();
            }
        }
    }
    return 0;
}.
