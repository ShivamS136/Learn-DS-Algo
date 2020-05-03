/*
Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1 

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.

Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1018
Example:
Input
2
4
1 3 2 4
4
4 3 2 1
Output
3 4 4 -1
-1 -1 -1 -1

Explanation:
Testcase1: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist hence -1.
 */
#include<bits/stdc++.h>
using namespace std;

void nextLarger(int arr[],int len){
	stack <int> val;
	stack <int> ind;
	int op[len], j;

	val.push(arr[0]);
	ind.push(0);

	for (int i = 1; i < len; ++i)
	{
		if (val.empty())
		{
			val.push(arr[i]);
			ind.push(i);
			continue;
		}

		while(!val.empty() && val.top()<arr[i]){
			j = ind.top();
			val.pop();
			ind.pop();
			op[j]=arr[i];
		}
		val.push(arr[i]);
		ind.push(i);
	}
	while(!val.empty()){
		j = ind.top();
		val.pop();
		ind.pop();
		op[j]=-1;
	}
	for (int i = 0; i < len; ++i)
	{
		cout<<op[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int len;
	int arr[] = {4,3,2,1};
	len = sizeof(arr)/sizeof(arr[0]);
	nextLarger(arr,len);
	int arr2[] = {1,3,2,4};
	len = sizeof(arr2)/sizeof(arr2[0]);
	nextLarger(arr2,len);
	int arr3[] = {1,8,2,4};
	len = sizeof(arr3)/sizeof(arr3[0]);
	nextLarger(arr3,len);
	
	return 0;
}