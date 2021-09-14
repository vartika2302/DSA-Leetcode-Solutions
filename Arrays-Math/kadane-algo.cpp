class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Naive approach-O(n^3)

//         int maxsum=INT_MIN;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 int sum=0;
//                 for(int k=i;k<=j;k++){
//                     sum+=nums[k];
//                 }
//                 maxsum=max(sum,maxsum);
//             }
//         }

//         return maxsum;


        /*********************************************************/

        //Optimised approach-O(n^2)
        // int n=nums.size();
        // int maxsum=INT_MIN;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         maxsum=max(sum,maxsum);
        //     }
        // }
        // return maxsum;

        /*********************************************************/

        //Optimal approach-O(n)
        //Kadane's algorithm
        int n=nums.size();
        int currsum=0;
        int maxsum=nums[0];
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            if(currsum>maxsum){
                maxsum=currsum;
            }
            if(currsum<0){
                currsum=0;
            }
        }
        return maxsum;
    }
};
