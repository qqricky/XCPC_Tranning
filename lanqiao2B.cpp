#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=60*60*24;i++){
        long double shi=i*1.0/(3600*24)*360;
        long double fen=(i%(60*60))*1.0/3600.0*360;
        long double miao=(i%60)*1.0/60.0*360;
        if(fabs(fabs(fen-shi)-2*fabs(miao-fen))<=1e-2){
            cout<<shi<<' '<<fen<<' '<<miao<<'\n';
            cout<<i/60/60<<' '<<(i%3600)/60<<' '<<i%60<<'\n';
        }
    }
    cout.flush();
    system("pause");
    return 0;
}