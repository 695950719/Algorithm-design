include<stdio.h>
char* lcs(char *str1, char *str2,int* p_length)
{
    int i,j,m,n,length,x,y;

    m = strlen(str1)+1;
    n = strlen(str2)+1;
    int **matrix = new int*[m];
    for(i = 0; i < m; i++)
        matrix[i] = new int[n];
    for(i = 0; i < m; i++)
        matrix[i][0]=0;//第0列都初始化为0
    for(j = 0; j < n; j++)
        matrix[0][j]=0;//第0行都初始化为0 

    length = -1;
    *p_length = -1;

    for(i = 1 ; i < m ; i++)
    {
        for(j = 1; j < n; j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                //只需要跟左上方的matrix[i-1][j-1]比较就可以了
                matrix[i][j]=matrix[i-1][j-1]+1;
            }
            else{ 
                //不连续的时候还要跟左边的matrix[i][j-1]、上边的matrix[i-1][j]值比较，这里不需要    
                matrix[i][j]=0;
            }
            if(matrix[i][j]>length)
            {
                length=matrix[i][j];
                x=i;
                y=j;
            }
        }
    }

    for(i = 0; i < m; i++)
        delete[] matrix[i];
    delete[] matrix;

    if (length>0)
    {
        *p_length = length;
        return &str1[x-length];
    }
    return NULL;
}
int main(void)
{
    char str1[1000],str2[1000],str3[1000];
    int length;

    printf("请输入第一个字符串：");
    gets(str1);
    printf("请输入第二个字符串：");
    gets(str2);
    char* pszText = lcs(str1, str2,&length);
    printf("最长公共连续子串的长度为：%d\n",length);
    if (pszText!=NULL)
    {
        strncpy(str3,pszText,length);
        str3[length] = 0;
        printf("最长公共连续子串：%s\n",str3);
    }
    system("pause");
    return 0;
}