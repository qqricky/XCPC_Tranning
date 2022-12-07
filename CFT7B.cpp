#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int f[N][27];
int l[27];
int r[27];
int k;
int cnt;
int len;
bool check(int now,int pos)
{
    int sum=0;
    for(int i=now;i<=len;i++){
        if(f[pos][i]<l[i])return 0;
        if(i>now)
        sum+=l[i];
    }
    //cout<<pos<<"QWWW"<<sum<<endl;
    if(sum<=k-cnt)return 0;
    if(k-cnt>len-pos)return 0;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    while(cin>>str)
    {
        int flag=1;
        cin>>k;
        len=str.length();
        str=' '+str;
        for(int i=1;i<=26;i++)f[len+1][i]=0;
        for(int i=len;i>=1;i--){
            for(int j=1;j<=26;j++){
                f[i][j]=f[i+1][j];
            }
            f[i][str[i]-'a'+1]++;
        }
        cnt=0;
        for(int i=1;i<=26;i++){
            cin>>l[i]>>r[i];
            cnt+=l[i];
        }
        int now=1;
        string ans;
        int pos=1;
        while(r[now]==0)now++;
        for(int i=1;i<=len;i++){
            if(!check(now,i)){
                char ch=str[i-1];
                for(int j=pos;j<=i-1;j++){
                    if(str[j]!='a'+now-1&&str[j]<ch){
                        ans=str[j]+ans;
                        cnt++;
                        l[str[j]-'a'+1]--;
                        r[str[j]-'a'+1]--;
                    }
                }
            }
            if(r[now]>0&&str[i]=='a'+now-1){
                cnt++;
                r[now]--;
                l[now]--;
                ans+=str[i];
            }
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}