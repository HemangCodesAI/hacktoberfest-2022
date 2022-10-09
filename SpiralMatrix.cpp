class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) 
    {
       vector<int>v;
       int top=0,left=0,bottom=mat.size()-1,right=mat[0].size()-1;
       //t top = 0, left = 0, bottom = R - 1, right = C - 1;

	while(top <= bottom && left <= right)
	{
		for(int i = left; i <= right; i++)
			v.push_back(mat[top][i]);

		top++;

		for(int i = top; i <= bottom; i++)
			v.push_back(mat[i][right]);
		
		right--;

		if(top <= bottom){
		for(int i = right; i >= left; i--)
			v.push_back(mat[bottom][i]);

		bottom--;
		}

		if(left <= right){
		for(int i = bottom; i >= top; i--)
			v.push_back(mat[i][left]);

		left++;
		}			
	} return v;
    }
};
