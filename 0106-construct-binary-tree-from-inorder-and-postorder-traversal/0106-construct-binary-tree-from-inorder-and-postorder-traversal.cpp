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
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int start, int end) {

        if (start > end)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postIndex--]);

        int pos;
        for (int i = start; i <= end; i++) {
            if (inorder[i] == root->val) {
                pos = i;
                break;
            }
        }

        root->right = build(inorder, postorder, pos + 1, end);
        root->left = build(inorder, postorder, start, pos - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        postIndex = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};