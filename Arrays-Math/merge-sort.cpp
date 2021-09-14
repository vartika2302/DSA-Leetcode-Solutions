class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // vector<int>temp;
        // int i=0;
        // int j=0;
        // int k=0;
        // while(i<m && j<n){
        //     if(nums1[i]<=nums2[j]){
        //         temp[k++]=nums1[i++];
        //     }
        //     else{
        //         temp[k++]=nums2[j++];
        //     }
        // }
        // while(i<m){
        //     temp[k++]=nums1[i++];
        // }
        // while(j<n){
        //     temp[k++]=nums2[j++];
        // }
        // int si=temp.size();
        // for(int p=0;p<si;p++){
        //     nums1[p]=temp[p];
        // }

        /**************************************************************/

        //Time complexity- O(n*m)
        //Space complexity-O(1)

//         if(n!=0){
//             for(int i=0;i<m;i++){

//             if(nums1[i]>nums2[0]){
//                 swap(nums1[i],nums2[0]);
//                 int elem=nums2[0];
//                 int k;
//                 for(k=1;k<n && nums2[k]<elem;k++){
//                     nums2[k-1]=nums2[k];
//                 }
//                 nums2[k-1]=elem;
//             }

//         }
//         int i=m;
//         for(int j=0;j<n;j++){
//             nums1[i]=nums2[j];
//             i++;
//         }
//         }

        /***************************************************************/

        //Gap algorithm
        //gap=ceil((n1+n2)/2)
        //gap=gap/2 & so on until gap=1
        //Time complexity- O(nlog2(n))
        //Sapce complexity- O(1)


        /***************************************************************/
        //Time complexity- O(n+m)
        //Space complexity- O(1)
        int i=m-1;
        int j=n-1;
        int k=(m+n-1);
        while(i>=0 && j>=0){
            if(nums1[i]<=nums2[j]){
                nums1[k]=nums2[j];
                k--;
                j--;
            }
            else{
                nums1[k]=nums1[i];
                i--;
                k--;
            }
        }
        while(i>=0){
            nums1[k]=nums1[i];
            i--;
            k--;
        }
        while(j>=0){
            nums1[k]=nums2[j];
            j--;
            k--;
        }


    }
};
