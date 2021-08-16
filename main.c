#include <stdio.h>
/*
 * C语言 学习之路
 * 李永生 2021-8-4
 * 需要深度学习：指针。
 */
const int MAX = 3;
const int LENGTH = 10;

struct Stu{
    char name[20];
    short  age;
    char sex[5];
};

void fun1(void);
void fun2(void);
void fun3(void);
void fun4(void);
void fun5(void);
void fun6(void);
void print1(struct Stu tmp);
void print2(struct Stu *tmp);
void select_sort(int * arr,int size);
void InsertionSort(int *arr, int size);
int main() {
    int arr[]={10,29,1,80,66,77,30,100,5,17};
    int size = sizeof (arr)/sizeof (arr[0]);
    InsertionSort(arr,size);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
/*插入排序
 *时间复杂度O(n^2)  空间复杂度O(1)
 *释义：将第一个元素看做一个顺序表，将后面的数据与顺序表中的数据挨个对比，依次插入表中
 */
void InsertionSort(int *arr, int size)
{
    int i, j, tmp;
    //将第一个元素看做一个顺序表，从第二个开始直至最后一个元素
    for (i = 1; i < size; i++) {
        //如果 当前元素 < 前一个元素
        if (arr[i] < arr[i-1]) {
            // tmp 记录当前元素的值
            tmp = arr[i];
            //逆序遍历i下标之前，从【j , ... , 0】的所有元素。 注：j = i - 1
            //且需要满足 每次遍历到的arr[j]元素 > tmp
            for (j = i - 1; j >= 0 && arr[j] > tmp; j--) {
                //把下标为j的元素赋值到j+1的元素上
                arr[j+1] = arr[j];
            }
            /*For Example:arr[]={1,10,29,80,66,77,30,100,5,17}
             * 当数组遍历到元素66时 arr[i] == 66
             * 66 小于 80 ==> arr[i] < arr[i-1]
             * tmp 赋 66  ==> tmp = arr[i];
             * 逆序遍历i下标之前的所有元素(且必须满足每次遍历到的arr[j]元素 大于 tmp )：
             *       第一次循环条件：满足 j=3 arr[j]=80 80大于66;
             *              元素为60的位置上，赋值80; j--;
             *       第二次循环条件：不满足 因为29 小于 60,
             *               结束循环；
             *此时j=2，arr[j]=29,因为29 小于 60，也就代表60要放在29的后边
             *亦：60要赋值在arr[j+1]上
             *arr[j+1] = tmp;
             */
            arr[j+1] = tmp;
        }
    }
}
/*选择排序(简单选择排序)
 * 时间复杂度O(n^2) 空间复杂度O(1)
 * 释义：遍历一次找到最小与第一个元素呼唤位置，再从第二个元素开始遍历找到最小与第二个元素呼唤
 *
 */
void select_sort(int *arr,int size){
    //i,j 控制内外层循环；k 记录最小值下标；temp 记录最小值；
    int i,j,k,temp;
    // i < size-1 ? 直至最后外层遍历到数组的倒数第二个元素，就能和倒数第一个进行比较，所以无需遍历到最后一个
    for(i=0;i<size-1;i++){
        //默认存储当前遍历的下标
        k=i;
        for(j=i+1;j<size;j++){
            //arr[j]<arr[i]
            if(arr[j]<arr[k]){
                k=j;//k 记录最小值下标
            }
        }
        //元素调换位置
        temp   = arr[k];
        arr[k] = arr[i];
        arr[i] = temp;
    }
}

//函数结构体传参
void print1(struct Stu tmp){
    printf("name is %s\n",tmp.name);
    printf("age is %d\n",tmp.age);
    printf("sex is %s\n",tmp.sex);
}
//函数结构体指针传参    提倡该方法   理由：节省系统空间的开销，提升性能
void print2(struct Stu *tmp){
    printf("name is %s\n",tmp->name);
    printf("age is %d\n",tmp->age);
    printf("sex is %s\n",tmp->sex);
}
/*指针
 *指针类型的意义：
 *          1.决定了指针解引用操作的时候能够访问几个字节
 *          2.决定了指针向前或向后能走多大距离（步长）
 */
void funPointer(){
    int arr[]={10,20,30,40,50,60,70,80,90,100};
    int *p_arr[LENGTH],i;
    for(i=0;i<LENGTH;i++){
        p_arr[i]=&arr[i];
        /*Such As:
         *      &arr[i]       该数组元素的地址
         *      *p_arr[i]     可打印数组元素
         *       p_arr[i] ==  &arr[i]
         */
        printf("数组元素: %d ,所在的位置：%p\n",*p_arr[i],&arr[i]);
    }
}

/*求一定范围内的水仙花数*/
void fun6(){
    int i,x,y,z;
    for(i=100;i<1000;i++){
        x = i % 10;//取个位上的数；
        y = i / 10 % 10;//取十位上的数
        z = i / 100 % 10;//取百位上的数
        if(i == (x*x*x+y*y*y+z*z*z)){
            printf("%d %d %d\n",z,y,x);
            printf("发现一个水仙花数: %d\n",i);
        }
    }
}
/*冒泡排序*/
void bubble_sort(int arr[], int len) {
    int i, j, temp;
    int count=0;
    for (i = 0; i < len - 1; i++){
        printf("=== 第一层循环i=%d,===\n", i);
        for (j = 0; j < len - 1 - i; j++){
            count++;
            printf("计数器：%d\n",count);
            printf("第二层循环j=%d,小于%d\n", j,(len - 1 - i));
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*求一定范围内的素数*/
void fun5(){
    int i,j;//声明循环初始值
    for(i = 2;i < 100;i++){//2-100范围内取素数
        for(j=2;j<i;j++){//从2 - i范围内（除i本身）
            if(i%j==0){//有能整除i的数值，那么i就不是素数
               break;
            }
        }
        /*若从2一直遍历到i本身，都没有发现，那么i就是素数*/
        if(i==j){
            printf("发现一个素数%d\n",i);
        }
    }
}

/*斐波那契数列：兔子生崽*/
void fun4(){
    int i,num;//声明i 循环初始值，num 月数
    printf("请输入月数：");
    scanf("%d",&num);//输入月数，例如30个月
    int month[num];//声明一个数组，长度是 month[30]，随用户输入的数而变化

    month[0]=month[1]=1;//定义数组中第一、二月的兔子数量
    for (i=0; i<num; i++) {
        if (i==0 || i==1) {//如果是第一、二月，兔子数量：1
            printf("第%d个月   数量:1\n",i+1);
        }
        else {//从第三个月开始
           // 当前月兔子数  = （-1）月兔子数 + （-2）月兔子数
            month[i]=month[i-1]+month[i-2];
            printf("第%d个月   数量: %d\n",i+1,month[i]);//打印

        }
    }
}

/*数字顺序排列*/
void fun3(){
    int x,y,z,t;
    printf("请输入三个数字（例如：30,20,62）：");
    scanf("%d,%d,%d",&x,&y,&z);
    if (x>y) { /*交换x,y的值*/
           t=x;x=y;y=t;
       }
       if(x>z) { /*交换x,z的值*/
           t=z;z=x;x=t;
       }
       if(y>z) { /*交换z,y的值*/
           t=y;y=z;z=t;
       }
        printf("从小到大排序: %d %d %d\n",x,y,z);
}

/*利润提成*/
void fun2()
{
    double i;
    double bonus1,bonus2,bonus4,bonus6,bonus10,bonus;
    printf("你的净利润是：\n");
    scanf("%lf",&i);
    bonus1=100000*0.1;//低于10万的  按10%计算
    bonus2=bonus1+100000*0.075;//  10w ~ 20w  按7.5%计算
    bonus4=bonus2+200000*0.05; //  20w ~ 40w  按5%计算
    bonus6=bonus4+200000*0.03; //  40w ~ 60w  按3%计算
    bonus10=bonus6+400000*0.015;// 60w ~ 100W 按1.5%计算
    if(i<=100000) {
        bonus=i*0.1;
        printf("利润提成为：%lf",bonus);
    } else if(i<=200000) {
        bonus=bonus1+(i-100000)*0.075;
        printf("\n低于10万的,按0.1计算;提成金额为：%lf",bonus1);
        printf("\n10w ~ 20w之间,按0.075计算;提成金额为：%lf",(i-100000)*0.075);
        printf("\n总奖金为：%lf",bonus);
    } else if(i<=400000) {
        bonus=bonus2+(i-200000)*0.05;
        printf("\n低于10万的,按0.1计算;提成金额为：%lf",bonus1);
        printf("\n10w ~ 20w之间,按0.075计算;提成金额为：%lf",bonus2);
        printf("\n20w ~ 40w之间,按0.05计算;提成金额为：%lf",(i-200000)*0.05);
        printf("\n总奖金为：%lf",bonus);
    } else if(i<=600000) {
        bonus=bonus4+(i-400000)*0.03;
        printf("\n低于10万的,按0.1计算;提成金额为：%lf",bonus1);
        printf("\n10w ~ 20w之间,按0.075计算;提成金额为：%lf",bonus2);
        printf("\n20w ~ 40w之间,按0.05计算;提成金额为：%lf",bonus4);
        printf("\n40w ~ 60w之间,按0.03计算;提成金额为：%lf",(i-400000)*0.03);
        printf("\n总奖金为：%lf",bonus);
    } else if(i<=1000000) {
        bonus=bonus6+(i-600000)*0.015;
        printf("\n低于10万的,按0.1计算;提成金额为：%lf",bonus1);
        printf("\n10w ~ 20w之间,按0.075计算;提成金额为：%lf",bonus2);
        printf("\n20w ~ 40w之间,按0.05计算;提成金额为：%lf",bonus4);
        printf("\n40w ~ 60w之间,按0.03计算;提成金额为：%lf",bonus6);
        printf("\n60w ~ 100w之间,按0.015计算;提成金额为：%lf",(i-600000)*0.015);
        printf("\n总奖金为：%lf",bonus);
    } else{
        bonus=bonus10+(i-1000000)*0.01;
        printf("\n低于10万的,按0.1计算;提成金额为：%lf",bonus1);
        printf("\n10w ~ 20w之间,按0.075计算;提成金额为：%lf",bonus2);
        printf("\n20w ~ 40w之间,按0.05计算;提成金额为：%lf",bonus4);
        printf("\n40w ~ 60w之间,按0.03计算;提成金额为：%lf",bonus6);
        printf("\n60w ~ 100w之间,按0.015计算;提成金额为：%lf",bonus10);
        printf("\n高于100万的,按0.01计算;提成金额为：%lf",(i-1000000)*0.01);
        printf("\n总奖金为：%lf",bonus);
    }


    printf("\n");
}

/*九九乘法表*/
void fun1(){
    int i,j;//定义循环初始值
    for(i=1;i<10;i++){
        for(j=1;j<=i;j++){
            if(i * j >9){ //该if 主要目的是为了表达式每列对齐
                printf("%d x %d = %d  ",i,j,i*j);//打印表达式
            }else{
                printf("%d x %d = %d   ",i,j,i*j);//打印表达式
            }

        }
        printf("\n\n");
    }

}
