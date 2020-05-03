/*
https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

Given a value V, if we want to make change for V cents, and we have infinite supply of each of 
C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change?

Examples:

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents
 */
#include<bits/stdc++.h> 
using namespace std;
int coinChange(int coins[], int len, int sum){
	int tab[sum+1];
	tab[0] = 0;
	for (int i = 1; i < sum+1; ++i)
	{
		tab[i] = INT_MAX;
	}

	for (int i = 1; i <= sum; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			if(coins[j]<=i){
				int prevCnt = tab[i - coins[j]];
				if (prevCnt != INT_MAX && prevCnt+1<tab[i])
				{
					tab[i] = prevCnt+1;
				}
			}
		}
	}
	return tab[sum];
}

int main()
{
	int coins[] = {9,6,5,1};
	int len = sizeof(coins)/sizeof(coins[0]);
	int sum=11;
	cout << "Minimum coins required: "
		<< coinChange(coins, len, sum);
	return 0;
}