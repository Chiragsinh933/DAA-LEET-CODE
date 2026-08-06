/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = topRight = bottomLeft = bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = topRight = bottomLeft = bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf,
         Node* _topLeft,
         Node* _topRight,
         Node* _bottomLeft,
         Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* t1, Node* t2) {

        if (t1->isLeaf) {
            if (t1->val) return t1;
            return t2;
        }

        if (t2->isLeaf) {
            if (t2->val) return t2;
            return t1;
        }
        

        Node* tl = intersect(t1->topLeft, t2->topLeft);
        Node* tr = intersect(t1->topRight, t2->topRight);
        Node* bl = intersect(t1->bottomLeft, t2->bottomLeft);
        Node* br = intersect(t1->bottomRight, t2->bottomRight);

        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
            tl->val == tr->val &&
            tr->val == bl->val &&
            bl->val == br->val) {

            return new Node(tl->val, true);
        }

        return new Node(false, false, tl, tr, bl, br);
    }
};