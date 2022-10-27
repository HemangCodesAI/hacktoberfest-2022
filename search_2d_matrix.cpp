/*
Search an element in a row and column wise sorted matrix.
This matrix has the following properties:

- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

*/

class Solution {
public:
bool searchMatrix(vector<vector>& matrix, int target) {

    int rowsize=matrix.size();
    int colsize=matrix[0].size();
    int i=0, j=colsize-1;
    while(i>=0 && i<rowsize && j>=0 && j<colsize)
    {
        int arr=matrix[i][j];
        if(arr==target)
            return true;
       else if(arr>target)
            j--;
        else if(arr<target)
            i++;
    }

    return false;
 }
};
