#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
struct men
{
    string name;
    int rank;
}a[55],b[55];
int pos1,pos2;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    pos1=pos2=0;
    int num[100]={};
    string sm[100];
    for(int i=1;i<=n;i++){
        int tmp;
        string str;
        cin>>tmp>>str;
        num[i]=tmp;
        sm[i]=str;
        if(tmp==0){
            a[++pos1].name=str;
            a[pos1].rank=i;
        }
        else{
            b[++pos2].name=str;
            b[pos2].rank=i;
        }
    }
    int v[105]={};
    for(int i=1;i<=n;i++){
        if(!v[i]){
            if(num[i]){
                cout<<sm[i]<<' ';
                v[i]=1;
                for(int j=pos1;j>=1;j--){
                    if(!v[a[j].rank]){
                        v[a[j].rank]=1;
                        //cout<<a[j].rank<<endl;
                        cout<<a[j].name<<endl;
                        break;
                    }
                }
            }
            else{
                cout<<sm[i]<<' ';
                v[i]=1;
                for(int j=pos2;j>=1;j--){
                    if(!v[b[j].rank]){
                        v[b[j].rank]=1;
                        cout<<b[j].name<<endl;
                        break;
                    }
                }
            }
        }
    }
    //system("pause");
    return 0;
}