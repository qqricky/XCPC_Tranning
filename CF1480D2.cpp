#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10; 
using namespace std;
int a[N];
int num[N];
int pos[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int val1=0,val2=0;
    int pos1=0,pos2=0;
    int ans=0;
    pos[0]=n+1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        num[a[i]]=n+1;
    }
    for(int i=n;i>=1;i--){
        pos[i]=num[a[i]];
        num[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==val1&&a[i]!=val2){
            pos1=i;
        }
        else if(a[i]==val2&&a[i]!=val1){
            pos2=i;
        }
        // else if(a[i]==val1&&a[i]==val2){
        //     pos1=pos2=i;
        // }
        else {
            if(pos[pos1]>=pos[pos2]){val1=a[i];pos1=i;}
            else {val2=a[i];pos2=i;}
            ans++;
        }
    }
    cout<<ans;
    //system("pause");
    return 0;
}