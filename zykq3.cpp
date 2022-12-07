#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
struct BST{
    int val,balanceFac;
    BST* lchlild;
    BST* rchlild;
}nd[N];
//计算该节点高度,O(n),n为子树大小
int getHeight(BST* bt){
    int hl,hr;
    if(bt==&nd[0])return 0;
    else{
        hl=getHeight(bt->lchlild);
        hr=getHeight(bt->rchlild);
    }
    if(hl>hr)return hl+1;
    else return hr+1;
}
void calcBalance(BST* bt){
    if(bt==&nd[0])return;
    calcBalance(bt->lchlild);
    calcBalance(bt->rchlild);
    int hl=getHeight(bt->lchlild);
    int hr=getHeight(bt->rchlild);
    bt->balanceFac=hl-hr;
}
BST* buildTree(){
    cout<<"please enter the size of this BST"<<endl;
    //默认1为根节点;
    int n;
    cin>>n;
    cout<<"For every node please enter the index of its lson and rson.enter 0 if it dosen't have son"<<endl;
    for(int i=1;i<=n;i++){
        int ls,rs;
        cin>>ls>>rs;
        // cout<<l<<" "<<r<<endl;
        // cout<<"so waht "<<endl;
        nd[i].lchlild=&nd[ls];
        nd[i].rchlild=&nd[rs];
        nd[i].val=rand();
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    // ios_base::sync_with_stdio(false); 
    // cin.tie(0);
    // cout.tie(0);
    buildTree();
    calcBalance(&nd[1]);
    for(int i=1;i<=5;i++){
        cout<<"Node No."<<i<<"with an BalanceFactor or"<<nd[i].balanceFac<<endl;
    }
    cout.flush();
    //system("pause");
    return 0;
}