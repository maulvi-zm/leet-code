/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0){
            return nullptr;
        }
        
        int middle = nums.size() / 2;

        TreeNode* root = new TreeNode(nums[middle]);

        vector<int> leftVec(nums.begin(), nums.begin() + middle);
        vector<int> rightVec(nums.begin() + middle + 1, nums.end());
        TreeNode* left = sortedArrayToBST(leftVec);
        TreeNode* right = sortedArrayToBST(rightVec);

        root->right = right;
        root->left  = left;

        return root;
    }
};