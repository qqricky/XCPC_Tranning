#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100002]={};
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        ll sum=0;
        ll last=0;
        cin>>a[1];
        int flag=1;
        int k=0;
        ll tmp=a[1];
        while(a[1]%x==0){
            a[1]/=x;
            k++;
        }
        if(tmp%x){
            flag=0;
        }
        for(int i=2;i<=n;i++){
            cin>>a[i];
            if(a[i]%x!=0)flag=0;
            if(flag)sum+=a[i]*2;
            else sum+=a[i];
        }
        if(flag==1){
            sum+=(k+1)*tmp;
        }
        else{
            sum+=2*tmp;
        }
        cout<<sum<<endl;
    }
    //system("pause");
    return 0;
}