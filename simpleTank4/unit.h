#pragma once
#include <Windows.h>

enum Color {
	e_��ɫ,
	e_��ɫ,
	e_��ɫ,
	e_ǳ��ɫ,
	e_��ɫ,
	e_��ɫ,
	e_��ɫ,
	e_��ɫ,
	e_��ɫ,
	e_����ɫ,
	e_����ɫ,
	e_��ǳ��ɫ,
	e_����ɫ,
	e_����ɫ,
	e_����ɫ,
	e_����ɫ,
};
#define COLOR(back,front) (((back)<<8) | (front))

typedef struct Unit {
	int m_x;
	int m_y;
	char* pszChar;
	WORD color;
}unit;

//���������굥�������Ϣ��
typedef struct mapUnit {
	int m_ix;
	int m_iy;
	int m_information;//��������ʣ���̹���ϰ���
					  //1Ϊǽ��2Ϊһ�����̹�ˣ�4Ϊ�ط�̹��
					  //	mapUnit* Next;//ָ����һ�������ݵ������
	char pic[3];
	WORD color;
}Map, *pMap;

extern Map g_nMap[50][60];
void initMap();

void ShowCursor();//���ع��
void PrintCHar(int m_x, int m_y, char* pszChar, WORD color);//��ӡ����
void eraseCHar(int m_x, int m_y, WORD color);
bool SetWindowSize(char* pszWindowTitle, int nX, int nY);
void DrawMap();
void OutPutPos(int nX, int nY);
int KeyEventProc(KEY_EVENT_RECORD ker);
void MouseEventProc(MOUSE_EVENT_RECORD mer);
int MessageLoop();
void editMap();
void printMap();