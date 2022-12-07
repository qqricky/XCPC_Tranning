#include <bits/stdc++.h>
#define ll long long
const int N=1e9+10; 
using namespace std;
ll cnt=N;
void goo(int a,int b,int pos){
    if(a!=0&&pos>=cnt)return;
    if(a==0){
        cnt=pos;
        return;
    }
    if(b==1){
        goo(a,b+1,pos+1);
    }
    else{
        goo(a/b,b,pos+1);
        goo(a,b+1,pos+1);
    }
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
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        cnt=N;
        goo(a,b,0);
        cout<<cnt<<endl;
    }
    //system("pause");
    return 0;
}