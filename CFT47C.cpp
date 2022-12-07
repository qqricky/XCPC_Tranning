#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	//cin.tie(0);
	//cout.tie(0);
    //ios_base::sync_with_stdio(false);
	int T;cin >> T;
	while(T--){
        ll n;
        cin>>n;
        n++;
        ll dd=n;
        ll now=(n+3)/4-1;
        ll fun;
        if(now==0)fun=1;
        else
        fun=1ll<<(now);
        n=n%4;
        if(n==0)printf("%lld\n",dd-fun*4);
        else if(n==1)printf("%lld\n",dd-fun*1);
        else printf("%lld\n",dd-fun*(2));
    }

}