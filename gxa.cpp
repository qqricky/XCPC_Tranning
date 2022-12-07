#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    int n=str.length();
    str=' '+str+' '+' ';
    int cnt=0;
    int num=0;
    int tmp=0;
    bool is=1;
    int ans=0;
    for(int i=1;i<=n+2;i++){
        if(str[i]=='1'){
            cnt++;
        }else{
            if(cnt==1){
                ans++;
                cnt=0;
            }else if(cnt==0){
                continue;
            }else{
                str[i]='1';
                ans++;
                cnt=1;
            }
        }
    }
    cout<<ans;
    cout.flush();
    // system("pause");
    return 0;
}