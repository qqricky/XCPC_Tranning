#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
using namespace std;
char ch[N];
char ans1[N];
char ans2[N];
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
        int n;
        cin>>n;
        int tot=0;
        for(int i=1;i<=n;i++){
            cin>>ch[i];
            tot+=ch[i]-'0';
        }
        if(tot&1||ch[1]=='0'){
            cout<<"NO"<<endl;
            continue;
        }
        int num1=0;
        int num2=0;
        int flag=1;
        int fl=1;
        int sum=tot/2;
        for(int i=1;i<=n;i++){
            if(ch[i]=='1'){
                if(sum>0){
                    sum--;
                    num1++;
                    num2++;
                    ans1[i]='(';
                    ans2[i]='(';
                }
                else{
                    num1--;
                    num2--;
                    ans1[i]=')';
                    ans2[i]=')';
                }
                if(num1<0||num2<0){
                    flag=0;
                    break;
                }
            }
            else{
                if(fl){
                    fl=1-fl;
                    num1++;
                    num2--;
                    ans1[i]='(';
                    ans2[i]=')';
                }
                else{
                    fl=1-fl;
                    num1--;
                    num2++;
                    ans1[i]=')';
                    ans2[i]='(';
                }
                if(num1<0||num2<0){
                    flag=0;
                    break;
                }
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)cout<<ans1[i];
            cout<<endl;
            for(int i=1;i<=n;i++)cout<<ans2[i];
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    //system("pause");
    return 0;
}