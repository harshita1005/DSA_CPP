#include <iostream>

int main() {
    // Write C++ code here
    int arr[5]={3,9,7,8,5};
    int n=5;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                std::swap(arr[j],arr[j+1]);
            }
        }
    }
    
    for(int k=0;k<n;k++){
        std::cout<<arr[k]<<" ";
    }

    return 0;
}
