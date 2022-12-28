//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

//You may assume that each input would have exactly one solution, and you may not use the same element twice.

//You can return the answer in any order.


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
        vector<int>arr(2);        //because we want only 1 pair
    
    int n= nums.size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<n;j++)
        {
        if(i==j){
            continue;
        }
            
        if((nums[i]+nums[j])==target)
        {
            
            arr[0]=i;
            arr[1]=j;
            return arr;
        }
        }
    }
    return arr;
	
    }
};
