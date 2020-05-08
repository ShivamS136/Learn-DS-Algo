/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 
 */
#include<bits/stdc++.h>
using namespace std;
#define MIN_BAD_VER 3

class Solution {
public:
    long int firstBadVersion(long int n) {
        long int s=1,e=n,m;
        while(1){
            m = (s+e)/2;
            if(isBadVersion(m)){
                if(m==s){
                    return s;
                }
                e=m;
            }
            else{
                if(m==s){
                    return e;
                }
                s=m;
            }
        }
    }
    bool isBadVersion(long int m){
    	return m<MIN_BAD_VER?false:true;
    }
};

int main()
{
	Solution S;
	long int n=5;
	cout<<S.firstBadVersion(n);
	return 0;
}