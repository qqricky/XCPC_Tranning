#include <bits/stdc++.h>
#include <cmath>
using namespace std;
const int N=1e5+3;
long long t[N]={};
long long x[N]={};
long long poss[N]={};
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        memset(t,0,sizeof(t));
        memset(x,0,sizeof(x));
        memset(poss,0,sizeof(poss));
        long long tmp=0;//next free time
        long long pos=0;
        long long cnt=0;
        long long des=0;
        int dir=0;//1right 0left
        for(int i=1;i<=n;i++)cin>>t[i]>>x[i];
        for(int i=1;i<=n;i++){
            if(t[i]<tmp){
                if(i==n){t[n+1]=tmp;poss[n+1]=des;}
                if(dir==1)pos+=(t[i]-t[i-1]);
                else pos-=(t[i]-t[i-1]);
                poss[i]=pos;
            }
            else{
                pos=des;
                poss[i]=pos;
                if(i==n){
                    if(x[i]>pos)poss[i+1]=1e10+5;
                    else poss[i+1]=-2147483647;
                }
                //cout<<t[i]<<'Q'<<endl;
                if(i==n)tmp=2147483647;
                else {
                    tmp=t[i]+abs(x[i]-poss[i]);   
                }
                des=x[i];
                dir=(x[i]>pos);
            }
        }
        //for(int i=1;i<=n+1;i++)cout<<'Q'<<poss[i]<<endl;
        for(int i=1;i<=n;i++)
        {
            int l=poss[i],r=poss[i+1];
            if(l>r)
                swap(l,r);
            if(x[i]>=l&&x[i]<=r)
                cnt++;
        }
        cout<<cnt<<endl;
    }
    //system("pause");
    return 0;
}