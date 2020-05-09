/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long int i=1;i*i<=num;i++){
            if(i*i==num)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution S;

    cout<<S.isPerfectSquare(16)<<endl; // True
    cout<<S.isPerfectSquare(14)<<endl; // False
    return 0;
}