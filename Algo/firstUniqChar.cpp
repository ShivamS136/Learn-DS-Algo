/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
 */
#include<bits/stdc++.h>
using namespace std;
#define TOTAL_CHARS 256

class Solution {
public:
    int firstUniqChar(string s) {
        struct tab
        {
        	int cnt=0;
        	int pos=-1;
        };
        tab dict[TOTAL_CHARS];
        for (int i = 0; i < s.length(); ++i)
        {
        	(dict[s[i]].cnt)++;
        	if(dict[s[i]].pos<0)
        		dict[s[i]].pos=i;
        }
        int result=INT_MAX;
        bool found=false;
        for (int i = 0; i < TOTAL_CHARS; ++i)
        {
        	if(dict[i].cnt==1 && dict[i].pos<result){
        		result=dict[i].pos;
        		found=true;
        	}
        }
        return found?result:-1;
    }
};

int main()
{
	Solution S;
	string str ="loveleetcode";
	cout<<S.firstUniqChar(str);
	return 0;
}