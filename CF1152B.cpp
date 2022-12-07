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
vector<int>bit;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>ans;
    vector<int>anss;
    int cntt=0;
    int cnt=0;
    int base=0;
    int st=1;
    while(n){
        if(n&1){
            bit.push_back(1);
        }
        else{
            bit.push_back(0);
        }
        n>>=1;
    }
    reverse(bit.begin(),bit.end());
    for(int i=0;i<bit.size();i++){
        if(bit[i]==0){
            anss.push_back(bit.size()-i);
            int pos=bit.size()-1;
            cntt++;
            bool flag=1;
            for(int j=i;j<bit.size();j++){
                bit[j]^=1;
                if(bit[j]==0)flag=0;
            }
            if(flag){
                break;
            }
            cntt++;
            while(bit[pos]==1){
                bit[pos]^=1;
                pos--;
            }
            bit[pos]=1;
            // cout<<"jkaljf  ";
            // for(int k=0;k<bit.size();k++)cout<<bit[k]<<' ';
            // cout<<endl;
        }
    }
    cout<<cntt<<'\n';
    for(int i=0;i<anss.size();i++)cout<<anss[i]<<' ';
    //cout<<endl;
    cout.flush();
    //system("pause");
    return 0;
}