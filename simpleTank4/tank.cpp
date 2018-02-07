
#include "stdafx.h"
#include "unit.h"
#include "tank.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include<conio.h>
#include <time.h>  

void initTank(allTank** aTank) {
	*aTank = (allTank*)malloc(sizeof(allTank));
	if (NULL == aTank) {
		printf("��ʼ��̹��ʧ��\n");
	}
	memset(*aTank, 0, sizeof(allTank));
	allTank* p = *aTank;
	p->bNum = 0;
	Tank *ptank = (Tank*)malloc(sizeof(Tank));
	memset(ptank, 0, sizeof(Tank));
	ptank->visable = 0;
	ptank->Next = NULL;
	p->bul = ptank;

}
void initBullet(allBullet** aBullet) {//�����ӵ�
	*aBullet = (allBullet*)malloc(sizeof(allBullet));
	if (NULL == aBullet) {
		printf("��ʼ���ӵ�ʧ��\n");
	}
	memset(*aBullet, 0, sizeof(allBullet));
	allBullet* p = *aBullet;
	Bullet *pbullet = (Bullet*)malloc(sizeof(Bullet));
	memset(pbullet, 0, sizeof(pbullet));
	pbullet->visable = 0;
	pbullet->Next = NULL;
	p->bNum = 0;
	p->bul = pbullet;
}


void initPlayerTank(allTank* aTank, int x, int y, WORD color, int faction, int blood) {
	Tank *ptank = (Tank*)malloc(sizeof(Tank));
	Tank *temp = aTank->bul;
	if (NULL == ptank) {
		printf("��ʼ�����̹��ʧ��\n");
	}
	memset(ptank, 0, sizeof(Tank));
	Tank *p = ptank;
	p->visable = 1;
	p->m_blood = blood;
	p->m_direction = UP;
	p->m_faction = faction;
	p->m_score = 0;
	p->m_x = x;
	p->m_y = y;
	p->body[0].m_x = p->m_x;
	p->body[0].m_y = p->m_y - 1;
	p->body[0].pszChar = "��";
	p->body[0].color = color;
	p->body[1].m_x = p->m_x;
	p->body[1].m_y = p->m_y;
	p->body[1].pszChar = "��";
	p->body[1].color = color;
	p->body[2].m_x = p->m_x - 1;
	p->body[2].m_y = p->m_y;
	p->body[2].pszChar = "��";
	p->body[2].color = color;
	p->body[3].m_x = p->m_x + 1;
	p->body[3].m_y = p->m_y;
	p->body[3].pszChar = "��";
	p->body[3].color = color;
	p->body[4].m_x = p->m_x - 1;
	p->body[4].m_y = p->m_y + 1;
	p->body[4].pszChar = "��";
	p->body[4].color = color;
	p->body[5].m_x = p->m_x + 1;
	p->body[5].m_y = p->m_y + 1;
	p->body[5].pszChar = "��";
	p->body[5].color = color;
	p->Next = NULL;
	while (temp->Next != NULL)
		temp = temp->Next;
	temp->Next = p;
	aTank->bNum += 1;
}

void initCTank(allTank* aTank, int x, int y, WORD color, int faction, int blood) {
	Tank *ptank = (Tank*)malloc(sizeof(Tank));
	Tank *temp = aTank->bul;
	if (NULL == ptank) {
		printf("��ʼ������̹��ʧ��\n");
	}
	memset(ptank, 0, sizeof(Tank));
	Tank *p = ptank;
	p->m_blood = blood;
	p->visable = 1;
	p->m_direction = DOWN;
	p->m_faction = faction;
	p->m_score = 0;
	p->m_x = x;
	p->m_y = y;
	p->body[0].m_x = p->m_x;
	p->body[0].m_y = p->m_y + 1;
	p->body[0].pszChar = "��";
	p->body[0].color = color;
	p->body[1].m_x = p->m_x;
	p->body[1].m_y = p->m_y;
	p->body[1].pszChar = "��";
	p->body[1].color = color;
	p->body[2].m_x = p->m_x + 1;
	p->body[2].m_y = p->m_y;
	p->body[2].pszChar = "��";
	p->body[2].color = color;
	p->body[3].m_x = p->m_x - 1;
	p->body[3].m_y = p->m_y;
	p->body[3].pszChar = "��";
	p->body[3].color = color;
	p->body[4].m_x = p->m_x + 1;
	p->body[4].m_y = p->m_y - 1;
	p->body[4].pszChar = "��";
	p->body[4].color = color;
	p->body[5].m_x = p->m_x - 1;
	p->body[5].m_y = p->m_y - 1;
	p->body[5].pszChar = "��";
	p->body[5].color = color;
	p->Next = NULL;
	while (temp->Next != NULL)
		temp = temp->Next;
	temp->Next = p;
	aTank->bNum += 1;

}

