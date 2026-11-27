
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {

        // Case 1: First node is a leaf
        if (quadTree1->isLeaf) {
            return quadTree1->val ? quadTree1 : quadTree2;
        }

        // Case 2: Second node is a leaf
        if (quadTree2->isLeaf) {
            return quadTree2->val ? quadTree2 : quadTree1;
        }

        // Case 3: Recursively merge four children
        Node* topLeft = intersect(
            quadTree1->topLeft,
            quadTree2->topLeft
        );

        Node* topRight = intersect(
            quadTree1->topRight,
            quadTree2->topRight
        );

        Node* bottomLeft = intersect(
            quadTree1->bottomLeft,
            quadTree2->bottomLeft
        );

        Node* bottomRight = intersect(
            quadTree1->bottomRight,
            quadTree2->bottomRight
        );

        // Case 4: Check whether all four children are equal leaves
        if (topLeft->isLeaf &&
            topRight->isLeaf &&
            bottomLeft->isLeaf &&
            bottomRight->isLeaf &&
            topLeft->val == topRight->val &&
            topRight->val == bottomLeft->val &&
            bottomLeft->val == bottomRight->val) {

            return new Node(topLeft->val, true);
        }

        // Case 5: Create an internal node
        return new Node(
            true,
            false,
            topLeft,
            topRight,
            bottomLeft,
            bottomRight
        );
    }
};
