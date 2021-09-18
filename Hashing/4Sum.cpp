class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        //Brute force
        //Time complexity-O(nlogn)+O((n^3)logn)
        //Space complexity-O(n)


        /********************************************************/
        //signed integer overflow
        // sort(nums.begin(),nums.end());
        // set<vector<int>>s;
        // int n=nums.size();
        // for(int i=0;i<(n-3);i++){
        //     for(int j=(i+1);j<(n-2);j++){
        //         int k=(j+1);
        //         int l=(n-1);
        //         while(k<l){
        //             int temp=(nums[i]+nums[j]);
        //             if((nums[k]+nums[l])==(target-temp)){
        //                 vector<int>v={nums[i],nums[j],nums[k],nums[l]};
        //                 s.insert(v);
        //                 k++;
        //                 l--;
        //             }
        //             else if(temp>target){
        //                 l--;
        //             }
        //             else{
        //                 k++;
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>>res;
        // for(auto x:s){
        //     res.push_back(x);
        // }
        // return res;


        /********************************************************/

        //Avoiding the duplicates (not checking for duplicates)
        //Optimal Solution
        //Time complexity-O(n^3)
        //Space complexity-O(1)
        int n=nums.size();
        vector<vector<int>>res;
        if(n<=3){
            return res;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=(i+1);j<n;j++){
                int target2=target-nums[i]-nums[j];
                int left=(j+1);
                int right=(n-1);
                while(left<right){
                    int two_sum=(nums[left]+nums[right]);
                    if(two_sum<target2){
                        left++;
                    }
                    else if(two_sum>target2){
                        right--;
                    }
                    else{
                        vector<int>quadruplet(4,0);
                        quadruplet[0]=nums[i];
                        quadruplet[1]=nums[j];
                        quadruplet[2]=nums[left];
                        quadruplet[3]=nums[right];
                        res.push_back(quadruplet);

                        //processing the duplicates of number 3
                        while(left<right && nums[left]==quadruplet[2])
                            left++;

                        //processing the duplicates of number 4
                        while(left<right && nums[right]==quadruplet[3]){
                            right--;
                        }
                    }
                }

                //Processing the duplicates of number 2
                while((j+1)<n && nums[j+1]==nums[j]){
                    j++;
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
