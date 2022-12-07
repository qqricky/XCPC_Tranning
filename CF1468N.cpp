#include <bits/stdc++.h>
using namespace std;
long long c[10],a[10];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int flag=1;
        for(int i=1;i<=3;i++)cin>>c[i];
        for(int i=1;i<=5;i++){
            cin>>a[i];
            if(i<=3&&a[i]>c[i]){
                flag=0;
            }
            if(i<=3)c[i]-=a[i];    
        }
        if(c[1]>=a[4])c[1]-=a[4];
        else{
            a[4]-=c[1];
            c[3]-=a[4];
        }
        if(c[2]>=a[5])c[2]-=a[5];
        else{
            a[5]-=c[2];
            c[3]-=a[5];
        }
        if(c[3]<0)flag=0;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}