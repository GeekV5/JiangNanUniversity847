#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("江南大学847计算机程序设计 历年真题汇总\n");
    printf("********请选择想要查看的年份*******\n");
    printf("         1.2015                \n");
    printf("         1.2016                \n");
    int InputYear;
    scanf("%d",&InputYear);

    switch (InputYear){
        case 2018:JU201801();
//        default:printf("无当前所选题库\n");
    }

    return 0;
}

int JU201801()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < 1000; ++i) {
        float b = rand() * 1.0 /RAND_MAX;
        float p = 2*b;
        printf("%f\n",p);
    }
}