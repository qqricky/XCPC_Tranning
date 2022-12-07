#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include<functional>
#define ll long long
const int N=200; 
using namespace std;
int a[N];
int v[N];
int ans=0;
int n;
int len,cnt;
int pre=0;
int calc(int num,int now,int last)
{
    if(num==cnt)return 1;
    if(now==len){
        if(calc(num+1,0,0))return 1;

    }
    // if(now==0){
    //     for(int i=1;i<=n;i++){
    //         if(!v[i]){
    //             v[i]=1;
    //             if(calc(num,a[i],i))return 1;
    //             else{
    //                 v[i]=0;
    //                 return 0;
    //             }
    //         }
    //     }
    // }
    pre=0;
    for(int i=last+1;i<=n;i++){
        if(!v[i]&&a[i]+now<=len&&a[i]!=pre){
            // for(int i=1;i<=n;i++){
            //     if(v[i])cout<<a[i]<<' ';
            // }
            // cout<<endl;
            // if(a[i]==len-now){
            //     v[i]=1;
            //     pre=0;
            //     if(calc(num+1,0,0))return 1;
            //     else {
            //         v[i]=0;
            //         return 0;
            //     }
            // }
            v[i]=1;
            if(calc(num,now+a[i],i))return 1;
            pre=a[i];
            v[i]=0;
            if(now==0||now+a[i]==len)return 0;
        }
    }
    return 0;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int sum=0;
    int big=0;
    while(n!=0)
    {
        memset(v,0,sizeof(v));
        pre=sum=big=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        sort(a+1,a+n+1,greater<int>());
        int flag=0;
        big=a[1];
        for(int i=big;i<=sum/2;i++){
            if(sum%i==0){
                cnt=sum/i;
                len=i;
                if(calc(0,0,0)){
                    cout<<len<<"\n";
                    flag=1;
                    break;
                }
            }
        }
        if(!flag)cout<<sum<<"\n";
        cin>>n;
    }
    //system("pause");
    return 0;
}