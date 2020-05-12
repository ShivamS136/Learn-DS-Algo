/*

 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int mid = (start+end)/2;
        
        while(mid!=start){
            if(mid%2 != 0){// 1,3,5
                if(nums[mid] == nums[mid-1]){
                    start=mid+1;
                }
                else{
                    end=mid;
                }
            }
            else{ // 0,2,4,6
                if(mid>0){ 
                    if(nums[mid] != nums[mid-1]){
                        start=mid;
                    }
                    else{
                        end=mid-1;
                    }
                }
                else if(nums.size()>1){
                    if(nums[mid] != nums[mid+1]){
                        break;
                    }
                }
            }
            
            mid = (start+end)/2;
        }
        return nums[mid];
    }
};

int main()
{
    Solution S;

    std::vector<int> vec{1,1,2,3,3,4,4,8,8}; 
    cout<<S.singleNonDuplicate(vec)<<endl; // 2

    std::vector<int> vec1{3,3,7,7,10,11,11};
    cout<<S.singleNonDuplicate(vec1)<<endl; // 10

    std::vector<int> vec2{1,1,2};
    cout<<S.singleNonDuplicate(vec2)<<endl; // 2
    return 0;
}