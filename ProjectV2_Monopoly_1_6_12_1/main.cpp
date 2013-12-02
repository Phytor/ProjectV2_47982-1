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
 */

/*
 *ERRORS
 *[001] - Cannot start the game/any key function does not work
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

//Global Constants
const string VERSION="1.6.12.01";

//function Prototypes
//----SYSTEM---------
void GameStart();
string s_PlacePlayer(int [],int,bool);
//----UTILITY--------
string I2S(int);
string D2S(double);
string InputString(string [],string [],string,string,int,int,bool,bool);
//----DISPLAY--------
string d_Title(int,bool,bool,int,int);
string d_Menu(int,bool,bool,int);
string d_Board(int,bool,bool,int);
string d_Jackpot(int);
string d_Setting(int,bool,bool,int);


int main(int argc, const char * argv[]){
    GameStart();
}

void GameStart(){
    string menu[3]={"1","2","3"};
    string begin;
    int playerWhere[4];
    int place[36];
    d_Title(0,true,false,50,100);
    begin=InputString(menu,menu,"Enter any key to start the game\n",d_Title(0,false,true,0,0)+"ERROR[001] - ",1,1,true,true);
    d_Menu(0,true,false,100);
    begin=InputString(menu,menu,"Please Select the menu\n",d_Menu(0,false,true,0)+"Incorrect number - ",3,0,true,true);
    d_Setting(0,true,false,100);
    begin=InputString(menu,menu,"Please Select the menu\n",d_Board(0,false,true,0)+"Incorrect number - ",3,0,true,true);
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

string d_Setting(int i,bool Animation, bool save, int duration1){
    string str="";
    int playerw[4]={10,10,10,10};
    int jackpot=10;
    int d=duration1;
    if(Animation==true)i=0;
    do{
        if(i==0){str+= " _____________________________________________________________________________________________ ";}
        else if(i==1){str+= "|          | B.SILIA|  BALI  |SANTIAGO| EVENT  |  OSLO  | S.HOLM | CHANCE | MOSCOW |          |";}
        else if(i==2){str+= "|   JAIL   |  ";str+=s_PlacePlayer(playerw,10,true);str+="  |  ";str+=s_PlacePlayer(playerw,11,true);str+="  |  ";str+=s_PlacePlayer(playerw,12,true);str+="  |  ";str+=s_PlacePlayer(playerw,13,true);str+="  |  ";str+=s_PlacePlayer(playerw,14,true);str+="  |  ";str+=s_PlacePlayer(playerw,15,true);str+="  |  ";str+=s_PlacePlayer(playerw,16,true);str+="  |  ";str+=s_PlacePlayer(playerw,17,true);str+="  | JACKPOT! |";}
        else if(i==3){str+= "|   ";str+=s_PlacePlayer(playerw,9,true);str+="   |  ";str+=s_PlacePlayer(playerw,10,false);str+="  |  ";str+=s_PlacePlayer(playerw,11,false);str+="  |  ";str+=s_PlacePlayer(playerw,12,false);str+="  |  ";str+=s_PlacePlayer(playerw,13,false);str+="  |  ";str+=s_PlacePlayer(playerw,14,false);str+="  |  ";str+=s_PlacePlayer(playerw,15,false);str+="  |  ";str+=s_PlacePlayer(playerw,16,false);str+="  |  ";str+=s_PlacePlayer(playerw,17,false);str+="  |   ";str+=s_PlacePlayer(playerw,18,true);str+="   |";}
        else if(i==4){str+= "|   ";str+=s_PlacePlayer(playerw,9,false);str+="   |________|________|________|________|________|________|________|________|   ";str+=s_PlacePlayer(playerw,18,false);str+="   |";}
        else if(i==5){str+= "|__________|__%__*__|__%__*__|__%__*__|__%__*__|__%__*__|__%__*__|__%__*__|__%__*__|__________|";}
        else if(i==6){str+= "| S.PORE | |                                                                       | | ATHENS |";}
        else if(i==7){str+= "|  ";str+=s_PlacePlayer(playerw,8,true);str+="  |%|                                                                       |%|  ";str+=s_PlacePlayer(playerw,19,true);str+="  |";}
        else if(i==8){str+= "|  ";str+=s_PlacePlayer(playerw,8,false);str+="  |*|         __________                                                    |*|  ";str+=s_PlacePlayer(playerw,19,false);str+="  |";}
        else if(i==9){str+= "|________|_|        /    C    /)                                                   |_|________|";}
        else if(i==10){str+="| NEWDELI| |       /    H    //                                                    | | P.RICO |";}
        else if(i==11){str+="|  ";str+=s_PlacePlayer(playerw,7,true);str+="  |%|      /    A    //                                                     |%|  ";str+=s_PlacePlayer(playerw,20,true);str+="  |";}
        else if(i==12){str+="|  ";str+=s_PlacePlayer(playerw,7,false);str+="  |*|     /    N    //                                                      |*|  ";str+=s_PlacePlayer(playerw,20,false);str+="  |";}
        else if(i==13){str+="|________|_|    /    G    //                                                       |_|________|";}
        else if(i==14){str+="| CHANCE | |   /____E____//                                                        | |  ROME  |";}
        else if(i==15){str+="|  ";str+=s_PlacePlayer(playerw,6,true);str+="  |%|   \\\\\\\\\\\\\\\\\\\\/                                                         |%|  ";str+=s_PlacePlayer(playerw,21,true);str+="  |";}
        else if(i==16){str+="|  ";str+=s_PlacePlayer(playerw,6,false);str+="  |*|                                                                       |*|  ";str+=s_PlacePlayer(playerw,21,false);str+="  |";}
        else if(i==17){str+="|________|_|                           _________________                           |_|________|";}
        else if(i==18){str+="| BANGKOK| |                          |                 |                          | | EVENT  |";}
        else if(i==19){str+="|  ";str+=s_PlacePlayer(playerw,5,true);str+="  |%|                          |  J A C K P O T  |                          |%|  ";str+=s_PlacePlayer(playerw,22,true);str+="  |";}
        else if(i==20){str+="|  ";str+=s_PlacePlayer(playerw,5,false);str+="  |*|                  ________|_________________|________                  |*|  ";str+=s_PlacePlayer(playerw,22,false);str+="  |";}
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
        else if(i==31){str+="|  ";str+=s_PlacePlayer(playerw,2,true);str+="  |%|                                                 /    N    //          |%|  ";str+=s_PlacePlayer(playerw,25,true);str+="  |";}
        else if(i==32){str+="|  ";str+=s_PlacePlayer(playerw,2,false);str+="  |*|                                                /    T    //           |*|  ";str+=s_PlacePlayer(playerw,25,false);str+="  |";}
        else if(i==33){str+="|________|_|                                               /_________//            |_|________|";}
        else if(i==34){str+="| TUNIS  | |                                               \\\\\\\\\\\\\\\\\\\\/             | | LONDON |";}
        else if(i==35){str+="|  ";str+=s_PlacePlayer(playerw,1,true);str+="  |%|                                                                       |%|  ";str+=s_PlacePlayer(playerw,26,true);str+="  |";}
        else if(i==36){str+="|  ";str+=s_PlacePlayer(playerw,1,false);str+="  |*|                                                                       |*|  ";str+=s_PlacePlayer(playerw,26,false);str+="  |";}
        else if(i==37){str+="|________|_|_______________________________________________________________________|_|________|";}
        else if(i==38){str+="|          |__%__*__|__%__*__|__%__*__|__%__*__|__%__*__|__%__*__|__%__*__|__%__*__|          |";}
        else if(i==39){str+="|  START!  |  L.A.  |  TAX   |NEW YORK| EVENT  | SEOUL  | TOKYO  | CHANCE |BEIJING | AIRPORT! |";}
        else if(i==40){str+="|   ";str+=s_PlacePlayer(playerw,0,true);str+="   |  ";str+=s_PlacePlayer(playerw,35,true);str+="  |  ";str+=s_PlacePlayer(playerw,34,true);str+="  |  ";str+=s_PlacePlayer(playerw,33,true);str+="  |  ";str+=s_PlacePlayer(playerw,32,true);str+="  |  ";str+=s_PlacePlayer(playerw,31,true);str+="  |  ";str+=s_PlacePlayer(playerw,30,true);str+="  |  ";str+=s_PlacePlayer(playerw,29,true);str+="  |  ";str+=s_PlacePlayer(playerw,28,true);str+="  |   ";str+=s_PlacePlayer(playerw,27,true);str+="   |";}
        else if(i==41){str+="|   ";str+=s_PlacePlayer(playerw,0,false);str+="   |  ";str+=s_PlacePlayer(playerw,35,false);str+="  |  ";str+=s_PlacePlayer(playerw,34,false);str+="  |  ";str+=s_PlacePlayer(playerw,33,false);str+="  |  ";str+=s_PlacePlayer(playerw,32,false);str+="  |  ";str+=s_PlacePlayer(playerw,31,false);str+="  |  ";str+=s_PlacePlayer(playerw,30,false);str+="  |  ";str+=s_PlacePlayer(playerw,29,false);str+="  |  ";str+=s_PlacePlayer(playerw,28,false);str+="  |   ";str+=s_PlacePlayer(playerw,27,false);str+="   |";}
        else if(i==42){str+="|__________|________|________|________|________|________|________|________|________|__________|";}
        if(save==false){if(Animation==true){i++;cout<<str<<endl;str="";Sleep(d);}}
        else{i++;str+="\n";}
    }while(i<=42&&(Animation==true||save==true));
    return str;

}

/*
 *
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
