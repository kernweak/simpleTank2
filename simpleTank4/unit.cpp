#include "stdafx.h"
#include "unit.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include<string.h>

Map g_nMap[50][60];//1为本身的墙，2为添加的不动墙，3为可打掉的墙
				   //= {0,0,0,"  ",COLOR(e_黑色, e_黑色) };
void initMap() {
	for (int i = 0;i < 50;i++) {
		for (int j = 0;j < 60;j++) {
			g_nMap[i][j].m_ix = j;
			g_nMap[i][j].m_iy = i;
			g_nMap[i][j].m_information = 0;
			strcpy_s(g_nMap[i][j].pic, "  ");
			g_nMap[i][j].color = COLOR(e_黑色, e_黑色);
		}
	}
}


void ShowCursor() {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOutStd, &cci);
}


void PrintCHar(int m_x, int m_y, char* pszChar, WORD color) {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD loc;
	loc.X = m_x * 2;
	loc.Y = m_y;
	SetConsoleCursorPosition(hOutStd, loc);
	SetConsoleTextAttribute(hOutStd, color);
	printf(pszChar);
}

void eraseCHar(int m_x, int m_y, WORD color) {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD loc;
	loc.X = m_x * 2;
	loc.Y = m_y;
	SetConsoleCursorPosition(hOutStd, loc);
	SetConsoleTextAttribute(hOutStd, color);
	printf("  ");
}

bool SetWindowSize(char* pszWindowTitle, int nX, int nY) {
	SetConsoleTitleA(pszWindowTitle);
	HANDLE hStdIn, hStdOut;
	hStdIn = GetStdHandle(STD_INPUT_HANDLE);
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = GetLargestConsoleWindowSize(hStdOut);
	COORD BufferSize = { pos.X + 1,pos.Y + 1 };
	if (!SetConsoleScreenBufferSize(hStdOut, BufferSize)) {
		printf("buffer err(%d,%d)%d\n", BufferSize.X, BufferSize.Y, GetLastError());
		return false;
	}
	SMALL_RECT srctWindow = { 0,0,nX,nY };
	if (!SetConsoleWindowInfo(hStdOut, true, &srctWindow)) {
		printf("size err%d\n", GetLastError());
		return false;
	}
	COORD Buffer = { nX + 1,nY + 1 };
	if (!SetConsoleScreenBufferSize(hStdOut, Buffer)) {
		("buffer err(%d,%d)%d\n", BufferSize.X, BufferSize.Y, GetLastError());
		return false;
	}
	return true;
}


void DrawMap() {
	for (int i = 0;i < 60;i++) {
		g_nMap[0][i].m_ix = i;
		g_nMap[0][i].m_iy = 0;
		g_nMap[0][i].m_information = 1;
		strcpy_s(g_nMap[0][i].pic, "█");
		g_nMap[0][i].color = COLOR(e_白色, e_白色);
		g_nMap[49][i].m_ix = i;
		g_nMap[49][i].m_iy = 49;
		g_nMap[49][i].m_information = 1;
		strcpy_s(g_nMap[49][i].pic, "█");
		g_nMap[49][i].color = COLOR(e_白色, e_白色);
	}
	for (int i = 0;i <50;i++) {
		g_nMap[i][0].m_ix = 0;
		g_nMap[i][0].m_iy = i;
		g_nMap[i][0].m_information = 1;
		strcpy_s(g_nMap[i][0].pic, "█");
		g_nMap[i][0].color = COLOR(e_白色, e_白色);
		g_nMap[i][59].m_ix = 59;
		g_nMap[i][59].m_iy = i;
		g_nMap[i][59].m_information = 1;
		strcpy_s(g_nMap[i][59].pic, "█");
		g_nMap[i][59].color = COLOR(e_白色, e_白色);
	}
	for (int i = 0;i < 50;i++) {
		for (int j = 0;j < 60;j++) {
			if (g_nMap[i][j].m_information == 1) {
				PrintCHar((g_nMap[i][j].m_ix), g_nMap[i][j].m_iy, \
					g_nMap[i][j].pic, g_nMap[i][j].color);
			}
		}
	}
}

void printMap() {
	for (int i = 0;i < 50;i++) {
		for (int j = 0;j < 60;j++) {
			PrintCHar((g_nMap[i][j].m_ix), g_nMap[i][j].m_iy, \
				g_nMap[i][j].pic, g_nMap[i][j].color);
		}
	}
}



void OutPutPos(int nX, int nY) {
	char szBuf[100] = { 0 };
	sprintf_s(szBuf, sizeof(szBuf), "x=%2d,y=%2d ", nX / 2, nY);
	SetConsoleTitleA(szBuf);
	PrintCHar(61, 1, szBuf, 7);
}

int KeyEventProc(KEY_EVENT_RECORD ker) {
	int temp = 0;
	if (ker.bKeyDown)
		PrintCHar(61, 1, "键盘 按下", 7);
	else
		PrintCHar(61, 1, "键盘 弹起", 7);
	if (0x5A == ker.wVirtualKeyCode)
		temp = 1;
	return temp;
}

void MouseEventProc(MOUSE_EVENT_RECORD mer) {
	switch (mer.dwEventFlags)
	{
	case 0:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			g_nMap[mer.dwMousePosition.Y][mer.dwMousePosition.X / 2].m_information = 2;
			g_nMap[mer.dwMousePosition.Y][mer.dwMousePosition.X / 2].color = 7;
			strcpy_s(g_nMap[mer.dwMousePosition.Y][mer.dwMousePosition.X / 2].pic, "█");
			PrintCHar(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y, "█", 7);
			PrintCHar(61, 1, "左键 单击", 7);
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
			g_nMap[mer.dwMousePosition.Y][mer.dwMousePosition.X / 2].m_information = 3;
			g_nMap[mer.dwMousePosition.Y][mer.dwMousePosition.X / 2].color = 4;
			strcpy_s(g_nMap[mer.dwMousePosition.Y][mer.dwMousePosition.X / 2].pic, "▓");
			PrintCHar(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y, "▓", 4);
			PrintCHar(61, 1, "右键 单击", 7);
		}
		break;
	case DOUBLE_CLICK:
		PrintCHar(61, 1, "双     击", 7);
		break;
	case MOUSE_MOVED:
		OutPutPos(mer.dwMousePosition.X, mer.dwMousePosition.Y);
		break;
	}
}

int MessageLoop() {
	PrintCHar(61, 2, "1左键是添加不可摧毁的障碍物，", 7);
	PrintCHar(61, 3, "2右键添加可摧毁的障碍物", 7);
	PrintCHar(61, 4, "3按下q键退出编辑", 7);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	SetConsoleMode(hStdin, ENABLE_INSERT_MODE | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);
		if (stcRecord.EventType == KEY_EVENT) {

			int temp = 0;
			temp = KeyEventProc(stcRecord.Event.KeyEvent);
			if (temp == 1)break;

		}
		else if (stcRecord.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRecord.Event.MouseEvent);
		}
	}
	return 0;
}



void editMap() {
	DrawMap();

}