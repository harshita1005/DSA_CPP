//Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
 


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        

        int row=matrix.size();         //will give the total rows in 2D matrix
        int col=matrix[0].size();        //will give the number of columns in 2D matrix

        int rowindex=0;
        int colindex=col-1;

        if(matrix.size() == 0)  return false;

       while(rowindex < row && colindex >=0){

           int element=matrix[rowindex][colindex];

           if(target==element){
               return 1;
           }

           if(element  < target){
               rowindex++;
           }
           else{
            colindex--;
            }

       }
         return 0;
       }
};
