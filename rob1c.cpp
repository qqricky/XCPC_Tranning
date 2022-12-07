#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll num[1070]={};
string str;
ll getnum(int st,int ed){
    if(st>ed)return 1;
    ll res=0;
    for(int i=st;i<=ed;i++){
        res=res*10+(str[i]-'0')*1ll;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll mi=0,mx=0;
    cin>>str;
    if(str[0]!='-'){
        str='+'+str+'#';
    }else{
        str=str+'#';
    }
    int now=0;
    while(now<str.length()){
        if(str[now]=='#')break;
        ll flag;
        if(str[now]=='+'){
            flag=1;
        }else{
            flag=-1;
        }
        ll ed=now+1;
        while(str[ed]!='-'&&str[ed]!='+'&&str[ed]!='#'){
            ed++;
        }
        ed--;
        ll pos=now;
        while(pos<=ed&&str[pos]!='d'){
            pos++;
        }
        if(pos>ed){
            ll val=getnum(now+1,ed);
            mx+=flag*val,mi+=flag*val;
        }else{
            ll cnt=getnum(now+1,pos-1);
            ll type=getnum(pos+1,ed);
            num[type]+=cnt;
            if(flag==1){
                mi+=cnt;
                mx+=type*cnt;
            }else{
                mi-=type*cnt;
                mx-=cnt;
            }
        }
        now=ed+1;
    }
    for(int i=2;i<=1000;i++){
        if(num[i]){
            cout<<i<<' '<<num[i]<<'\n';
        }
    }
    cout<<mi<<' '<<mx;
    // cout.flush();
    // system("pause");
    return 0;
}