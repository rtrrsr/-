/*--------------------------------------------------
      �ļ����ƣ�������
      �ļ���������Ϸ
      ���뻷����Code::Blocks 16.01
---------------------------------------------------*/
#include <stdio.h>
#include <conio.h>

int map[9][11] = {
    {0,1,1,1,1,1,1,1,1,1,0},
    {0,1,0,0,0,1,0,0,0,1,0},
    {0,1,0,4,0,4,4,4,0,1,0},
    {0,1,0,4,0,4,0,4,0,1,1},
    {0,1,0,0,0,0,5,0,4,0,1},
    {1,1,0,1,1,1,1,0,4,0,1},
    {1,0,3,3,3,3,1,1,0,0,1},
    {1,0,3,3,3,3,3,0,0,1,1},
    {1,1,1,1,1,1,1,1,1,1,0}};

void PlayGame();
void DrawMap();

int main()
{
    while (1)
    {
        system("cls");
        DrawMap();
        PlayGame();
    }
    return 0;
}

void DrawMap()
{
    int i,j;
    for (i=0; i < 9; i++)
    {
        for (j=0; j <11; j++)
        {
            switch (map[i][j])
            {
            case 0:
                printf("  ");//0�յ�
                break;
            case 1:
                printf("��");//1ǽ
                break;
            case 3:
                printf("��");//3Ŀ�ĵ�
                break;
            case 4:
                printf("��");//4����
                break;
            case 5:
                printf("��");//5����
                break;
            case 7: //4+3 ��������+Ŀ�ĵ�
                printf("��");
                break;
            case 8: //5+3 ����+Ŀ�ĵ�
                printf("��");
                break;
            }
        }
        printf("\n");
    }
    printf("��ӭ������������Ϸ��\n������ͨ����������������ƶ����ӵ���Ŀ�ĵء�\n�޸�����:2017��10��13��\n");
    return 0;
}//ͨ���ı�����Ԫ�ص�����˳�����ﵽ��Ϸ��Ŀ�ģ����ҽ����ػ�
//����Ϸ�Ĺ���
void PlayGame()
{
    int i,j,r,c;//�˵��к���
    for(i=0;i<9;i++)
    {
        for(j=0;j<11;j++)
        {
            if(map[i][j]==5||map[i][j]==8)
            {
                r=i;
                c=j;
            }
        }
    }
    printf("%d %d\n",r,c);
    int dir=getch();//getchar()�����ַ�����Ҫ���»س��������
    switch (dir)
    {
    case 72://��
        //1.�˵�ǰ���ǿյأ�2.�˵�ǰ����Ŀ�ĵ�
        if(map[r-1][c]==0||map[r-1][c]==3)
        {
            map[r-1][c] += 5;
            map[r][c] -= 5;
        }
        //3�˵�ǰ��������
        else if(map[r-1][c]==4||map[r-1][c]==7)
        {
           if(map[r-2][c]==0||map[r-2][c]==3)
           {
               map[r-2][c] +=4;
               map[r-1][c] +=1;
               map[r][c] -=5;
           }
        }
        break;
    case 80://��
        if(map[r+1][c]==0||map[r+1][c]==3)
        {
            map[r+1][c] += 5;
            map[r][c] -= 5;
        }
        else if(map[r+1][c]==4||map[r+1][c]==7)
        {
           if(map[r+2][c]==0||map[r+2][c]==3)
           {
               map[r+2][c] +=4;
               map[r+1][c] +=1;
               map[r][c] -=5;
           }
        }
        break;
    case 75://��
        if(map[r][c-1]==0||map[r][c-1]==3)
        {
            map[r][c-1] += 5;
            map[r][c] -= 5;
        }
        else if(map[r][c-1]==4||map[r][c-1]==7)
        {
           if(map[r][c-2]==0||map[r][c-2]==3)
           {
               map[r][c-2] +=4;
               map[r][c-1] +=1;
               map[r][c] -=5;
           }
        }
        break;
    case 77://��
        if(map[r][c+1]==0||map[r][c+1]==3)
        {
            map[r][c+1] += 5;
            map[r][c] -= 5;
        }
        else if(map[r][c+1]==4||map[r][c+1]==7)
        {
           if(map[r][c+2]==0||map[r][c+2]==3)
           {
               map[r][c+2] +=4;
               map[r][c+1] +=1;
               map[r][c] -=5;
           }
        }
        break;
        }
}












