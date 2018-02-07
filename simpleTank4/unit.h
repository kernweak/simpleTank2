#pragma once
#include <Windows.h>

enum Color {
	e_黑色,
	e_蓝色,
	e_绿色,
	e_浅绿色,
	e_红色,
	e_紫色,
	e_黄色,
	e_白色,
	e_灰色,
	e_淡蓝色,
	e_淡绿色,
	e_淡浅绿色,
	e_淡红色,
	e_淡紫色,
	e_淡黄色,
	e_亮白色,
};
#define COLOR(back,front) (((back)<<8) | (front))

typedef struct Unit {
	int m_x;
	int m_y;
	char* pszChar;
	WORD color;
}unit;

//有意义坐标单独点的信息。
typedef struct mapUnit {
	int m_ix;
	int m_iy;
	int m_information;//坐标点性质，入坦克障碍等
					  //1为墙，2为一号玩家坦克，4为地方坦克
					  //	mapUnit* Next;//指向下一个有数据的坐标点
	char pic[3];
	WORD color;
}Map, *pMap;

extern Map g_nMap[50][60];
void initMap();

void ShowCursor();//隐藏光标
void PrintCHar(int m_x, int m_y, char* pszChar, WORD color);//打印坐标
void eraseCHar(int m_x, int m_y, WORD color);
bool SetWindowSize(char* pszWindowTitle, int nX, int nY);
void DrawMap();
void OutPutPos(int nX, int nY);
int KeyEventProc(KEY_EVENT_RECORD ker);
void MouseEventProc(MOUSE_EVENT_RECORD mer);
int MessageLoop();
void editMap();
void printMap();