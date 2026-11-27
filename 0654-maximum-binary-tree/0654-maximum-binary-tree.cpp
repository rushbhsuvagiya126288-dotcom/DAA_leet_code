
class Solution {
public:

    TreeNode* build(vector<int>& nums, int left, int right) {

        // Base case
        if (left > right) {
            return nullptr;
        }

        // Find maximum element
        int maxIndex = left;

        for (int i = left; i <= right; i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // Create root node
        TreeNode* root = new TreeNode(nums[maxIndex]);

        // Build left subtree
        root->left = build(nums, left, maxIndex - 1);

        // Build right subtree
        root->right = build(nums, maxIndex + 1, right);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        return build(nums, 0, nums.size() - 1);
    }
};
