#include <stdio.h>
/*C ��ϰʵ��2:��ҵ���ŵĽ������������ɡ�*/
void fun2(void)
{
    double i;
    double bons1,bons2,bons4,bons6,bons10,bons;
    printf("����������:\n");
    scanf("%lf",&i);
    bons1 = 100000*0.1;//ʮ�򲿷ֵ����
    bons2 = bons1+(100000*0.075);//��ʮ�򲿷ֵ����
    bons4 = bons2+(200000*0.05);//��ʮ�򲿷ֵ����
    bons6 = bons4+(200000*0.03);//��ʮ�򲿷ֵ����
    bons10 = bons1+(400000*0.015);//һ���򲿷ֵ����
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
     printf("���Ϊ��bonus=%lf",bons);
}
/*C ��ϰʵ��4:����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿*/
void fun4(void){
    int year,month,day,sum,leap;
    printf("�����밴�ո�ʽ��2021,5,12�����������գ�");
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
    printf("\n���ڽ���ĵ�%d��",sum);
    LOOP:sum == 365 ? printf("\n������Ϸ��·�\n"): 0 ;
}
/*C ��ϰʵ��5:����3�����ֱȽϴ�С*/
void fun5(void){
    int x,y,z,t;
    printf("������3�����֣��ö��Ÿ�����");
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

    printf("\n�ɴ�С��˳��%d > %d > %d",z,y,x);
}
/*C ��ϰʵ��8:�žų˷��ھ���*/
void fun8(void){
    int i,j;
    for(i=1;i<=9;i++){
        for(j=1;j<=i;j++){
            printf("%d*%d=%-3d",j,i,i*j);
        }
        printf("\n");
    }
}
/*C ��ϰʵ��11:��������*/
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
/*C ��ϰʵ��12:��101 ~ 200 ֮�������*/
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
/*C ��ϰʵ��13:ˮ�ɻ���*/
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
/*C ��ϰʵ��18:��s=a+aa+aaa+aaaa+aa...a��ֵ������a��һ������*/
void fun18(void){
    int s=0,a,n,t;
       printf("������ a �� n��\n");
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
/*C ��ϰ���ṹ�� ����ѧ���ɼ��ɸߵ�������*/
void fun19(void){
    //ѧ����Ϣ�ṹ
    struct student{
        int num;//ѧ��
        char name[20];//����
        float score;//�ɼ�
    };
    //�ṹ�帳ֵ
    struct student stu[8] = {
            {1101,"����",99.1},
            {1102,"����",88.0},
            {1103,"����",90.5},
            {1104,"����",100.0},
            {1105,"����",21.0},
            {1106,"��",190.5},
            {1107,"��",120.0},
            {1108,"��",210.0}
    };
    //����һ���ṹ�壬������ʱ�����Ϣ
    struct student t;
    int i,j,k;//�������ͱ���
    for(i=0;i<7;i++){
        k=i;//k �����洢���ֵ�±�  ��һ��Ĭ����Ԫ��Ϊ��Сֵ
        for(j=i+1;j<8;j++){
            if(stu[k].score < stu[j].score){//�Ƚϴ�С
                k = j;//��  �±�Ϊj��ֵ  ����  �±�k��ֵ ��k = j
            }
        }
        //�滻����
        t = stu[i];
        stu[i] = stu[k];
        stu[k] = t;
    }
    for(i=0;i<8;i++){
        printf("%d\t%s\t%6.2f\n",stu[i].num,stu[i].name,stu[i].score);
    }
}
/*C ��ϰʵ��20��С����������*/
void fun20(void){
    int i;
    double s,h;
    s = 100;//���ʱ�����ľ���
    h = 100.0/2;//��һ�η����ĸ߶�
    printf("��1�����ʱ��������%f�ף�������%f��\n",s,h);
    for(i=2;i<=10;i++){

        s=s+h*2;
        h=h/2;
        printf("��%d�����ʱ��������%f�ף�������%f��\n",i,s,h);
    }


}
