/*
* File:   main.cpp
* Author: TaeYoun Kim
* Created by Minji Kim on 2013. 11. 18..
* programming tools
* 1.0.11.18 //Xcode on OSX
* 1.1.11.26 //Qt Creator on Windows
* source - http://www.asciiworld.com/-Maps-.html  //World Map
 *          http://www.chris.com/ASCII/  //Some Ascii code arts
*          http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20  //Ascii code text generator
  */

/*
 * PATCH NOTE
 * 1.0.11.18 - Setup libraries and basic settings
 * 1.1.11.26 - Intro banner
 * 1.2.11.26 - Add world map on intro
 * 1.3.11.27 - Change Font on Intro
 * 1.4.11.28 - Setup MENU
  * 1.5.11.29 - Create Visualized board
 * 1.6.12.01 - Add functions and variables on board
 * 1.7.12.02 - Build universial memory controller
 * 1.8.12.04 - Add constant informations
 * 1.9.12.04 - build structure for store user data
 * 1.10.12.04 - build letter and number image to use in multiple functions easily
 */

/*
 *ERRORS
 *[001] - Cannot start the game/any key function does not work
 *[002] - Error when player input the player-name
  */

/*
 *Notes
 *cout<<showpoint<<fixed<<setprecision(2);
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
#include <ctime>
#include <windows.h>
using namespace std;
#include "Player.h"

//Global Constants
const string VERSION="1.6.12.01";

//function Prototypes
 //----SYSTEM---------
void GameStart();
void s_initializeData(GameData);
void Initialization(int [][4],int [][36], int[][3][3]);
string s_PlacePlayer(int [],int,bool);
string s_PlaceOwner(int);
//----UTILITY--------
string I2S(int);
string D2S(double);
string IntRank(int);
string InputString(string [],string [],string,string,int,int,bool,bool);
 //----DISPLAY--------
string d_Title(int,bool,bool,int,int);
string d_Menu(int,bool,bool,int);
string d_Board(int,bool,bool,int);
string d_Words(GameData,string,int);
string d_Jackpot(int);
string d_Setting(int,bool,bool,int);
string d_PlayerSetting(int,bool,bool,int,P *);


//int main(int argc, const char * argv[]){
int main(){
     GameStart();
}

void GameStart(){
    string menu[3]={"1","2","3"};
    string begin;
    int playerWhere[4];
    int place[10][36];
    P player,*playername=&player;
    GameData gamedata;
    s_initializeData(gamedata);
    //d_Title(0,true,false,50,100);
    //begin=InputString(menu,menu,"Enter any key to start the game\n",d_Title(0,false,true,0,0)+"ERROR[001] - ",1,1,true,true);
    //d_Menu(0,true,false,20);
    //begin=InputString(menu,menu,"Please Select the menu\n",d_Menu(0,false,true,0)+"Incorrect number - ",3,0,true,false);
    d_PlayerSetting(0,true,false,20,playername);
    menu[0]="";menu[1]="";menu[2]="";
    for(int i=0;i<4;i++){
        player.name[i]=InputString(menu,menu,"Please Enter the "+IntRank(i+1)+" player's name. If Player does not play, enter 0\n",d_PlayerSetting(0,false,true,0,playername)+"ERROR[002] - ",0,0,true,true);
        if(player.name[i]!="0")player.status[i]=true;
        d_PlayerSetting(0,true,false,20,playername);
    }
    for(int i=0;i<6;i++){
        cout<<gamedata.letter[0][22][i]<<gamedata.letter[0][22][i]<<gamedata.letter[0][22][i]<<gamedata.letter[0][22][i]<<gamedata.letter[0][22][i]<<endl;
    }

    //d_Setting(0,true,false,20);
    //begin=InputString(menu,menu,"Please Select the menu\n",d_Board(0,false,true,0)+"Incorrect number - ",3,0,true,true);
}

void Initialization(int player[][4], int place[][36], int building[][3][3], string placename[], string buildinglevel[], string specialplace[]){
/*
 * Place[place36][order]

 order 1 = place name
 order 2 = place type
  order 3 = place owner
 order 4 = building level & price & selling price
 order 5 = place special effect
 order 6 =

 Player[player4][order]

 order 1 = where is player
 order 2 = which lands player has & buliding level - pointer points
  order 3 = how much money player has
 order 4 = which chance card player has now
*/
    int i;
    //Player

    //Place
    i=1;//Place Type - 1.place 2.vacation 3.chance 4.event 5.special 6.casino 7.tax
    place[i][0]=5;
    place[i][1]=1;
    place[i][2]=6;
    place[i][3]=1;
    place[i][4]=2;
    place[i][5]=1;
    place[i][6]=3;
    place[i][7]=1;
    place[i][8]=1;
    place[i][9]=5;
    place[i][10]=1;
    place[i][11]=2;
    place[i][12]=1;
    place[i][13]=4;
    place[i][14]=1;
    place[i][15]=1;
    place[i][16]=3;
    place[i][17]=1;
    place[i][18]=5;
    place[i][19]=1;
    place[i][20]=2;
    place[i][21]=1;
    place[i][22]=4;
    place[i][23]=1;
    place[i][24]=2;
    place[i][25]=1;
    place[i][26]=1;
    place[i][27]=5;
    place[i][28]=1;
    place[i][29]=3;
    place[i][30]=1;
    place[i][31]=1;
    place[i][32]=4;
    place[i][33]=1;
    place[i][34]=7;
    place[i][35]=1;
    //Buildings
    placename[0]="start";
    placename[1]="Tunis";
    placename[2]="Casino";
    placename[3]="Cairo";
    placename[4]="Guam";
    placename[5]="Bangkok";
    placename[6]="Chance";
    placename[7]="New Deli";
    placename[8]="Singarpore";
    placename[9]="Jail";
    placename[10]="Brasilia";
    placename[11]="Bali";
    placename[12]="Santiago";
    placename[13]="Event";
    placename[14]="Oslo";
    placename[15]="Stockholm";
    placename[16]="Chance";
    placename[17]="Moscow";
    placename[18]="Jackpot";
    placename[19]="Athens";
    placename[20]="Puerto Rico";
    placename[21]="Rome";
    placename[22]="Event";
    placename[23]="Berlin";
    placename[24]="Sicilia";
    placename[25]="Pari";
    placename[26]="London";
    placename[27]="Airport";
    placename[28]="Beijing";
    placename[29]="Chance";
    placename[30]="Tokyo";
    placename[31]="Seoul";
    placename[32]="Event";
    placename[33]="New York";
    placename[34]="Tax";
    placename[35]="Los Angeles";
    buildinglevel[0]="Land";
    buildinglevel[1]="House";
    buildinglevel[2]="Inn";
    buildinglevel[3]="Hotel";
    buildinglevel[4]="Landmark";
    specialplace[0]="";
    specialplace[1]="Olive Oil";//
    specialplace[2]="";
    specialplace[3]="Pyramid";//If player visit cairo first, player will pay additional 20% of current cost
    specialplace[4]="";
    specialplace[5]="Bangkok";
    specialplace[6]="";
    specialplace[7]="Hinduism";//
    specialplace[8]="Police State";//Player cannot use chance card on this place
    specialplace[9]="";
    specialplace[10]="Samba Festival";//Add samba festival event that makes player has come to brasilia on the event cards
    specialplace[11]="";
    specialplace[12]="Moai";
    specialplace[13]="";
    specialplace[14]="Oslo";
    specialplace[15]="Nobel Prize";//
    specialplace[16]="";
    specialplace[17]="Moscow";
    specialplace[18]="";
    specialplace[19]="Greek";//
    specialplace[20]="";
    specialplace[21]="Roman Catolic";//Player earns more money from start as much as player has his/her own places
    specialplace[22]="";
    specialplace[23]="Beer";//As any player visit Berlin, Berlin's total cost is increasing as much as 10%
    specialplace[24]="";
    specialplace[25]="Fashion Show";//Player can open fashion show on the places that charges additional 20% of money from visitors.
    specialplace[26]="Oxford";//If other player visit here and player has no chance card, it generates random chance card for free.
    specialplace[27]="";
    specialplace[28]="World's Factory";//Player can build their buildings with less money
    specialplace[29]="";
    specialplace[30]="Japanimation";//Player earn 30% more from event cards
    specialplace[31]="Information Technology";//If Player visit his own place, player can build higher level-buildings except landmark. If player visit Start, he can build landmark on the other place.
    specialplace[32]="";
    specialplace[33]="New York Stock Exchange";//Player no longer pays tax when he/she visit tax place, player earn 10% more when he earn from start, jackpot, casino, and event cards
    specialplace[34]="";
    specialplace[35]="Silicon valley"; // When owner player visit L.A., player earn 20% of place cost, if player visit other own place where has landmark, player earn 10%.
}

string InputString(string ansTrue[], string ansFalse[], string ask, string reTryTxt,
                  int numTrue, int numFalse, bool askAgain, bool anyKey){
    string input;
    if(askAgain==false){cout<<ask;}
    for(bool b=false;b==false;){
        if(askAgain==true){cout<<ask;}
         cin>>input;
        if(anyKey==true){b=true;}
        else{
            for(int i=0;i<numTrue;i++){
                if(input==ansTrue[i]){b=true;}
            }
            for(int i=0;i<numFalse;i++){
                 if(input==ansFalse[i]){b=true;}
            }
            if(b==false){cout<<reTryTxt;}
        }
    }
    return input;
}

string I2S(int input){
    stringstream ss;
    ss << input;
     string str = ss.str();
    return str;
}

string D2S(double input){
    stringstream ss;
    ss << input;
    string str = ss.str();
    return str;
}

string IntRank(int i){
    string str=I2S(i);
    str+="th";
    if(i==1)str="1st";
    else if(i==2)str="2nd";
    else if(i==3)str="3rd";
    return str;
}

