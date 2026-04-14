#include "innerFunctions.hpp"

void earthquake(vec2d(char)& grid, vector<draftsman>& draftsman,vector<intpair>& mnpos, int remain_dr){
    srand(time(0));
    for(int d=0; d<remain_dr; d++){
        int newx = draftsman[d].x, newy = draftsman[d].y;
        if(draftsman[d].winned || draftsman[d].defeated) continue;
        
        vector<intpair> neighs;
        if(grid[newx][newy+1] == ' '){
            if(grid[newx][newy+2] == ' ') neighs.push_back({newx, newy+2});
        }
        if(grid[newx-1][newy] == ' '){
            if(grid[newx-2][newy] == ' ') neighs.push_back({newx-2, newy});
        }
        if(grid[newx][newy-1] == ' '){
            if(grid[newx][newy-2] == ' ') neighs.push_back({newx, newy-2});
        }
        if(grid[newx+1][newy] == ' '){
            if(grid[newx+2][newy] == ' ') neighs.push_back({newx+2, newy});
        }
        
        if(neighs.empty()) continue;
        
        int i = rand()%neighs.size();
        auto neigh = neighs[i];
        char a = 'D';
        if(grid[draftsman[d].x][draftsman[d].y] == 'Z') a = 'Z';
        grid[draftsman[d].x][draftsman[d].y] = ' ';
        grid[neigh.first][neigh.second] = a;
        draftsman[d].x = neigh.first, draftsman[d].y = neigh.second;
    }

    for(int mn=0; mn<mnpos.size(); mn++){
        int newx = mnpos[mn].first, newy = mnpos[mn].second;
        vector<intpair> neighs;
        if(grid[newx][newy+1] == ' '){
            if(grid[newx][newy+2] == ' ') neighs.push_back({newx, newy+2});
        }
        if(grid[newx-1][newy] == ' '){
            if(grid[newx-2][newy] == ' ') neighs.push_back({newx-2, newy});
        }
        if(grid[newx][newy-1] == ' '){
            if(grid[newx][newy-2] == ' ') neighs.push_back({newx, newy-2});
        }
        if(grid[newx+1][newy] == ' '){
            if(grid[newx+2][newy] == ' ') neighs.push_back({newx+2, newy});
        }
        if(neighs.empty()) continue;
        
        int i = rand()%neighs.size();
        auto neigh = neighs[i];
        grid[mnpos[mn].first][mnpos[mn].second] = ' ';
        grid[neigh.first][neigh.second] = 'M';
        mnpos[mn].first = neigh.first, mnpos[mn].second = neigh.second;
    }
}
