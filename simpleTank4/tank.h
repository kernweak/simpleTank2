#pragma once
#include"unit.h"

enum DIRE {
	UP, DOWN, RIGHT, LEFT,
};


typedef struct Tank {
	int visable;//是否可见
	int m_blood;//坦克的生命值
	int m_score;//坦克的得分
	int m_x;//坦克中心的x坐标
	int m_y;//坦克中心的y坐标
	DIRE m_direction;//坦克的方向
	int m_faction;//阵营
	unit body[6];//坦克的躯干
	Tank* Next;
}Tank;

typedef struct allTank {
	int bNum;//屏幕坦克的数量
	Tank* bul;//指向的第一个坦克
}allTank;


typedef struct Bullet {
	int m_x;//子弹的x坐标
	int m_y;//子弹的的y坐标
	DIRE m_direction;//子弹的方向
	int m_faction;//子弹所属坦克
	char bulletBody[3];//子弹的图标
	bool value;//子弹是否有效
	int visable;
	int classify;//子弹所属种类
	WORD color;
	Bullet* Next;
	//	Bullet* prior;
}Bullet;

typedef struct allBullet {
	int bNum;//屏幕子弹的数量
	Bullet* bul;//指向的第一个子弹
}allBullet;


void initTank(allTank** aTank);//初始化坦克表头
void initBullet(allBullet** aBullet);//初始化子弹表头
void initPlayerTank(allTank* aTank, int x, int y, WORD color, int faction, int blood);//建立一个玩家坦克
void initCTank(allTank* aTank, int x, int y, WORD color, int faction, int blood);//建立一个电脑坦克
void initCompuTank(allTank* aTank, int number, WORD color, int faction);//创建3个电脑坦克
void printTank(Tank* ptank);//打印坦克
void eraseTank(Tank* ptank);//擦除坦克
void printBullet(allBullet* aBullet);//打印子弹
void eraseBullet(allBullet* aBullet, allTank* aTank);//擦除子弹
void printAllpTank(allTank* aTank);//打印所有坦克
void move(Tank* ptank, char keyPress, allTank* aTank);//移动坦克
void setBullet(Tank* ptank, allBullet* aBullet);//发射子弹
void isAttack(Tank** ptank, Bullet* bullet, allTank* aTank);//判断是否击中坦克
bool isBullet(Bullet** bullet, allTank* aTank, allBullet* aBullet, int value);//上下左右的value值为1234
void moveBullet(allBullet* aBullet, allTank* aTank);
int run(allTank* aTank, allBullet* aBullet);
void deleteTank(allTank* aTank);
bool moveWall(int x, int y);//判断坦克是否撞墙