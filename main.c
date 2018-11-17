#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("江南大学847计算机程序设计 历年真题汇总\n");
    printf("********请选择想要查看的年份*******\n");
    printf("         1.2015                \n");
    printf("         2.2016                \n");
    printf("         3.2017                \n");
    printf("         4.2018                \n");
    printf("（提示：输入序号或者年份进行选择）");
    int InputYearOrSerilNo;
    scanf("%d",&InputYearOrSerilNo);

    switch (InputYearOrSerilNo){
        case 2018:JU201801();
//        default:printf("无当前所选题库\n");
    }

    return 0;
}

int JU201801()
{
    //srand((unsigned)time(NULL));
    for (int i = 0; i < 1000; ++i) {
        float b = rand() * 1.0 /RAND_MAX;
        float p = 2*b;
        printf("%f\n",p);
    }
}

int JU201802()
{
    double x;
    int n;

}

double pow(double x,int n)
{
    if(n < 0)
    {
        return pow(1/x,-n);
    }
    if(n == 0)
    {
        return 1;
    }
    if(n ==2 )
    {
        return x*x;
    }
    if(n%2 == 0)
    {
        return pow(pow(x,n/2),2);
    }
    else
    {
        return x*pow(x,n-1);
    }
}