string d_Title(int i,bool Animation, bool save, int duration1,int duration2){
     string str="";
    int d=duration1;
    if(Animation==true)i=0;
    do{
        if(i>23)d=duration2;
        if(i==23||i==34||i==42)Sleep(500);
        if(i==0)str+= "          _______________________________________________________________                 ";
         else if(i==1)str+= "         /         ,_   .  ._. _.  .                                     \\                ";
        else if(i==2)str+= "        /      , _-\\','|~\\~      ~/      ;-'_   _-'     ,;_;_,    ~~-     \\               ";
         else if(i==3)str+= "       |/~~-\\_/-'~'--' \\~~| ',    ,'      /  / ~|-_\\_/~/~      ~~--~~~~'--_|              ";
        else if(i==4)str+= "       |/              ,/'-/~ '\\ ,' _  , '|,'|~                   ._/-, /~ |              ";
         else if(i==5)str+= "       |~/-'~\\_,       '-,| '|. '   ~  ,\\ /'~                /    /_  /~   |              ";
        else if(i==6)str+= "       |.-~      '|        '',\\~|\\       _\\~     ,_  ,               /|    |              ";
         else if(i==7)str+= "       |      '\\        /'~          |_/~\\\\,-,~  \\ \\\"         ,_,/ |       |              ";
        else if(i==8)str+= "       |       |       /            ._-~'\\_ _~|              \\ ) /         |              ";
         else if(i==9)str+= "       |        \\   __-\\           '/      ~ |\\  \\_          /  ~          |              ";
        else if(i==10)str+="       |.,         '\\ |,  ~-_      - |          \\\\_' ~|  /\\  \\~ ,          |              ";
         else if(i==11)str+="       |           ~-_'  _;       '\\           '-,   \\,' /\\/  |            |              ";
        else if(i==12)str+="       |             '\\_,~'\\_       \\_ _,       /'    '  |, /|'            |              ";
         else if(i==13)str+="       |               /     \\_       ~ |      /         \\  ~'; -,_.       |              ";
        else if(i==14)str+="       |               |       ~\\        |    |  ,        '-_, ,; ~ ~\\     |              ";
         else if(i==15)str+="       |                \\,      /        \\    / /|            ,-, ,   -,   |              ";
        else if(i==16)str+="       |                 |    ,/          |  |' |/          ,-   ~ \\   '.  |              ";
         else if(i==17)str+="       |                ,|   ,/           \\ ,/              \\       |      |              ";
        else if(i==18)str+="       |                /    |             ~                 -~~-, /   _   |              ";
         else if(i==19)str+="       |                |  ,-'                                    ~    /   |              ";
        else if(i==20)str+="       |                / ,'                                      ~        |              ";
         else if(i==21)str+="        \\              ',|  ~                                             /               ";
        //else if(i==22)str+="        \\                 ~'                                              /               ";
         else if(i==22)str+="         \\_______________________________________________________________/                ";
        else if(i==23)str+="     $$\\      $$\\                                                   $$\\                   ";
         else if(i==24)str+="     $$$\\    $$$ |                                                  $$ |                  ";
        else if(i==25)str+="     $$$$\\  $$$$ | $$$$$$\\  $$$$$$$\\   $$$$$$\\   $$$$$$\\   $$$$$$\\  $$ |$$\\   $$\\         ";
         else if(i==26)str+="     $$\\$$\\$$ $$ |$$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ $$ |$$ |  $$ |        ";
        else if(i==27)str+="     $$ \\$$$  $$ |$$ /  $$ |$$ |  $$ |$$ /  $$ |$$ /  $$ |$$ /  $$ |$$ |$$ |  $$ |        ";
         else if(i==28)str+="     $$ |\\$  /$$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |$$ |  $$ |        ";
        else if(i==29)str+="     $$ | \\_/ $$ |\\$$$$$$  |$$ |  $$ |\\$$$$$$  |$$$$$$$  |\\$$$$$$  |$$ |\\$$$$$$$ |        ";
         else if(i==30)str+="     \\__|     \\__| \\______/ \\__|  \\__| \\______/ $$  ____/  \\______/ \\__| \\____$$ |        ";
        else if(i==31)str+="                                                $$ |                    $$\\   $$ |        ";
         else if(i==32)str+="                                                $$ |                    \\$$$$$$  |        ";
        else if(i==33)str+="                                                \\__|                     \\______/         ";
         else if(i==34)str+=" $$\\      $$\\                     $$\\       $$\\       $$$$$$$$\\                            ";
        else if(i==35)str+=" $$ | $\\  $$ |                    $$ |      $$ |      \\__$$  __|                           ";
         else if(i==36)str+=" $$ |$$$\\ $$ | $$$$$$\\   $$$$$$\\  $$ | $$$$$$$ |         $$ | $$$$$$\\  $$\\   $$\\  $$$$$$\\  ";
        else if(i==37)str+=" $$ $$ $$\\$$ |$$  __$$\\ $$  __$$\\ $$ |$$  __$$ |         $$ |$$  __$$\\ $$ |  $$ |$$  __$$\\ ";
         else if(i==38)str+=" $$$$  _$$$$ |$$ /  $$ |$$ |  \\__|$$ |$$ /  $$ |         $$ |$$ /  $$ |$$ |  $$ |$$ |  \\__|";
        else if(i==39)str+=" $$$  / \\$$$ |$$ |  $$ |$$ |      $$ |$$ |  $$ |         $$ |$$ |  $$ |$$ |  $$ |$$ |      ";
         else if(i==40)str+=" $$  /   \\$$ |\\$$$$$$  |$$ |      $$ |\\$$$$$$$ |         $$ |\\$$$$$$  |\\$$$$$$  |$$ |      ";
        else if(i==41)str+=" \\__/     \\__| \\______/ \\__|      \\__| \\_______|         \\__| \\______/  \\______/ \\__|      ";
         else if(i==42)str+="                                            Copyright (R) TaeYoun Kim. All right reserved";
        if(save==false){if(Animation==true){i++;cout<<str<<endl;str="";Sleep(d);}}
         else{i++;str+="\n";}
    }while(i<=42&&(Animation==true||save==true));
    return str;
}

string d_Menu(int i,bool Animation, bool save, int duration1){
    string str="";
     int d=duration1;
    if(Animation==true)i=0;
    do{
        if(i==11)str+= "              .                                          ";
        else if(i==12)str+= "              |~                                         ";
         else if(i==13)str+= "             /|\\                                         ";
        else if(i==14)str+= "            |-.-|             __  __ ______ _   _ _    _ ";
        else if(i==15)str+= "            '-:-'            |  \\/  |  ____| \\ | | |  | |";
         else if(i==16)str+= "             [|]             | \\  / | |__  |  \\| | |  | |";
        else if(i==17)str+= "             [|]             | |\\/| |  __| | . ` | |  | |";
        else if(i==18)str+= "             [|]             | |  | | |____| |\\  | |__| |";
         else if(i==19)str+= "             [|]             |_|  |_|______|_| \\_|\\____/ ";
        else if(i==20)str+="             [|]                                         ";
        else if(i==21)str+="            .[|].                                        ";
         else if(i==22)str+="            :/|\\:             1. Normal Game             ";
        else if(i==23)str+="            [/|\\]                - start without settings";
        else if(i==24)str+="            [/|\\]             2. Custom Gmae             ";
         else if(i==25)str+="          .:_#|#_:.              - player customize settings";
        else if(i==26)str+="          |_ '-' _|           3. Exit Game               ";
        else if(i==27)str+="          /\\:-.-:/\\              - End game              ";
         else if(i==28)str+="         /\\|_[|]_|/\\                                     ";
        else if(i==29)str+="       _/\\|~ [|] ~|/\\_                                   ";
        else if(i==30)str+="       [''=-.[|].-='']                                   ";
         else if(i==31)str+="       :-._   |   _.-:                                   ";
        else if(i==32)str+="       //\\;::-:-::;/\\\\                                   ";
        else if(i==33)str+="      /\\.'-\\\\/|\\//-'./\\                                  ";
         else if(i==34)str+="    .'\\/'   :\\|/:   '\\/'.                                ";
        else if(i==35)str+="  .//\\('    [\\|/]    ')/\\\\.                              ";
         else if(i==36)str+=" '':][\\.'  .[\\|/].  './][:''                             ";
        else if(i==37)str+="     ''    :/\\|/\\:    ''                                 ";
         else if(i==38)str+="          .[\\/|\\/].                                      ";
        else if(i==39)str+="            '.|.'                                        ";
        else if(i==40)str+="              '                                          ";
         else if(i>=41)str+="";
        if(save==false){if(Animation==true){i++;cout<<str<<endl;str="";Sleep(d);}}
        else{i++;str+="\n";}
    }while(i<=42&&(Animation==true||save==true));
     return str;

}

string d_PlayerSetting(int i,bool Animation, bool save, int duration1,P *playername){
    string str="";
     int d=duration1;
    if(Animation==true)i=0;
    do{
        if(i==10)str+= "                     *                       ";
        if(i==11)str+= "                     :                       ";
        if(i==12)str+= "                     |                       ";
        if(i==13)str+= "                     |                       ";
        if(i==14)str+= "                     |                       ";
        if(i==15)str+= "                    :|:                      ";
        if(i==16){str+= "                    |||                 1p. ";
            if((*playername).status[0]==true)str+=(*playername).name[0];}
        if(i==17)str+= "               _____|||_____                 ";
        if(i==18){str+= "              /=============\\           2p. ";
            if((*playername).status[1]==true)str+=(*playername).name[1];}
        if(i==19)str+= "          ---<~~~~~~~~~~~~~~~>---            ";
        if(i==20){str+= "              \\-------------/           3p. ";
            if((*playername).status[2]==true)str+=(*playername).name[2];}
        if(i==21)str+= "               \\___________/                 ";
        if(i==22){str+= "                 \\||:::||/              4p. ";
            if((*playername).status[3]==true)str+=(*playername).name[3];}
        if(i==23)str+= "                  ||:::||                    ";
        if(i==24)str+= "                  ||:::||                    ";
        if(i==25)str+= "                  ||:::||                    ";
        if(i==26)str+= "                  ||ooo||                    ";
        if(i==27)str+= "                  ||___||                    ";
        if(i==28)str+= "                  ||:::||                    ";
        if(i==29)str+= "                  ||:::||                    ";
        if(i==30)str+= "                  ||:::||                    ";
        if(i==31)str+= "                  ||:::||                    ";
        if(i==32)str+= "                  ||:::||                    ";
        if(i==33)str+= "                 /||:::||\\                   ";
        if(i==34)str+= "                / ||:::|| \\                  ";
        if(i==35)str+= "               /  ||:::||  \\                 ";
        if(i==36)str+= "              /   ||:::||   \\                ";
        if(i==37)str+= "          ___/____||:::||____\\____           ";
        if(i==38)str+= "         /~~~~~~~~~~~~~~~~~~~~~~~~\\          ";
        if(i==39)str+= "        /   |~~~~~~~~|  _____      \\         ";
        if(i==40)str+= "        |   |________| |  |  |     |         ";
        if(i==41)str+= "  ______|______________|__|__|_____|_________";
        else if(i>=41)str+="";
       if(save==false){if(Animation==true){i++;cout<<str<<endl;str="";Sleep(d);}}
       else{i++;str+="\n";}
   }while(i<=42&&(Animation==true||save==true));
    return str;

}




