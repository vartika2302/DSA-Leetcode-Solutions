class Solution {
public:

    int findDuplicate(vector<int>& nums) {
         //naive approach
    //Time complexity-O(nlogn),Space complexity-O(1)

        // int ans;
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // for(int i=0,j=(i+1);i<(n-1),j<n;i++,j++){
        //     if(nums[i]==nums[j]){
        //         ans=nums[i];
        //         break;
        //     }
        // }
        // return ans;

        //Optimised approach
    //time complexity-O(n), Space complexity-O(n)

//         int ans;
//         int n=nums.size();
//         vector<int>freq(n,0);
//         for(int i=0;i<n;i++){
//             freq[nums[i]]++;
//             if(freq[nums[i]]>=2){
//                 ans=nums[i];
//                 break;
//             }
//         }

//         return ans;

        //Optimal approach
        //using fast & slow pointers
        //Time complexity-O(n),Space complexity-O(1)
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        fast=nums[0];
        while(fast!=slow){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
