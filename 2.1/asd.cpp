#include <iostream>
#include <fstream>
 
using namespace std;
 
int n,v[26],m,g[16][26],now[26],res[16],dat[16],minn=2147483647;
 
bool check()
{
	for(int i=1; i<=n; i++)
		if(now[i]<v[i]) return 0;
	return 1;
}
 
void dfs(int deep,int count)
{
     if (deep==m+1)
     {
                   //for (int i=1;i<=n;i++)
                     //  if (now[i]<v[i]) return ;
                   if (count<minn&&check())
                   {
                                 minn=count;
                                 for (int i=1;i<=minn;i++)
                                     res[i]=dat[i];
                   }
                   return ;
     }
     for (int i=1;i<=n;i++)
         now[i]+=g[deep][i];
     dat[count+1]=deep;
     dfs(deep+1,count+1);
     for (int i=1;i<=n;i++)
         now[i]-=g[deep][i];
     dfs(deep+1,count);
}
 
int main()
{
    ifstream fin("holstein.in");
    ofstream fout("holstein2.out");
 
    fin>>n;
    for (int i=1;i<=n;i++)
        fin>>v[i];
    fin>>m;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
            fin>>g[i][j];
    }
    for (int i=1;i<=n;i++)
        now[i]=0;
    dfs(1,0);
    fout<<minn;
    for (int i=1;i<=minn;i++)
        fout<<" "<<res[i];
    fout<< endl;    
    int ans[26]={0};
	for(int i=1; i<=m; i++)
    {
    	if(!(i==10||i==12))
    		for(int j=1; j<=n; j++)
    			ans[j]+=g[i][j];
    }
    for(int i=1; i<=n; i++)
    	fout <<" "<<ans[i];
    fout<<endl;
    return 0;
}