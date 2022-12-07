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
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int a[3],b[3];
        cin>>a[1]>>a[2]>>b[1]>>b[2];
        if(a[1]<=b[1]&&a[2]>=b[2]){
            cout<<a[1]<<' '<<b[2]<<endl;
        }
        else if(a[1]>=b[1]&&a[2]<=b[2]){
            cout<<a[2]<<' '<<b[1]<<endl;
        }
        else if(a[2]<=b[1]){
            cout<<a[1]<<' '<<b[2]<<endl;
        }
        else if(a[1]<=b[1]){
                cout<<a[1]<<' '<<b[2]<<endl;
        }
        else{
            cout<<a[2]<<' '<<b[1]<<endl;
        }
    }
    //system("pause");
    return 0;
}