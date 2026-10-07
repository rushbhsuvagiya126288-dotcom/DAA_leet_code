class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;

        ListNode *slow = head, *fast = head, *prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) prev->next = nullptr;

        TreeNode* root = new TreeNode(slow->val);

        if (head != slow)
            root->left = sortedListToBST(head);

        root->right = sortedListToBST(slow->next);

        return root;
    }
};