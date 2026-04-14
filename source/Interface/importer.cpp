#include "innerFunctions.hpp"

void import_dimensions();
void import_Xnum();

status importer(bool wellcom, int given_n, int given_m,
                  int given_drnum, int given_mnnum){
    clear_the_screen();
    if(wellcom){
        while(true){
            cout << "Wellcome to 'The Tale of Labyrinth' game! choose an option:" << endl;
            string chosen = "o";
            while(chosen!="1" && chosen!="2"){
                cout << "1.Play a new game              2.Play a saved game" << endl;
                cin >> chosen;
            }
            if(chosen == "2"){
                is_saved_game = true;
                int numofsaved = number_of_games();
                if(numofsaved <= 0){
                    cout << "No saved games found. Please start a new game." << endl;
                    continue;
                }
                int whichgame = 0;
                cout << "Which one do you play?"<<endl;
                for(int i=0; i<numofsaved; i++) cout << i+1 << ", ";
                cout << endl;
                while(whichgame == 0){
                    cin >> whichgame;
                    if(whichgame<1 || whichgame > numofsaved)whichgame=0;
                }

                status loaded = load_the_game(whichgame-1);
                if(is_saved_game) return loaded;

                cout << "The selected save file is invalid/corrupted. Please choose another slot or start a new game." << endl;
                continue;
            }
            break;
        }
        cout << "You have chosen to play a new game! " << endl;
        cout << string(50, '-') << endl;
        cout << "Before starting the game, enter the dimensions of the grid and the numbers of draftsmen, monsters and walls for generating the maze" << endl;
        cout << "remember that rules(n and m are dimensions):" << endl;
        cout << "Any time, quit by pressing the 'Q' word.(and play it at the other time)" << endl;
        
    }
    import_dimensions();
    import_Xnum();
    cout << "Let's generate the maze..." << endl;
    cout << string(50, '-') << endl;

    return status{};
}



void import_dimensions(){
    cout << "Enter the dimensions of the grid (n,m): ";
    cin >> n >> m;
    while(n <= 2 || m <= 2 || n > 50 || m > 50){
        cout << "Invalid dimensions! Please re-enter n and m (2 < n,m <= 50):" << endl;
        cin >> n >> m;
    }
}

void import_Xnum(){
    do{
    cout << "enter the numbers of draftsmen for generating maze(<" << ((n*m)/9)-1 << ") ";
    cin >> drnum;
    cout << "enter the numbers of monsters for generating maze(<" << ((n*m)/9)-drnum << ") ";
    cin >> mnnum;
    cout << "enter the number of walls to generate the maze(<" << n*m - n - m << ") ";
    cin >> wlnum;
    if(drnum + mnnum < 1 || drnum + mnnum > (n * m) / 9 || wlnum < 0 || wlnum > n * m - n - m)
        cout << "Invalid numbers of draftsmen, monsters or walls!" << endl;
    }while (drnum + mnnum < 1 || drnum + mnnum > (n * m) / 9 || wlnum < 0 || wlnum > n * m - n - m);
}