void initCompuTank(allTank* aTank, int number, WORD color, int faction) {
	initCTank(aTank, 3, 2, color, faction, 2);
	initCTank(aTank, 48, 2, color, faction, 2);
	initCTank(aTank, 24, 2, color, faction, 2);
}

void printTank(Tank* ptank) {
	//	if(ptank!=NULL)
	if (ptank->visable == 1)
		for (int i = 0;i < 6;i++) {
			PrintCHar(ptank->body[i].m_x, ptank->body[i].m_y, \
				ptank->body[i].pszChar, ptank->body[i].color);
		}
}
void eraseTank(Tank* ptank) {
	if (ptank != NULL)
		for (int i = 0;i < 6;i++) {
			PrintCHar(ptank->body[i].m_x, ptank->body[i].m_y, \
				g_nMap[ptank->body[i].m_y][ptank->body[i].m_x].pic, \
				g_nMap[ptank->body[i].m_y][ptank->body[i].m_x].color);
		}
}

void printBullet(allBullet* aBullet) {
	Bullet* p = aBullet->bul->Next;
	while (NULL != p) {
		PrintCHar(p->m_x, p->m_y, \
			p->bulletBody, p->color);
		p = p->Next;
	}
}

void eraseBullet(allBullet* aBullet, allTank* aTank) {
	Bullet* p = aBullet->bul->Next;
	while (NULL != p) {
		Tank* q = aTank->bul->Next;
		int temp = 0;
		WORD color1;
		char temp2[3];
		while (q != NULL) {
			for (int i = 0;i < 6;i++) {
				if ((q->body[i].m_x == p->m_x) && (q->body[i].m_y == p->m_y))
					temp = 1;
				strcpy_s(temp2, q->body[i].pszChar);
				color1 = q->body[i].color;
			}
			q = q->Next;
		}

		if (temp == 1) {
			PrintCHar(p->m_x, p->m_y, temp2, color1);


		}
		else {
			PrintCHar(p->m_x, p->m_y, \
				g_nMap[p->m_y][p->m_x].pic, g_nMap[p->m_y][p->m_x].color);
		}
		p = p->Next;
	}
}


void printAllpTank(allTank* aTank) {
	Tank *p = aTank->bul->Next;
	while (NULL != p) {
		printTank(p);
		p = p->Next;
	}
}

bool moveWall(int x, int y) {
	if (g_nMap[y][x].m_information != 0)

		return true;
	else
		return false;
}


