#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[100002]={};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        vector<int>v;
        map<int,int>mp;
        ll n,x;
        cin>>n>>x;
        ll sum=0;
        ll tmp;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            mp[i-1]=tmp;
            v.push_back(tmp);
        }
        ll pos=0;
        int flag=1;
        ll si=v.size();
        while(pos<si)
        {
            if(v[pos]%x){
                flag=0;
            }
            if(flag){
                v.push_back(v[pos]/x);
                mp[v.size()-1]=mp[pos];
                sum+=mp[pos];
                si++;
            }
            else{
                sum+=mp[pos];
            }
            pos++;
        }
        cout<<sum<<endl;
    }
    //system("pause");
    return 0;
}