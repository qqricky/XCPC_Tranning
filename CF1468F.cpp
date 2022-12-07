#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        map<double,int>num;
        map<double,int>num2;
        int n;
        cin>>n;
        long long ans=0;
        long long x,y,z,w;
        int ver1=0,ver2=0;
        for(int i=1;i<=n;i++){
            cin>>x>>y>>z>>w;
            if(x==z){
                if(y>w){
                    ans+=num[1e9+1];
                    num2[1e9+1]++;
                }
                else{
                    ans+=num2[1e9+1];
                    num[1e9+1]++;
                }
                continue;
            }
            double k=(double)(w-y)/(z-x);
            if(w>y){
                ans+=num2[k];
                num[k]++;
            }
            else if(w<y){
                ans+=num[k];
                num2[k]++;
            }
            else{
                if(z>x){
                    ans+=num2[0];
                    num[0]++;
                }
                else{
                    ans+=num[0];
                    num2[0]++;
                }
            }
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}