void move(Tank* ptank, char keyPress, allTank* aTank) {
	Tank* currentTank = ptank;
	Tank* tempTank = aTank->bul->Next;
	eraseTank(ptank);
	int isCollide = 0;
	if (ptank != NULL)
		switch (keyPress) {

		case 'w':
			if (ptank->m_direction == UP) {
				//�ж�̹���Ƿ���ϰ����������̹����ײ
				while (NULL != tempTank) {
					for (int i = 0;i < 6;i++) {
						if (((tempTank->body[i].m_x == currentTank->body[0].m_x) && (tempTank->body[i].m_y == (currentTank->body[0].m_y - 1))) || ((tempTank->body[i].m_x == currentTank->body[2].m_x) && (tempTank->body[i].m_y == (currentTank->body[2].m_y - 1))) || ((tempTank->body[i].m_x == currentTank->body[3].m_x) && (tempTank->body[i].m_y == (currentTank->body[3].m_y - 1)))) {
							isCollide = 1;
						}
					}
					tempTank = tempTank->Next;
				}

				if (moveWall(currentTank->body[0].m_x, currentTank->body[0].m_y - 1))
					isCollide = 1;
				if (moveWall(currentTank->body[2].m_x, currentTank->body[2].m_y - 1))
					isCollide = 1;
				if (moveWall(currentTank->body[3].m_x, currentTank->body[3].m_y - 1))
					isCollide = 1;
				if (isCollide == 1) {
					printTank(currentTank);
					//					PrintCHar(currentTank->body[3].m_x, currentTank->body[3].m_y - 1, g_nMap[currentTank->body[3].m_y - 1][currentTank->body[3].m_x].pic, g_nMap[currentTank->body[3].m_y - 1][currentTank->body[3].m_x].color);
					break;
				}
				if (ptank->body[0].m_y > 1) {
					ptank->m_y = ptank->m_y - 1;
					for (int i = 0;i < 6;i++) {
						ptank->body[i].m_y = ptank->body[i].m_y - 1;

					}
				}
			}
			else {
				ptank->m_direction = UP;
				ptank->body[0].m_x = ptank->m_x;
				ptank->body[0].m_y = ptank->m_y - 1;
				ptank->body[2].m_x = ptank->m_x - 1;
				ptank->body[2].m_y = ptank->m_y;
				ptank->body[3].m_x = ptank->m_x + 1;
				ptank->body[3].m_y = ptank->m_y;
				ptank->body[4].m_x = ptank->m_x - 1;
				ptank->body[4].m_y = ptank->m_y + 1;
				ptank->body[5].m_x = ptank->m_x + 1;
				ptank->body[5].m_y = ptank->m_y + 1;
			}
			printTank(ptank);
			break;
		case 's':
			if (ptank->m_direction == DOWN) {
				//�ж�̹���Ƿ���ϰ����������̹����ײ
				while (NULL != tempTank) {
					for (int i = 0;i < 6;i++) {
						if (((tempTank->body[i].m_x == currentTank->body[0].m_x) && (tempTank->body[i].m_y == (currentTank->body[0].m_y + 1))) || ((tempTank->body[i].m_x == currentTank->body[2].m_x) && (tempTank->body[i].m_y == (currentTank->body[2].m_y + 1))) || ((tempTank->body[i].m_x == currentTank->body[3].m_x) && (tempTank->body[i].m_y == (currentTank->body[3].m_y + 1)))) {
							isCollide = 1;
						}

					}
					tempTank = tempTank->Next;
				}

				if (moveWall(currentTank->body[0].m_x, currentTank->body[0].m_y + 1))
					isCollide = 1;
				if (moveWall(currentTank->body[2].m_x, currentTank->body[2].m_y + 1))
					isCollide = 1;
				if (moveWall(currentTank->body[3].m_x, currentTank->body[3].m_y + 1))
					isCollide = 1;
				if (isCollide == 1) {
					printTank(currentTank);
					break;
				}




				if (ptank->body[0].m_y < 48) {
					ptank->m_y = ptank->m_y + 1;
					for (int i = 0;i < 6;i++) {
						ptank->body[i].m_y = ptank->body[i].m_y + 1;
					}
				}
			}
			else {
				ptank->m_direction = DOWN;
				ptank->body[0].m_x = ptank->m_x;
				ptank->body[0].m_y = ptank->m_y + 1;
				ptank->body[2].m_x = ptank->m_x + 1;
				ptank->body[2].m_y = ptank->m_y;
				ptank->body[3].m_x = ptank->m_x - 1;
				ptank->body[3].m_y = ptank->m_y;
				ptank->body[4].m_x = ptank->m_x + 1;
				ptank->body[4].m_y = ptank->m_y - 1;
				ptank->body[5].m_x = ptank->m_x - 1;
				ptank->body[5].m_y = ptank->m_y - 1;
			}
			printTank(ptank);
			break;

		case 'a':
			if (ptank->m_direction == LEFT) {

				//�ж�̹���Ƿ���ϰ����������̹����ײ
				while (NULL != tempTank) {
					for (int i = 0;i < 6;i++) {
						if (((tempTank->body[i].m_x == (currentTank->body[0].m_x - 1)) && (tempTank->body[i].m_y == (currentTank->body[0].m_y))) || ((tempTank->body[i].m_x == (currentTank->body[2].m_x - 1)) && (tempTank->body[i].m_y == (currentTank->body[2].m_y))) || ((tempTank->body[i].m_x == (currentTank->body[3].m_x - 1)) && (tempTank->body[i].m_y == (currentTank->body[3].m_y)))) {
							isCollide = 1;
						}
					}
					tempTank = tempTank->Next;
				}

				if (moveWall(currentTank->body[0].m_x - 1, currentTank->body[0].m_y))
					isCollide = 1;
				if (moveWall(currentTank->body[2].m_x - 1, currentTank->body[2].m_y))
					isCollide = 1;
				if (moveWall(currentTank->body[3].m_x - 1, currentTank->body[3].m_y))
					isCollide = 1;

				if (isCollide == 1) {
					printTank(currentTank);
					break;
				}


				if (ptank->body[0].m_x > 1) {
					ptank->m_x = ptank->m_x - 1;
					for (int i = 0;i < 6;i++) {
						ptank->body[i].m_x = ptank->body[i].m_x - 1;

					}
				}
			}
			else {
				ptank->m_direction = LEFT;
				ptank->body[0].m_x = ptank->m_x - 1;
				ptank->body[0].m_y = ptank->m_y;
				ptank->body[2].m_x = ptank->m_x;
				ptank->body[2].m_y = ptank->m_y + 1;
				ptank->body[3].m_x = ptank->m_x;
				ptank->body[3].m_y = ptank->m_y - 1;
				ptank->body[4].m_x = ptank->m_x + 1;
				ptank->body[4].m_y = ptank->m_y + 1;
				ptank->body[5].m_x = ptank->m_x + 1;
				ptank->body[5].m_y = ptank->m_y - 1;
			}
			printTank(ptank);
			break;

		case 'd':
			if (ptank->m_direction == RIGHT) {


				//�ж�̹���Ƿ���ϰ����������̹����ײ
				while (NULL != tempTank) {
					for (int i = 0;i < 6;i++) {
						if (((tempTank->body[i].m_x == (currentTank->body[0].m_x + 1)) && (tempTank->body[i].m_y == (currentTank->body[0].m_y))) || ((tempTank->body[i].m_x == (currentTank->body[2].m_x + 1)) && (tempTank->body[i].m_y == (currentTank->body[2].m_y))) || ((tempTank->body[i].m_x == (currentTank->body[3].m_x + 1)) && (tempTank->body[i].m_y == (currentTank->body[3].m_y)))) {
							isCollide = 1;
						}
					}
					tempTank = tempTank->Next;
				}

				if (moveWall(currentTank->body[0].m_x + 1, currentTank->body[0].m_y))
					isCollide = 1;
				if (moveWall(currentTank->body[2].m_x + 1, currentTank->body[2].m_y))
					isCollide = 1;
				if (moveWall(currentTank->body[3].m_x + 1, currentTank->body[3].m_y))
					isCollide = 1;

				if (isCollide == 1) {
					printTank(currentTank);
					break;
				}



				if (ptank->body[0].m_x < 59) {
					ptank->m_x = ptank->m_x + 1;
					for (int i = 0;i < 6;i++) {
						ptank->body[i].m_x = ptank->body[i].m_x + 1;

					}
				}
			}
			else {
				ptank->m_direction = RIGHT;
				ptank->body[0].m_x = ptank->m_x + 1;
				ptank->body[0].m_y = ptank->m_y;
				ptank->body[2].m_x = ptank->m_x;
				ptank->body[2].m_y = ptank->m_y - 1;
				ptank->body[3].m_x = ptank->m_x;
				ptank->body[3].m_y = ptank->m_y + 1;
				ptank->body[4].m_x = ptank->m_x - 1;
				ptank->body[4].m_y = ptank->m_y - 1;
				ptank->body[5].m_x = ptank->m_x - 1;
				ptank->body[5].m_y = ptank->m_y + 1;
			}
			printTank(ptank);
			break;


		}
}


