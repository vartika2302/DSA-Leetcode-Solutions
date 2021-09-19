//unordered map in worst case take O(n) time complexity in searching.

//{4,2,2,6,4}
//target=6

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;

    //Naive Solution
    /*int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xors=0;
            for(int k=i;k<=j;k++){
                xors^=arr[k];
            }
            if(xors==target){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    */


    //Optimised Solution
    /*int cnt=0;
    for(int i=0;i<n;i++){
        int xors=0;
        for(int j=i;j<n;j++){
            xors^=arr[j];
            if(xors==target){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    */


    //Optimal Solution
    //Time complexity-O(nlogn)
    //Space complexity-O(n)

    map<int,int>freq;
    int cnt=0;
    int xors=0;
    for(auto it:arr){
        xors^=it;
        if(xors==target){
            cnt++;
        }
        if(freq.find(xors^target)!=freq.end()){
            cnt+=freq[xors^target];
        }
        freq[xors]++;
    }
    cout<<cnt<<endl;


    return 0;
}
