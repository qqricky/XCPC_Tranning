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
string str1;
string str2;
bool ck(int st1,int ed1,int st2,int ed2){
    if(st1>ed1)return 0;
    bool flag=1;
    for(int j=st1,jj=st2;j<=ed1;j++,jj++){
        if(str1[j]!=str2[jj]){
            flag=0;
            break;
        }
    }
    if(flag)return 1;
    if((ed1-st1+1)&1)return 0;
    if(st1==ed1)return 0;
    int mid1=(st1+ed1)>>1;
    int mid2=(st2+ed2)>>1;
    if(ck(st1,mid1,st2,mid2)&&ck(mid1+1,ed1,mid2+1,ed2))return 1;
    if(ck(st1,mid1,mid2+1,ed2)&&ck(mid1+1,ed1,st2,mid2))return 1;
    return 0;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>str1>>str2;
    int n=str1.length();
    if((n&1) && str1!=str2){
        cout<<"NO";
        return 0;
    }
    else if(n&1){
        cout<<"YES";
        return 0;
    }
    str1=' '+str1;
    str2=' '+str2;
    if(ck(1,n,1,n)){
        cout<<"YES";
    } 
    else{
        cout<<"NO";
    }
    cout.flush();
    //system("pause");
    return 0;
}