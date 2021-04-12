#include<stdio.h>
#include<time.h>
#include<math.h>
#include<algorithm>


#define LENGTH 100001
#define INF 1e20

struct point
{
    double x;
    double y;
}p[LENGTH],tmp[LENGTH];

double dist(point a,point b) { return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)); }
double min(double a,double b) { return a<b?a:b; }
bool cpx(point a,point b) { return a.x<b.x; }
bool cpy(point a,point b) { return a.y<b.y; }

double mindist(int l,int r)
{
    double d=INF;
    if(r==l)
        return d;
    if(r-l==1)
        return dist(p[l],p[r]);
    if(r-l==2)
        return min(dist(p[l],p[l+1]),min(dist(p[l],p[r]),dist(p[l+1],p[r])));

    int mid=(r+l)>>1;
    d=min(mindist(l,mid),mindist(mid+1,r));

    int k=0;
    for(int i=l;i<=r;i++)
        if(fabs(p[i].x-p[mid].x)<=d)
        {
            tmp[k++]=p[i];
            if(k>5) break;//最多只有6个点
        }
    std::sort(tmp,tmp+k,cpy);
    for(int i=0;i<k;i++)
        for(int j=i+1;j<k&&tmp[j].y-tmp[i].y<d;j++)
        {
            double t=dist(tmp[i],tmp[j]);
            if(t<d) d=t;
        }

    return d;
}

int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==0) break;

        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        std::sort(p,p+n,cpx);
        printf("%.2f\n",mindist(0,n-1)/2);
    }
}