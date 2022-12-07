#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int n,m;
string str;
int pi[2*N];
void prefix_function() {
  int n = (int)str.length();
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && str[i] != str[j]) j = pi[j - 1];
    if (str[i] == str[j]) j++;
    pi[i] = j;
  }
}
vector<int>v;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s,t;
    while(cin>>s>>t){
        v.clear();
        n=s.length();
        m=t.length();
        str=s+t;
        prefix_function();
        int now=str.length()-1;
        while(now){
            v.push_back(pi[now]);
            now=pi[pi[now]-1];
        }
        reverse(v.begin(),v.end());
        int pos=0;
        for(int i=0;i<n;i++){
            while(pos<v.size()&&v[pos]<=m+i)pos++;
            
        }
    }
    cout.flush();
    system("pause");
    return 0;
}