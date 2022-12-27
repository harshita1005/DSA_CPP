//Given an array, rotate the array to the right by k steps, where k is non-negative.

#include<iostream>
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        //creating a temp to store the ans to avoid overwrite if we use num to store
       vector<int>temp(nums.size());

       for(int i=0;i<nums.size();i++){

           //we have a formula to rotate  arr[(i+k)%n]=arr[i]
           temp[(i+k) % nums.size()] = nums[i];
       }
       nums=temp;

    }
};
