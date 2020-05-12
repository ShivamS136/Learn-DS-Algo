/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,unsigned int newColor) {
        unsigned int currColor = image.at(sr).at(sc);
        colorNode(image, sr, sc, currColor, newColor);
        return image;
    }
    
    void colorNode(vector<vector<int>>& image, int sr, int sc,unsigned int currColor,unsigned int newColor){
        unsigned int clr = image.at(sr).at(sc);
        
        if(clr != currColor) return;
        if(clr == newColor) return;
        if(0 > sr || sr>= image.size()) return;
        if(0 > sc || sc>= image[0].size()) return;
        image.at(sr).at(sc) = newColor;
        if(sr>0) colorNode(image, sr-1, sc, currColor, newColor);
        if(sc>0) colorNode(image, sr, sc-1, currColor, newColor);
        if(sc<image[0].size()-1) colorNode(image, sr, sc+1, currColor, newColor);
        if(sr<image.size()-1) colorNode(image, sr+1, sc, currColor, newColor);
        return;
    }
};

void printVect(vector<vector<int>> vec){
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = 0; j < vec[0].size(); ++j)
		{
			cout<<vec.at(i).at(j)<<" ";
		}
		cout<<endl;
	}
}

int main()
{
    Solution S;
    std::vector<vector<int>> v;
    std::vector<int> t;
    t.push_back(1);
    t.push_back(1);
    t.push_back(1);
    v.push_back(t);
    t.clear();
    t.push_back(1);
    t.push_back(1);
    t.push_back(0);
    v.push_back(t);
    t.clear();
    t.push_back(1);
    t.push_back(0);
    t.push_back(1);
    v.push_back(t);
    t.clear();
    printVect(S.floodFill(v, 1, 1, 2));
    return 0;
}