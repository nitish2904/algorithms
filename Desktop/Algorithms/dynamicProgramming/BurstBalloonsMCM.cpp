#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/burst-balloons/
int maxCoins(vector<int>& nums) {
	int n = nums.size();
	if(n == 0)
		return 0;
	nums.emplace_back(1);
	n += 1;
	vector<vector<int>> dp(n,vector<int>(n));

	for(int len = 2; len <= n; len++){
		for(int left = 0; left < n-len+1; left++){
			int right = left+len-1;
			for(int k = left; k < right; k++){
				int temp = dp[left][k] + dp[k+1][right];
				temp += left == 0 ? nums[k]*nums[right] : nums[left-1]*nums[k]*nums[right];
				dp[left][right] = max(temp,dp[left][right]);
			}
		}
	}
	return dp[0][n-1];
}

int main(){
  int n;
  vector<int>nums(n);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>nums[i];
  }
  cout<< maxCoins(nums);
  return 0;
}
