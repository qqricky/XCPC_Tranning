#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
char c;
int i,j,k,num,stat,flag;
string words,program;
vector<string> sign;
vector<int> Num;
int scan(string pro){//扫描输入的字符串 
	vector <string> KeyWord;
	KeyWord.push_back("int");
	KeyWord.push_back("void");
	KeyWord.push_back("break");
	KeyWord.push_back("float");
	KeyWord.push_back("while");
	KeyWord.push_back("do");
	KeyWord.push_back("struct");
	KeyWord.push_back("const");
	KeyWord.push_back("case");
	KeyWord.push_back("for");
	KeyWord.push_back("return");
	KeyWord.push_back("if");
	KeyWord.push_back("default");
	KeyWord.push_back("else");
	num=0;
	stat=0;
	words.clear();
	c=pro[i];
	if(c>='a'&&c<='z'){
		while(c>='a'&&c<='z'||c>='0'&&c<='9'){
			words.push_back(c);
			i++;
			c=pro[i]; 
		}
		for(int t=0;t<14;t++){//关键字表目前有14个关键字 
			if(words==KeyWord[t]){
				stat=1;
				flag=t+1;
			}
		}
		if(stat==0){
			flag=100;
		}
		i--;
	}
	else if(c<='9'&&c>='0'){
		num=0;
		while(c<='9'&&c>='0'){
			num=num*10+(c-'0');
			i++;
			c=pro[i];
		}
		flag=200;
		i--;
		for(int m=0;m<Num.size();m++){
			if(Num[m]==num) flag+=m+1;
		}
		if(flag==200)Num.push_back(num); 
	}
	else switch(c){//界符表 
		case '=':
			words.push_back(c);
			if(pro[i+1]=='='){
				i++;
				words.push_back('=');
				flag=305;
			} 
			else flag=311;
			break;
		case '-':
			words.push_back(c);
			flag=301;
			break;
		case '/': 
			words.push_back(c);
			flag=302; 
			break;
		case '(':
			words.push_back(c);
			flag=303;
			break;
		case ')':
			words.push_back(c);
			flag=304;
			break;
		case '<':
			words.push_back(c);  
			if(pro[i+1]=='='){
				i++;
				words.push_back(c);
				flag=306; 
			}
			else flag=307;
			break;
		case '+':
			words.push_back(c); 
			if(pro[i+1]=='+'){
				i++;
				words.push_back('+');
				flag=314; 
			}	 
			else flag=308;
			break;
		case '*': 
			words.push_back(c);
			flag=309; 
			break;
		case '>':
			words.push_back(c);
			flag=310;
			break;
		case ',':
			words.push_back(c);
			flag=312;
			break;
		case ';':
			words.push_back(c);
			flag=313;
			break;
		case '{':
			words.push_back(c);
			flag=315;
			break;
		case '}':
			words.push_back(c);
			flag=316;
			break;	
	}
	i++;
	if(flag==100){
		if(pro[i]<='9'&&pro[i]>='0'){
			c=pro[i];
			while(c<='9'&&c>='0'){
				words.push_back(c);
				i++;
				c=pro[i]; 
			}
		}
		for(int m=0;m<sign.size();m++){
			if(sign[m]==words) flag+=m+1;
		}
		if(flag==100) sign.push_back(words); 
	}
	return flag;
}
int main(){
// 	freopen("TestCase.in","r",stdin);
// freopen("TestCase.out","w",stdout);
	i=0;
	char x;
//	fstream fp;
//	fp.open("111.txt");
	// while(x=getchar(),x!='\n'){
	// 	program.push_back(x);
	// }
	getline(cin, program);
	cout<<"Token :";
	int p=1,q=1;
	do{
		flag=scan(program);
		if(flag>=1&&flag<=14){
			cout<<"(K "<<flag<<")";
		}
		if(flag>=100&&flag<180){
			if(flag==100) cout<<"(I "<<p++<<")";
			else cout<<"(I "<<flag-100<<")";
		}
		if(flag>=200&&flag<300){
			if(flag==200) cout<<"(C "<<q++<<")";
			else cout<<"(C "<<flag-200<<")";
		}
		if(flag<=316&&flag>=301){
			cout<<"(P "<<flag-300<<")"; 
		}
	}while(i<program.size());
	cout<<endl;
	cout<<"I :";
	cout<<sign[0];
	for(int m=1;m<sign.size();m++){
		cout<<" "<<sign[m];
	} 
	cout<<endl<<"C :";
	cout<<Num[0];
	for(int m=1;m<Num.size();m++){
		cout<<" "<<Num[m];
	}
}
