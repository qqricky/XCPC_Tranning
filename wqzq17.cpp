#include<bits/stdc++.h>
using namespace std;
#define long long long
#define MAX 100001

struct store{
	int a[MAX];
	int score;
	int flag;
};

int cal(store*s,int N,int T){
	for(int i=0;i<N;i++){
//		cout<<'\n'; //
		for(int j=0;j<T;j++){
			if(!s[i].a[j]){
				if(s[i].score>0)
					s[i].score-=1;
				if(s[i].flag==1&&s[i].score<=3)
					s[i].flag=0;
			}
			else{
				s[i].score+=s[i].a[j]*2;
				if(s[i].score>5)
					s[i].flag=1;}
//			cout<<s[i].score<<'\t'<<s[i].flag<<'\n';// 
		}
//		cout<<'\n'; //
	}
	int count=0;
	for(int i=0;i<N;i++)
		if(s[i].flag)
			count++;
	return count;
}
int main(void){
	int N,M,T;
	cin>>N>>M>>T;
	store *s=(store*)malloc(sizeof(store)*N);
	for(int i=0;i<N;i++){
		for(int j=0;j<MAX;j++)
			s[i].a[j]=0;
		s[i].score=0;
		s[i].flag=0;
	}
	while(M--){
		int ts,id;
		cin>>ts>>id;
		s[id-1].a[ts-1]++;
	}
	cout<<cal(s,N,T);
	free(s);
	return 0;
}