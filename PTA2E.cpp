#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
struct s
{
    string name;
    int x;
}stu[10000];
bool cmp(s a, s b)
{
    return a.x>b.x;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,g,k;
    cin>>n>>g>>k;
    string str;
    int tot=0;
    for(int i=1;i<=n;i++){
        cin>>stu[i].name>>stu[i].x;
        if(stu[i].x>=g)tot+=50;
        else if(stu[i].x>=60)tot+=20;
    }
    sort(stu+1,stu+n+1,cmp);
    int pos=1;
    cout<<tot<<endl;
    int cnt=1;
    cout<<1<<' '<<stu[1].name<<' '<<stu[1].x<<endl;
    for(int i=2;i<=k;i++){
        if(stu[i].x<stu[i-1].x){
            pos+=cnt;
            cnt=1;
        }
        else{
            cnt++;
        }
        cout<<pos<<' '<<stu[i].name<<' '<<stu[i].x<<endl;
    }
    for(int i=k+1;i<=n;i++){
        if(stu[i].x==stu[i-1].x){
            cout<<pos<<' '<<stu[i].name<<' '<<stu[i].x<<endl;
        }
        else{
            break;
        }
    }
    //system("pause");
    return 0;
}