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
    int a,b;
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int cnt=0;
        map<int,int>mp;
        for(int i=2;i*i<=a;i++){
            if(a%i==0){
                if(mp[i]==0){mp[i]++;cnt++;}
                while(a%i==0)a/=i;
            }
        }
        if(a>1){
            if(mp[a]==0){
                mp[a]++;
                cnt++;
            }
        }
        for(int i=2;i*i<=b;i++){
            if(b%i==0){
                if(mp[i]==0){mp[i]++;cnt++;}
                while(b%i==0)b/=i;
            }
        }
        if(b>1){
            if(mp[b]==0){
                mp[b]++;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }

    //system("pause");
    return 0;
}