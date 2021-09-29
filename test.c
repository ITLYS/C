#include <stdio.h>
/*C 练习实例2:企业发放的奖金根据利润提成。*/
void fun2(void)
{
    double i;
    double bons1,bons2,bons4,bons6,bons10,bons;
    printf("请输入利润:\n");
    scanf("%lf",&i);
    bons1 = 100000*0.1;//十万部分的提成
    bons2 = bons1+(100000*0.075);//二十万部分的提成
    bons4 = bons2+(200000*0.05);//四十万部分的提成
    bons6 = bons4+(200000*0.03);//六十万部分的提成
    bons10 = bons1+(400000*0.015);//一百万部分的提成
    if(i<=100000){
     bons=i*0.1;
    }else if (i<=200000) {
     bons=bons1+(i-100000)*0.075;
    }else if(i<=400000){
     bons=bons2+(i-200000)*0.05;
    }else if(i<=600000){
     bons=bons4+(i-400000)*0.03;
    }else if(i<=1000000){
     bons=bons6+(i-600000)*0.015;
    }else{
     bons=bons10+(i-1000000)*0.01;
    }
     printf("提成为：bonus=%lf",bons);
}
/*C 练习实例4:输入某年某月某日，判断这一天是这一年的第几天？*/
void fun4(void){
    int year,month,day,sum,leap;
    printf("请输入按照格式【2021,5,12】输入年月日：");
    scanf("%d,%d,%d",&year,&month,&day);
    switch (month) {
      case 1:  sum = 0;     break;
      case 2:  sum = 31;    break;
      case 3:  sum = 59;    break;
      case 4:  sum = 90;    break;
      case 5:  sum = 120;   break;
      case 6:  sum = 151;   break;
      case 7:  sum = 181;   break;
      case 8:  sum = 212;   break;
      case 9:  sum = 243;   break;
      case 10: sum = 273;   break;
      case 11: sum = 304;   break;
      case 12: sum = 334;   break;
      default: sum = 365;   break;
    }
    if(sum == 365){
        goto LOOP;
    }
    sum += day;
    if( year % 400 == 0 || ( year % 4 == 0 && year % 100 == 0 ) ){
        leap = 1;
    }else{
        leap = 0;
    }
    if( leap == 1 && month > 2 ){
        sum++;
    }
    printf("\n出于今年的第%d天",sum);
    LOOP:sum == 365 ? printf("\n请输入合法月份\n"): 0 ;
}
/*C 练习实例5:输入3个数字比较大小*/
void fun5(void){
    int x,y,z,t;
    printf("请输入3个数字，用逗号隔开：");
    scanf("%d,%d,%d",&x,&y,&z);
    if(x>y){
        t=x;x=y;y=t;
    }
    if(x>z){
        t=x;x=z;z=t;
    }
    if(y>z){
        t=z;z=y;y=t;
    }

    printf("\n由大到小的顺序：%d > %d > %d",z,y,x);
}
/*C 练习实例8:九九乘法口诀表*/
void fun8(void){
    int i,j;
    for(i=1;i<=9;i++){
        for(j=1;j<=i;j++){
            printf("%d*%d=%-3d",j,i,i*j);
        }
        printf("\n");
    }
}
/*C 练习实例11:兔子生崽*/
void fun11(void){
    int arr[40]={0};
    int i;
    for(i=0;i<40;i++){
       if(i>1){
           arr[i]=arr[i-1]+arr[i-2];
           printf("%d\t",arr[i]);
       }else{
           arr[i]=1;
           printf("%d\t",arr[i]);
       }
    }

}
/*C 练习实例12:求101 ~ 200 之间的素数*/
void fun12(void){
    int i,j;
    for(i=101;i<200;i++){
        for(j=2;j<i;j++){
            if(i%j==0){
                break;
            }
        }
        if(j==i){
            printf("%d\t",i);
        }
    }
}
/*C 练习实例13:水仙花数*/
void fun13(void){
    int g,s,b,i;
    for(i=100;i<=999;i++){
        g=i%10;
        s=i/10%10;
        b=i/100%10;
        if(g*g*g+s*s*s+b*b*b==i){
            printf("%d\t",i);
        }
    }
}
/*C 练习实例18:求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字*/
void fun18(void){
    int s=0,a,n,t;
       printf("请输入 a 和 n：\n");
       scanf("%d%d",&a,&n);
       t=a;
       while(n>0)
       {
           s+=t;
           printf("s = %d",s);
           a=a*10;
           t+=a;
           printf("t = %d\n",t);
           n--;
       }
       printf("a+aa+...=%d\n",s);
}
/*C 练习：结构体 按照学生成绩由高到低排序*/
void fun19(void){
    //学生信息结构
    struct student{
        int num;//学号
        char name[20];//名称
        float score;//成绩
    };
    //结构体赋值
    struct student stu[8] = {
            {1101,"张三",99.1},
            {1102,"李四",88.0},
            {1103,"王二",90.5},
            {1104,"赵六",100.0},
            {1105,"秦五",21.0},
            {1106,"将",190.5},
            {1107,"候",120.0},
            {1108,"孙",210.0}
    };
    //声明一个结构体，用来临时存放信息
    struct student t;
    int i,j,k;//声明整型变量
    for(i=0;i<7;i++){
        k=i;//k 用来存储最大值下标  第一次默认首元素为最小值
        for(j=i+1;j<8;j++){
            if(stu[k].score < stu[j].score){//比较大小
                k = j;//若  下标为j的值  大于  下标k的值 ，k = j
            }
        }
        //替换数据
        t = stu[i];
        stu[i] = stu[k];
        stu[k] = t;
    }
    for(i=0;i<8;i++){
        printf("%d\t%s\t%6.2f\n",stu[i].num,stu[i].name,stu[i].score);
    }
}
/*C 练习实例20：小球自由落体*/
void fun20(void){
    int i;
    double s,h;
    s = 100;//落地时经过的距离
    h = 100.0/2;//第一次反弹的高度
    printf("第1次落地时，共经过%f米，反弹高%f米\n",s,h);
    for(i=2;i<=10;i++){

        s=s+h*2;
        h=h/2;
        printf("第%d次落地时，共经过%f米，反弹高%f米\n",i,s,h);
    }


}
/*C 练习实例21：最大公约数 和 最小公倍数*/
void fun21(int a,int b){
    int i,k,r;
    for(i=1;i<=a||i<=b;i++){
        if((a%i==0)&&(b%i==0)){
            k=i;
        }
    }
    r = a*b/k;
    printf("a b最大公约数:%d,最小公倍数：%d",k,r);
}
/*C 练习实例22：最大公约数 和 最小公倍数*/
void fun22(int (*p)[4],int x,int y){
    int i,j;
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("%4d",*(p[i]+j));
        }
        printf("\n");
    }
}
/*C 练习实例22：5人分鱼*/
void fun23(void){
    int one,two,three,four,five,sum;
    for(sum=0;;sum++){
        one   =  sum;
        two   =  4 * (one - 1) / 5;
        three =  4 * (two - 1) / 5;
        four  =  4 * (three- 1)/ 5;
        five  =  4 * (four - 1)/ 5;
        if( one%5==1 && two%5==1 && three%5==1 && four%5==1 && five%5==1){
            printf("五个人一共捕鱼%d条\n",sum);
            printf("第一个人醒来看到的是%d条\n",one);
            printf("第二个人醒来看到的是%d条\n",two);
            printf("第三个人醒来看到的是%d条\n",three);
            printf("第四个人醒来看到的是%d条\n",four);
            printf("第个人醒来看到的是%d条\n",five);
            break;
        }
    }
}
/*C 练习实例24：利用指针冒泡排序*/
void fun24(void){
    //初始化数组
    int arr[10]={31,1,89,50,22,9,60,20,11,100};
    //声明变量
    int i,j,temp,count=0;
    //外层循环
    for(i=0;i< 10;i++){
        //内层循环
        for(j=0;j< 10-i;j++){
            int *p = &arr[j];//使用指针指向 -> 遍历元素的地址
            if( *p > *(p+1) ){//当前地址 与 下一个地址 进行比较
               temp= *(p);  //调换位置
               *(p) = *(p+1);
               *(p+1) = temp;
               count++;
            }

        }

    }
    printf("循环%d次\n",count);
    for(i=0;i< 10;i++){
        printf("%d\t",arr[i]);
    }
}
/*C 练习实例24：利用指针快排序*/
void fun25(void){
    //初始化数组
    int arr[10]={31,1,89,50,22,9,60,20,11,100};
    //声明变量i,j控制循环 temp 临时存储元素  k 存最小值下标
    int i,j,temp,s;

    for(i=0;i<10-1;i++){
        int *p = &arr[i];
        int *pmin = p;
        printf("i的值%d ",*pmin);
        for(j=i+1;j<10;j++){
            printf("j的值%d ",*(p+j));
            if(*pmin>arr[j]){
                pmin = &arr[j];
            }
        }
          printf("%p %d\n",pmin,*pmin);
        temp=*pmin;
        *pmin=*p;
        *p=temp;
        printf("\n");
        printf("第一次排序:");
        for(s=0;s< 10;s++){
            printf("%d\t",arr[s]);
        }
        printf("\n");
        printf("\n");
    }
}
/*
 C 练习实例25：猴子摘桃
*/
void func25(void ){
    int day = 9;
    int num=1;
    while (day>0) {
        num=(num+1)*2;
        day--;
    }
    printf("%d",num);
}

