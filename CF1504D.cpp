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
    int n;
    cin>>n;
    int lev1=1;
    int lev2=1;
    int pos1=1;
    int pos2=2;
    int x;
    int flag=1;
    int val;
    for(int i=1;i<=n*n;i++){
        cin>>x;
        if(flag&&x!=1){
            cout<<1<<' '<<lev1<<' '<<pos1<<endl;
            pos1+=2;
            if(pos1>n){
                lev1++;
                if(lev1&1)pos1=1;
                else pos1=2;
            }
            if(lev1>n){
                val=2;//odd
                flag=0;
            }
        }
        else if(flag&&x!=2){
            cout<<2<<' '<<lev2<<' '<<pos2<<endl;
            pos2+=2;
            if(pos2>n){
                lev2++;
                if(lev2&1)pos2=2;
                else pos2=1;
            }
            if(lev2>n){
                val=1;//even
                flag=0;
            }
        }
        else{
            if(val==1){
                if(x!=1){
                    cout<<1<<' '<<lev1<<' '<<pos1<<endl;
                    pos1+=2;
                    if(pos1>n){
                        lev1++;
                        if(lev1&1)pos1=1;
                        else pos1=2;
                    }
                }
                else{
                    cout<<3<<' '<<lev1<<' '<<pos1<<endl;
                    pos1+=2;
                    if(pos1>n){
                        lev1++;
                        if(lev1&1)pos1=1;
                        else pos1=2;
                    }
                }
            }
            else{
                if(x!=2){
                    cout<<2<<' '<<lev2<<' '<<pos2<<endl;
                    pos2+=2;
                    if(pos2>n){
                        lev2++;
                        if(lev2&1)pos2=2;
                        else pos2=1;
                    }
                }
                else{
                    cout<<3<<' '<<lev2<<' '<<pos2<<endl;
                    pos2+=2;
                    if(pos2>n){
                        lev2++;
                        if(lev2&1)pos2=2;
                        else pos2=1;
                    }
                }
            }
        }
    }
    //system("pause");
    return 0;
}