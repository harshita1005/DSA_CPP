class Solution {
public:

    int getpivot(vector<int>&nums,int n){

        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;

        while(s<e){
            //pivot lies in first line
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return s;
    }

    int binarysearch(vector<int>&nums,int s,int e,int target){
        int start=s;
        int end=e;
        int middle=start+(end-start)/2;
        while(start<=end){
            if(target==nums[middle]){
                return middle;
            }
            else if(target>nums[middle]){
                start=middle+1;
            }
            else if(target<nums[middle]){
                end=middle-1;
            }
            middle=start+(end-start)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        int pivot=getpivot(nums,n);

        if(nums[pivot] <= target && target <=nums[n-1]){
            //Binary search on second line
           return binarysearch(nums,pivot,n,target);
        }
        else{
            //binary search on first line
             return binarysearch(nums,0,pivot,target);
        }
    }
    
};
