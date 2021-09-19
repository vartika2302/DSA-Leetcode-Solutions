class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code 
        //Naive solution-O(n^3) ,generate all the subarrays and then check
        //Space complexity-O(1)
        // int maxi=INT_MIN;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int sum=0;
        //         for(int k=i;k<=j;k++){
        //             sum+=A[k];
        //         }
        //         int t_max=(j-i+1);
        //         if(sum==0 && t_max>maxi){
        //             maxi=t_max;
        //         }
        //     }
        // }
        // return maxi;
        
        
        //Optimsed approach
        //Time complexity-O(n^2)
        //Space complexity-O(1)
        // int maxi=INT_MIN;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=A[j];
        //         if(sum==0 && (j-i+1)>maxi){
        //             maxi=(j-i+1);
        //         }
        //     }
        // }
        // return maxi;
        
        
        //Optimal approach
        //Time complexity-O(nlogn)
        //Space complexity-O(n)
        map<int,int>mp;
        int maxi=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                maxi=(i+1);
            }
            else{
                if(mp.find(sum)!=mp.end()){
                    maxi=max(maxi,i-mp[sum]);
                }
                else{
                    mp[sum]=i;
                }
            }
        }
        return maxi;
    }
};
