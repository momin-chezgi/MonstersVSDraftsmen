#include "innerFunctions.hpp"

void magic_transfer(vector<intpair>& mnpos, vec2d(char)& grid){
    int x, y;
    int newx = x, newy = y;
    cout << "Magic Transport! Write the coordinate of the monster that you want to move him(splitted by space):";
    cin >> x >> y;
    x = 2*x-1, y = 2*y-1;
    int mnid = coor2id4monster(x,y,mnpos);
    while(mnid==-1){
        cout << "Try again!(splitted by space):";
        cin >> x >> y;
        x = 2*x-1, y = 2*y-1;
        mnid = coor2id4monster(x,y,mnpos);
    }
    newx = x, newy = y;
    while(newx==x && newy==y){
        cout << "In which direction?(W/A/S/D) ";
        char move;
        cin >> move;
        switch(move){
            case 'W':
            case 'w':
                newx -= 2;
                break;
            case 'A':
            case 'a':
                newy -= 2;
                break;
            case 'S':
            case 's':
                newx += 2;
                break;
            case 'D':
            case 'd':
                newy += 2;
                break;
            default:
                cout << "Invalid move! Please enter W, A, S, or D." << endl;
                newx = x;
                newy = y;
        }
        
        //check if the player wants to go out of bounds
        if(newx < 1 || newx >= 2*n || newy < 1 || newy >= 2*m){
            cout << "Move out of bounds! Try again." << endl;
            newx = x;
            newy = y;
            continue;
        }
        
        // check if the move is blocked by a wall
        if(grid[(x + newx)/2][(y + newy)/2] == '#'){
            cout << "Cell blocked by a wall! Try again." << endl;
            newx = x;
            newy = y;
            continue;
        }

        // check if there aren't any monsters or draftsmen in the new position
        if(grid[newx][newy] == 'M'){
            cout << "Sorry! every room hasn't got the place for you both. Try again." << endl;
            newx = x;
            newy = y;
        }
    }
    grid[x][y] = ' ';
    grid[newx][newy] = 'M';
    mnpos[mnid].first = newx, mnpos[mnid].second = newy;
}