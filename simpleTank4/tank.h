#pragma once
#include"unit.h"

enum DIRE {
	UP, DOWN, RIGHT, LEFT,
};


typedef struct Tank {
	int visable;//�Ƿ�ɼ�
	int m_blood;//̹�˵�����ֵ
	int m_score;//̹�˵ĵ÷�
	int m_x;//̹�����ĵ�x����
	int m_y;//̹�����ĵ�y����
	DIRE m_direction;//̹�˵ķ���
	int m_faction;//��Ӫ
	unit body[6];//̹�˵�����
	Tank* Next;
}Tank;

typedef struct allTank {
	int bNum;//��Ļ̹�˵�����
	Tank* bul;//ָ��ĵ�һ��̹��
}allTank;


typedef struct Bullet {
	int m_x;//�ӵ���x����
	int m_y;//�ӵ��ĵ�y����
	DIRE m_direction;//�ӵ��ķ���
	int m_faction;//�ӵ�����̹��
	char bulletBody[3];//�ӵ���ͼ��
	bool value;//�ӵ��Ƿ���Ч
	int visable;
	int classify;//�ӵ���������
	WORD color;
	Bullet* Next;
	//	Bullet* prior;
}Bullet;

typedef struct allBullet {
	int bNum;//��Ļ�ӵ�������
	Bullet* bul;//ָ��ĵ�һ���ӵ�
}allBullet;


void initTank(allTank** aTank);//��ʼ��̹�˱�ͷ
void initBullet(allBullet** aBullet);//��ʼ���ӵ���ͷ
void initPlayerTank(allTank* aTank, int x, int y, WORD color, int faction, int blood);//����һ�����̹��
void initCTank(allTank* aTank, int x, int y, WORD color, int faction, int blood);//����һ������̹��
void initCompuTank(allTank* aTank, int number, WORD color, int faction);//����3������̹��
void printTank(Tank* ptank);//��ӡ̹��
void eraseTank(Tank* ptank);//����̹��
void printBullet(allBullet* aBullet);//��ӡ�ӵ�
void eraseBullet(allBullet* aBullet, allTank* aTank);//�����ӵ�
void printAllpTank(allTank* aTank);//��ӡ����̹��
void move(Tank* ptank, char keyPress, allTank* aTank);//�ƶ�̹��
void setBullet(Tank* ptank, allBullet* aBullet);//�����ӵ�
void isAttack(Tank** ptank, Bullet* bullet, allTank* aTank);//�ж��Ƿ����̹��
bool isBullet(Bullet** bullet, allTank* aTank, allBullet* aBullet, int value);//�������ҵ�valueֵΪ1234
void moveBullet(allBullet* aBullet, allTank* aTank);
int run(allTank* aTank, allBullet* aBullet);
void deleteTank(allTank* aTank);
bool moveWall(int x, int y);//�ж�̹���Ƿ�ײǽ