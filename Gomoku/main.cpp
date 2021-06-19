#include"Gomoku.h"
#include<iostream>
using namespace std;


int main() {
    Gomoku game;
    game.welcome();
    system("CLS");
    game.show();
    int x, y;
    char player = '0';  //第一顆棋子為O  
    while (1) {
        cout << "（Y軸：↑X軸：→     X、Y都按0時，結束遊戲）" << endl;
        cout << "X:";
        cin >> x;       //輸入X座標
        cout << "Y:";
        cin >> y;       //輸入Y座標

        if (x == 0 && y == 0) {     //如果X、Y都輸入0，結束迴圈
            cout << endl << "遊戲結束！" << endl;
            break;
        }
        else {
            x--;  //因為陣列起始為0，所以輸入的值需要-1
            y--;
        }
        system("CLS");  //清除畫面的系統字
        bool TFset = game.tfSet(player, x, y);  //判斷有效輸入，放入棋子
        game.show();    //更新地圖顯示

        if (game.winner(player, x, y)) {    //判斷獲勝，若有玩家獲勝，輸出提示後結束迴圈
            cout << endl << player << " 獲勝。" << endl;
            break;
        }

        if (game.mapOver()) {   //判斷滿圖，輸出提示後結束迴圈
            cout << endl << "滿盤，不分勝負。" << endl;
            break;
        }

        if (TFset) {    //若為有效輸入則更換棋子
            if (player == '0')
                player = '@';
            else
                player = '0';
        }
    }
}
