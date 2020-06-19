/*--------------------------------------------------
�ļ����ƣ�������
�ļ���������Ϸ
���뻷����Visual Studio 2015
����޸ģ�<2017��10��13��> <��������> <����>
---------------------------------------------------*/
#include <conio.h>
#include <graphics.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

IMAGE box, people, darkbox, end, wall, blank;
int map[13][12] = {
	{ 0,0,1,1,1,1,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,1,0,0,0,0,0 },
	{ 1,1,1,0,0,4,0,1,0,0,0,0 },
	{ 1,3,0,1,0,0,0,0,1,0,0,0 },
	{ 1,3,0,0,1,0,0,0,0,1,0,0 },
	{ 0,1,0,0,0,1,0,0,4,0,1,0 },
	{ 0,0,1,3,0,0,5,4,0,0,0,1 },
	{ 0,1,0,0,0,1,0,0,4,0,1,0 },
	{ 1,3,0,0,1,0,0,0,0,1,0,0 },
    { 1,3,0,1,0,0,0,0,1,0,0,0 },
    { 1,1,1,0,0,4,0,1,0,0,0,0 },
    { 0,1,0,0,0,0,1,0,0,0,0,0 },
    { 0,0,1,1,1,1,0,0,0,0,0,0 } };

void DrawMap();
void PlayGame();
void loadImage();

int main()
{
	initgraph(845, 780);	//13 12

	mciSendString(L"open ./image/�һ�Ц.mp3 alias music", 0, 0, 0);
	mciSendString(L"play music repeat", 0, 0, 0);

	loadImage();

	while (1)
	{

		DrawMap();
		PlayGame();
	}


	getch();
	return 0;
}

void loadImage()
{
	loadimage(&box, L"./image/box.jpg", 65, 65);
	loadimage(&people, L"./image/people.jpg", 65, 65);
	loadimage(&darkbox, L"./image/darkbox.jpg", 65, 65);
	loadimage(&end, L"./image/end.jpg", 65, 65);
	loadimage(&wall, L"./image/wall.jpg", 65, 65);
	loadimage(&blank, L"./image/blank.jpg", 65, 65);
}

void DrawMap()
{
	BeginBatchDraw();
	cleardevice();
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			switch (map[i][j])
			{
			case 0:
				putimage(i * 65, j * 65, &blank);
				break;

			case 1:
				putimage(i * 65, j * 65, &wall);
				break;

			case 3:
				putimage(i * 65, j * 65, &end);
				break;

			case 4:
				putimage(i * 65, j * 65, &box);
				break;

			case 5:
				putimage(i * 65, j * 65, &people);
				break;

			case 7:
				putimage(i * 65, j * 65, &darkbox);
				break;

			case 8:
				putimage(i * 65, j * 65, &people);
				break;
			}
		}
	}
	EndBatchDraw();
}

void PlayGame()
{

	int r, c;  //�˵��к���

			   //�˵���������. // 5   8
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (map[i][j] == 5 || map[i][j] == 8)
			{
				r = i;
				c = j;
			}
		}
	}

	int dir = getch();  //getchar() �����ַ� ��Ҫ���»س��������.

	switch (dir)
	{
	case 72:
		if (map[r][c - 1] == 0 || map[r][c - 1] == 3)
		{
			map[r][c - 1] += 5;
			map[r][c] -= 5;
		}
		//3.�˵�ǰ��������
		//3.1���ӵ�ǰ���ǿյ�.
		//3.2���ӵ�ǰ����Ŀ�ĵ�.
		else if (map[r][c - 1] == 4 || map[r][c - 1] == 7)
		{
			if (map[r][c - 2] == 0 || map[r][c - 2] == 3)
			{
				map[r][c - 2] += 4;
				map[r][c - 1] += 1;
				map[r][c] -= 5;
			}
		}
		break;

	case 80:
		if (map[r][c + 1] == 0 || map[r][c + 1] == 3)
		{
			map[r][c + 1] += 5;
			map[r][c] -= 5;
		}
		else if (map[r][c + 1] == 4 || map[r][c + 1] == 7)
		{
			if (map[r][c + 2] == 0 || map[r][c + 2] == 3)
			{
				map[r][c + 2] += 4;
				map[r][c + 1] += 1;
				map[r][c] -= 5;
			}
		}


		break;

	case 75:    //��ֵ
		if (map[r - 1][c] == 0 || map[r - 1][c] == 3)
		{
			map[r - 1][c] += 5;
			map[r][c] -= 5;
		}
		//3.�˵�ǰ��������
		//3.1���ӵ�ǰ���ǿյ�.
		//3.2���ӵ�ǰ����Ŀ�ĵ�.
		else if (map[r - 1][c] == 4 || map[r - 1][c] == 7)
		{
			if (map[r - 2][c] == 0 || map[r - 2][c] == 3)
			{
				map[r - 2][c] += 4;
				map[r - 1][c] += 1;
				map[r][c] -= 5;
			}
		}
		break;

	case 77:
		if (map[r + 1][c] == 0 || map[r + 1][c] == 3)
		{
			map[r + 1][c] += 5;
			map[r][c] -= 5;
		}
		//3.�˵�ǰ��������
		//3.1���ӵ�ǰ���ǿյ�.
		//3.2���ӵ�ǰ����Ŀ�ĵ�.
		else if (map[r + 1][c] == 4 || map[r + 1][c] == 7)
		{
			if (map[r + 2][c] == 0 || map[r + 2][c] == 3)
			{
				map[r + 2][c] += 4;
				map[r + 1][c] += 1;
				map[r][c] -= 5;
			}
		}
		break;
	}
}
