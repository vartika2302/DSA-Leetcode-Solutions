/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?



Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
Example 4:

Input: nums = [0]
Output: 1
Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1]. 1 is the missing number in the range since it does not appear in nums.

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        //Brute force approach
        //T.C. O(nlogn)+O(n)
        //S.C. O(1)
        // sort(nums.begin(),nums.end());
        // int ans=-1;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]!=i){
        //         ans=i;
        //         break;
        //     }
        // }
        // if(ans==-1){
        //     ans=n;
        // }
        // return ans;



        //Optimised approach
        //T.C. O(n)+O(n)
        //S.C. O(n)

        // int n=nums.size();
        // vector<int>temp(n+1,0);
        // for(int i=0;i<n;i++){
        //     temp[nums[i]]=1;
        // }
        // int ans;
        // for(int i=0;i<(n+1);i++){
        //     if(temp[i]==0){
        //         ans=i;
        //         break;
        //     }
        // }
        // return ans;

        //Optimal approach-1(sum approach)
        //T.C. O(n)
        //S.C. O(1)
        int n=nums.size();
        int initial_sum=(n*(n+1))/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return initial_sum-sum;

        //Optimal approach-2()

    }
};
