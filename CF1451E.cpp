#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int a[N];
int ask(int x,int y)
{
    cout<<"XOR "<<x<<' '<<y<<endl;
    cout.flush();
    int ans;
    cin>>ans;
    return ans;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a1;
    map<int,int>mp;
    map<int,int>mpp;
    int flag=0;
    for(int i=2;i<=n;i++){
        a[i]=ask(1,i);
        if(!flag&&a[i]==0){
            cout<<"OR"<<' '<<1<<' '<<i<<endl;
            cout.flush();
            int k;
            cin>>k;
            a1=k;
            flag=1;
        }
        if(!flag&&mp[a[i]]){
            flag=1;
            int pos=mpp[a[i]];
            cout<<"OR"<<' '<<pos<<' '<<i<<endl;
            cout.flush();
            int k;
            cin>>k;
            a1=(a[i]^k);
        }
        mpp[a[i]]=i;
        mp[a[i]]++;
    }
    if(!flag){
        int pos=mpp[1];
        cout<<"OR"<<' '<<pos<<' '<<1<<endl;
        cout.flush();
        int k;
        cin>>k;
        pos=mpp[2];
        cout<<"OR"<<' '<<pos<<' '<<1<<endl;
        cout.flush();
        int kk;
        cin>>kk;
        if(kk&1){
            k|=1;
        }
        else{
            k=k&(~(1<<0));
        }
        a1=k;
    }
    cout<<'!'<<' '<<a1;
    for(int i=2;i<=n;i++){
        cout<<' '<<(a[i]^a1);
    }
    cout<<endl;
    cout.flush();
    //system("pause");
    return 0;
}