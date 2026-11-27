
class Solution {
public:

    vector<int> values;

    // Step 1: Inorder traversal
    void inorder(TreeNode* root) {

        if (root == nullptr) {
            return;
        }

        inorder(root->left);

        values.push_back(root->val);

        inorder(root->right);
    }

    // Step 2: Build balanced BST
    TreeNode* build(int left, int right) {

        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(values[mid]);

        root->left = build(left, mid - 1);

        root->right = build(mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {

        // Get sorted values
        inorder(root);

        // Construct balanced BST
        return build(0, values.size() - 1);
    }
};
