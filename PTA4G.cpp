#include<bits/stdc++.h>
#define ll long long
using namespace std;
int num[300]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans=0;
    int n,k,s;
    cin>>n>>k>>s;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if(y>=s&&x>=175){
            ans++;
        }
        else{
            if(x>=175){
                num[x]++;
            }
        }
    }
    for(int i=175;i<=290;i++){
        ans+=min(num[i],k);
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}