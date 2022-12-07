#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
vector<bool>mp[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        mp[i].resize(m+1);
    }
    int q;
    cin>>q;
    while(q--){
        int var,c;
        cin>>var>>c;
        if(var){
            for(int i=1;i<=n;i++){
                mp[i][c]=1;
            }
        }
        else{
            for(int i=1;i<=m;i++){
                mp[c][i]=1;
            }
        }
    }
    int num=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!mp[i][j]){
                num++;
            }
        }
    }
    cout<<num;
    cout.flush();
    //system("pause");
    return 0;
}