/*
Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

Input:
The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |s| ≤ 105

Example:
Input:
3
{([])}
()
([]

Output:
balanced
balanced
not balanced
*/
#include<bits/stdc++.h>
using namespace std;

string checkParanthesis(string str){
	int ind = -1;
	int len = str.length();
	char stack[len];
	for (int i = 0; i < len; ++i)
	{
		if(str[i] == '{' || str[i]=='(' || str[i]=='['){
			ind++;
			stack[ind]=str[i];
		}
		else{
			if(str[i]==')'){
				if(stack[ind] != '('){
					return "not balanced";
				}
				else{
					--ind;
				}
			}
			else if(str[i]=='}'){
				if(stack[ind] != '{'){
					return "not balanced";
				}
				else{
					--ind;
				}
			}
			else if(str[i]==']'){
				if(stack[ind] != '['){
					return "not balanced";
				}
				else{
					--ind;
				}
			}
		}
	}
	if(ind==-1)
		return "balanced";
	else
		return "not balanced";
}

int main()
{
	string str = "[()]{}{[()()]()}";
	cout << checkParanthesis(str);
	return 0;
}