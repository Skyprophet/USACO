/*
TASK:castle
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

const int dx[4]={0,-1,0,1};
const int dy[4]={-1,0,1,0};
const int dn[4]={1,2,4,8};
const char ch[2]={'N','E'};
int m, n, color, rx, ry, rs, x, y;
int code[51][51], area[2501];
bool wall[51][51][4];

void fill(int x,int y,int t)
{
	code[x][y]=t; area[t]++;
	for(int i=0; i<4; i++)
		if(!wall[x][y][i])
		{
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(code[tx][ty]==0)
				fill(tx,ty,t);
		}
}

int main()
{
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	
	scanf("%d%d", &m, &n);
	int i, j, k, x;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
		{
			scanf("%d", &x);
			for(k=3; k>=0; k--)
				if(x>=dn[k])
				{
					x-=dn[k];
					wall[i][j][k]=1;
				}
		}
	color=0;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			if(code[i][j]==0)
			{
				color++; fill(i,j,color);
			}
	int res=0;
	for(i=1; i<=color; i++)
		if(area[i]>res) res=area[i];
	printf("%d\n", color);
	printf("%d\n", res);
	for(j=0; j<m; j++)
		for(i=n-1; i>=0; i--)
			for(k=0; k<=1; k++)
			{
				x=i+dx[k+1];
				y=j+dy[k+1];
				if(x>=0 && y<m && code[i][j]!=code[x][y])
					if(res<area[code[x][y]]+area[code[i][j]])
					{
						res=area[code[x][y]]+area[code[i][j]];
						rx=i+1; ry=j+1; rs=k;
					}
			}
	printf("%d\n", res);
	printf("%d %d %c\n", rx, ry, ch[rs]);
	
	return 0;
}
