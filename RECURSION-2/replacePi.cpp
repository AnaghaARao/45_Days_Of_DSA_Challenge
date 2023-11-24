#include<bits/stdc++.h>
using namespace std;

void replacePi(char a[]) {
	string s = a;
    // base case:
    if(s.size()<=1) return;

    // induction step
	if(a[0]=='p' && a[1]=='i'){
		 string temp = s.substr(2);
		 a[0]='3';a[1]='.';a[2]='1';a[3]='4';
		 for(int i = 0; i<temp.size();i++) a[4+i] = temp[i];
		 //recursive call
    	replacePi(a+4);
	}
	else replacePi(a+1);


    // int x = s.find_first_of("pi");
	//
	// cout<<s<<" "<<temp<<endl;
	// a[x]='3';a[x+1]='.';a[x+2]='1';a[x+3]='4';
	// for(int i = 0; i<temp.size();i++) a[x+4+i] = temp[i];


    // a[x] = '3';
    // a[x+1] = '.';
    // for(int i = s.size()+1; i>=x+2;i--){
    //     a[i] = a[i-2];
    // }
    // a[x+3] = '1';
    // s[x+4] = '4';
