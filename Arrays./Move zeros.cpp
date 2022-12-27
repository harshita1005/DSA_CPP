//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        

        int i=0;       //single pointer to swap the jth element from array
        for(int j=0;j<nums.size();j++){

            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
            
        }
    }
};
