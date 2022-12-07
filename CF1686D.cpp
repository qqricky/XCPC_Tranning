#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
vector<int>v1,v2;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v1.clear(),v2.clear();
        int cnt1=0;
        int cnt2=0;
        string str;
        cin>>str;
        for(char ch:str){
            if(ch=='A')cnt1++;
            else cnt2++;
        }
        if((a+c+d!=cnt1)||(b+c+d!=cnt2)){
            cout<<"NO\n";
            continue;
        }
        str=str+str[str.length()-1];
        int num=0;
        int cnt=0;
        int star=0;
        bool flag=1;
        cnt1=0,cnt2=0;
        for(int i=1;i<str.length();i++){
            if(str[i]!=str[i-1]){
                cnt++;
            }else{
                if(cnt==1){
                    if(str[i]=='B'){
                        cnt1++;
                    }
                    else{
                        cnt2++;
                    }
                }
                cnt=0;
            }
        }
        cnt=0;
        for(int i=1;i<str.length();i++){
            if(str[i]!=str[i-1]){
                cnt++;
            }else{
                num=cnt/2;
                cnt%=2;
                if(cnt&&num){
                    if(str[i]=='B'){
                        v1.push_back(num+1);
                    }else if(str[i]=='A'){
                        v2.push_back(num+1);
                    }
                    star+=num;
                }else{
                    star+=num;
                }
                cnt=0;
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        c-=min(c,cnt1);
        d-=min(d,cnt2);
        for(int j=0;j<v1.size();j++){
            if(c<v1[j])break;
            c-=v1[j];
            star-=(v1[j]-1);
        }
        for(int j=0;j<v2.size();j++){
            if(d<v2[j])break;
            d-=v2[j];
            star-=(v2[j]-1);
        }
        if(star>=c+d){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    cout.flush();
    // system("pause");
    return 0;
}