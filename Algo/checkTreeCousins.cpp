/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.
 */
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int parx=-1, pary=-1, depx=-1,depy=-1;
        findInTree(root,0,-1,x,y,&parx,&pary, &depx, &depy);
        if(depx==depy && depx!=-1 && parx!=pary){
            return true;
        }
        return false;
    }
    bool findInTree(TreeNode* root, int dep, int par, int x, int y, int *parx, int* pary, int* depx, int* depy){
        if(root->val == x){
            *parx = par;
            *depx = dep;
        }
        if(root->val == y){
            *pary = par;
            *depy = dep;
        }
        if((*depy!=-1 && *depx!=-1) || *depx==0 || *depy==0){
            return true;
        }
        bool foundBoth=false;
        
        if(root->left != NULL){
            foundBoth = findInTree(root->left,dep+1,root->val,x,y,parx,pary,depx,depy);
        }
        if(!foundBoth && root->right != NULL){
            foundBoth = findInTree(root->right,dep+1,root->val,x,y,parx,pary,depx,depy);
        }
        return foundBoth;
    }
};

/*
            1
    2              3
^       4       5       6
 */
int main()
{
    Solution sol;
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    TreeNode n2(2, NULL, &n4);
    TreeNode n3(3, &n5, &n6);
    TreeNode n1(1, &n2, &n3);

    cout<<sol.isCousins(&n1, 5, 4)<<endl; // True
    cout<<sol.isCousins(&n1, 2, 5)<<endl; // False
    cout<<sol.isCousins(&n1, 1, 6)<<endl; // False
    return 0;
}