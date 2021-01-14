#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string,int> dp;
public:
    int minOperations(vector<int>& nums, int x) {
        
        return fun(nums, x, 1, nums.size());
    }
    
    int valid(int d1, int d2, int x, int size){
        string ref;
        ref = to_string(d1)+"_"+to_string(d2);
        auto refVal = dp.find(ref);
        if(refVal!=dp.end()){
            // cout<<"refVal="<<refVal->second<<" d1="<<d1<<" d2="<<d2<<endl;
            return refVal->second;
        }
        else if(x==0){
            dp.insert(pair<string,int>(ref,0));
            // cout<<"zero, d1="<<d1<<" d2="<<d2<<endl;
            return 0;
        }
        else if(size==0){
            dp.insert(pair<string,int>(ref,-1));
            // cout<<"empty array, x="<<x<<" d1="<<d1<<" d2="<<d2<<endl;
            return -1;
        }
        else if(d1>d2){
            // cout<<"d1>d2, x="<<x<<" d1="<<d1<<" d2="<<d2<<endl;
            return -1;
        }
        return -2;
    }
    
    int fun(vector<int>& nums, int x, int d1, int d2){
        
        string ref;
        ref = to_string(d1)+"_"+to_string(d2);
        auto refVal = dp.find(ref);
        
        auto r = nums.end();
        r--;
        int f = nums[0];
        int l = *r;
        
        int left = INT_MAX;
        int right = INT_MAX;
        
        
        if(f<=x){
            nums.erase(nums.begin());
            
            int r = valid(d1+1,d2,x-f,nums.size());
            if(r==-2){
                left = fun(nums, x-f, d1+1,d2);
            }
            else{
                left=r;
            }
            
            if(left==-1){
                left = INT_MAX;
            }
            nums.insert(nums.begin(),f);
        }
        if(l<=x){
            nums.pop_back();
            int r = valid(d1,d2-1,x-l,nums.size());
            if(r==-2){
                right = fun(nums, x-l, d1,d2-1);
            }
            else{
                right=r;
            }
            
            if(right==-1){
                right = INT_MAX;
            }
            nums.push_back(l);
        }
        // cout<<"x="<<x<<" f="<<f<<" l="<<l<<" left="<<left<<" right="<<right<<" d1="<<d1<<" d2="<<d2<<endl;
        if(left==INT_MAX && right==INT_MAX){
            dp.insert(pair<string,int>(ref,-1));
            return -1;
        }
        int m = 1+min(left,right);
        dp.insert(pair<string,int>(ref,m));
        return m;
    }
};

int main()
{
    Solution S;
    std::vector<int> t;
    t.push_back(3);
    t.push_back(2);
    t.push_back(20);
    t.push_back(1);
    t.push_back(1);
    t.push_back(3);
    int x=10;
    cout << S.minOperations(t,x);
    return 0;
}