string d_Board(int i,bool Animation, bool save, int duration1){
    string str="";
    int d=duration1;
    if(Animation==true)i=0;
    do{
        if(i==0)str+= " _____________________________________________________________________________________________ ";
    else if(i==1)str+= "|          | B.SILIA|  BALI  |SANTIAGO| EVENT  |  OSLO  | S.HOLM | CHANCE | MOSCOW |          |";
   else if(i==2)str+= "|   JAIL   |        |        |        |        |        |        |        |        | JACKPOT! |";
    else if(i==3)str+= "|          |        |        |        |        |        |        |        |        |          |";
   else if(i==4)str+= "|          |________|________|________|________|________|________|________|________|          |";
    else if(i==5)str+= "|__________|________|________|________|________|________|________|________|________|__________|";
   else if(i==6)str+= "| S.PORE | |                                                                       | | ATHENS |";
    else if(i==7)str+= "|        | |                                                                       | |        |";
   else if(i==8)str+= "|        | |         __________                                                    | |        |";
    else if(i==9)str+= "|________|_|        /    C    /)                                                   |_|________|";
   else if(i==10)str+="| NEWDELI| |       /    H    //                                                    | | P.RICO |";
    else if(i==11)str+="|        | |      /    A    //                                                     | |        |";
   else if(i==12)str+="|        | |     /    N    //                                                      | |        |";
    else if(i==13)str+="|________|_|    /    G    //                                                       |_|________|";
   else if(i==14)str+="| CHANCE | |   /____E____//                                                        | |  ROME  |";
    else if(i==15)str+="|        | |   \\\\\\\\\\/                                                         | |        |";
   else if(i==16)str+="|        | |                                                                       | |        |";
    else if(i==17)str+="|________|_|                           _________________                           |_|________|";
   else if(i==18)str+="| BANGKOK| |                          |                 |                          | | EVENT  |";
    else if(i==19)str+="|        | |                          |  J A C K P O T  |                          | |        |";
   else if(i==20)str+="|        | |                  ________|_________________|________                  | |        |";
    else if(i==21)str+="|________|_|                 |                                   |                 |_|________|";
   else if(i==22)str+="|  GUAM  | |                 |                                   |                 | | BERLIN |";
    else if(i==23)str+="|        | |                 |___________________________________|                 | |        |";
   else if(i==24)str+="|        | |                                                                       | |        |";
    else if(i==25)str+="|________|_|                                                                       |_|________|";
   else if(i==26)str+="| CAIRO  | |                                                                       | | SICILiA|";
    else if(i==27)str+="|        | |                                                     __________        | |        |";
   else if(i==28)str+="|        | |                                                    /    E    /)       | |        |";
    else if(i==29)str+="|________|_|                                                   /    V    //        |_|________|";
   else if(i==30)str+="| CASINO | |                                                  /    E    //         | |  PARI  |";
    else if(i==31)str+="|        | |                                                 /    N    //          | |        |";
   else if(i==32)str+="|        | |                                                /    T    //           | |        |";
    else if(i==33)str+="|________|_|                                               /_________//            |_|________|";
   else if(i==34)str+="| TUNIS  | |                                               |_________/             | | LONDON |";
    else if(i==35)str+="|        | |                                                                       | |        |";
   else if(i==36)str+="|        | |                                                                       | |        |";
    else if(i==37)str+="|________|_|_______________________________________________________________________|_|________|";
   else if(i==38)str+="|          |________|________|________|________|________|________|________|________|          |";
    else if(i==39)str+="|  START!  |  L.A.  |  TAX   |NEW YORK| EVENT  | SEOUL  | TOKYO  | CHANCE |BEIJING | AIRPORT! |";
   else if(i==40)str+="|          |        |        |        |        |        |        |        |        |          |";
    else if(i==41)str+="|          |        |        |        |        |        |        |        |        |          |";
   else if(i==42)str+="|__________|________|________|________|________|________|________|________|________|__________|";
         if(save==false){if(Animation==true){i++;cout<<str<<endl;str="";Sleep(d);}}
        else{i++;str+="\n";}
    }while(i<=42&&(Animation==true||save==true));
    return str;

}


string s_PlacePlayer(int p[],int place,bool top){
    //Max Place is 36 - start is 0
    string str="";
    int num=1;
    if(top==false){num+=2;str+=" ";}
    for(int i=0;i<2;i++){
         if(p[i+num-1]==place){
            str+=I2S(i+num);
        }else{
            str+=" ";
        }
        if(i==0)str+=" ";
    }
    if(top==true){str+=" ";}
     return str;
}

/*string s_PlaceOwner(int p[], int place){
    string str="";
    for(int i=0;i<4;i++){
        if(p==i){str=I2S(i+1);}
    }
    return str;
}*/

void u_LoadBoardInfo(int player[][4],int place[][36],int *wplayer, int *mplayer, int *cplayer, int *oplace, int *lplace){
    for(int i=0;i<4;i++){
        player[0][i]=*(wplayer+i);
        player[2][i]=*(mplayer+i);
        player[3][i]=*(cplayer+i);
    }
    for(int k=0;k<36;k++){
        place[2][k]=*(oplace+k);
    }
}

string d_Jackpot(int m){
    string str="";
    for(int i=0;i<28;i++){
        if(pow(10.0,i)>m){
            str+=I2S(m);
            for(int k=0;k<29-i;k++){
                str+=" ";
             }
            break;
        }
    }
    return str;
}

string d_Words(GameData g, string word, int line){
    return word;
}

