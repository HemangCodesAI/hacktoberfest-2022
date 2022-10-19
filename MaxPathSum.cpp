class Solution {
public:
   int findMaxPathSum(TreeNode * root, int & maxi) {
  if (root == NULL) return 0;

  int leftMaxPath = max(0, findMaxPathSum(root -> left, maxi));
  int rightMaxPath = max(0, findMaxPathSum(root -> right, maxi));
  int value = root -> val;
  maxi = max(maxi, (leftMaxPath + rightMaxPath) + value);
  return max(leftMaxPath, rightMaxPath) + value;

}
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        findMaxPathSum(root , maxi);
        return maxi;
    }
};
