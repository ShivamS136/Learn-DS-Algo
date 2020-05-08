/*
N one dimensional kingdoms are represented as intervals of the form [ai , bi] on the real line. A kingdom of the form [L, R] can be destroyed completely by placing a bomb at a point x on the real line if L ≤ x ≤ R.

Your task is to determine minimum number of bombs required to destroy all the one dimensional kingdoms.

Input
First line of the input contains T denoting number of test cases.
For each test case, first line contains N denoting the number of one dimensional kingdoms.
For each next N lines, each line contains two space separated integers ai and bi.
Output
For each test case , output an integer denoting the minimum number of bombs required.

Constraints
Subtask 1 (20 points) : 1 ≤ T ≤ 100 , 1 ≤ N ≤ 100 , 0 ≤ ai ≤ bi ≤500

Subtask 2 (30 points) : 1 ≤ T ≤ 100 , 1 ≤ N ≤ 1000 , 0 ≤ ai ≤ bi ≤ 1000

Subtask 3 (50 points) : 1 ≤ T ≤ 20 , 1 ≤ N ≤ 105, 0 ≤ ai ≤ bi ≤ 2000

Example
Input:
1
3
1 3
2 5
6 9

Output:
2

Problem: https://www.codechef.com/submit/ONEKING
Solution: https://www.codechef.com/viewsolution/32881898
 */
#include <bits/stdc++.h>
using namespace std;

/*
INPUT:
1
7
8 9
2 6
1 3
7 8
3 4
5 6
4 8

OUTPUT:
3
 */
int main() {
    int T;
    long int N;
    int a,b;
    scanf("%d", &T);
    for (int t = 0; t < T;  t++) {
        scanf("%ld",&N);
        vector<pair<int, int>> arr;
        for (int i = 0; i < N; i++) {
            scanf("%d %d",&a,&b);
            arr.push_back(make_pair(a,b));
        }
       sort(arr.begin(), arr.end());
       
       long int bomb=1;
       pair<int,int> temp;
       long int start=arr.at(0).first, end=arr.at(0).second;
       for (int i = 1; i < N; i++) {
           temp = arr.at(i);
           if(temp.first<=end){
               start=temp.first;
               if(temp.second<=end){
                   end = temp.second;
               }
           }
           else{
               bomb++;
               start = temp.first;
               end = temp.second;
           }
       }
       printf("%ld\n",bomb);
    }
    
    return 0;
}
