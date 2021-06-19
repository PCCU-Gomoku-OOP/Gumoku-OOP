#include "Gomoku.h"
#include <iostream>
using namespace std;


Gomoku::Gomoku() {  //全地圖初始化
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            map[i][j] = ' ';
        }
    }
}

bool Gomoku::colWin(char player, int x, int y) {    //判斷直向棋子數
    int connect = 1;    //棋子數(因為初始本身就是一顆棋子，所以為1)
    for (int i = 1;; i++) { 
        if (map[y + i][x] == player)
            connect++;  //如果Y座標+1(直線向上)是相同的棋子，棋子數+1
        else
            break;  //不是相同棋子結束迴圈
    }
    for (int i = 1;; i++) {
        if (map[y - i][x] == player)
            connect++;  //如果Y座標-1(直線向下)是相同的棋子，棋子數+1
        else
            break;
    }
    if (connect >= 5)
        return true;    //如果棋子數大於等於5，則獲勝
    else
        return false;
}

bool Gomoku::rowWin(char player, int x, int y) {    //判斷橫向棋子數
    int connect = 1;
    for (int i = 1;; i++) {
        if (map[y][x + i] == player)
            connect++;  //如果X座標+1(橫線向右)是相同的棋子，棋子數+1
        else
            break;
    }
    for (int i = 1;; i++) {
        if (map[y][x - i] == player)
            connect++;  //如果X座標-1(橫線向左)是相同的棋子，棋子數+1
        else
            break;
    }
    if (connect >= 5)
        return true;
    else
        return false;
}

bool Gomoku::obliWin1(char player, int x, int y) {  //判斷斜率為正的棋子數
    int connect = 1;
    for (int i = 1;; i++) {
        if (map[y + i][x + i] == player) connect++; //如果XY座標+1(右斜向上)是相同的棋子，棋子數+1
        else break;
    }
    for (int i = 1;; i++) {
        if (map[y - i][x - i] == player) connect++; //如果XY座標-1(右斜向下)是相同的棋子，棋子數+1
        else break;
    }
    if (connect >= 5) 
        return true;
    else 
        return false;
}

bool Gomoku::obliWin2(char player, int x, int y) {  //判斷斜率為負的棋子數
    int connect = 1;
    for (int i = 1;; i++) {
        if (map[y + i][x - i] == player) connect++; //如果XY座標各-1+1(左斜向上)是相同的棋子，棋子數+1
        else break;
    }
    for (int i = 1;; i++) {
        if (map[y - i][x + i] == player) connect++; //如果XY座標各+1-1(左斜向下)是相同的棋子，棋子數+1
        else break;
    }
    if (connect >= 5) return true;
    else return false;
}

bool Gomoku::winner(char player, int x, int y) {    //上述四個判斷有一個成立，及獲勝

    if (colWin(player, x, y) || rowWin(player, x, y) || obliWin1(player, x, y) || obliWin2( player, x, y))
        return true;
    else
        return false;
}

bool Gomoku::tfSet(char player, int x, int y) {     //輸入有效判斷
    if (x >= 0 && x < 15 && y >= 0 && y < 15 && map[y][x] == ' ') {     //是否在棋盤內和有無棋子，同時為TRUE為有效輸入
        map[y][x] = player;
        return true;
    }
    else {
        cout << "無效的輸入，請重新輸入。" << endl;     //錯誤提示
        system("pause");
        system("CLS");
        return false;
    }
}

bool Gomoku::mapOver() {    //搜尋是否滿盤，只要有一個是空的，地圖就不為滿
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            if (map[i][j] == ' ')
                return false;

    return true;  
}

void Gomoku::show() const{  //地圖顯示
    cout << "   01  02  03  04  05  06  07  08  09  10  11  12  13  14  15" << endl;    //X座標提示
    for (int i = 14; i >= 0; i--) {     //地圖要倒過來顯示，Y座標才會接近一般數學使用
        cout << "   －－－－－－－－－－－－－－－－－－－－－－－－－－－－－－" << endl;

        if (i + 1 < 10)
            cout << "0" << i + 1;   //Y座標提示
        else
            cout << i + 1;

        for (int j = 0; j < 15; j++) {
            cout << "| " << map[i][j] << " ";
        }
        cout << "|";

        if (i + 1 < 10)
            cout << "0" << i + 1 << endl;   //Y座標提示
        else
            cout << i + 1 << endl;

    }cout << "   －－－－－－－－－－－－－－－－－－－－－－－－－－－－－－" << endl;
    cout << "   01  02  03  04  05  06  07  08  09  10  11  12  13  14  15" << endl;//X座標提示
}

void Gomoku::welcome() const{   //歡迎畫面

    cout << " －－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－" << endl;
    cout << "|                          歡迎遊玩第12組五子棋                            |" << endl;
    cout << " －－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－" << endl;
    cout << "   遊戲說明：" << endl << endl
        << "˙ 棋盤為15*15大小" << endl
        << "˙ '0'代表白棋，'@'代表黑棋" << endl
        << "˙ 遊戲由白棋先手，先達連續五顆棋子者（包含斜著）即獲勝" << endl
        << "˙ 若滿盤（棋盤已滿且無獲勝者）則平手" << endl
        << "˙ X和Y同時輸入0結束遊戲" << endl << endl;
    system("pause");

}