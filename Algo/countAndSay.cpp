// https://www.geeksforgeeks.org/look-and-say-sequence/
#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n){
	if(n==1)
		return "1";
	if(n==2)
		return "11";

	string prev="11";
	for (int i = 3; i <= n; ++i)
	{
		string temp="";
		int len=prev.length();
		char prevChar=prev[0];
		int prevCnt=1;
		for (int j = 1; j < len; ++j)
		{
			if(prev[j]==prevChar){
				prevCnt++;
			}
			else{
				temp += to_string(prevCnt)+prevChar;
				prevChar=prev[j];
				prevCnt=1;
			}
		}
		temp += to_string(prevCnt)+prevChar;
		prev=temp;
	}
	return prev;
}

int main()
{
	for (int i = 1; i <= 10; ++i)
	{
		cout<<countAndSay(i)<<endl;
	}
	return 0;
}