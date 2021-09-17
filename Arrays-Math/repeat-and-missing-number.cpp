/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and
smallest positive missing number is 1.
Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and
smallest positive missing number is 2.
*/

class Solution{

public:

    int *findTwoElement(int *arr, int n) {

        // code here
        //Optimsed approach
        //Time complexity-O(2*n)
        //Space complexity-O(n)
        // int*temp=new int[n+1];
        // for(int i=0;i<n;i++){
        //     temp[arr[i]]++;
        // }
        // int *res=new int[2];
        // for(int i=1;i<=n;i++){
        //     if(temp[i]==2){
        //         res[0]=i;
        //     }
        //     else if(temp[i]==0){
        //         res[1]=i;
        //     }
        // }
        // return res;

        //Two optimal solutions
        //Solution-1
        //Using sum property- but it has certain restrictions as for
        //storing sum of squares we need a long long data type;
        //Time complexity-O(n)
        //Space complexity-O(1)
        // int *res=new int[2];
        // int m,r;
        // long long int sumlinear=0,sumquad=0;
        // for(int i=0;i<n;i++){
        //     sumlinear+=arr[i];
        // }
        // for(int i=0;i<n;i++){
        //     sumquad+=(arr[i]*arr[i]);
        // }
        // long long int originallinear=(n*(n+1))/2;
        // long long int originalquad=(n*(n+1)*((2*n)+1))/6;

        // long long int s1=originallinear-sumlinear;
        // long long int s2=originalquad-sumquad;

        // m=((s1/2)+(s2/(2*s1)));
        // r=m-s1;

        // res[0]=r;
        // res[1]=m;
        // return res;

        //Optimal approach-2
        //Time complexity-O(5*n)
        int xors=0;
        for(int i=0;i<n;i++){
            xors^=arr[i];
        }
        for(int i=1;i<=n;i++){
            xors^=i;
        }
        int rsb=xors&-xors;


        int set=0,notset=0;
        for(int i=0;i<n;i++){
            if((arr[i]&rsb)==1){
                set=set^arr[i];
            }
            else{
                notset=notset^arr[i];
            }
        }
        for(int i=1;i<=n;i++){
            if((arr[i]&rsb)==0){
                notset=notset^i;
            }
            else{
                set=set^i;
            }
        }

        int*res=new int[2];
        for(int i=0;i<n;i++){
            if(arr[i]==set){
               res[0]=set;
               res[1]=notset;
               break;
            }
            else if(arr[i]==notset){
                res[0]=notset;
                res[1]=set;
                break;
            }
        }

        return res;


    }
};
