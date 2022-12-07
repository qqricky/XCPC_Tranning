#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10; 
using namespace std;
int a[N];
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
        string str;
        cin>>str;
        queue<int>q;
        queue<int>q2;
        int cnt=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='1'){
                if(q.empty()){
                    q2.push(++cnt);
                    a[i]=cnt;
                }
                else{
                    a[i]=q.front();
                    q.pop();
                    q2.push(a[i]);
                }
            }
            else{
                if(q2.empty()){
                    q.push(++cnt);
                    a[i]=cnt;
                }
                else{
                    a[i]=q2.front();
                    q2.pop();
                    q.push(a[i]);
                }
            }
        }
        cout<<cnt<<"\n";
        for(int i=0;i<n-1;i++)cout<<a[i]<<' ';
        cout<<a[n-1]<<"\n";
    }
    //system("pause");
    return 0;
}