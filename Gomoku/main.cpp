#include"Gomoku.h"
#include<iostream>
using namespace std;


int main() {
    Gomoku game;
    game.welcome();
    system("CLS");
    game.show();
    int x, y;
    char player = '0';  //�Ĥ@���Ѥl��O  
    while (1) {
        cout << "�]Y�b�G��X�b�G��     X�BY����0�ɡA�����C���^" << endl;
        cout << "X:";
        cin >> x;       //��JX�y��
        cout << "Y:";
        cin >> y;       //��JY�y��

        if (x == 0 && y == 0) {     //�p�GX�BY����J0�A�����j��
            cout << endl << "�C�������I" << endl;
            break;
        }
        else {
            x--;  //�]���}�C�_�l��0�A�ҥH��J���Ȼݭn-1
            y--;
        }
        system("CLS");  //�M���e�����t�Φr
        bool TFset = game.tfSet(player, x, y);  //�P�_���Ŀ�J�A��J�Ѥl
        game.show();    //��s�a�����

        if (game.winner(player, x, y)) {    //�P�_��ӡA�Y�����a��ӡA��X���ܫᵲ���j��
            cout << endl << player << " ��ӡC" << endl;
            break;
        }

        if (game.mapOver()) {   //�P�_���ϡA��X���ܫᵲ���j��
            cout << endl << "���L�A�����ӭt�C" << endl;
            break;
        }

        if (TFset) {    //�Y�����Ŀ�J�h�󴫴Ѥl
            if (player == '0')
                player = '@';
            else
                player = '0';
        }
    }
}