string d_Setting(int i,bool Animation, bool save, int duration1){
    string str="";
    int player[4][5];
    player[0][0]=1;
     player[1][0]=2;
    player[2][0]=3;
    player[3][0]=1;
    int *playerw;
    for(int i=0;i<4;i++){
        *(playerw+i)=player[i][0];
    }
    int jackpot=10;
    int d=duration1;
    if(Animation==true)i=0;
     do{
        if(i==0){str+= " _____________________________________________________________________________________________ ";}
        else if(i==1){str+= "|          | B.SILIA|  BALI  |SANTIAGO| EVENT  |  OSLO  | S.HOLM | CHANCE | MOSCOW |          |";}
         else if(i==2){str+= "|   JAIL   |  ";str+=s_PlacePlayer(playerw,10,true);str+="  |  ";str+=s_PlacePlayer(playerw,11,true);str+="  |  ";str+=s_PlacePlayer(playerw,12,true);str+="  |  ";str+=s_PlacePlayer(playerw,13,true);str+="  |  ";str+=s_PlacePlayer(playerw,14,true);str+="  |  ";str+=s_PlacePlayer(playerw,15,true);str+="  |  ";str+=s_PlacePlayer(playerw,16,true);str+="  |  ";str+=s_PlacePlayer(playerw,17,true);str+="  | JACKPOT! |";}
         else if(i==3){str+= "|   ";str+=s_PlacePlayer(playerw,9,true);str+="   |  ";str+=s_PlacePlayer(playerw,10,false);str+="  |  ";str+=s_PlacePlayer(playerw,11,false);str+="  |  ";str+=s_PlacePlayer(playerw,12,false);str+="  |  ";str+=s_PlacePlayer(playerw,13,false);str+="  |  ";str+=s_PlacePlayer(playerw,14,false);str+="  |  ";str+=s_PlacePlayer(playerw,15,false);str+="  |  ";str+=s_PlacePlayer(playerw,16,false);str+="  |  ";str+=s_PlacePlayer(playerw,17,false);str+="  |   ";str+=s_PlacePlayer(playerw,18,true);str+="   |";}
         else if(i==4){str+= "|   ";str+=s_PlacePlayer(playerw,9,false);str+="   |________|________|________|________|________|________|________|________|   ";str+=s_PlacePlayer(playerw,18,false);str+="   |";}
         else if(i==5){str+= "|__________|__%__*__|__%__*__|__%__*__|________|__%__*__|__%__*__|________|__%__*__|__________|";}
        else if(i==6){str+= "| S.PORE | |                                                                       | | ATHENS |";}
         else if(i==7){str+= "|  ";str+=s_PlacePlayer(playerw,8,true);str+="  |%|                                                                       |%|  ";str+=s_PlacePlayer(playerw,19,true);str+="  |";}
         else if(i==8){str+= "|  ";str+=s_PlacePlayer(playerw,8,false);str+="  |*|         __________                                                    |*|  ";str+=s_PlacePlayer(playerw,19,false);str+="  |";}
         else if(i==9){str+= "|________|_|        /    C    /)                   1                               |_|________|";}
        else if(i==10){str+="| NEWDELI| |       /    H    //                    2                               | | P.RICO |";}
         else if(i==11){str+="|  ";str+=s_PlacePlayer(playerw,7,true);str+="  |%|      /    A    //                     3                               |%|  ";str+=s_PlacePlayer(playerw,20,true);str+="  |";}
         else if(i==12){str+="|  ";str+=s_PlacePlayer(playerw,7,false);str+="  |*|     /    N    //                      4                               |*|  ";str+=s_PlacePlayer(playerw,20,false);str+="  |";}
         else if(i==13){str+="|________|_|    /    G    //                                                       |_|________|";}
        else if(i==14){str+="| CHANCE | |   /____E____//                                                        | |  ROME  |";}
         else if(i==15){str+="|  ";str+=s_PlacePlayer(playerw,6,true);str+="  | |   \\\\\\\\\\\\\\\\\\\\/                                                         |%|  ";str+=s_PlacePlayer(playerw,21,true);str+="  |";}
         else if(i==16){str+="|  ";str+=s_PlacePlayer(playerw,6,false);str+="  | |                                                                       |*|  ";str+=s_PlacePlayer(playerw,21,false);str+="  |";}
         else if(i==17){str+="|________|_|                           _________________                           |_|________|";}
        else if(i==18){str+="| BANGKOK| |                          |                 |                          | | EVENT  |";}
         else if(i==19){str+="|  ";str+=s_PlacePlayer(playerw,5,true);str+="  |%|                          |  J A C K P O T  |                          | |  ";str+=s_PlacePlayer(playerw,22,true);str+="  |";}
         else if(i==20){str+="|  ";str+=s_PlacePlayer(playerw,5,false);str+="  |*|                  ________|_________________|________                  | |  ";str+=s_PlacePlayer(playerw,22,false);str+="  |";}
         else if(i==21){str+="|________|_|                 |                                   |                 |_|________|";}
        else if(i==22){str+="|  GUAM  | |                 | $ ";str+=d_Jackpot(jackpot);str+="   |                 | | BERLIN |";}
         else if(i==23){str+="|  ";str+=s_PlacePlayer(playerw,4,true);str+="  |%|                 |___________________________________|                 |%|  ";str+=s_PlacePlayer(playerw,23,true);str+="  |";}
         else if(i==24){str+="|  ";str+=s_PlacePlayer(playerw,4,false);str+="  |*|                                                                       |*|  ";str+=s_PlacePlayer(playerw,23,false);str+="  |";}
         else if(i==25){str+="|________|_|                                                                       |_|________|";}
        else if(i==26){str+="| CAIRO  | |                                                                       | | SICILiA|";}
         else if(i==27){str+="|  ";str+=s_PlacePlayer(playerw,3,true);str+="  |%|                                                     __________        |%|  ";str+=s_PlacePlayer(playerw,24,true);str+="  |";}
         else if(i==28){str+="|  ";str+=s_PlacePlayer(playerw,3,false);str+="  |*|                                                    /    E    /)       |*|  ";str+=s_PlacePlayer(playerw,24,false);str+="  |";}
         else if(i==29){str+="|________|_|                                                   /    V    //        |_|________|";}
        else if(i==30){str+="| CASINO | |                                                  /    E    //         | |  PARI  |";}
         else if(i==31){str+="|  ";str+=s_PlacePlayer(playerw,2,true);str+="  | |                                                 /    N    //          |%|  ";str+=s_PlacePlayer(playerw,25,true);str+="  |";}
         else if(i==32){str+="|  ";str+=s_PlacePlayer(playerw,2,false);str+="  | |                                                /    T    //           |*|  ";str+=s_PlacePlayer(playerw,25,false);str+="  |";}
         else if(i==33){str+="|________|_|                                               /_________//            |_|________|";}
        else if(i==34){str+="| TUNIS  | |                                               \\\\\\\\\\\\\\\\\\\\/             | | LONDON |";}
         else if(i==35){str+="|  ";str+=s_PlacePlayer(playerw,1,true);str+="  |%|                                                                       |%|  ";str+=s_PlacePlayer(playerw,26,true);str+="  |";}
         else if(i==36){str+="|  ";str+=s_PlacePlayer(playerw,1,false);str+="  |*|                                                                       |*|  ";str+=s_PlacePlayer(playerw,26,false);str+="  |";}
         else if(i==37){str+="|________|_|_______________________________________________________________________|_|________|";}
        else if(i==38){str+="|          |__%__*__|________|__%__*__|________|__%__*__|__%__*__|__%__*__|__%__*__|          |";}
         else if(i==39){str+="|  START!  |  L.A.  |  TAX   |NEW YORK| EVENT  | SEOUL  | TOKYO  | CHANCE |BEIJING | AIRPORT! |";}
        else if(i==40){str+="|   ";str+=s_PlacePlayer(playerw,0,true);str+="   |  ";str+=s_PlacePlayer(playerw,35,true);str+="  |  ";str+=s_PlacePlayer(playerw,34,true);str+="  |  ";str+=s_PlacePlayer(playerw,33,true);str+="  |  ";str+=s_PlacePlayer(playerw,32,true);str+="  |  ";str+=s_PlacePlayer(playerw,31,true);str+="  |  ";str+=s_PlacePlayer(playerw,30,true);str+="  |  ";str+=s_PlacePlayer(playerw,29,true);str+="  |  ";str+=s_PlacePlayer(playerw,28,true);str+="  |   ";str+=s_PlacePlayer(playerw,27,true);str+="   |";}
         else if(i==41){str+="|   ";str+=s_PlacePlayer(playerw,0,false);str+="   |  ";str+=s_PlacePlayer(playerw,35,false);str+="  |  ";str+=s_PlacePlayer(playerw,34,false);str+="  |  ";str+=s_PlacePlayer(playerw,33,false);str+="  |  ";str+=s_PlacePlayer(playerw,32,false);str+="  |  ";str+=s_PlacePlayer(playerw,31,false);str+="  |  ";str+=s_PlacePlayer(playerw,30,false);str+="  |  ";str+=s_PlacePlayer(playerw,29,false);str+="  |  ";str+=s_PlacePlayer(playerw,28,false);str+="  |   ";str+=s_PlacePlayer(playerw,27,false);str+="   |";}
         else if(i==42){str+="|__________|________|________|________|________|________|________|________|________|__________|";}
        if(save==false){if(Animation==true){i++;cout<<str<<endl;str="";Sleep(d);}}
         else{i++;str+="\n";}
    }while(i<=42&&(Animation==true||save==true));
    return str;

}