void setBullet(Tank* ptank, allBullet* aBullet) {
	if (ptank==NULL||ptank->visable == 0)return;
	Bullet* p = (Bullet*)malloc(sizeof(Bullet));
	memset(p, 0, sizeof(Bullet));
	Bullet* temp = aBullet->bul;
		while (NULL != temp->Next) {
			temp = temp->Next;
		}
		temp->Next = p;

	if (p != NULL) {
		p->m_direction = ptank->m_direction;
		p->m_faction = ptank->m_faction;
		p->color = ptank->body[0].color;
		p->Next = NULL;
		strcpy_s(p->bulletBody, "��");
		switch (ptank->m_direction) {
		case UP:
			p->m_x = ptank->m_x;
			p->m_y = ptank->m_y - 2;
			break;
		case DOWN:
			p->m_x = ptank->m_x;
			p->m_y = ptank->m_y + 2;
			break;
		case LEFT:
			p->m_x = ptank->m_x - 2;
			p->m_y = ptank->m_y;
			break;
		case RIGHT:
			p->m_x = ptank->m_x + 2;
			p->m_y = ptank->m_y;
			break;
		}
		aBullet->bNum += aBullet->bNum;
	}
}

void isAttack(Tank** ptank1, Bullet* bullet, allTank* aTank) {
	Tank* ptank = *ptank1;
	Tank*p = aTank->bul->Next;
	ptank->m_blood -= 1;
	if (ptank->m_blood == 0) {
		ptank->visable = 0;
	}

}

