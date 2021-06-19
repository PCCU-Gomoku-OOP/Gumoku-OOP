#ifndef GOMOKU_H
#define GOMOKU_H

class Gomoku {

public:
	Gomoku();
	bool colWin(char, int, int);
	bool rowWin(char, int, int);
	bool obliWin1(char, int, int);
	bool obliWin2(char, int, int);
	bool winner(char, int, int);
	bool tfSet(char, int, int);
	bool mapOver();
	void show() const;
	void welcome() const;

private:
	char map[15][15];	//地圖大小為15*15

};


#endif // !GOMOKU_H
