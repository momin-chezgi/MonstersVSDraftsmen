#include "innerFunctions.hpp"

intpair get_the_move_of_dr(vec2d(char)& grid, draftsman& dr , vector<int>& announcedid, const int round){ //returns the coordinate of moved draftsman
    bool wants_to_rest = false;
    char move, move2;
    int new_x = dr.x, new_y = dr.y;
    
    if(!announcedid.empty()){
        for(auto d:announcedid)    
            d>0 ? cout << "congrats player #" << d << "! You got out of this hell!\n" 
            : cout << "Ops! player #" << -d  << "! God bless you!\n";
    }

    if(round!=0) cout << "Round " << round <<":============================================\n";
    cout << "Player #" << dr.id+1 << ":  coordinate(" << (dr.x+1)/2 << ", " << (dr.y+1)/2 << ")" << "  remained walls: " << dr.token_limit-dr.temp_token << endl;
    while(new_x == dr.x && new_y == dr.y && !wants_to_rest){
        cout << "Enter your move (W/A/S/D),Z for sleeping and TW/TA/TS/TD for building temporary walls: ";
        cin >> move;
        if(move == 'T' || move == 't') cin >> move2;
        switch(move){
            case 'Q':
            case 'q':
                cout << "Quit: do you want to save the game? Y/N  ";
                cin >> move2;
                if(move2 == 'Y' || move2 == 'y'){
                    cout << "Saving the game...\n";
                    return {0,0};
                }
                if(move2 == 'N' || move2 == 'n'){
                    cout << "Quit the game..,\n";
                    return {0,-1};
                }
                break;
            case 'W':
            case 'w':
                new_x -= 2;
                break;
            case 'A':
            case 'a':
                new_y -= 2;
                break;
            case 'S':
            case 's':
                new_x += 2;
                break;
            case 'D':
            case 'd':
                new_y += 2;
                break;
            case 'Z':
            case 'z':
                wants_to_rest = true;
                break;
            case 'T':
            case 't':
                switch(move2){
                    case 'W':
                    case 'w':
                        new_x -= 1;
                        break;
                    case 'A':
                    case 'a':
                        new_y -= 1;
                        break;
                    case 'S':
                    case 's':
                        new_x += 1;
                        break;
                    case 'D':
                    case 'd':
                        new_y += 1;
                        break;
                    default:
                        cout << "Invlaid move! Please enter  TW, TA, TS, or TD.\n";
                        new_x = dr.x;
                        new_y = dr.y;
                        continue;
                }
                break;
            default:
                cout << "Invalid move! Please enter W, A, S, or D.\n";
                new_x = dr.x;
                new_y = dr.y;
                continue;
        }

        //check if the player wants to build a temporary wall
        if(move == 'T' || move == 't'){
            if(dr.temp_token < dr.token_limit){
                dr.temp_token++;
                if(grid[new_x][new_y] == '#' || grid[new_x][new_y] == '2' || grid[new_x][new_y] == '1'){
                    cout << "You can't build the temporary wall there! Try again." << endl;
                    new_x = dr.x;
                    new_y = dr.y;
                    continue;
                }
            }
            else{
                cout << "Your temporary walls token has been limited! Try again." << endl;
                new_x = dr.x;
                new_y = dr.y;
                continue;
            }
        }

        //check if the player wants to go out of bounds
        if(new_x < 1 || new_x >= 2*n || new_y < 1 || new_y >= 2*m){
            cout << "Move out of bounds! Try again." << endl;
            new_x = dr.x;
            new_y = dr.y;
            continue;
        }
        
        // check if the move is blocked by a wall
        if(grid[(dr.x + new_x)/2][(dr.y + new_y)/2] == '#'){
            cout << "Move blocked by a wall! Try again." << endl;
            new_x = dr.x;
            new_y = dr.y;
            continue;
        }

        // check if there aren't any monsters or draftsman in the new position
        if(grid[new_x][new_y] == 'M'){
            cout << "Do you want to be the snack of a monster? Try again." << endl;
            new_x = dr.x;
            new_y = dr.y;
        }
        else {
            if(grid[new_x][new_y] == 'D' || grid[new_x][new_y] == 'd'){
                cout << "Sorry! every room hasn't got the place for you both. Try again." << endl;
                new_x = dr.x;
                new_y = dr.y;
            }
            else if(grid[new_x][new_y] == 'Z'){
                cout << "He's asleep! Don't make him wake up. Try again." << endl;
                new_x = dr.x;
                new_y = dr.y;
            }
        }
    }
    return {new_x, new_y};
}
