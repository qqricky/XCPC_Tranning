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
int cnt[11]={};
int cnt9[11][11]={};
int cnt10[11][11]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    int n=str.length();
    str=' '+str;
    vector<pair<int,int> >v;
    vector<pair<int,int> >vv;
    int cnt0=0;
    bool flag=0;
    for(int i=0;i<n;i++){
        int c=str[i]-'0';
        if(cnt[9-c]>0){
            cnt[9-c]--;
            cnt9[c][9-c]++;
            cnt9[9-c][c]++;
        }
        cnt[str[i]-'0']++;
    }
    for(int i=1;i<5;i++){
        while(cnt[i]>0&&cnt[10-i]>0){
            cnt10[i][10-i]++;
            cnt10[10-i][i]++;
            cnt[i]--;
            cnt[10-i]--;
            flag=1;
        }
    }
    cnt10[5][5]+=cnt[5];
    if(cnt[5]>0)flag=1;
    if(!flag){
        for(int i=1;i<=9;i++){
            if(cnt[i]>0&&cnt9[10-i][9-(10-i)]>0){
                cnt9[10-i][9-(10-i)]--;
                cnt[i]--;
                v.push_back(make_pair(i,9-(10-i)));
                cnt10[i][10-i]++;
                flag=1;
                break;
            }
        }
    }
    if(!flag){
        for(int i=0;i<=9;i++){
            if(i==5)continue;
            if(cnt9[i][9-i]>0&&cnt9[10-i][9-(10-i)]>0){
                cnt9[i][9-i]--;
                cnt9[10-i][9-(10-i)]--;
                cnt10[i][10-i]++;
                v.push_back(make_pair(9-i,9-(10-i)));
                flag=1;
                break;
            }
        }
        if(!flag){
            if(cnt9[5][4]>0){
                cnt9[5][4]--;
                cnt9[4][5]--;
                cnt10[5][5]++;
                v.push_back(make_pair(4,4));
                flag=1;
            }
        }
        vector<int>q1,q2;
        while (cnt[0]>0)
        {
            q1.push_back(0);
            q2.push_back(0);
        }
        
    }
    cout.flush();
    system("pause");
    return 0;
}