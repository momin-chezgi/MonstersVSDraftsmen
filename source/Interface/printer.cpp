#include "innerFunctions.hpp"

void print_the_status(vec2d(char)& shown_grid) 
{
    clear_the_screen();
    //print the index of rows and columns
    cout << "   ";
    for(int j=1; j<=m; j++){
        if(j>9)cout << (j-j%10)/10 << " ";
        else cout << "  ";
    }
    cout << endl << "   ";
    for(int j=1; j<=m; j++) cout << j%10 << ' ';
    cout << endl;
    for(int i = 0; i <= 2*n; i++){
        if(i%2==1) (i+1)/2 > 9 ? cout << (i+1)/2 : cout << (i+1)/2 << " ";
        else cout << "  ";
        for( int j =0; j <= 2*m; j++){
            cout << shown_grid[i][j];
        }
        cout << endl;
    }
}

void print_the_ranking(vector<int>& winners, vector<int>& losers)
{
    cout << "----------------------------------------" << endl;
    cout << "Ranking:" << endl;
    int w=0;
    for(; w<winners.size(); w++){
        cout << w+1 << ".player #" << winners[w]+1 << endl;
    }
    for(int l=losers.size()-1; l>=0; l--){
        cout << ++w << ".player #" << losers[l]+1 << " XXX" << endl;
    }
    cout << "press 'e' and hit the Enter to end the game! ";
    string meaningless;
    cin >> meaningless;
}