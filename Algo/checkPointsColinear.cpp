/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkPointsColinear(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2)
            return true;
        vector<int> p1, p2, p3;
        int x1,y1,x2,y2,x3,y3;
        int len = coordinates.size();
        for(int i=2;i<len;i++){
            p1 = coordinates.at(i-2);
            p2 = coordinates.at(i-1);
            p3 = coordinates.at(i);
            x1 = p1.at(0);
            y1 = p1.at(1);
            x2 = p2.at(0);
            y2 = p2.at(1);
            x3 = p3.at(0);
            y3 = p3.at(1);
            if(!(((y1 - y2) * (x1 - x3)) == ((y1 - y3) * (x1 - x2)))){
                return false;
            }
        }
        return true;
    }
};

/*
Formula used: All points on same line has same slope
https://stackoverflow.com/a/3813723/8494462
 */
int main()
{
    Solution sol;
    vector<vector<int>> v1{{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    cout<<sol.checkPointsColinear(v1)<<endl; // True

    vector<vector<int>> v2{{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
    cout<<sol.checkPointsColinear(v2)<<endl; // False
    return 0;
}