#Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.


class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int>m;            //to store the frequency of each num
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            int b= k - arr[i];             //pairs of 2 num a+b=k  --> b= k-a
            if(m[b]){                      //will check if that num is already there in map if there then add its freq count to ans
               ans += m[b];
            }
            m[arr[i]]++;                  //if not present in map increment the number frequency
        }
        return ans;
        
    }
};
