#ifndef Gomoku_h
#define Gomoku_h
class Gomoku
{
private:
	char map[15][15]; // 地圖大小為15 * 15
public:
	Gomoku();       //地圖初始化
	void show() const;    //顯示棋盤
	void welcome() const;   //歡迎介面
};
#endif // !Gomoku_h