/*
 * 已知数列：2/1，3/2,5/3,8/5 ...
 C 练习实例26：求数列前20项之和
*/
void fun26(void ){
    int count=20;//    double sum=0,fz=1,fm=2,temp;
    while(count>0){
        printf("%d\t",count);
        sum+=fm/fz;
        printf("%f/%f\n",fm,fz);
       temp = fz;
       fz = fm;
        fm=fm+temp; 
        count--;

    }
    printf("%lf",sum);
}

/*
c语言实例27：求一个3x3矩阵的对角线之和
*/
void fun27(void){
    int arr[3][3];
    int i,j,sum=0;
    printf("请输入数字：\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%3d",&arr[i][j]);
        }
    }
    for(i=0;i<3;i++){
        sum+=arr[i][i];
    }
    printf("\n对角线之和为%d",sum);
}

/*
C语言实例28：求2~1000之内的完数
*/
void fun28(void){
    int i,j,sum;//声明变量
    for(i=2;i<=1000;i++){//遍历1000以内的数
        sum=0;//初始值
        for(j=1;j<i;j++){//从1~数值i
            if(i%j==0){//只要取模等于0 那j就是i的因子
                sum+=j;//累计因子之和
            }
        }

        if(sum==i){//只要因子加起来等于它本身，那就是完数
            printf("%d\t",i);
        }
    }
}
/*
C语言实例：循环输入数字，判断奇偶个数
*/
void fun29(void){
    int a=0,b=0,num,i;
    printf("请输入数字：");
    for(i=0;i<5;i++){
        scanf("%d",&num);
        if(num%2==0)
            a++;
        else
            b++;
    }
    printf("\n奇数%d个，偶数%d个",b,a);
}
/*
C语言实例30：冒泡排序
*/
void fun30(void){
    int arr[]={4,3,1,9,5,8,6,7,2};
    int i,j,temp;
    for(i=0;i<9;i++){
       //j<9-i-1的目的就是减少对比
       //每次i循环一次，都会把最大的数放到后边
       //所以后边的数字都不需要再次进行对比了
       for(j=0;j<9-1-i;j++){
           if(arr[j]>arr[j+1]){
               temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
           }
       }
    }
    for(i=0;i<9;i++){
        printf("%d\t",arr[i]);
    }
}













