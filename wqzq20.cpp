#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define n 3
bool cmp(ll x,ll y){
  return x<y;
}
ll pow_q(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res*=a;
        b>>=1;
        a*=a;
    }
    return res;
}
int main(void)
{
  ll n;
  while(cin>>n){
  	ll m1=log(n)/log(7),m2=log(n)/log(5),m3=log(n)/log(3),count=0; //算各幂次的上界 
  	ll *data=(ll*)malloc(sizeof(ll)*(m1+1)*(m2+1)*(m3+1));
  	for(int i=0;i<(m1+1)*(m2+1)*(m3+1);i++)  //所有元素初始化为n+1 
  		data[i]=n+1;
	for(ll k1=1;k1<=n;k1*=7){       
		for(ll k2=1;k2*k1<=n;k2*=5){
			for(ll k3=1;k3*k2*k1<=n;k3*=3){
				// if(k1+k2+k3==0){
				// 	continue;
				// }
				//ll tmp=pow_q(7,k1)*pow_q(5,k2);   //算数基本定理 
				// if(tmp>n){
				// 	break;
				// }
				// tmp*=pow_q(3,k3);
				// if(tmp>n){
				// 	break;
				// }
				data[count++]=k1*k2*k3;
			}
		}
	}
	sort(data,data+(m1+1)*(m2+1)*(m3+1),cmp);   //从小到大排序，然后看n是第几个元素 
	for(int i=0;i<(m1+1)*(m2+1)*(m3+1);i++){
		//cout<<data[i]<<endl;
		if(data[i]==n){
			cout<<i+1<<endl;
			break;
		}
	}  	
  }
}