//
//  main.cpp
//  FLoyd算法
//
//  Created by apple on 2021/3/15.
//  Copyright © 2021 apple. All rights reserved.
//

#include <iostream>
#include<iomanip>
#include<string>
using namespace std;
#define INF 0x3f3f3f3f
#define vertexNum 4
int G[vertexNum][vertexNum];
string vertex[]={"1","2","3","4"};
void creatM(){
    for(int i =0;i<vertexNum;i++)
        for (int j=0; j<vertexNum; j++) {
            if(i==j){
                G[i][j]=0;
            }
            else
                G[i][j]=INF;
        }
    G[0][1]=2;G[0][2]=6;G[0][3]=4;
    G[1][2]=3;G[2][3]=1;G[2][0]=7;
    G[3][0]=5;G[3][2]=12;
        
    
}
void floyd()
{
    int dist[vertexNum][vertexNum],i,k,j;
    string path[vertexNum][vertexNum];
    
    for(i=0;i<vertexNum;i++)
    for(j=0;j<vertexNum;j++)
    {
        dist[i][j]=G[i][j];
        path[i][j]=vertex[i]+"-->"+vertex[j];
    }
    for (k=0; k<vertexNum; k++) {
        for (i=0; i<vertexNum; i++) {
            for (j=0; j<vertexNum; j++) {
                if ((dist[i][k]+dist[k][j]<dist[i][j])&&(dist[i][k]!=INF)&&(dist[k][j]!=INF)&&(i!=j)) {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    path[i][j]=path[i][k]+"-->"+vertex[j];
                }
            }
        }
    }
    for(i=0;i<vertexNum;i++)
    {
        cout<<"顶点"<<vertex[i]<<"到各顶点的最短路径及权值和"<<endl;
        for(j=0;j<vertexNum;j++)
        {
            cout<<path[i][j]<<" ";
            if(dist[i][j]!=INF) cout<<dist[i][j]<<endl;
            else cout<<"∞"<<endl;
        }
    }
   
 
}
int main(int argc, const char * argv[]) {
    creatM();
    cout << "打印邻接矩阵" << endl;
    for (int i=0; i<vertexNum; i++) {
        for (int j=0; j<vertexNum; j++) {
            if (G[i][j]==INF) {
                cout <<"∞";
            }
            else cout<<G[i][j];
            if (j==3) {
                cout<<endl;
            }
        }
    }
    floyd();
    return 0;
}
