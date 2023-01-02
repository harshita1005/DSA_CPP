#include <iostream>

int main() {
    // Write C++ code here
    int arr[5]={3,9,7,8,5};
    int n=5;
    for(int i=1;i<n;i++){
        int j=i-1;
        int temp=arr[i];
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
    
    
    for(int k=0;k<n;k++){
        std::cout<<arr[k]<<" ";
    }

    return 0;
}
