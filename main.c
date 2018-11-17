#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    printf("--江南大学847计算机程序设计历年真题汇总---\n");
    printf("********请选择想要查看的年份+题号*******\n");
    printf("（提示：例如：201801就是选择2018年第一道题）\n");
    int InputYearOrSerilNo;
    scanf("%d",&InputYearOrSerilNo);

    switch (InputYearOrSerilNo){
        case 201801:JU201801();
        case 201802:JU201802();
        case 201803:JU201803();
        case 201804:JU201804();
//        default:printf("无当前所选题库\n");
    }

    return 0;
}

//JU201801 Start
int JU201801()
{
    printf("[201801]：rand为[0,1]均匀随机产生的函数，写出一个程序模拟输出1000个[0,1]区间上函数为p(x)=2x的随机数\n");
    srand((unsigned)time(NULL));
    for (int i = 0; i < 1000; ++i) {
        float b = rand() * 1.0 /RAND_MAX;
        float p = 2*b;
        printf("%f\n",p);
    }
}
//JU201801 End

//JU201802 Start
double pow(double x,int n);

int JU201802()
{
    double x;
    int n;
    scanf("%lf%d",&x,&n);
    printf("%0.f\n",pow(x,n));
    return 0;

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
//JU201802 End

//JU201803 Start
//准备两个栈，data栈和min栈，min栈用来获取最小值
typedef struct {
    int data[20000];
    int min[20000];
    int top;
    int mintop;//min栈顶指针
}MinStack;

//初始化工作
void minStackCreate(MinStack *stack)
{
    stack->top = -1;
    stack->mintop = -1;
    memset(stack->data,0,20000);
    memset(stack->min,0,20000);
}

//压栈逻辑：data栈直接压入，min栈则将待压入元素与min栈栈顶相比较，如element较小则压入。否则继续压入min栈栈顶元素
void Push(MinStack *stack,int element)
{
    if(stack->top < 19999){// 栈未溢出时才进行Push栈操作
        stack->top++;
        stack->data[stack->top] = element;
        if(stack->mintop == -1 || element <= stack->min[stack->mintop]){//第一个元素进行比较时或者element较小则压入
            stack->mintop++;
            stack->min[stack->mintop] = element;
        }
//        else if(){
//            int data = stack->min[stack->mintop];
//            stack->mintop++;
//            stack->min[stack->mintop] = element;
//        }
        else if(stack->mintop > -1 && element > stack->min[stack->mintop]){
            //element较大时不压入，将最小栈中的栈顶元素即最小值压入栈
            int data = stack->min[stack->mintop];
            stack->mintop++;
            stack->min[stack->mintop] = data;
        }
    }
    else{
        printf("栈已满，无法继续进行进栈操作！\n");
        return;
    }
}

void Pop(MinStack *stack)
{
    if(stack->top == -1)
    {
        return;
    }
    stack->top--;
    stack->mintop--;
}

//返回data栈栈顶
int minStackTop(MinStack *stack)
{
    return stack->data[stack->top];
}

//返回min栈栈顶
int Min(MinStack *stack)
{
    return stack->min[stack->mintop];
}

int JU201803()
{
    //新建栈
    MinStack stack;
    minStackCreate(&stack);
    //入栈
    Push(&stack,9);
    printf("当前入栈值：%d，当前栈中最小值为：%d\n",9,Min(&stack));
    Push(&stack,12);
    printf("当前入栈值：%d，当前栈中最小值为：%d\n",12,Min(&stack));
    Push(&stack,3);
    printf("当前入栈值：%d，当前栈中最小值为：%d\n",3,Min(&stack));
    Push(&stack,100);
    printf("当前入栈值：%d，当前栈中最小值为：%d\n",12,Min(&stack));
    Push(&stack,1);
    printf("当前入栈值：%d，当前栈中最小值为：%d\n",12,Min(&stack));
    Push(&stack,6);
    printf("当前入栈值：%d，当前栈中最小值为：%d\n",12,Min(&stack));
    Push(&stack,18);
    printf("当前入栈值：%d，当前栈中最小值为：%d\n",12,Min(&stack));

    //出栈
    Pop(&stack);
    printf("出栈一次，当前栈中最小值为：%d\n",Min(&stack));
    Pop(&stack);
    int min = Min(&stack);
    printf("出栈第二次，最终栈中最小值为：%d\n",min);
    return 0;
}

//JU201803 End

//JU201804 Start
double Average(int start)
{
    double result = 0.0;
    int count = 0;
    for (int i = 0; i < start + 10; ++i) {
        if(i >= 9){
            ++count;
            result += i;
        }
    }
    result = result/count;
    return result;
}
int JU201804()
{
    int tmp = 6;//6 7 8 9 10 11 12 13 14 15
    double result = Average(tmp);
    printf("大于9的部分累计求平均数结果为：%.f",result);
    return 0;
}

//JU201804 End
