class Solution {
public:


    int longestConsecutive(vector<int>& nums) {
        //fast
        //Brute Force
    //Time complexity-O(nlogn)+O(n)
    //Space complexity-O(1)

        // if(nums.size()==0){
        //     return 0;
        // }
        // sort(nums.begin(),nums.end());
        // int maxCount=1;
        // int currCount=1;
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i]!=nums[i-1]){
        //         if(nums[i]==nums[i-1]+1){
        //         currCount++;
        //     }
        //     else{
        //         maxCount=max(maxCount,currCount);
        //         currCount=1;
        //     }
        //     }
        // }
        // return max(maxCount,currCount);


        //Optimal Solution
        //Time complexity-O(3*n)
        //Space complexity-O(n)

        int n=nums.size();
        if(n==0){
            return 0;
        }
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int maxCount=1;

        for(int i=0;i<n;i++){
            if(s.count(nums[i]-1)==0){
                int currCount=1;
                while(s.count(nums[i]+1)){
                    nums[i]=nums[i]+1;
                    currCount++;
                }
                maxCount=max(maxCount,currCount);
            }
        }
        return maxCount;
    }
};
