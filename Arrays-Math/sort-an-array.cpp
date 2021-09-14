class Solution {
public:
    void merge(vector<int>&nums,int low,int mid,int high){
        int i=low;
        int j=mid+1;
        int k=0;
        vector<int>ans(high-low+1);
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                ans[k++]=nums[i++];
            }
            else{
                ans[k++]=nums[j++];
            }
        }
        while(i<=mid){
            ans[k++]=nums[i++];
        }
        while(j<=high){
            ans[k++]=nums[j++];
        }
        for(int p=0;p<k;p++){
            nums[low+p]=ans[p];
        }
    }

    void mergeSort(vector<int>&nums,int low,int high){
        if(low>=high){
            return;
        }
        int mid=(low+high)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }


//     void merge(vector<int>& nums, int l, int m, int r){
//         vector<int> tmp(r - l + 1);
//         int i = l; // index for left subarray
//         int j = m + 1; // index for right subarray
//         int k = 0; // index for temporary array
//         while(i <= m && j <= r){
//             if(nums[i] <= nums[j]) tmp[k++] = nums[i++];
//             else tmp[k++] = nums[j++];
//         }
//         while(i <= m) tmp[k++] = nums[i++];
//         while(j <= r) tmp[k++] = nums[j++];
//         for(i = 0; i < k; i++) nums[l + i] = tmp[i];
//     }

// 	// mergeSort(nums, 0, nums.size() - 1);
//     void mergeSort(vector<int>& nums, int l, int r){
//         if(l >= r) return;
//         int m = l + (r - l) / 2; //middle index, same as (l+r)/2
//         mergeSort(nums, l, m);
//         mergeSort(nums, m + 1, r);
//         merge(nums, l, m, r);
//     }

};
