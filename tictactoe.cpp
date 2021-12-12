#include<ncurses/ncurses.h>
#include<string.h>
#include<iostream>
using namespace std;

void Table(){

    int panjang, lebar, x, y;
    panjang = 38;
    lebar = 19;
    x = 1;
    y = 1;

    start_color();
    init_pair(1, 0, COLOR_RED);
    attron(COLOR_PAIR(1));

    // horizontal border
    for (int i = x; i <= panjang; i++){

        // top border
        mvprintw(y, i, " ");

        // 1st horizontal
        mvprintw(y+6, i, " ");

        // 2nd horizontal
        mvprintw(y+12, i, " ");

        // bottom border
        mvprintw(lebar, i, " ");

    }

    // vertical border
    for (int j = y; j <= lebar; j++){

        // left bordeer
        mvprintw(j, x, " ");
        mvprintw(j, x+1, " ");

        // 1st vertical
        mvprintw(j, x+12, " ");
        mvprintw(j, x+13, " ");

        // 2nd vertical
        mvprintw(j, x+24, " ");
        mvprintw(j, x+25, " ");

        // right border
        mvprintw(j, panjang, " ");
        mvprintw(j, panjang-1, " ");

    }

    attroff(COLOR_PAIR(1));

}

// nti pake parameter:
// int x_startPoint, int y_startPoint
void X(int x, int y){

    start_color();
    init_pair(2, 0, COLOR_BLUE);
    attron(COLOR_PAIR(2));

    // bikin x/o nya manual aj, tp flexibel ama startpoint (ngandelin tambah2an pixel)
    // ...

    mvprintw(y, x, " ");
    mvprintw(y, x+1, " ");
    mvprintw(y, x+8, " ");
    mvprintw(y, x+9, " ");

    mvprintw(y+1, x+2, " ");
    mvprintw(y+1, x+3, " ");
    mvprintw(y+1, x+6, " ");
    mvprintw(y+1, x+7, " ");

    mvprintw(y+2, x+4, " ");
    mvprintw(y+2, x+5, " ");

    mvprintw(y+3, x+2, " ");
    mvprintw(y+3, x+3, " ");
    mvprintw(y+3, x+6, " ");
    mvprintw(y+3, x+7, " ");

    mvprintw(y+4, x, " ");
    mvprintw(y+4, x+1, " ");
    mvprintw(y+4, x+8, " ");
    mvprintw(y+4, x+9, " ");

    attroff(COLOR_PAIR(2));

}

void O(int x, int y){

    start_color();
    init_pair(3, 0, COLOR_MAGENTA);
    attron(COLOR_PAIR(3));

    mvprintw(y, x+4, " ");
    mvprintw(y, x+5, " ");

    mvprintw(y+1, x+2, " ");
    mvprintw(y+1, x+3, " ");
    mvprintw(y+1, x+6, " ");
    mvprintw(y+1, x+7, " ");

    mvprintw(y+2, x, " ");
    mvprintw(y+2, x+1, " ");
    mvprintw(y+2, x+8, " ");
    mvprintw(y+2, x+9, " ");

    mvprintw(y+3, x+2, " ");
    mvprintw(y+3, x+3, " ");
    mvprintw(y+3, x+6, " ");
    mvprintw(y+3, x+7, " ");

    mvprintw(y+4, x+4, " ");
    mvprintw(y+4, x+5, " ");

    attroff(COLOR_PAIR(3));

}


int* Fill(int startPointX[3], int startPointY[3]){

    static int a[2];
    int x, y;
    bool cek = false;
    char userInput;
    keypad(stdscr, true);
    
    do{

        userInput = getchar();

        if (userInput == '7'){

            x = startPointX[0];
            y = startPointY[0];
            cek = false;

        }

        else if (userInput == '8'){

            x = startPointX[1];
            y = startPointY[0];
            cek = false;

        }

        else if (userInput == '9'){

            x = startPointX[2];
            y = startPointY[0];
            cek = false;

        }

        else if (userInput == '4'){

            x = startPointX[0];
            y = startPointY[1];
            cek = false;

        }

        else if (userInput == '5'){

            x = startPointX[1];
            y = startPointY[1];
            cek = false;

        }

        else if (userInput == '6'){

            x = startPointX[2];
            y = startPointY[1];
            cek = false;

        }

        else if (userInput == '1'){

            x = startPointX[0];
            y = startPointY[2];
            cek = false;

        }

        else if (userInput == '2'){

            x = startPointX[1];
            y = startPointY[2];
            cek = false;

        }

        else if (userInput == '3'){

            x = startPointX[2];
            y = startPointY[2];
            cek = false;

        }

        else{

            //print error : pilihan tidak tersedia.
            cek = true;

        }

    }while(cek == true);

    a[0] = x;
    a[1] = y;

    return a;

}

void ClearRow(int x, int y){

    for (int i = 0; i < 100; i++){

        mvprintw(y, x+i, " ");

    }

}

