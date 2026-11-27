
class Solution {
public:

    unordered_map<int, int> pos;

    TreeNode* build(vector<int>& preorder,
                    vector<int>& postorder,
                    int preStart,
                    int postStart,
                    int n) {

        // Base case
        if (n == 0) {
            return nullptr;
        }

        // Create root
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Only one node
        if (n == 1) {
            return root;
        }

        // Find left subtree root in postorder
        int leftRoot = preorder[preStart + 1];

        int index = pos[leftRoot];

        // Calculate left subtree size
        int leftSize = index - postStart + 1;

        // Build left subtree
        root->left = build(
            preorder,
            postorder,
            preStart + 1,
            postStart,
            leftSize
        );

        // Build right subtree
        root->right = build(
            preorder,
            postorder,
            preStart + leftSize + 1,
            index + 1,
            n - leftSize - 1
        );

        return root;
    }

    TreeNode* constructFromPrePost(
        vector<int>& preorder,
        vector<int>& postorder) {

        int n = preorder.size();

        // Store postorder positions
        for (int i = 0; i < n; i++) {
            pos[postorder[i]] = i;
        }

        return build(preorder, postorder, 0, 0, n);
    }
};
