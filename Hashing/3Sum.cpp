class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Brute Force
        //Time complexity-O(n*n*logn)
        //Space complexity-O(n)
        //TLE
        // int n=nums.size();
        // set<vector<int>>s;
        // vector<vector<int>>res;
        // sort(nums.begin(),nums.end());
        // if(n==0){
        //     return res;
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=(i+1);j<n;j++){
        //         int target=0-(nums[i]+nums[j]);
        //         int st=(j+1);
        //         int en=(n-1);
        //         while(st<=en){
        //             int mid=(st+en)/2;
        //             if(nums[mid]>target){
        //                 en--;
        //             }
        //             else if(nums[mid]<target){
        //                 st++;
        //             }
        //             else{
        //                 s.insert({nums[i],nums[j],nums[mid]});
        //                 st++;
        //                 en--;
        //             }
        //         }
        //     }
        // }
        // for(auto x:s){
        //     res.push_back(x);
        // }
        // return res;


        //Optimal Solution
        //Time complexity-O(n^2)
        //Space complexity-O(1)
        int n=nums.size();
        vector<vector<int>>res;
        if(n==0){
            return res;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int left=(i+1);
            int right=(n-1);
            int target=(0-nums[i]);
            while(left<right){
                int sum=(nums[left]+nums[right]);
                if(sum>target){
                    right--;
                }
                else if(sum<target){
                    left++;
                }
                else{
                    vector<int>triplet(3,0);
                    triplet[0]=nums[i];
                    triplet[1]=nums[left];
                    triplet[2]=nums[right];
                    res.push_back(triplet);

                    //Processing the duplicates of number 3
                    while(left<right && nums[right]==triplet[2]){
                        right--;
                    }

                    //Processing the duplicates of number 2
                    while(left<right && nums[left]==triplet[1]){
                        left++;
                    }
                }
            }
            //Processing the duplicates of number 1
            while((i+1)<n && nums[i+1]==nums[i]){
                i++;
            }
        }
        return res;
    }
};