int main(){

        string player_name[2] = {"Player 1", "Player 2"};

        // input player's name
        system("cls");
        string p1, p2;
        cout << "Nama Player 1 : " << "\n";
        getline(cin, p1);
        cout << "Nama Player 2 : " << "\n";
        getline(cin, p2);

        if (p1 != ""){

            player_name[0] = p1;

        }
        if (p2 != ""){

            player_name[1] = p2;

        }

        int startPointX[3] = {3, 15, 27};
        int startPointY[3] = {2, 8 ,14};
       
        char filledBox [3][3] = {

            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}

        };

        string winPlayer;
        bool end = false;
        int c = 0;

        initscr();
        clear();

        // table
        Table();
        refresh();

        do{ 

            if (c % 2 == 0){

                ClearRow(45, 9);
                move(9, 45);
                printw("Sekarang, giliran %s", player_name[0].c_str());

            }

            else{

                ClearRow(45, 9);
                move(9, 45);
                printw("Sekarang, giliran %s", player_name[1].c_str());

            }

            refresh();

            int* coor = Fill(startPointX, startPointY);

            // klo ternyata boxnya udh diisi
            bool skip = false;
            for (int i = 0; i < 3; i++){

                for (int j = 0; j < 3; j++){
                    
                    if (startPointX[i] == coor[0] && startPointY[j] == coor[1]){

                        if (filledBox[i][j] != ' '){

                            //print error : box telah diisi
                            skip = true;

                        }

                    }

                }

            }

            if (skip == true){

                continue;

            }

            char x_or_o;
            if (c % 2 == 0){

                // u1 turn
                // print "sekarang, giliran player 1"
                X(coor[0], coor[1]);
                x_or_o = 'x';

            }

            else{

                // u2 turn
                // print "sekarang, giliran player 1"
                O(coor[0], coor[1]);
                x_or_o = 'o';

            }

            // tampung x / o ke arr filled box
            for (int i = 0; i < 3; i++){

                for (int j = 0; j < 3; j++){
                    
                    if (startPointX[i] == coor[0] && startPointY[j] == coor[1]){

                        filledBox[i][j] = x_or_o;

                    }

                }

            }

            // cek win or lose
            // cek baris
            bool stop = false;
            for (int p = 0; p < 3; p++){
                
                if (stop == true){

                    break;

                }

                // klo salah satunya kosong yaa skipp
                // klo udh keisi smua baruu di cek
                if (filledBox[p][0] != ' ' && filledBox[p][1] != ' ' && filledBox[p][2] != ' '){

                    if (filledBox[p][0] == filledBox[p][1] && filledBox[p][0] == filledBox[p][2]){

                        // yang menang
                        if (filledBox[p][0] == 'x'){

                            winPlayer = player_name[0];

                        }

                        else{

                            winPlayer = player_name[1];

                        }

                        // move(y, x) => move cursor
                        // addstr() or printw() => print str
                        move(10, 45);
                        printw("Yeay! %s menang!", winPlayer.c_str());

                        end = true;
                        stop = true;

                    }

                }

            }

            // cek kolom
            for (int q = 0; q < 3; q++){
                
                if (stop == true){

                    break;

                }

                // klo salah satunya kosong yaa skipp
                // klo udh keisi smua baruu di cek
                if (filledBox[0][q] != ' ' && filledBox[1][q] != ' ' && filledBox[2][q] != ' '){

                    if (filledBox[0][q] == filledBox[1][q] && filledBox[0][q] == filledBox[2][q]){

                        // yang menang
                        if (filledBox[0][q] == 'x'){

                            winPlayer = player_name[0];

                        }

                        else{

                            winPlayer = player_name[1];

                        }

                        move(10, 45);
                        printw("Yeay! %s menang!", winPlayer.c_str());

                        end = true;
                        stop = true;

                    }

                }

            }

            // cek diagonal
            if (stop != true){

                if (filledBox[0][0] != ' ' && filledBox[1][1] != ' ' && filledBox[2][2] != ' '){

                    if (filledBox[0][0] == filledBox[1][1] && filledBox[0][0] == filledBox[2][2]){

                        // yang menang
                        if (filledBox[0][0] == 'x'){

                            winPlayer = player_name[0];

                        }

                        else{

                            winPlayer = player_name[1];

                        }

                        move(10, 45);
                        printw("Yeay! %s menang!", winPlayer.c_str());

                        end = true;
                        stop = true;

                    }

                }

                if (stop != true){

                    if (filledBox[0][2] != ' ' && filledBox[1][1] != ' ' && filledBox[2][0] != ' '){

                        if (filledBox[0][2] == filledBox[1][1] && filledBox[0][2] == filledBox[2][0]){

                            // yang menang
                            if (filledBox[0][2] == 'x'){

                                winPlayer = player_name[0];

                            }

                            else{

                                winPlayer = player_name[1];

                            }

                            move(10, 45);
                            printw("Yeay! %s menang!", winPlayer.c_str());

                            end = true;
                            stop = true;

                        }

                    }                                               

                }

            }

            // draw
            if (stop != true && c == 8){

                move(10, 45);
                printw("Draw!");

                end = true;

            }


            refresh();

            c += 1;

        }while(end == false);

        ClearRow(45, 9);

        getch();
        endwin();

        system("cls");

}