void s_intializeData(GameData g){

    //Place Type - 1.place 2.vacation 3.chance 4.event 5.special 6.casino 7.tax
    g.placetype[0]=5;
    g.placetype[1]=1;
    g.placetype[2]=6;
    g.placetype[3]=1;
    g.placetype[4]=2;
    g.placetype[5]=1;
    g.placetype[6]=3;
    g.placetype[7]=1;
    g.placetype[8]=1;
    g.placetype[9]=5;
    g.placetype[10]=1;
    g.placetype[11]=2;
    g.placetype[12]=1;
    g.placetype[13]=4;
    g.placetype[14]=1;
    g.placetype[15]=1;
    g.placetype[16]=3;
    g.placetype[17]=1;
    g.placetype[18]=5;
    g.placetype[19]=1;
    g.placetype[20]=2;
    g.placetype[21]=1;
    g.placetype[22]=4;
    g.placetype[23]=1;
    g.placetype[24]=2;
    g.placetype[25]=1;
    g.placetype[26]=1;
    g.placetype[27]=5;
    g.placetype[28]=1;
    g.placetype[29]=3;
    g.placetype[30]=1;
    g.placetype[31]=1;
    g.placetype[32]=4;
    g.placetype[33]=1;
    g.placetype[34]=7;
    g.placetype[35]=1;
    //Buildings
    g.placename[0]="start";
    g.placename[1]="Tunis";
    g.placename[2]="Casino";
    g.placename[3]="Cairo";
    g.placename[4]="Guam";
    g.placename[5]="Bangkok";
    g.placename[6]="Chance";
    g.placename[7]="New Deli";
    g.placename[8]="Singarpore";
    g.placename[9]="Jail";
    g.placename[10]="Brasilia";
    g.placename[11]="Bali";
    g.placename[12]="Santiago";
    g.placename[13]="Event";
    g.placename[14]="Oslo";
    g.placename[15]="Stockholm";
    g.placename[16]="Chance";
    g.placename[17]="Moscow";
    g.placename[18]="Jackpot";
    g.placename[19]="Athens";
    g.placename[20]="Puerto Rico";
    g.placename[21]="Rome";
    g.placename[22]="Event";
    g.placename[23]="Berlin";
    g.placename[24]="Sicilia";
    g.placename[25]="Pari";
    g.placename[26]="London";
    g.placename[27]="Airport";
    g.placename[28]="Beijing";
    g.placename[29]="Chance";
    g.placename[30]="Tokyo";
    g.placename[31]="Seoul";
    g.placename[32]="Event";
    g.placename[33]="New York";
    g.placename[34]="Tax";
    g.placename[35]="Los Angeles";
    g.buildingname[0]="Land";
    g.buildingname[1]="House";
    g.buildingname[2]="Inn";
    g.buildingname[3]="Hotel";
    g.buildingname[4]="Landmark";

    //letters
    g.letter[0][0][0]="           ";
    g.letter[0][0][1]="     /\\    ";
    g.letter[0][0][2]="    /  \\   ";
    g.letter[0][0][3]="   / /\\ \\  ";
    g.letter[0][0][4]="  / ____ \\ ";
    g.letter[0][0][5]=" /_/    \\_\\";

    g.letter[0][1][0]="  ____  ";
    g.letter[0][1][1]=" |  _ \\ ";
    g.letter[0][1][2]=" | |_) |";
    g.letter[0][1][3]=" |  _ < ";
    g.letter[0][1][4]=" | |_) |";
    g.letter[0][1][5]=" |____/ ";

    g.letter[0][2][0]="   _____ ";
    g.letter[0][2][1]="  / ____|";
    g.letter[0][2][2]=" | |     ";
    g.letter[0][2][3]=" | |     ";
    g.letter[0][2][4]=" | |____ ";
    g.letter[0][2][5]="  \\_____|";

    g.letter[0][3][0]="  _____  ";
    g.letter[0][3][1]=" |  __ \\ ";
    g.letter[0][3][2]=" | |  | |";
    g.letter[0][3][3]=" | |  | |";
    g.letter[0][3][4]=" | |__| |";
    g.letter[0][3][5]=" |_____/ ";

    g.letter[0][4][0]="  ______ ";
    g.letter[0][4][1]=" |  ____|";
    g.letter[0][4][2]=" | |__   ";
    g.letter[0][4][3]=" |  __|  ";
    g.letter[0][4][4]=" | |____ ";
    g.letter[0][4][5]=" |______|";

    g.letter[0][5][0]="  ______ ";
    g.letter[0][5][1]=" |  ____|";
    g.letter[0][5][2]=" | |__   ";
    g.letter[0][5][3]=" |  __|  ";
    g.letter[0][5][4]=" | |     ";
    g.letter[0][5][5]=" |_|     ";

    g.letter[0][6][0]="   _____ ";
    g.letter[0][6][1]="  / ____|";
    g.letter[0][6][2]=" | |  __ ";
    g.letter[0][6][3]=" | | |_ |";
    g.letter[0][6][4]=" | |__| |";
    g.letter[0][6][5]="  \\_____|";

    g.letter[0][7][0]="  _    _ ";
    g.letter[0][7][1]=" | |  | |";
    g.letter[0][7][2]=" | |__| |";
    g.letter[0][7][3]=" |  __  |";
    g.letter[0][7][4]=" | |  | |";
    g.letter[0][7][5]=" |_|  |_|";

    g.letter[0][8][0]="  _____ ";
    g.letter[0][8][1]=" |_   _|";
    g.letter[0][8][2]="   | |  ";
    g.letter[0][8][3]="   | |  ";
    g.letter[0][8][4]="  _| |_ ";
    g.letter[0][8][5]=" |_____|";

    g.letter[0][9][0]="       _ ";
    g.letter[0][9][1]="      | |";
    g.letter[0][9][2]="      | |";
    g.letter[0][9][3]="  _   | |";
    g.letter[0][9][4]=" | |__| |";
    g.letter[0][9][5]="  \\____/ ";

    g.letter[0][10][0]="  _  __";
    g.letter[0][10][1]=" | |/ /";
    g.letter[0][10][2]=" | ' / ";
    g.letter[0][10][3]=" |  <  ";
    g.letter[0][10][4]=" | . \\ ";
    g.letter[0][10][5]=" |_|\\_\\";

    g.letter[0][11][0]="  _      ";
    g.letter[0][11][1]=" | |     ";
    g.letter[0][11][2]=" | |     ";
    g.letter[0][11][3]=" | |     ";
    g.letter[0][11][4]=" | |____ ";
    g.letter[0][11][5]=" |______|";

    g.letter[0][12][0]="  __  __ ";
    g.letter[0][12][1]=" |  \\/  |";
    g.letter[0][12][2]=" | \\  / |";
    g.letter[0][12][3]=" | |\\/| |";
    g.letter[0][12][4]=" | |  | |";
    g.letter[0][12][5]=" |_|  |_|";

    g.letter[0][13][0]="  _   _ ";
    g.letter[0][13][1]=" | \\ | |";
    g.letter[0][13][2]=" |  \\| |";
    g.letter[0][13][3]=" | . ` |";
    g.letter[0][13][4]=" | |\\  |";
    g.letter[0][13][5]=" |_| \\_|";

    g.letter[0][14][0]="   ____  ";
    g.letter[0][14][1]="  / __ \\ ";
    g.letter[0][14][2]=" | |  | |";
    g.letter[0][14][3]=" | |  | |";
    g.letter[0][14][4]=" | |__| |";
    g.letter[0][14][5]="  \\____/ ";

    g.letter[0][15][0]="  _____  ";
    g.letter[0][15][1]=" |  __ \\ ";
    g.letter[0][15][2]=" | |__) |";
    g.letter[0][15][3]=" |  ___/ ";
    g.letter[0][15][4]=" | |     ";
    g.letter[0][15][5]=" |_|     ";

    g.letter[0][16][0]="   ____  ";
    g.letter[0][16][1]="  / __ \\ ";
    g.letter[0][16][2]=" | |  | |";
    g.letter[0][16][3]=" | |  | |";
    g.letter[0][16][4]=" | |__| |";
    g.letter[0][16][5]="  \\___\\_\\";

    g.letter[0][17][0]="  _____  ";
    g.letter[0][17][1]=" |  __ \\ ";
    g.letter[0][17][2]=" | |__) |";
    g.letter[0][17][3]=" |  _  / ";
    g.letter[0][17][4]=" | | \\ \\ ";
    g.letter[0][17][5]=" |_|  \\_\\";

    g.letter[0][18][0]="   _____ ";
    g.letter[0][18][1]="  / ____|";
    g.letter[0][18][2]=" | (___  ";
    g.letter[0][18][3]="  \\___ \\ ";
    g.letter[0][18][4]="  ____) |";
    g.letter[0][18][5]=" |_____/ ";

    g.letter[0][19][0]="  _______ ";
    g.letter[0][19][1]=" |__   __|";
    g.letter[0][19][2]="    | |   ";
    g.letter[0][19][3]="    | |   ";
    g.letter[0][19][4]="    | |   ";
    g.letter[0][19][5]="    |_|   ";

    g.letter[0][20][0]="  _    _ ";
    g.letter[0][20][1]=" | |  | |";
    g.letter[0][20][2]=" | |  | |";
    g.letter[0][20][3]=" | |  | |";
    g.letter[0][20][4]=" | |__| |";
    g.letter[0][20][5]="  \\____/ ";

    g.letter[0][21][0]=" __      __";
    g.letter[0][21][1]=" \\ \\    / /";
    g.letter[0][21][2]="  \\ \\  / / ";
    g.letter[0][21][3]="   \\ \\/ /  ";
    g.letter[0][21][4]="    \\  /   ";
    g.letter[0][21][5]="     \\/    ";

    g.letter[0][22][0]=" __          __";
    g.letter[0][22][1]=" \\ \\        / /";
    g.letter[0][22][2]="  \\ \\  /\\  / / ";
    g.letter[0][22][3]="   \\ \\/  \\/ /  ";
    g.letter[0][22][4]="    \\  /\\  /   ";
    g.letter[0][22][5]="     \\/  \\/    ";

    g.letter[0][23][0]=" __   __";
    g.letter[0][23][1]=" \\ \\ / /";
    g.letter[0][23][2]="  \\ V / ";
    g.letter[0][23][3]="   > <  ";
    g.letter[0][23][4]="  / . \\ ";
    g.letter[0][23][5]=" /_/ \\_\\";

    g.letter[0][24][0]=" __     __";
    g.letter[0][24][1]=" \\ \\   / /";
    g.letter[0][24][2]="  \\ \\_/ / ";
    g.letter[0][24][3]="   \\   /  ";
    g.letter[0][24][4]="    | |   ";
    g.letter[0][24][5]="    |_|   ";

    g.letter[0][25][0]="  ______";
    g.letter[0][25][1]=" |___  /";
    g.letter[0][25][2]="    / / ";
    g.letter[0][25][3]="   / /  ";
    g.letter[0][25][4]="  / /__ ";
    g.letter[0][25][5]=" /_____|";

    g.letter[1][0][0]="        ";
    g.letter[1][0][1]="        ";
    g.letter[1][0][2]="   __ _ ";
    g.letter[1][0][3]="  / _` |";
    g.letter[1][0][4]=" | (_| |";
    g.letter[1][0][5]="  \\__,_|";

    g.letter[1][1][0]="  _     ";
    g.letter[1][1][1]=" | |    ";
    g.letter[1][1][2]=" | |__  ";
    g.letter[1][1][3]=" | '_ \\ ";
    g.letter[1][1][4]=" | |_) |";
    g.letter[1][1][5]=" |_.__/ ";

    g.letter[1][2][0]="       ";
    g.letter[1][2][1]="       ";
    g.letter[1][2][2]="   ___ ";
    g.letter[1][2][3]="  / __|";
    g.letter[1][2][4]=" | (__ ";
    g.letter[1][2][5]="  \\___|";

    g.letter[1][3][0]="      _ ";
    g.letter[1][3][1]="     | |";
    g.letter[1][3][2]="   __| |";
    g.letter[1][3][3]="  / _` |";
    g.letter[1][3][4]=" | (_| |";
    g.letter[1][3][5]="  \\__,_|";

    g.letter[1][4][0]="       ";
    g.letter[1][4][1]="       ";
    g.letter[1][4][2]="   ___ ";
    g.letter[1][4][3]="  / _ \\";
    g.letter[1][4][4]=" |  __/";
    g.letter[1][4][5]="  \\___|";

    g.letter[1][5][0]="   __ ";
    g.letter[1][5][1]="  / _|";
    g.letter[1][5][2]=" | |_ ";
    g.letter[1][5][3]=" |  _|";
    g.letter[1][5][4]=" | |  ";
    g.letter[1][5][5]=" |_|  ";

    g.letter[1][6][0]="   __ _ ";
    g.letter[1][6][1]="  / _` |";
    g.letter[1][6][2]=" | (_| |";
    g.letter[1][6][3]="  \\__, |";
    g.letter[1][6][4]="   __/ |";
    g.letter[1][6][5]="  |___/ ";

    g.letter[1][7][0]="  _     ";
    g.letter[1][7][1]=" | |    ";
    g.letter[1][7][2]=" | |__  ";
    g.letter[1][7][3]=" | '_ \\ ";
    g.letter[1][7][4]=" | | | |";
    g.letter[1][7][5]=" |_| |_|";

    g.letter[1][8][0]="  _ ";
    g.letter[1][8][1]=" (_)";
    g.letter[1][8][2]="  _ ";
    g.letter[1][8][3]=" | |";
    g.letter[1][8][4]=" | |";
    g.letter[1][8][5]=" |_|";

    g.letter[1][9][0]="     _ ";
    g.letter[1][9][1]="    (_)";
    g.letter[1][9][2]="     _ ";
    g.letter[1][9][3]="    | |";
    g.letter[1][9][4]="  __/ |";
    g.letter[1][9][5]=" |___/ ";

    g.letter[1][10][0]="  _    ";
    g.letter[1][10][1]=" | |   ";
    g.letter[1][10][2]=" | | __";
    g.letter[1][10][3]=" | |/ /";
    g.letter[1][10][4]=" |   < ";
    g.letter[1][10][5]=" |_|\\_\\";

    g.letter[1][11][0]="  _ ";
    g.letter[1][11][1]=" | |";
    g.letter[1][11][2]=" | |";
    g.letter[1][11][3]=" | |";
    g.letter[1][11][4]=" | |";
    g.letter[1][11][5]=" |_|";

    g.letter[1][12][0]="            ";
    g.letter[1][12][1]="            ";
    g.letter[1][12][2]="  _ __ ___  ";
    g.letter[1][12][3]=" | '_ ` _ \\ ";
    g.letter[1][12][4]=" | | | | | |";
    g.letter[1][12][5]=" |_| |_| |_|";

    g.letter[1][13][0]="        ";
    g.letter[1][13][1]="        ";
    g.letter[1][13][2]="  _ __  ";
    g.letter[1][13][3]=" | '_ \\ ";
    g.letter[1][13][4]=" | | | |";
    g.letter[1][13][5]=" |_| |_|";

    g.letter[1][14][0]="        ";
    g.letter[1][14][1]="        ";
    g.letter[1][14][2]="   ___  ";
    g.letter[1][14][3]="  / _ \\ ";
    g.letter[1][14][4]=" | (_) |";
    g.letter[1][14][5]="  \\___/ ";

    g.letter[1][15][0]="  _ __  ";
    g.letter[1][15][1]=" | '_ \\ ";
    g.letter[1][15][2]=" | |_) |";
    g.letter[1][15][3]=" | .__/ ";
    g.letter[1][15][4]=" | |    ";
    g.letter[1][15][5]=" |_|    ";

    g.letter[1][16][0]="   __ _ ";
    g.letter[1][16][1]="  / _` |";
    g.letter[1][16][2]=" | (_| |";
    g.letter[1][16][3]="  \\__, |";
    g.letter[1][16][4]="     | |";
    g.letter[1][16][5]="     |_|";

    g.letter[1][17][0]="       ";
    g.letter[1][17][1]="       ";
    g.letter[1][17][2]="  _ __ ";
    g.letter[1][17][3]=" | '__|";
    g.letter[1][17][4]=" | |   ";
    g.letter[1][17][5]=" |_|   ";

    g.letter[1][18][0]="      ";
    g.letter[1][18][1]="      ";
    g.letter[1][18][2]="  ___ ";
    g.letter[1][18][3]=" / __|";
    g.letter[1][18][4]=" \\__ \\";
    g.letter[1][18][5]=" |___/";

    g.letter[1][19][0]="  _   ";
    g.letter[1][19][1]=" | |  ";
    g.letter[1][19][2]=" | |_ ";
    g.letter[1][19][3]=" | __|";
    g.letter[1][19][4]=" | |_ ";
    g.letter[1][19][5]="  \\__|";

    g.letter[1][20][0]="        ";
    g.letter[1][20][1]="        ";
    g.letter[1][20][2]="  _   _ ";
    g.letter[1][20][3]=" | | | |";
    g.letter[1][20][4]=" | |_| |";
    g.letter[1][20][5]="  \\__,_|";

    g.letter[1][21][0]="        ";
    g.letter[1][21][1]="        ";
    g.letter[1][21][2]=" __   __";
    g.letter[1][21][3]=" \\ \\ / /";
    g.letter[1][21][4]="  \\ V / ";
    g.letter[1][21][5]="   \\_/  ";

    g.letter[1][22][0]="           ";
    g.letter[1][22][1]="           ";
    g.letter[1][22][2]=" __      __";
    g.letter[1][22][3]=" \\ \\ /\\ / /";
    g.letter[1][22][4]="  \\ V  V / ";
    g.letter[1][22][5]="   \\_/\\_/  ";

    g.letter[1][23][0]="       ";
    g.letter[1][23][1]="       ";
    g.letter[1][23][2]=" __  __";
    g.letter[1][23][3]=" \\ \\/ /";
    g.letter[1][23][4]="  >  < ";
    g.letter[1][23][5]=" /_/\\_\\";

    g.letter[0][24][0]="  _   _ ";
    g.letter[0][24][1]=" | | | |";
    g.letter[0][24][2]=" | |_| |";
    g.letter[0][24][3]="  \\__, |";
    g.letter[0][24][4]="   __/ |";
    g.letter[0][24][5]="  |___/ ";

    g.letter[0][25][0]="      ";
    g.letter[0][25][1]="      ";
    g.letter[0][25][2]="  ____";
    g.letter[0][25][3]=" |_  /";
    g.letter[0][25][4]="  / / ";
    g.letter[0][25][5]=" /___|";

    g.letter[2][0][0]="  __ ";
    g.letter[2][0][1]=" /_ |";
    g.letter[2][0][2]="  | |";
    g.letter[2][0][3]="  | |";
    g.letter[2][0][4]="  | |";
    g.letter[2][0][5]="  |_|";

    g.letter[2][1][0]="  ___  ";
    g.letter[2][1][1]=" |__ \\ ";
    g.letter[2][1][2]="    ) |";
    g.letter[2][1][3]="   / / ";
    g.letter[2][1][4]="  / /_ ";
    g.letter[2][1][5]=" |____|";

    g.letter[2][2][0]="  ____  ";
    g.letter[2][2][1]=" |___ \\ ";
    g.letter[2][2][2]="   __) |";
    g.letter[2][2][3]="  |__ < ";
    g.letter[2][2][4]="  ___) |";
    g.letter[2][2][5]=" |____/ ";

    g.letter[2][3][0]="  _  _   ";
    g.letter[2][3][1]=" | || |  ";
    g.letter[2][3][2]=" | || |_ ";
    g.letter[2][3][3]=" |__   _|";
    g.letter[2][3][4]="    | |  ";
    g.letter[2][3][5]="    |_|  ";

    g.letter[2][4][0]="  _____ ";
    g.letter[2][4][1]=" | ____|";
    g.letter[2][4][2]=" | |__  ";
    g.letter[2][4][3]=" |___ \\ ";
    g.letter[2][4][4]="  ___) |";
    g.letter[2][4][5]=" |____/ ";

    g.letter[2][5][0]="    __  ";
    g.letter[2][5][1]="   / /  ";
    g.letter[2][5][2]="  / /_  ";
    g.letter[2][5][3]=" | '_ \\ ";
    g.letter[2][5][4]=" | (_) |";
    g.letter[2][5][5]="  \\___/ ";

    g.letter[2][6][0]="  ______ ";
    g.letter[2][6][1]=" |____  |";
    g.letter[2][6][2]="     / / ";
    g.letter[2][6][3]="    / /  ";
    g.letter[2][6][4]="   / /   ";
    g.letter[2][6][5]="  /_/    ";

    g.letter[2][7][0]="   ___  ";
    g.letter[2][7][1]="  / _ \\ ";
    g.letter[2][7][2]=" | (_) |";
    g.letter[2][7][3]="  > _ < ";
    g.letter[2][7][4]=" | (_) |";
    g.letter[2][7][5]="  \\___/ ";

    g.letter[2][8][0]="   ___  ";
    g.letter[2][8][1]="  / _ \\ ";
    g.letter[2][8][2]=" | (_) |";
    g.letter[2][8][3]="  \\__, |";
    g.letter[2][8][4]="    / / ";
    g.letter[2][8][5]="   /_/  ";

    g.letter[2][9][0]="   ___  ";
    g.letter[2][9][1]="  / _ \\ ";
    g.letter[2][9][2]=" | | | |";
    g.letter[2][9][3]=" | | | |";
    g.letter[2][9][4]=" | |_| |";
    g.letter[2][9][5]="  \\___/ ";
}




