
#include <iostream>
#include <windows.h>
using namespace std;


void gotoxy(int x, int y);
void printenemy1();  
void eraseenemy1(); 
void printenemy2();  
void eraseenemy2(); 
void printenemy3();  
void eraseenemy3(); 
void eraseplayer();
void printplayer();
void moveplayerleft();
void moveplayerright();
void moveenemy1();
void moveenemy2();
void moveenemy3();
void printmaze();
void printscore();
void placebonus();
void erasebonus();
bool checkcollision();
void updatebonusstatus();
void moveplayerup();
void moveplayerdown();
char getCharAtxy(short int x, short int y);

int ex1 = 2, ey1 = 2; 
int ex2 = 4, ey2 = 2; 
int ex3 = 2, ey3 = 6; 
int px = 20, py = 20; 
int bonusx = 10, bonusy = 10; 
int score = 0; 

bool bonus_collected = false; 

int main() {
    system("cls");
    printmaze();
    placebonus();
    printenemy1();
    printenemy2();
    printenemy3();
    printplayer();
    printscore();
    
    while (true) {
        if (GetAsyncKeyState(VK_LEFT)) {
            moveplayerleft();
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            moveplayerright();
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            moveplayerdown();
        }
        if (GetAsyncKeyState(VK_UP)) {
            moveplayerup();
        }
        moveenemy1(); 
        moveenemy2(); 
        moveenemy3(); 
        updatebonusstatus(); 
        Sleep(200);
    }
}


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void eraseplayer() {
    gotoxy(px, py);
    cout << "                          ";
    gotoxy(px, py + 1);
    cout << "                          ";
    gotoxy(px, py + 2);
    cout << "                          ";
    gotoxy(px, py + 3);
    cout << "                          ";
    gotoxy(px, py + 4);
    cout << "                          ";
}


void printplayer() {
    gotoxy(px, py);
    cout << "          /\\             ";
    gotoxy(px, py + 1);
    cout << "       __/~~\\__          ";
    gotoxy(px, py + 2);
    cout << "     /  ||  ||   \\       ";
    gotoxy(px, py + 3);
    cout << "=====             ======= ";
    gotoxy(px, py + 4);
    cout << "         ||||             ";
}


void printmaze() {
    cout << "###########################################################################################################"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "#                                                                                                         #"<<endl;
    cout << "###########################################################################################################"<<endl;
}


void moveenemy1() {
    eraseenemy1();
    ex1 += 1;  
    if (ex1 >= 48) { 
        ex1 = 2;  
    }
    printenemy1();
}


void moveenemy2() {
    eraseenemy2();
    ey2 += 1;
    if (ey2 >= 24) { 
        ey2 = 2;  
    }
    printenemy2();
}


void moveenemy3() {
    eraseenemy3();
    ex3 += 1;
    ey3 += 1;
    if (ex3 >= 48 || ey3 >= 24) { 
        ex3 = 2;
        ey3 = 6;
    }
    printenemy3();
}


void printenemy1() {
    gotoxy(ex1, ey1);
    cout << "  |  ";
    gotoxy(ex1, ey1 + 1);
    cout << " / \\ ";
    gotoxy(ex1, ey1 + 2);
    cout << "|___|";  
}


void eraseenemy1() {
    gotoxy(ex1, ey1);
    cout << "     ";
    gotoxy(ex1, ey1 + 1);
    cout << "     ";
    gotoxy(ex1, ey1 + 2);
    cout << "     ";
}


void printenemy2() {
    gotoxy(ex2, ey2);
    cout << "  |  ";
    gotoxy(ex2, ey2 + 1);
    cout << " / \\ ";
    gotoxy(ex2, ey2 + 2);
    cout << "|___|";  
}


void eraseenemy2() {
    gotoxy(ex2, ey2);
    cout << "     ";
    gotoxy(ex2, ey2 + 1);
    cout << "     ";
    gotoxy(ex2, ey2 + 2);
    cout << "     ";
}


void printenemy3() {
    gotoxy(ex3, ey3);
    cout << "  |  ";
    gotoxy(ex3, ey3 + 1);
    cout << " / \\ ";
    gotoxy(ex3, ey3 + 2);
    cout << "|___|";  
}


void eraseenemy3() {
    gotoxy(ex3, ey3);
    cout << "     ";
    gotoxy(ex3, ey3 + 1);
    cout << "     ";
    gotoxy(ex3, ey3 + 2);
    cout << "     ";
}


void placebonus() {
    gotoxy(bonusx, bonusy);
    cout << "  O  "; 
}


void erasebonus() {
    gotoxy(bonusx, bonusy);
    cout << "     ";
}

// Print the score
void printscore() {
    gotoxy(0, 0); 
    cout << "Score: " << score;
}


bool checkcollision() {
    return px == bonusx && py == bonusy;
}


void updatebonusstatus() {
    if (!bonus_collected && checkcollision()) {
        erasebonus();
        bonus_collected = true;
        score += 1;
        printscore();
    }
}


void moveplayerup()
{
    
    if (getCharAtxy(px, py-5) == ' ')
    {
        eraseplayer();
        py = py- 1;
        printplayer();
    }
}


void moveplayerdown()
{
    
    if (getCharAtxy(px, py+5) == ' ')
    {
        eraseplayer();
        py = py+ 1;
        printplayer();
    }
}




void moveplayerleft() {
    eraseplayer();
    if (px > 1) { 
        px = px - 1;
    }
    printplayer(); 
}


void moveplayerright() {
    eraseplayer();
    if (px < 48) { 
        px = px + 1;
    }
    printplayer();
}

char getCharAtxy(short int x, short int y)

{

CHAR_INFO ci;

COORD xy = {0, 0};

SMALL_RECT rect = {x, y, x, y};

COORD coordBufSize;

coordBufSize.X = 1;

coordBufSize.Y = 1;

return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
: ' ';

}