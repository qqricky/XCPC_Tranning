#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
string str;
int n;
int ck(char ch){
    int l=1,r=n;
    int cnt=0;
    while(l<r){
        if(str[l]!=str[r]){
            if(str[l]==ch){
                l++;
                cnt++;
            }
            else if(str[r]==ch){
                r--;
                cnt++;
            }
            else{
                cnt=INF;
                break;
            }
        }
        else{
            l++;
            r--;
        }
    }
    return cnt;
}
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
        cin>>n;
        cin>>str;
        str=' '+str;
        int ans=INF;
        for(char ch='a';ch<='z';ch++){
            ans=min(ans,ck(ch));
        }
        cout<<(ans==INF ? -1 : ans)<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}