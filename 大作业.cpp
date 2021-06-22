#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a[30],s[30];
int n,k=2,minn=0x7ffff;//n代表任务数量，k代表机器数量
void search(int,int);
int main() {
    cout<<"请输入您的任务总数n"<<endl;
    cin>>n;
    cout<<"请输入您每项任务的时间"<<endl;
    for(int i=1; i<=n; i++) //输入每个人物需要花费的时间
        scanf("%d",&a[i]);
    search(1,0);//加入第一个时间，现在花费的时间是0；
    cout<<minn;
    return 0;
}
void search(int x,int y) {//x表示第x个任务，y表示当前的时间
    if(y>=minn)return;//剪枝 已经比最小的大了就不用再放了，舍弃这种方法
    if(x>n) { //放完了进行判断
        if(y<minn)minn=y;
        return;
    }
    for(int i=1; i<=k; i++) {
        if(s[i]+a[x]<=minn) { //剪枝
            s[i]+=a[x];
            search(x+1,max(y,s[i]));
            s[i]-=a[x];//回溯
        }
    }
    return;
}