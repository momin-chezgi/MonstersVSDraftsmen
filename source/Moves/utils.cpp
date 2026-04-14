
#include "innerFunctions.hpp"

intpair Im_hungry(vec2d(char)& grid,
                         intpair mnpos,
                          vec2d(int)& has_seen)
{
    vector<intpair> breadth1, breadth2;
    breadth1.push_back(mnpos);
    while(!breadth1.empty()){
        for(auto neigh : breadth1){
            if(grid[neigh.first][neigh.second] == 'D' || grid[neigh.first][neigh.second] == 'd' || grid[neigh.first][neigh.second] == 'Z'){
                return neigh;
            }
            int x = neigh.first;
            int y = neigh.second;
            if(has_seen[x][y]==1) continue;
            has_seen[x][y] = 1;
            if(grid[x+1][y]==' ') breadth2.push_back({x+2,y});
            if(grid[x][y+1]==' ') breadth2.push_back({x,y+2});
            if(grid[x-1][y]==' ') breadth2.push_back({x-2,y});
            if(grid[x][y-1]==' ') breadth2.push_back({x,y-2});
        }
        breadth1 = breadth2;
        breadth2.clear();
    }
    return {-1,-1};
}


