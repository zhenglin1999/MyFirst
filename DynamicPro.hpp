#pragma once
#include "primitives.hpp"
/* 
this function is used to solve coins Problems,
such as a specific amount can be divided into many parts.
*/
int count(int total, vector<int>& values)
{
	vector<int> dp(total + 1);
	dp[0] = 1;
	for (int i = 0; i < values.size(); i++)
	{
		for (int j = values[i]; j <= total; j++)
		{
			dp[j] = dp[j] + dp[j - values[i]];
		}
	}
	return dp[total];
}