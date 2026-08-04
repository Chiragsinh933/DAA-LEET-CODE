/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* build(vector<int>& nums, int start, int end) {
        if (start > end)
            return NULL;

        int maxIndex = start;
        for (int i = start; i <= end; i++) {
            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        TreeNode* root = new TreeNode(nums[maxIndex]);

        root->left = build(nums, start, maxIndex - 1);
        root->right = build(nums, maxIndex + 1, end);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};