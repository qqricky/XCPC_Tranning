#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a[6];
        int n;
        cin>>n;
        for(int i=1;i<=4;i++)cin>>a[i];
        if(n==2){
            int sum=0;
            for(int i=1;i<=4;i++)sum+=a[i];
            if(sum>4)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
            continue;
        }
        a[0]=a[4];
        a[5]=a[1];
        int d[6]={};
        int cnt=0;
        int v[6]={};
        int cnt2=0;
        for(int i=1;i<=4;i++){
            if(a[i]>n-2){
                v[i]=a[i]-(n-2);
                if(v[i]==2){d[i]=1;cnt2++;}
                else cnt++;
            }
        }
        v[5]=v[1];
        v[0]=v[4];
        int flag=1;
        if(cnt2>2)flag=0;
        else if(cnt2==2){
            if(cnt)flag=0;
            for(int i=1;i<=4;i++){
                if(a[i]<2)flag=0;
            }
        }
        else if(cnt2==1){
        if(cnt>2)flag=0;
        for(int i=1;i<=4;i++){
            if(v[i]==2){
                if(a[i+1]<1||a[i-1]<1)flag=0;
                else if(cnt==2){
                    for(int j=1;j<=4;j++)
                    if(a[j]<2){
                        flag=0;
                        break;
                    }
                }
                else if(cnt==1){
                    if(v[(i+2)%4]==1){
                        int cntt=0;
                        for(int j=1;j<=4;j++){
                            if(a[j]<2)cntt++;
                            if(a[j]<1)flag=0;
                        }
                        if(cntt>1)flag=0;
                    }
                    for(int j=1;j<=4;j++){
                        if(a[j]==0){
                            flag=0;
                            break;
                        }
                    }
                }
            }
        }
        }
        else{
            if(cnt==4);
            else if(cnt==3){
                for(int i=1;i<=4;i++){
                    if(a[i]==0)flag=0;
                }
            }
            else if(cnt==2){
                int f=0;
                for(int i=1;i<=4;i++){
                    if(v[i]&&v[i+1]){
                        f=1;
                        break;
                    }
                }
                if(f){
                    for(int i=1;i<=4;i++){
                        if(v[i]){
                            if(a[i-1]==0&&a[(i+2)%4]==0)flag=0;
                        }
                    }
                }
                else{
                    int cntt=0;
                    for(int i=1;i<=4;i++){
                        if(!v[i])cntt+=a[i];
                    }
                    if(cntt<2)flag=0;
                }
            }
            else if(cnt==1){
                for(int i=1;i<=4;i++){
                    if(v[i]){
                        if(a[i-1]==0&&a[i+1]==0)flag=0;
                    }
                }
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}