bool isBullet(Bullet** bullet, allTank* aTank, allBullet* aBullet, int value) {
	int x = 0, y = 0;
	if (value == 1)
		y = -1;
	if (value == 2)
		y = 1;
	if (value == 3)
		x = -1;
	if (value == 4)
		x = 1;
	Bullet*p = *bullet;
	Bullet*q = aBullet->bul;
	Tank* u = aTank->bul->Next;
	Tank* destoryTank = NULL;//�洢���ݻٵ�̹��
	int temp = 0;//�ж��ӵ��Ƿ��̹����ײ��0Ϊ��ײ
	while (u != NULL) {//�ж��ӵ��Ƿ��ĳ��̹����ײ
		for (int i = 0;i < 6;i++) {
			if ((u->body[i].m_x == (p->m_x + x)) && (u->body[i].m_y == (p->m_y + y))) {
				temp = 1;
				destoryTank = u;
				break;
			}
		}
		if (temp == 1)break;
		u = u->Next;
	}
	if (temp == 1) {
		if (destoryTank->m_faction != p->m_faction)
			isAttack(&destoryTank, p, aTank);
	}
	int temp2 = 0;//�ж��ӵ��Ƿ�͵�ͼ��Ϣ��ײ
	if (g_nMap[p->m_y + y][p->m_x + x].m_information != 0)
		temp2 = 1;
	if (g_nMap[p->m_y + y][p->m_x + x].m_information == 3)
	{
		g_nMap[p->m_y + y][p->m_x + x].m_information = 0;
		g_nMap[p->m_y + y][p->m_x + x].color = (e_��ɫ, e_��ɫ);
		strcpy_s(g_nMap[p->m_y + y][p->m_x + x].pic, "  ");
		PrintCHar(p->m_x + x, p->m_y + y, g_nMap[p->m_y + y][p->m_x + x].pic, g_nMap[p->m_y + y][p->m_x + x].color);
	}

	if (g_nMap[p->m_y + y][p->m_x + x].m_information == 4)
	{
		g_nMap[p->m_y + y][p->m_x + x].m_information = 0;
		g_nMap[p->m_y + y][p->m_x + x].color = (e_��ɫ, e_��ɫ);
		strcpy_s(g_nMap[p->m_y + y][p->m_x + x].pic, "  ");
		PrintCHar(p->m_x + x, p->m_y + y, g_nMap[p->m_y + y][p->m_x + x].pic, g_nMap[p->m_y + y][p->m_x + x].color);
		aTank->bul->Next->m_blood = -1;
	}

	if ((0 != g_nMap[p->m_x + x][p->m_y + y].m_information) || (temp == 1)||(temp2==1)) {
			while (q->Next != p) {
				q = q->Next;
			}
			q->Next = p->Next;
			free(p);
			*bullet = q->Next;
		
		return false;
	}

	return true;
}

