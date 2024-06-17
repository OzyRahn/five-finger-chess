#include<iostream>
#include"Gomoku.h"
using namespace std;
Gomoku::Gomoku() 
{
	//地圖初始化
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			map[i][j] = ' ';
		}
	}
}
void Gomoku::show() const
{
	//顯示棋盤
	cout << "   01  02  03  04  05  06  07  08  09  10  11  12  13  14  15" << endl; //X座標提示
	for (int i = 14, j = 0;i >= 0; i--, j++)
	{
		//地區要倒過來顯示,座標才會接近一般數學使用
		cout << "  一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一" << endl;

		if (i + 1 < 10)
			cout << "0" << i + 1; //Y座標提示 
		else
			cout << i + 1;

		for (int j = 0; j < 15; j++)
		{
			cout << "| " << map[i][j] << " ";
		}
		cout << "|";

		if (i + 1 >= 10)
			cout << i + 1 << endl;
		else
			cout << "0" << i + 1 << endl; //

	}

	cout << "  一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一" << endl;
	cout << "   01  02  03  04  05  06  07  08  09  10  11  12  13  14  15" << endl; //X座標提示

}
void Gomoku::welcome() const
{
	cout << "  ----------------" << endl;
	cout << "| --歡迎遊玩五子棋------|" << endl;
	cout << "  ----------------" << endl;
	cout << "遊戲說明:\n\n"
		<< " 棋盤為15 * 15大小\n"
		<< " '0'代表白棋, '@'代表黑棋 \n"
		<< " 遊戲由白棋先手, 先達連續五顆棋子者(包含斜著)即獲勝\n"
		<< " 若滿盤(棋盤已滿且無獲勝者)則平手\n"
		<< " X和Y同時輸入0結束遊戲\n\n";

	system("pause");
}
bool Gomoku::colWin(char player, int x, int y) 
{
    //判斷直向棋子數  
    int connect = 1;//棋子數(因為初始本身就是一顆棋子,所以為1)
    for (int i = 1;; i++) {
        if (map[x + i][y] == player)
            connect++; //如果Y座標+1(直線向上)是相同的棋子,棋子數+1  
        else
            break;//不是相同棋子結束迴圈
    }

    for (int i = 1;; i++) {
        if (map[x - i][y] == player)
            connect++; //如果Y座標-1(直線向下)是相同的棋子,棋子數+1
        else
            break;
    }

    //如果棋子數大於等於5,則獲勝 
    if (connect >= 5)
        return true;
    else
        return false;

}

bool Gomoku::rowWin(char player, int x, int y) 
{
    //判斷橫向棋子數 
    int connect = 1;
    for (int i = 1;; i++) {
        if (map[x][y + i] == player)
        {
            connect++; //如果X座標+1(橫線向右)是相同的棋子,棋子數+1
        }
        else
        {
            break;
        }
    }

    for (int i = 1;; i++) {
        //如果X座標-1(橫線向左)是相同的棋子,棋子數+1 
        if (map[x][y - i] == player)
        {
            connect++;
        }
        else
        {
            break;
        }
    }

    if (connect >= 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Gomoku::obliWinl(char player, int x, int y)
{
    //判斷斜向棋子數
    int connect = 1;//棋子數(因為初始本身就是一顆棋子,所以為1)
    for (int i = 1;; i++) {
        if (map[x + i][y + i] == player)
        {
            connect++; //如果Y座標+1 和 X座標+1(斜線向右上)是相同的棋子,棋子數+1  
        }
        else
        {
            break;//不是相同棋子結束迴圈
        }
    }

    for (int i = 1;; i++) {
        if (map[x - i][y - i] == player)
        {
            connect++; //如果Y座標-1 和 X座標-1(斜線向左下)是相同的棋子,棋子數+1
        }
        else
        {
            break;
        }
    }
    //如果棋子數大於等於5,則獲勝 
    if (connect >= 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Gomoku::obliWin2(char player, int x, int y)
{
    //判斷斜向棋子數
    int connect = 1;//棋子數(因為初始本身就是一顆棋子,所以為1)
    for (int i = 1;; i++) {
        if (map[x + i][y - i] == player)
        {
            connect++; //如果Y座標+1 和 X座標-1(斜線向左上)是相同的棋子,棋子數+1  
        }
        else
        {
            break;//不是相同棋子結束迴圈
        }
    }

    for (int i = 1;; i++) {
        if (map[x - i][y + i] == player)
        {
            connect++; //如果Y座標-1 和 X座標+1(斜線向右下)是相同的棋子,棋子數+1
        }
        else
        {
            break;
        }
    }
    //如果棋子數大於等於5,則獲勝 else
    if (connect >= 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Gomoku::winner(char player, int x, int y)
{
    //上述四個判斷有一個成立,及獲勝
    if (colWin(player, x, y) or rowWin(player, x, y) or obliWinl(player, x, y) or obliWin2(player, x, y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Gomoku::tfSet(char player, int x, int y)
{
    //輸入棋子位置
    if (x >= 0 && x < 15 && y >= 0 && y < 15 && map[x][y] == ' ') {
        map[x][y] = player;
        return true;
    }
    else
    {
        cout << "無效的輸入, 請重新輸入。" << endl;
        system("pause");
        system("CLS");
        return false;
    }
}

bool Gomoku::mapOver()
{
    //搜尋是否滿盤,只要有一個是空的,地圖就不為滿
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (map[i][j] == ' ') return false;
        }
    }

    return true;
}
