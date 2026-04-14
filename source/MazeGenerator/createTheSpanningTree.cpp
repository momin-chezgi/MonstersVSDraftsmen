#include "innerFunctions.hpp"

void create_the_spanning_tree(vec2d(cell) &grid, intpair light_source_pos,
    vec2d(int) &connected, vec2d(char) &shown_grid){
    vector<cell*> check_list;
    check_list.push_back(&grid[light_source_pos.first][light_source_pos.second]);

    while(!check_list.empty()){
        int list_size = check_list.size();
        srand(time(0));
        int idx = rand() % list_size;
        cell* current = check_list[idx];

        // remove current from check_list
        check_list.erase(check_list.begin() + idx);

        // explore neighbors
        for(int direction = 0; direction < 4; direction++){
            intpair neighbor_pos = where_is_the_neighbor(current->x, current->y, direction);
            
            // if not connected and is valid, add to the tree
            if(neighbor_pos != make_pair(-1, -1)){
                cell* neighbor = &grid[neighbor_pos.first][neighbor_pos.second];
                
                // if already connected, skip
                if(connected[neighbor_pos.first][neighbor_pos.second]==1){
                    continue;
                }

                //add the neighbor to the tree and Update shown_grid to reflect the connection
                if(current->unite(current, neighbor, grid)) shown_grid[current->x + neighbor->x + 1][current->y + neighbor->y + 1] = '.';
                check_list.push_back(neighbor);
                connected[neighbor_pos.first][neighbor_pos.second]=1;
                }
        }
    }
}
