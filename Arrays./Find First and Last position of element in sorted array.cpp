//Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
//If target is not found in the array, return [-1, -1].
//You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    int firstoccur(vector<int>arr, int n,int target){

        int s=0,e=n-1;
        int ans=-1;
        int mid=s+(e-s)/2;
        while(s<=e){

            if(arr[mid]==target){
                ans=mid;
                e=mid-1;      //left most occurrence
            }
            else if(target>arr[mid]){       //right side
                s=mid+1;
            } 
            else if(target<arr[mid]){
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }


    int lastoccur(vector<int>arr, int n,int target){

        int s=0,e=n-1;
        int ans=-1;
        int mid=s+(e-s)/2;
        while(s<=e){

            if(arr[mid]==target){
                ans=mid;
                s=mid+1;      //right most occurrence
            }
            else if(target>arr[mid]){       //right side
                s=mid+1;
            } 
            else if(target<arr[mid]){
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
 

    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>ans(2);
        int n=nums.size();

        ans[0]=firstoccur(nums,n,target);
        ans[1]=lastoccur(nums,n,target);

        return ans;
        
    }
};
