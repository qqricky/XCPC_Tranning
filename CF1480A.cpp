#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        if(str.length()==1){
            if(str[0]=='a')cout<<'b'<<endl;
            else cout<<'a'<<endl;
        }
        else{
            for(int i=0;i<str.size();i++){
                if(i%2==0){
                    if(str[i]=='a')str[i]='b';
                    else str[i]='a';
                }
                else{
                    if(str[i]=='z')str[i]='y';
                    else str[i]='z';
                }
            }
            cout<<str<<endl;
        }

    }
    //system("pause");
    return 0;
}