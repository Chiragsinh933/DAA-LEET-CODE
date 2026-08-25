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
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
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

    Node* solve(vector<vector<int>>& grid, int r, int c, int size) {

        // Check if all values are same
        bool same = true;

        for(int i = r; i < r + size; i++) {
            for(int j = c; j < c + size; j++) {

                if(grid[i][j] != grid[r][c]) {
                    same = false;
                    break;
                }
            }

            if(!same)
                break;
        }

        // If all values are same
        if(same) {
            return new Node(grid[r][c], true);
        }

        // Divide into 4 parts
        int half = size / 2;

        Node* root = new Node(true, false);

        root->topLeft =
            solve(grid, r, c, half);

        root->topRight =
            solve(grid, r, c + half, half);

        root->bottomLeft =
            solve(grid, r + half, c, half);

        root->bottomRight =
            solve(grid, r + half, c + half, half);

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {

        int n = grid.size();

        return solve(grid, 0, 0, n);
    }
};