void moveBullet(allBullet* aBullet, allTank* aTank) {
	eraseBullet(aBullet, aTank);
	Bullet*p = aBullet->bul->Next;
	while (NULL != p) {
		switch (p->m_direction) {
		case UP:
			//		p->m_y -= 1;
			if (isBullet(&p, aTank, aBullet, 1))
				p->m_y -= 1;
			break;
		case DOWN:
			//		p->m_y += 1;
			if (isBullet(&p, aTank, aBullet, 2))
				p->m_y += 1;
			break;
		case LEFT:
			//		p->m_x -= 1;
			if (isBullet(&p, aTank, aBullet, 3))
				p->m_x -= 1;
			break;
		case RIGHT:
			//			p->m_x += 1;
			if (isBullet(&p, aTank, aBullet, 4))
				p->m_x += 1;
			break;
		}
		if (p == NULL)break;
		p = p->Next;
	}
	printBullet(aBullet);
}

void deleteTank(allTank* aTank) {
	Tank* temp = NULL;
	Tank*p = aTank->bul->Next;
	Tank* Findp = aTank->bul;
	if (p == NULL)return;
	for (; NULL != p;)
	{
		if (p->visable == 0)
		{
			eraseTank(p);
			temp = p;
			Findp->Next = p->Next;
			p = p->Next;
			free(temp);
			temp = NULL;
		}
		else
		{
			p = p->Next;
			Findp = Findp->Next;
		}

	}

}


int run(allTank* aTank, allBullet* aBullet) {
	int fina = 0;
	Tank* player = aTank->bul->Next;
	while (player->m_faction != 2) {
		player = player->Next;
	}

	srand(time(NULL));
	bool pauseFlag = true;//0Ϊ��ͣ
	bool stopMove = true;
	char press = 0;
	char dir[4] = { 'w','s', 'd','a' };
	clock_t start, finish;//�о�̹��
	clock_t start1, finish1;//�ӵ��ƶ�
	clock_t start2, finish2;//�ӵ�����
	start = clock();
	start1 = clock();
	start2 = clock();
	while (press != 0X1b && stopMove) {
		printAllpTank(aTank);
		Tank* temp = aTank->bul->Next;
		if (temp->m_blood == -1) {
			fina = 6;
			break;
		}
		if (temp->m_faction != 2) {
			fina = 3;
			break;
		}
		if (temp->Next == NULL) {
			fina = 5;
			break;
		}

		deleteTank(aTank);
		if (_kbhit()) {
			press = _getch();
			if (press == 0x20) {
				pauseFlag = !pauseFlag;
			}
			if (press == 0x71)
			{

				setBullet(player, aBullet);
				printTank(player);
				printBullet(aBullet);
			}
			move(player, press, aTank);
		}
		if (pauseFlag) {
			continue;
		}

		finish = clock();
		finish1 = clock();
		finish2 = clock();
		if (finish - start > 400) {
			start = finish;
			if (temp == NULL)
			{
				fina = 4;
				break;
			}
			Tank *p = temp->Next;
			while (p != NULL) {

				int a, b;
				a = rand() % 4;
				b = rand() % 2;
				if (p != NULL)
				if((a = rand() % 8)%4==0)
				setBullet(p, aBullet);
				printBullet(aBullet);
				printTank(p);
				for (int i = 0;i < b;i++) {
					move(p, dir[a], aTank);
				}
				p = p->Next;
			}
		}
		if (finish1 - start1 > 100) {
			start1 = finish1;
			moveBullet(aBullet, aTank);
			printBullet(aBullet);
			printAllpTank(aTank);
		}
	}
	return fina;
}
void pGameIntroduce() {
	PrintCHar(61, 1, "������Ϸ���¿ո�ʼ��Ϸ", 7);
	PrintCHar(61, 2, "���Ʒ����Ϊwasd", 7);
	PrintCHar(61, 3, "qΪ�����ӵ�", 7);
	PrintCHar(61, 4, "��ǽ���ϰ��ﲻ�ɴݻ�", 7);
	PrintCHar(61, 5, "��ǽ���ϰ���ɴݻ�", 7);
	PrintCHar(61, 6, "�ո�Ϊ��ͣ", 7);
}