/*
 *
string[3][26][6]
    letter[0][0][0]="           ";
    letter[0][0][1]="     /\    ";
    letter[0][0][2]="    /  \   ";
    letter[0][0][3]="   / /\ \  ";
    letter[0][0][4]="  / ____ \ ";
    letter[0][0][5]=" /_/    \_\";

    letter[0][1][0]="  ____  ";
    letter[0][1][1]=" |  _ \ ";
    letter[0][1][2]=" | |_) |";
    letter[0][1][3]=" |  _ < ";
    letter[0][1][4]=" | |_) |";
    letter[0][1][5]=" |____/ ";

    letter[0][2][0]="   _____ ";
    letter[0][2][1]="  / ____|";
    letter[0][2][2]=" | |     ";
    letter[0][2][3]=" | |     ";
    letter[0][2][4]=" | |____ ";
    letter[0][2][5]="  \_____|";

    letter[0][3][0]="  _____  ";
    letter[0][3][1]=" |  __ \ ";
    letter[0][3][2]=" | |  | |";
    letter[0][3][3]=" | |  | |";
    letter[0][3][4]=" | |__| |";
    letter[0][3][5]=" |_____/ ";

    letter[0][4][0]="  ______ ";
    letter[0][4][1]=" |  ____|";
    letter[0][4][2]=" | |__   ";
    letter[0][4][3]=" |  __|  ";
    letter[0][4][4]=" | |____ ";
    letter[0][4][5]=" |______|";

    letter[0][5][0]="  ______ ";
    letter[0][5][1]=" |  ____|";
    letter[0][5][2]=" | |__   ";
    letter[0][5][3]=" |  __|  ";
    letter[0][5][4]=" | |     ";
    letter[0][5][5]=" |_|     ";

    letter[0][6][0]="   _____ ";
    letter[0][6][1]="  / ____|";
    letter[0][6][2]=" | |  __ ";
    letter[0][6][3]=" | | |_ |";
    letter[0][6][4]=" | |__| |";
    letter[0][6][5]="  \_____|";

    letter[0][7][0]="  _    _ ";
    letter[0][7][1]=" | |  | |";
    letter[0][7][2]=" | |__| |";
    letter[0][7][3]=" |  __  |";
    letter[0][7][4]=" | |  | |";
    letter[0][7][5]=" |_|  |_|";

    letter[0][8][0]="  _____ ";
    letter[0][8][1]=" |_   _|";
    letter[0][8][2]="   | |  ";
    letter[0][8][3]="   | |  ";
    letter[0][8][4]="  _| |_ ";
    letter[0][8][5]=" |_____|";

    letter[0][9][0]="       _ ";
    letter[0][9][1]="      | |";
    letter[0][9][2]="      | |";
    letter[0][9][3]="  _   | |";
    letter[0][9][4]=" | |__| |";
    letter[0][9][5]="  \____/ ";

    letter[0][10][0]="  _  __";
    letter[0][10][1]=" | |/ /";
    letter[0][10][2]=" | ' / ";
    letter[0][10][3]=" |  <  ";
    letter[0][10][4]=" | . \ ";
    letter[0][10][5]=" |_|\_\";

    letter[0][11][0]="  _      ";
    letter[0][11][1]=" | |     ";
    letter[0][11][2]=" | |     ";
    letter[0][11][3]=" | |     ";
    letter[0][11][4]=" | |____ ";
    letter[0][11][5]=" |______|";

    letter[0][12][0]="  __  __ ";
    letter[0][12][1]=" |  \/  |";
    letter[0][12][2]=" | \  / |";
    letter[0][12][3]=" | |\/| |";
    letter[0][12][4]=" | |  | |";
    letter[0][12][5]=" |_|  |_|";

    letter[0][13][0]="  _   _ ";
    letter[0][13][1]=" | \ | |";
    letter[0][13][2]=" |  \| |";
    letter[0][13][3]=" | . ` |";
    letter[0][13][4]=" | |\  |";
    letter[0][13][5]=" |_| \_|";

    letter[0][14][0]="   ____  ";
    letter[0][14][1]="  / __ \ ";
    letter[0][14][2]=" | |  | |";
    letter[0][14][3]=" | |  | |";
    letter[0][14][4]=" | |__| |";
    letter[0][14][5]="  \____/ ";

    letter[0][15][0]="  _____  ";
    letter[0][15][1]=" |  __ \ ";
    letter[0][15][2]=" | |__) |";
    letter[0][15][3]=" |  ___/ ";
    letter[0][15][4]=" | |     ";
    letter[0][15][5]=" |_|     ";

    letter[0][16][0]="   ____  ";
    letter[0][16][1]="  / __ \ ";
    letter[0][16][2]=" | |  | |";
    letter[0][16][3]=" | |  | |";
    letter[0][16][4]=" | |__| |";
    letter[0][16][5]="  \___\_\";

    letter[0][17][0]="  _____  ";
    letter[0][17][1]=" |  __ \ ";
    letter[0][17][2]=" | |__) |";
    letter[0][17][3]=" |  _  / ";
    letter[0][17][4]=" | | \ \ ";
    letter[0][17][5]=" |_|  \_\";

    letter[0][18][0]="   _____ ";
    letter[0][18][1]="  / ____|";
    letter[0][18][2]=" | (___  ";
    letter[0][18][3]="  \___ \ ";
    letter[0][18][4]="  ____) |";
    letter[0][18][5]=" |_____/ ";

    letter[0][19][0]="  _______ ";
    letter[0][19][1]=" |__   __|";
    letter[0][19][2]="    | |   ";
    letter[0][19][3]="    | |   ";
    letter[0][19][4]="    | |   ";
    letter[0][19][5]="    |_|   ";

    letter[0][20][0]="  _    _ ";
    letter[0][20][1]=" | |  | |";
    letter[0][20][2]=" | |  | |";
    letter[0][20][3]=" | |  | |";
    letter[0][20][4]=" | |__| |";
    letter[0][20][5]="  \____/ ";

    letter[0][21][0]=" __      __";
    letter[0][21][1]=" \ \    / /";
    letter[0][21][2]="  \ \  / / ";
    letter[0][21][3]="   \ \/ /  ";
    letter[0][21][4]="    \  /   ";
    letter[0][21][5]="     \/    ";

    letter[0][22][0]=" __          __";
    letter[0][22][1]=" \ \        / /";
    letter[0][22][2]="  \ \  /\  / / ";
    letter[0][22][3]="   \ \/  \/ /  ";
    letter[0][22][4]="    \  /\  /   ";
    letter[0][22][5]="     \/  \/    ";

    letter[0][23][0]=" __   __";
    letter[0][23][1]=" \ \ / /";
    letter[0][23][2]="  \ V / ";
    letter[0][23][3]="   > <  ";
    letter[0][23][4]="  / . \ ";
    letter[0][23][5]=" /_/ \_\";

    letter[0][24][0]=" __     __";
    letter[0][24][1]=" \ \   / /";
    letter[0][24][2]="  \ \_/ / ";
    letter[0][24][3]="   \   /  ";
    letter[0][24][4]="    | |   ";
    letter[0][24][5]="    |_|   ";

    letter[0][25][0]="  ______";
    letter[0][25][1]=" |___  /";
    letter[0][25][2]="    / / ";
    letter[0][25][3]="   / /  ";
    letter[0][25][4]="  / /__ ";
    letter[0][25][5]=" /_____|";

    letter[1][0][0]="        ";
    letter[1][0][1]="        ";
    letter[1][0][2]="   __ _ ";
    letter[1][0][3]="  / _` |";
    letter[1][0][4]=" | (_| |";
    letter[1][0][5]="  \__,_|";

    letter[1][1][0]="  _     ";
    letter[1][1][1]=" | |    ";
    letter[1][1][2]=" | |__  ";
    letter[1][1][3]=" | '_ \ ";
    letter[1][1][4]=" | |_) |";
    letter[1][1][5]=" |_.__/ ";

    letter[1][2][0]="       ";
    letter[1][2][1]="       ";
    letter[1][2][2]="   ___ ";
    letter[1][2][3]="  / __|";
    letter[1][2][4]=" | (__ ";
    letter[1][2][5]="  \___|";

    letter[1][3][0]="      _ ";
    letter[1][3][1]="     | |";
    letter[1][3][2]="   __| |";
    letter[1][3][3]="  / _` |";
    letter[1][3][4]=" | (_| |";
    letter[1][3][5]="  \__,_|";

    letter[1][4][0]="       ";
    letter[1][4][1]="       ";
    letter[1][4][2]="   ___ ";
    letter[1][4][3]="  / _ \";
    letter[1][4][4]=" |  __/";
    letter[1][4][5]="  \___|";

    letter[1][5][0]="   __ ";
    letter[1][5][1]="  / _|";
    letter[1][5][2]=" | |_ ";
    letter[1][5][3]=" |  _|";
    letter[1][5][4]=" | |  ";
    letter[1][5][5]=" |_|  ";

    letter[1][6][0]="   __ _ ";
    letter[1][6][1]="  / _` |";
    letter[1][6][2]=" | (_| |";
    letter[1][6][3]="  \__, |";
    letter[1][6][4]="   __/ |";
    letter[1][6][5]="  |___/ ";

    letter[1][7][0]="  _     ";
    letter[1][7][1]=" | |    ";
    letter[1][7][2]=" | |__  ";
    letter[1][7][3]=" | '_ \ ";
    letter[1][7][4]=" | | | |";
    letter[1][7][5]=" |_| |_|";

    letter[1][8][0]="  _ ";
    letter[1][8][1]=" (_)";
    letter[1][8][2]="  _ ";
    letter[1][8][3]=" | |";
    letter[1][8][4]=" | |";
    letter[1][8][5]=" |_|";

    letter[1][9][0]="     _ ";
    letter[1][9][1]="    (_)";
    letter[1][9][2]="     _ ";
    letter[1][9][3]="    | |";
    letter[1][9][4]="  __/ |";
    letter[1][9][5]=" |___/ ";

    letter[1][10][0]="  _    ";
    letter[1][10][1]=" | |   ";
    letter[1][10][2]=" | | __";
    letter[1][10][3]=" | |/ /";
    letter[1][10][4]=" |   < ";
    letter[1][10][5]=" |_|\_\";

    letter[1][11][0]="  _ ";
    letter[1][11][1]=" | |";
    letter[1][11][2]=" | |";
    letter[1][11][3]=" | |";
    letter[1][11][4]=" | |";
    letter[1][11][5]=" |_|";

    letter[1][12][0]="            ";
    letter[1][12][1]="            ";
    letter[1][12][2]="  _ __ ___  ";
    letter[1][12][3]=" | '_ ` _ \ ";
    letter[1][12][4]=" | | | | | |";
    letter[1][12][5]=" |_| |_| |_|";

    letter[1][13][0]="        ";
    letter[1][13][1]="        ";
    letter[1][13][2]="  _ __  ";
    letter[1][13][3]=" | '_ \ ";
    letter[1][13][4]=" | | | |";
    letter[1][13][5]=" |_| |_|";

    letter[1][14][0]="        ";
    letter[1][14][1]="        ";
    letter[1][14][2]="   ___  ";
    letter[1][14][3]="  / _ \ ";
    letter[1][14][4]=" | (_) |";
    letter[1][14][5]="  \___/ ";

    letter[1][15][0]="  _ __  ";
    letter[1][15][1]=" | '_ \ ";
    letter[1][15][2]=" | |_) |";
    letter[1][15][3]=" | .__/ ";
    letter[1][15][4]=" | |    ";
    letter[1][15][5]=" |_|    ";

    letter[1][16][0]="   __ _ ";
    letter[1][16][1]="  / _` |";
    letter[1][16][2]=" | (_| |";
    letter[1][16][3]="  \__, |";
    letter[1][16][4]="     | |";
    letter[1][16][5]="     |_|";

    letter[1][17][0]="       ";
    letter[1][17][1]="       ";
    letter[1][17][2]="  _ __ ";
    letter[1][17][3]=" | '__|";
    letter[1][17][4]=" | |   ";
    letter[1][17][5]=" |_|   ";

    letter[1][18][0]="      ";
    letter[1][18][1]="      ";
    letter[1][18][2]="  ___ ";
    letter[1][18][3]=" / __|";
    letter[1][18][4]=" \__ \";
    letter[1][18][5]=" |___/";

    letter[1][19][0]="  _   ";
    letter[1][19][1]=" | |  ";
    letter[1][19][2]=" | |_ ";
    letter[1][19][3]=" | __|";
    letter[1][19][4]=" | |_ ";
    letter[1][19][5]="  \__|";

    letter[1][20][0]="        ";
    letter[1][20][1]="        ";
    letter[1][20][2]="  _   _ ";
    letter[1][20][3]=" | | | |";
    letter[1][20][4]=" | |_| |";
    letter[1][20][5]="  \__,_|";

    letter[1][21][0]="        ";
    letter[1][21][1]="        ";
    letter[1][21][2]=" __   __";
    letter[1][21][3]=" \ \ / /";
    letter[1][21][4]="  \ V / ";
    letter[1][21][5]="   \_/  ";

    letter[1][22][0]="           ";
    letter[1][22][1]="           ";
    letter[1][22][2]=" __      __";
    letter[1][22][3]=" \ \ /\ / /";
    letter[1][22][4]="  \ V  V / ";
    letter[1][22][5]="   \_/\_/  ";

    letter[1][23][0]="       ";
    letter[1][23][1]="       ";
    letter[1][23][2]=" __  __";
    letter[1][23][3]=" \ \/ /";
    letter[1][23][4]="  >  < ";
    letter[1][23][5]=" /_/\_\";

    letter[0][24][0]="  _   _ ";
    letter[0][24][1]=" | | | |";
    letter[0][24][2]=" | |_| |";
    letter[0][24][3]="  \__, |";
    letter[0][24][4]="   __/ |";
    letter[0][24][5]="  |___/ ";

    letter[0][25][0]="      ";
    letter[0][25][1]="      ";
    letter[0][25][2]="  ____";
    letter[0][25][3]=" |_  /";
    letter[0][25][4]="  / / ";
    letter[0][25][5]=" /___|";

    letter[2][0][0]="  __ ";
    letter[2][0][1]=" /_ |";
    letter[2][0][2]="  | |";
    letter[2][0][3]="  | |";
    letter[2][0][4]="  | |";
    letter[2][0][5]="  |_|";

    letter[2][1][0]="  ___  ";
    letter[2][1][1]=" |__ \ ";
    letter[2][1][2]="    ) |";
    letter[2][1][3]="   / / ";
    letter[2][1][4]="  / /_ ";
    letter[2][1][5]=" |____|";

    letter[2][2][0]="  ____  ";
    letter[2][2][1]=" |___ \ ";
    letter[2][2][2]="   __) |";
    letter[2][2][3]="  |__ < ";
    letter[2][2][4]="  ___) |";
    letter[2][2][5]=" |____/ ";

    letter[2][3][0]="  _  _   ";
    letter[2][3][1]=" | || |  ";
    letter[2][3][2]=" | || |_ ";
    letter[2][3][3]=" |__   _|";
    letter[2][3][4]="    | |  ";
    letter[2][3][5]="    |_|  ";

    letter[2][4][0]="  _____ ";
    letter[2][4][1]=" | ____|";
    letter[2][4][2]=" | |__  ";
    letter[2][4][3]=" |___ \ ";
    letter[2][4][4]="  ___) |";
    letter[2][4][5]=" |____/ ";

    letter[2][5][0]="    __  ";
    letter[2][5][1]="   / /  ";
    letter[2][5][2]="  / /_  ";
    letter[2][5][3]=" | '_ \ ";
    letter[2][5][4]=" | (_) |";
    letter[2][5][5]="  \___/ ";

    letter[2][6][0]="  ______ ";
    letter[2][6][1]=" |____  |";
    letter[2][6][2]="     / / ";
    letter[2][6][3]="    / /  ";
    letter[2][6][4]="   / /   ";
    letter[2][6][5]="  /_/    ";

    letter[2][7][0]="   ___  ";
    letter[2][7][1]="  / _ \ ";
    letter[2][7][2]=" | (_) |";
    letter[2][7][3]="  > _ < ";
    letter[2][7][4]=" | (_) |";
    letter[2][7][5]="  \___/ ";

    letter[2][8][0]="   ___  ";
    letter[2][8][1]="  / _ \ ";
    letter[2][8][2]=" | (_) |";
    letter[2][8][3]="  \__, |";
    letter[2][8][4]="    / / ";
    letter[2][8][5]="   /_/  ";

    letter[2][9][0]="   ___  ";
    letter[2][9][1]="  / _ \ ";
    letter[2][9][2]=" | | | |";
    letter[2][9][3]=" | | | |";
    letter[2][9][4]=" | |_| |";
    letter[2][9][5]="  \___/ ";


 Place[place36][order]

 order 1 = place name
 order 2 = place type
  order 3 = place owner
 order 4 = building level & price & selling price
 order 5 = place special effect
 order 6 =

 Player[player4][order]

 order 1 = where is player
 order 2 = which lands player has & buliding level - pointer points
  order 3 = how much money player has
 order 4 = which chance card player has now
             if(i==0)str+= " _____________________________________________________________________________________________ ";
         else if(i==1)str+= "|          | B.SILIA|  BALI  |SANTIAGO| EVENT  |  OSLO  | S.HOLM | CHANCE | MOSCOW |          |";
        else if(i==2)str+= "|   JAIL   |   "PlayerPlace1"   |   "PlayerPlace1"   |   "PlayerPlace1"   |   "PlayerPlace1"   |   "PlayerPlace1"   |   "PlayerPlace1"   |   "PlayerPlace1"   |   "PlayerPlace1"   | JACKPOT! |";
         else if(i==3)str+= "|    "PlayerPlace1"    |   "PlayerPlace2"   |   "PlayerPlace2"   |   "PlayerPlace2"   |   "PlayerPlace2"   |   "PlayerPlace2"   |   "PlayerPlace2"   |   "PlayerPlace2"   |   "PlayerPlace2"   |    "PlayerPlace1"    |";
         else if(i==4)str+= "|    "PlayerPlace2"    |________|________|________|________|________|________|________|________|    "PlayerPlace2"    |";
        else if(i==5)str+= "|__________|__"B_Level"__"B_Level"__|__"B_Level"__"B_Level"__|__"B_Level"__"B_Level"__|__"B_Level"__"B_Level"__|__"B_Level"__"B_Level"__|__"B_Level"__"B_Level"__|__"B_Level"__"B_Level"__|__"B_Level"__"B_Level"__|__________|";
         else if(i==6)str+= "| S.PORE | |                                                                       | | ATHENS |";
        else if(i==7)str+= "|   "PlayerPlace1"   |"B_Level"|                                                                       |"B_Level"|   "PlayerPlace1"   |";
         else if(i==8)str+= "|   "PlayerPlace2"   |"B_Level"|         __________                                                    |"B_Level"|   "PlayerPlace2"   |";
        else if(i==9)str+= "|________|_|        /    C    /)                                                   |_|________|";
         else if(i==10)str+="| NEWDELI| |       /    H    //                                                    | | P.RICO |";
        else if(i==11)str+="|   "PlayerPlace1"   |"B_Level"|      /    A    //                                                     |"B_Level"|   "PlayerPlace1"   |";
         else if(i=="PlayerPlace1")str+="|   "PlayerPlace2"   |"B_Level"|     /    N    //                                                      |"B_Level"|   "PlayerPlace2"   |";
         else if(i==13)str+="|________|_|    /    G    //                                                       |_|________|";
        else if(i==14)str+="| CHANCE | |   /____E____//                                                        | |  ROME  |";
         else if(i==15)str+="|   "PlayerPlace1"   |"B_Level"|   |_________/                                                         |"B_Level"|   "PlayerPlace1"   |";
        else if(i==16)str+="|   "PlayerPlace2"   |"B_Level"|                                                                       |"B_Level"|   "PlayerPlace2"   |";
         else if(i==17)str+="|________|_|                           _________________                           |_|________|";
        else if(i==18)str+="| BANGKOK| |                          |                 |                          | | EVENT  |";
         else if(i==19)str+="|   "PlayerPlace1"   |"B_Level"|                          |  J A C K P O T  |                          |"B_Level"|   "PlayerPlace1"   |";
        else if(i==20)str+="|   "PlayerPlace2"   |"B_Level"|                  ________|_________________|________                  |"B_Level"|   "PlayerPlace2"   |";
         else if(i==21)str+="|________|_|                 |                                   |                 |_|________|";
        else if(i==22)str+="|  GUAM  | |                 | $ "JPD"   |                 | | BERLIN |";
         else if(i==23)str+="|   "PlayerPlace1"   |"B_Level"|                 |___________________________________|                 |"B_Level"|   "PlayerPlace1"   |";
        else if(i==24)str+="|   "PlayerPlace2"   |"B_Level"|                                                                       |"B_Level"|   "PlayerPlace2"   |";
         else if(i==25)str+="|________|_|                                                                       |_|________|";
        else if(i==26)str+="| CAIRO  | |                                                                       | | SICILiA|";
         else if(i==27)str+="|   "PlayerPlace1"   |"B_Level"|                                                     __________        |"B_Level"|   "PlayerPlace1"   |";
        else if(i==28)str+="|   "PlayerPlace2"   |"B_Level"|                                                    /    E    /)       |"B_Level"|   "PlayerPlace2"   |";
         else if(i==29)str+="|________|_|                                                   /    V    //        |_|________|";
        else if(i==30)str+="| CASINO | |                                                  /    E    //         | |  PARI  |";
         else if(i==31)str+="|   "PlayerPlace1"   |"B_Level"|                                                 /    N    //          |"B_Level"|   "PlayerPlace1"   |";
        else if(i==32)str+="|   "PlayerPlace2"   |"B_Level"|                                                /    T    //           |"B_Level"|   "PlayerPlace2"   |";
         else if(i==33)str+="|________|_|                                               /_________//            |_|________|";
        else if(i=="PlayerPlace2")str+="| TUNIS  | |                                               |_________/             | | LONDON |";
         else if(i==35)str+="|   "PlayerPlace1"   |"B_Level"|                                                                       |"B_Level"|   "PlayerPlace1"   |";
        else if(i==36)str+="|   "PlayerPlace2"   |"B_Level"|                                                                       |"B_Level"|   "PlayerPlace2"   |";
         else if(i==37)str+="|________|_|_______________________________________________________________________|_|________|";
        else if(i==38)str+="|          |__"B_Level"__"B_Level"__|__"B_Level"__"B_Level"__|__"B_Level"__"B_Level"__|__"B_Level"__"B_Level"__|__"B_Level"__"B_Level"__|__"B_Level"__"B_Level"__|__"B_Level"__"B_Level"__|__"B_Level"__"B_Level"__|          |";
         else if(i==39)str+="|  START!  |  L.A.  |  TAX   |NEW YORK| EVENT  | SEOUL  | TOKYO  | CHANCE |BEIJING | AIRPORT! |";
        else if(i==40)str+="|    "PlayerPlace1"    |   "PlayerPlace1"   |   "PlayerPlace1"   |   "PlayerPlace1"   |   "PlayerPlace1"   |   "PlayerPlace1"   |   "PlayerPlace1"   |   "PlayerPlace1"   |   "PlayerPlace1"   |    "PlayerPlace1"    |";
         else if(i==41)str+="|    "PlayerPlace2"    |   "PlayerPlace2"   |   "PlayerPlace2"   |   "PlayerPlace2"   |   "PlayerPlace2"   |   "PlayerPlace2"   |   "PlayerPlace2"   |   "PlayerPlace2"   |   "PlayerPlace2"   |    "PlayerPlace2"    |";
         else if(i==42)str+="|__________|________|________|________|________|________|________|________|________|__________|";
        */
