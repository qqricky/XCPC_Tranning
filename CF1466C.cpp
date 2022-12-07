#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int pos[27];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(pos,0,sizeof(pos));
        string str;
        cin>>str;
        int n=str.length();
        str=' '+str;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(pos[str[i]-'a'+1]!=0&&i-pos[str[i]-'a'+1]==2){
                cnt++;
            }
            else if(pos[str[i]-'a'+1]!=0&&pos[str[i]-'a'+1]==i-1){
                cnt++;
                //cout<<"Wwwww"<<endl;
            }
            else{
                pos[str[i]-'a'+1]=i;
            }
        }
        cout<<cnt<<endl;
    }
    //system("pause");
    return 0;
}