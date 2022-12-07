#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;

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
        string str1,str2;
        cin>>str1>>str2;
        string ans1,ans2;
        ans1+=str1[0];
        for(int i=1;i<str1.length();i++){
            if(str1[i]!=str1[i-1]){
                ans1+=str1[i];
            }
        }
        ans2+=str2[0];
        for(int i=1;i<str2.length();i++){
            if(str2[i]!=str2[i-1]){
                ans2+=str2[i];
            }
        }
        if(ans1==ans2)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    //system("pause");
    return 0;
}
