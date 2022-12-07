#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
string cut(ll x){
    string str;
    ll base=1;
    while(x){
        if(x&1){
            str='1'+str;
        }
        else{
            str='0'+str;
        }
        x/=2;
    }
    return str;
}

int main()
{

    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a,b,k;
    cin>>a>>b>>k;
    string str=cut(k);
    int ak=0;
    int len=str.length();
    str+=' ';
    for(int i=0;i<str.length();i++){
        if(str[i]=='1'&&str[i+1]=='1'){
            cout<<"No";
            return 0;
        }
        else if(str[i]=='1')ak++;
    }
    int bk=str.length()-ak;
    if(a<=ak||len+2<a+b){
        cout<<"No";
        return 0;
    }
    a-=ak;
    b-=(ak+1);
    bk-=ak;
    if(b<0){
        cout<<"No";
        return 0;
    }
    int num=0;
    if(bk>=b){b-=bk;num=bk;}
    else{
        num=b;
        bk-=b;
        b=0;
        a-=bk;
    }
    string a1,a2;
    for(int i=1;i<=a;i++){a1+='1';a2+='1';}
    for(int i=1;i<=b;i++){a1+='0';a2+='0';}
    for(int i=0;i<len;i++){
        if(str[i]=='0'&&str[i+1]=='1')continue;
        if(str[i]=='1'){
            a1+="10";
            a2+="01";
            i++;
        }
        else{
            if(num>0){
                num--;
                a1+='0';
                a2+='0';
            }
            else{
                a1+='a';
                a2+='0';
            }
        }
    }
    cout<<"Yes"<<endl;
    cout<<a1<<endl<<a2<<endl;
    system("pause");
    return 0;
}