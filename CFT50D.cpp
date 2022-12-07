#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int r,c;
bool vis[4000+100][6100]={};
int ans=0;
struct po{
	int x;int y;int val;
};
unordered_map<int,int>mpp[4100];
queue<po>que;
int stx,sty,endx,endy;
int wei[10][2]={{-3,1},{-3,-1},{3,1},{3,-1},{0,2},{0,-2}};
int bfs(int a,int b){
	int head=0;
	int tail=0;
	po f,ff;
	f.x=a;
	f.y=b;
	f.val=1;
	que.push(f);
	vis[a][b]=true;
	while(!que.empty()){
		f=que.front();
        que.pop();
		int x=f.x;
		int y=f.y;
		if(x<=0||x>r)continue;
		if(y<=0||y>c)continue;
		int val=f.val;
		if(x==endx&&y==endy)return val;
		int i;
		for(i=0;i<=5;i++){
			int xx=x+wei[i][1];
			int yy=y+wei[i][0];
			if(xx<=0||xx>r)continue;
			if(yy<=0||yy>c)continue;
			if(mpp[xx][yy]==false)continue;
			xx+=wei[i][1];
			yy+=wei[i][0];
            if(xx<=0||xx>r)continue;
			if(yy<=0||yy>c)continue;
			if(!vis[xx][yy]){
				vis[xx][yy]=true;
				f.x=xx;
				f.y=yy;
				f.val=val+1;
                que.push(f);
			}
		}
	}
	return -1;
}
int main(void){
	ios::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		string str;
		ans=99999999;
		cin>>r>>c;
		r=4*r+3;
        c=6*c+3;
		int i;
		for(i=0;i<=r;i++)mpp[i].clear();
		getchar();
		for(i=1;i<=r;i++){
            str.clear();
			getline(cin,str);
            while(str.size()<c){
                str+=' ';
            }
			str=" "+str;
			int j;
			for(j=1;j<str.size();j++){
				if(str[j]=='S')stx=i,sty=j;
				if(str[j]=='T')endx=i,endy=j;
			}
			if(i%4==1){
				int cnt=5;
				for(j=1;j<str.size();j++){
					cnt--;
					if(cnt==0){
						cnt=12;
						if(str[j]==' ')mpp[i][j]=true;
						else mpp[i][j]=false;
					}
				}
			}
			else if(i%4==2){
				int cnt=2;
				for(j=1;j<str.size();j++){
					cnt--;
					if(cnt==0){
						cnt=6;
						if(str[j]==' ')mpp[i][j]=true;
						else mpp[i][j]=false;
					}
				}
			}
			else if(i%4==3){
				int cnt=11;
				for(j=1;j<str.size();j++){
					cnt--;
					if(cnt==0){
						cnt=12;
						if(str[j]==' ')mpp[i][j]=true;
						else mpp[i][j]=false;
					}
				}
			}
			else{
				int cnt=2;
				for(j=1;j<str.size();j++){
					cnt--;
					if(cnt==0){
						cnt=6;
						if(str[j]==' ')mpp[i][j]=true;
						else mpp[i][j]=false;
					}
				}
			}
		}
		int j;
		for(i=0;i<=r;i++){
			for(j=0;j<=c;j++){
				vis[i][j]=false;
			}
		}
		ans=bfs(stx,sty);
		cout<<ans<<'\n';
		cout.flush();
        //system("pause");
	}
	
}
