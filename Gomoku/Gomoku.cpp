#include "Gomoku.h"
#include <iostream>
using namespace std;


Gomoku::Gomoku() {  //���a�Ϫ�l��
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            map[i][j] = ' ';
        }
    }
}

bool Gomoku::colWin(char player, int x, int y) {    //�P�_���V�Ѥl��
    int connect = 1;    //�Ѥl��(�]����l�����N�O�@���Ѥl�A�ҥH��1)
    for (int i = 1;; i++) { 
        if (map[y + i][x] == player)
            connect++;  //�p�GY�y��+1(���u�V�W)�O�ۦP���Ѥl�A�Ѥl��+1
        else
            break;  //���O�ۦP�Ѥl�����j��
    }
    for (int i = 1;; i++) {
        if (map[y - i][x] == player)
            connect++;  //�p�GY�y��-1(���u�V�U)�O�ۦP���Ѥl�A�Ѥl��+1
        else
            break;
    }
    if (connect >= 5)
        return true;    //�p�G�Ѥl�Ƥj�󵥩�5�A�h���
    else
        return false;
}

bool Gomoku::rowWin(char player, int x, int y) {    //�P�_��V�Ѥl��
    int connect = 1;
    for (int i = 1;; i++) {
        if (map[y][x + i] == player)
            connect++;  //�p�GX�y��+1(��u�V�k)�O�ۦP���Ѥl�A�Ѥl��+1
        else
            break;
    }
    for (int i = 1;; i++) {
        if (map[y][x - i] == player)
            connect++;  //�p�GX�y��-1(��u�V��)�O�ۦP���Ѥl�A�Ѥl��+1
        else
            break;
    }
    if (connect >= 5)
        return true;
    else
        return false;
}

bool Gomoku::obliWin1(char player, int x, int y) {  //�P�_�ײv�������Ѥl��
    int connect = 1;
    for (int i = 1;; i++) {
        if (map[y + i][x + i] == player) connect++; //�p�GXY�y��+1(�k�צV�W)�O�ۦP���Ѥl�A�Ѥl��+1
        else break;
    }
    for (int i = 1;; i++) {
        if (map[y - i][x - i] == player) connect++; //�p�GXY�y��-1(�k�צV�U)�O�ۦP���Ѥl�A�Ѥl��+1
        else break;
    }
    if (connect >= 5) 
        return true;
    else 
        return false;
}

bool Gomoku::obliWin2(char player, int x, int y) {  //�P�_�ײv���t���Ѥl��
    int connect = 1;
    for (int i = 1;; i++) {
        if (map[y + i][x - i] == player) connect++; //�p�GXY�y�ЦU-1+1(���צV�W)�O�ۦP���Ѥl�A�Ѥl��+1
        else break;
    }
    for (int i = 1;; i++) {
        if (map[y - i][x + i] == player) connect++; //�p�GXY�y�ЦU+1-1(���צV�U)�O�ۦP���Ѥl�A�Ѥl��+1
        else break;
    }
    if (connect >= 5) return true;
    else return false;
}

bool Gomoku::winner(char player, int x, int y) {    //�W�z�|�ӧP�_���@�Ӧ��ߡA�����

    if (colWin(player, x, y) || rowWin(player, x, y) || obliWin1(player, x, y) || obliWin2( player, x, y))
        return true;
    else
        return false;
}

bool Gomoku::tfSet(char player, int x, int y) {     //��J���ħP�_
    if (x >= 0 && x < 15 && y >= 0 && y < 15 && map[y][x] == ' ') {     //�O�_�b�ѽL���M���L�Ѥl�A�P�ɬ�TRUE�����Ŀ�J
        map[y][x] = player;
        return true;
    }
    else {
        cout << "�L�Ī���J�A�Э��s��J�C" << endl;     //���~����
        system("pause");
        system("CLS");
        return false;
    }
}

bool Gomoku::mapOver() {    //�j�M�O�_���L�A�u�n���@�ӬO�Ū��A�a�ϴN������
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            if (map[i][j] == ' ')
                return false;

    return true;  
}

void Gomoku::show() const{  //�a�����
    cout << "   01  02  03  04  05  06  07  08  09  10  11  12  13  14  15" << endl;    //X�y�д���
    for (int i = 14; i >= 0; i--) {     //�a�ϭn�˹L����ܡAY�y�Ф~�|����@��ƾǨϥ�
        cout << "   �ССССССССССССССССССССССССССССС�" << endl;

        if (i + 1 < 10)
            cout << "0" << i + 1;   //Y�y�д���
        else
            cout << i + 1;

        for (int j = 0; j < 15; j++) {
            cout << "| " << map[i][j] << " ";
        }
        cout << "|";

        if (i + 1 < 10)
            cout << "0" << i + 1 << endl;   //Y�y�д���
        else
            cout << i + 1 << endl;

    }cout << "   �ССССССССССССССССССССССССССССС�" << endl;
    cout << "   01  02  03  04  05  06  07  08  09  10  11  12  13  14  15" << endl;//X�y�д���
}

void Gomoku::welcome() const{   //�w��e��

    cout << " �СССССССССССССССССССССССССССССССССССС�" << endl;
    cout << "|                          �w��C����12�դ��l��                            |" << endl;
    cout << " �СССССССССССССССССССССССССССССССССССС�" << endl;
    cout << "   �C�������G" << endl << endl
        << "�� �ѽL��15*15�j�p" << endl
        << "�� '0'�N��մѡA'@'�N��´�" << endl
        << "�� �C���ѥմѥ���A���F�s�����Ѥl�̡]�]�t�׵ۡ^�Y���" << endl
        << "�� �Y���L�]�ѽL�w���B�L��Ӫ̡^�h����" << endl
        << "�� X�MY�P�ɿ�J0�����C��" << endl << endl;
    system("pause");

}