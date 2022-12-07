#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
vector<char>v1,v2;
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        v1.clear(),v2.clear();
        for(int i=0;i<str.length();i++){
            if(i&1)v2.push_back(str[i]);
            else v1.push_back(str[i]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int p1=0;
        int p2=0;
        for(int i=0;i<str.length();i++){
            if(i&1){
                cout<<v2[p2++];
            }else{
                cout<<v1[p1++];
            }
        }
        cout<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}