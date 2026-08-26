class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty())
            return NULL;

        int n = postorder.size();

        TreeNode* root = new TreeNode(postorder[n - 1]);

        int pos = 0;
        while (inorder[pos] != postorder[n - 1])
            pos++;

        vector<int> leftIn(inorder.begin(), inorder.begin() + pos);
        vector<int> rightIn(inorder.begin() + pos + 1, inorder.end());

        vector<int> leftPost(postorder.begin(), postorder.begin() + pos);
        vector<int> rightPost(postorder.begin() + pos, postorder.end() - 1);

        root->left = buildTree(leftIn, leftPost);
        root->right = buildTree(rightIn, rightPost);

        return root;
    }
};