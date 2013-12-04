#ifndef PLAYER_H
#define PLAYER_H

struct P{
    bool status[4];
    string name[4];
    int position[4];
    int chance[4];
};

struct GameData{
    string letter[3][26][6];
    string placename[36];
    int placetype[36];
    int placelevel[36];
    string buildingname[36];
};

#endif // PLAYER_H
