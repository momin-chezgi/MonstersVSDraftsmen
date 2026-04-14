
#include "classes.hpp"

void Node::find(vec2d(cell)& grid) {
    if (xp == x && yp == y) return;  // Already root
    int rootx = x, rooty = y;
    while (xp != rootx || yp != rooty) {
        rootx = xp;
        rooty = yp;
        xp = grid[xp][yp].xp;
        yp = grid[xp][yp].yp;
    }
    // Now compress path: set this node's parent directly to root
    this->xp = rootx;
    this->yp = rooty;
}
bool Node::unite(Node* n1, Node* n2, vec2d(cell)& grid) {
    n1->find(grid);
    n2->find(grid);
    int root2_x = n2->xp;
    int root2_y = n2->yp;
    if (n1->xp != root2_x || n1->yp != root2_y) {
        grid[root2_x][root2_y].xp = n1->xp;
        grid[root2_x][root2_y].yp = n1->yp;
        return true;
    } else {
        return false;
    }
}
