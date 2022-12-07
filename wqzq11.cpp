#include <iostream> 
#include <string>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string a[n];
    cin.get();
    for(int i=0;i<n;i++)
    {
    	getline(cin,a[i]);
    }
    for(int i=0 ;i<n;i++) 
    {
        string text =a[i];
        istringstream iss(text);
        vector<string> results((istream_iterator<string>(iss)),istream_iterator<string>());
        int num = results.size();// 
        //cout<<num<<endl;
        for(int p=0;p<num;p++)
        {
            int length =results[p].length(); 
            //cout<<length<<endl;
            for(int j = 0;j<length/2;j++)
            {
                char temp;
                temp=results[p][j];
                results[p][j]=results[p][length-j-1];
                results[p][length-j-1]=temp; 
            }
        }
        for(int q = 0;q<num;q++)
        {
    	    cout<<results[q]<<' ';	   
        }
        cout<<endl;
    }
    system("pause");
}   


