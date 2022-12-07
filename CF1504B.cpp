#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=3e5+10;
using namespace std;
char a[N];
char b[N];
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
        int n;
        cin>>n;
        vector<int>v;
        int val=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            val+=a[i]-'0';
            //cout<<i/2<<'Q'<<val<<endl;
            //cout<<i%2<<endl;
            if((i%2==0)&& (val==i/2))v.push_back(i);
        }
        for(int i=1;i<=n;i++)cin>>b[i];
        int fl;
        int pos=1;
        int flag=1;
        int num;
        if(v.empty()){
            for(int i=1;i<=n;i++){
                if(a[i]!=b[i]){
                    flag=0;
                    break;
                }
            }
        }
        for(int i=0;i<v.size();i++){
            num=v[i];
            fl=(a[pos]==b[pos]);
            for(int j=pos+1;j<=num;j++){
                if(fl){
                    if(a[j]!=b[j]){
                        flag=0;
                        break;
                    }
                }
                else{
                    if(a[j]==b[j]){
                        flag=0;
                        break;
                    }
                }
            }
            pos=num+1;
        }
        if(v.size())
        for(int j=v[v.size()-1]+1;j<=n;j++){
            if(a[j]!=b[j]){
                flag=0;
                break;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}