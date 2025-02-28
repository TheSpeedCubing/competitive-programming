#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

// 以上可放置你的程式
// 以下五行程式碼請勿做任何變更
void gendata();

int main(int argc, char** argv)
{
    gendata();
    
    vector<ULL> s;
    
    ULL value;
    
    FILE* f1 = fopen(*(argv+1),"r");
    while(fscanf(f1,"%llu",&value) != EOF) {
    	s.push_back(value);
    }
    
    FILE* f2 = fopen(*(argv+2),"rb");
    while(fread(&value, 1, sizeof(ULL), f2)) {
    	s.push_back(value);
    }
    sort(s.begin(),s.end());
    
    for(ULL u : s) {
    	cout << u <<"\n";
    }
}

// 以上可放置你的程式
// 以下程式碼請勿做任何變更
void gendata()
{
    int seed;
    scanf("%d", &seed);
    if(seed==0) return;
    srand(seed);

    FILE* fp=fopen("file1.txt", "w");
    int sz = 10000*(rand()%5+1)+rand();
    unsigned long long val=10ULL*rand()*rand();

    for(int i=0; i<sz; i++){
        fprintf(fp, "%llu\n", val);
        val += rand();
    }
    fclose(fp);

    fp=fopen("file2.bin", "wb");
    sz = 10000*(rand()%10+1)+rand();
    int gap=(val)/sz*2;

    val+=rand();
    val-=rand();

    for(int i=0; i<sz; i++){
        fwrite(&val, sizeof(unsigned long long), 1, fp);
        val -= rand()%gap;
    }

    fclose(fp);
}
