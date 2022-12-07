#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimise(2)
using namespace std;
ll pri[1000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		ll m;
		cin>>m;
        if(m==1){
            cout<<1<<'\n'<<1<<'\n';
            continue;
        }
		int i;
		int cnt=0;
        ll rawm=m;
		ll fun1=sqrt(m)+1;
		for(i=2;i<=fun1;i++){
			while(m%i==0){
				m/=i;
				pri[++cnt]=i;
			}
		}
		if(m!=1){
			pri[++cnt]=m;
		}
		ll now=0;
		for(i=1;i<=cnt;i++)now+=pri[i];
        int test=0;
        int sv=0;
		while(now>100){
            test++;
			m=rawm-test;
            cnt=0;
            fun1=sqrt(m)+1;
            for(i=2;i<=fun1;i++){
			while(m%i==0){
                    m/=i;
                    pri[++cnt]=i;
                }
            }
            if(m!=1){
                pri[++cnt]=m;
            }
            now=0;
            for(i=1;i<=cnt;i++)now+=pri[i];
            if(now+cnt*test<=100){
                sv=cnt*test;
                goto ed;
            }
            if(test>=100||test>=rawm)goto ed;
            now=1e5;
		}
        ed:;
        if(now>100){
            cout<<-1<<'\n';
        }
        else{
			cout<<now+cnt*test<<'\n';
			int sh=sv+1;
			for(i=1;i<=cnt;i++){
				int j;
				for(j=sh+pri[i]-1;j>=sh;j--){
					cout<<j<<' ';
				}
				sh=sh+pri[i];
			}
            sh=sv;
            for(int i=1;i<=test;i++){
                int j;
                for(j=sh-cnt+1;j<=sh;j++){
					cout<<j<<' ';
				}
				sh-=cnt;
            }
			cout<<'\n';
		}
	}
}