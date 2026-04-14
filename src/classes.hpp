#ifndef CLASSES_HPP
#define CLASSES_HPP

#include "includer.hpp"
struct Node
{

    int x {};
    int y {};
    int xp {};
    int yp {};

    void find(vec2d(cell)& grid);
    bool unite(Node* n1, Node* n2, vec2d(cell)& grid);

};

struct draftsman
{
    int id {-1};
    int x {-1};
    int y {-1};
    int temp_token {};
    int token_limit {};
    bool winned {false};
    bool defeated {false};
};

struct status
{
    int round {-1};
    int lastplayer {};
    vector<draftsman> drs;
    vector<intpair> mns;
    vector<intpair> lighpos;
    vector<intpair> walls;
    vector<intpair> temp1;
    vector<intpair> temp2;
    vector<intpair> chancecubes;
    int n {3};
    int m {3};
};

extern vector<draftsman> dr;

#endif // INCLUDER_H