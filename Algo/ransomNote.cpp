/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
canConstruct("", "") -> true
canConstruct("fab", "buffalo") -> true
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> dict;
        map<char,int>::iterator it;
        char tempChar;
        int len = ransomNote.length();
        if(len==0){
            return true;
        }
        for(int i=0;i<len;++i){
            tempChar = ransomNote[i];
            it = dict.find(tempChar);
            if(it != dict.end()){
                it->second = ++it->second;
            }
            else{
                dict.insert(std::pair<char,int>(tempChar,1));
            }
        }
        
        for(int i=0; i<magazine.length();i++){
            tempChar = magazine[i];
            it = dict.find(tempChar);
            if(it != dict.end()){
                if(it->second>0){
                    it->second = --it->second;
                    --len;
                    if(len==0){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
	Solution sol;
	cout<<sol.canConstruct("a","b")<<endl; // false
	cout<<sol.canConstruct("","")<<endl; // true
	cout<<sol.canConstruct("ab","aba")<<endl; // true
	cout<<sol.canConstruct("aa","ab")<<endl; // false
	cout<<sol.canConstruct("fab","buffalo")<<endl; // true
	return 0;
}