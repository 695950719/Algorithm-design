#include<iostream>
using namespace std;
const int MaxSize = 20;
const int INF = 2147483647;
int visited[MaxSize];
int lowcost[MaxSize];
int adjvex[MaxSize];
int MinEdge(int a[], int n)
{
    int min = INF;
    int k = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (min > a[i] && a[i] != 0)
        {
            min = a[i];
            k = i;
        }
    }
    return k;
}
class MGraph
{
private:
    int arc[MaxSize][MaxSize];
    int vertex[MaxSize];
    int arcNum;
    int vertexNum;
public:
    MGraph(int a[], int n, int e)
    {
        arcNum = e;
        vertexNum = n;
        for (int i = 1; i <= vertexNum; ++i)
        {
            vertex[i] = a[i];
        }
        for (int i = 1; i <= vertexNum; ++i)
        {
            for (int j = 1; j <= vertexNum; ++j)
            {
                arc[i][j] = INF;
            }
        }
        for (int i = 1; i <= arcNum; ++i)
        {
            int a, b, v;
            cin >> a >> b >> v;
            arc[a][b] = arc[b][a] = v;
        }
    }
    void Prime()
    {
        for (int i = 2; i <= vertexNum; ++i)
        {
            lowcost[i] = arc[1][i];
            adjvex[i] = 1;
        }
        lowcost[1] = 0;
        for (int i = 2; i <= vertexNum; ++i)
        {
            int k = MinEdge(lowcost, vertexNum);
            cout << k << "  " << adjvex[k] << "  " << lowcost[k] << endl;
            lowcost[k] = 0;
            for (int j = 1; j <= vertexNum; ++j)
            {
                if (arc[k][j] < lowcost[j])
                {
                    lowcost[j] = arc[k][j];
                    adjvex[j] = k;
                }
            }
        }
    }
};
int main()
{
    int a[MaxSize];
    for (int i = 1; i < MaxSize; ++i)
    {
        a[i] = i;
    }
    int x, y;
    cin >> x >> y;
    MGraph G(a, x, y);
    G.Prime();
    return 0;
}

