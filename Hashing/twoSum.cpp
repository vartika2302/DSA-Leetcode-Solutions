class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Brute force
        //Time complexity- O(n^2)
        // int n=nums.size();
        // vector<int>res;
        // for(int i=0;i<(n-1);i++){
        //     for(int j=(i+1);j<n;j++){
        //         if((nums[i]+nums[j])==target){
        //             res.push_back(i);
        //             res.push_back(j);
        //             goto end;
        //         }
        //     }
        // }
        // end:
        // return res;


        //Optimised approach
        //T.C. O(nlogn)+O(n)
        //S.C. O(n)
        // int n=nums.size();
        // vector<pair<int,int>>v;
        // vector<int>res;
        // for(int i=0;i<n;i++){
        //     v.push_back({nums[i],i});
        // }
        // sort(v.begin(),v.end());
        // int i=0,j=(n-1);
        // while(i<j){
        //     int curr=(v[i].first+v[j].first);
        //     if(curr==target){
        //         res.push_back(v[i].second);
        //         res.push_back(v[j].second);
        //         break;
        //     }
        //     else if(curr<target){
        //         i++;
        //     }
        //     else{
        //         j--;
        //     }
        // }
        // return res;


        //Optimal Approach
        //Time complexity- O(n)
        //Space complexity- O(n)
        //O(1) searching & O(1) inserting on average case
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<int>res;
        for(int i=0;i<n;i++){
            if(mp.find(target-nums[i])!=mp.end()){
                res.push_back(mp[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            else{
                mp[nums[i]]=i;
            }
        }
        return res;


    }
};
