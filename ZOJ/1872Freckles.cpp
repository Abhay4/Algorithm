/*
 * ZJU 1872 Freckles
 * 00:00.00 928k
 * 2005.03.13 by adai
 */

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define MAXN 100
#define inf 10000000

//�ɸ��ı�Ȩ������,pre[]�������Ĺ���,�ø�����ʾ,���ڵ�(��һ��)preֵΪ-1
//���뱣֤ͼ����ͨ��!
typedef double elem_t;

elem_t prim(int n,elem_t mat[][MAXN],int* pre)
{
	elem_t min[MAXN],ret=0;
	int v[MAXN],i,j,k;
	for (i=0;i<n;i++)
		min[i]=inf,v[i]=0,pre[i]=-1;
	for (min[j=0]=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
		for (v[k]=1,ret+=min[k],i=0;i<n;i++)
			if (!v[i]&&mat[k][i]<min[i])
				min[i]=mat[pre[i]=k][i];
	}
	return ret;
}

class point{
public:
	double x;
	double y;
}pt[MAXN];

double len(point a, point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dis[MAXN][MAXN];
int pre[MAXN];
int num;

int main()
{
	while (scanf("%d", &num) != EOF)
	{
		for (int i = 0; i < num; ++i)
		{
			scanf("%lf %lf", &pt[i].x, &pt[i].y);
		}
		for (int i = 0; i < num; ++i)
		{
			for (int j = i; j < num; ++j)
			{
				dis[i][j] = dis[j][i] = len(pt[i], pt[j]);
			}
		}
		double ret = prim(num, dis, pre);
		printf("%.2lf\n", ret);
	}
	return 0;
}