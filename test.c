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
