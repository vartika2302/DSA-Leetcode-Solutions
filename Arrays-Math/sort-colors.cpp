class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Counting sort

        // int freq[3]={0};
        // for(int i=0;i<nums.size();i++){
        //     freq[nums[i]]++;
        // }
        // int j=0;
        // for(int i=0;i<3;i++){
        //     while(freq[i]--){
        //         nums[j]=i;
        //         j++;
        //     }
        // }

        //Without using any algo-inplace
        //Dutch National Flag Algorithm
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
