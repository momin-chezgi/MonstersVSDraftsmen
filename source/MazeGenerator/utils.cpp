#include "innerFunctions.hpp"

int fix_the_wrong_walls(int i1, int j1, int direction){
    if (i1 == 0)
    {
        if (j1 == 0 && (direction == 1 || direction == 2))
        {
            direction == 1 ? direction = 0 : direction = 3;
        }
        else if (j1 == n - 1 && (direction == 0 || direction == 1))
        {
            direction == 0 ? direction = 2 : direction = 3;
        }
        else
        {
            if (direction == 1)
                direction = 3;
        }
    }

    if (i1 == n - 1)
    {
        if (j1 == 0 && (direction == 2 || direction == 3)){
            direction == 2 ? direction = 0 : direction = 1;
        }
        else if (j1 == n - 1 && (direction == 0 || direction == 3))
        {
            direction == 0 ? direction = 2 : direction = 1;
        }
        else
        {
            if (direction == 3)
                direction = 1;
        }
    }

    if (j1 == 0 && direction == 2)
    {
        direction = 0;
    }

    if (j1 == m - 1 && direction == 0)
    {
        direction = 2;
    }
    return direction;
}

intpair where_is_the_neighbor(int i, int j, int direction){
    switch(direction){
        case 0: //right
            if(j!=m-1)return {i, j+1};
            break;
        case 1: //up
            if(i!=0) return {i-1, j};
            break;
        case 2: //left
            if(j!=0)return {i, j-1};
            break;
        case 3: //down
            if(i!=n-1)return {i+1, j};
            break;
        default:
            return {-1,-1};
    }
    return {-1, -1}; // should not reach here
}


void remove_dots(vec2d(char)& shown_grid){
    for(int i=1; i<2*n; i++){
        for(int j=1; j<2*m; j++){
            if(i%2==j%2) continue;
            if(shown_grid[i][j] == '.')shown_grid[i][j] = ' ';
        }
    }
}


bool are_there_no_enemy_nearby(vec2d(char) & shown_grid, int i, int j, char cell_type){
    char enemy;
    cell_type == 'D' ? enemy = 'M' : enemy = 'D';
    int ni = i;
    int nj = j;
    if(i > 0){ // up
        ni = i -1;
        if(shown_grid[2*ni +1][2*nj +1] == enemy) return false;
    }
    ni = i;
    if(i < n-1){ // down
        ni = i +1;
        if(shown_grid[2*ni +1][2*nj +1] == enemy) return false;
    }
    ni = i;
    if(j > 0){ // left
        nj = j -1;
        if(shown_grid[2*ni +1][2*nj +1] == enemy) return false;
    }
    nj = j;
    if(j < m-1){ // right
        nj = j +1;
        if(shown_grid[2*ni +1][2*nj +1] == enemy) return false;
    }
    return true;
}

