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
/*C ��ϰʵ��21�����Լ�� �� ��С������*/
void fun21(int a,int b){
    int i,k,r;
    for(i=1;i<=a||i<=b;i++){
        if((a%i==0)&&(b%i==0)){
            k=i;
        }
    }
    r = a*b/k;
    printf("a b���Լ��:%d,��С��������%d",k,r);
}
/*C ��ϰʵ��22�����Լ�� �� ��С������*/
void fun22(int (*p)[4],int x,int y){
    int i,j;
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("%4d",*(p[i]+j));
        }
        printf("\n");
    }
}
/*C ��ϰʵ��22��5�˷���*/
void fun23(void){
    int one,two,three,four,five,sum;
    for(sum=0;;sum++){
        one   =  sum;
        two   =  4 * (one - 1) / 5;
        three =  4 * (two - 1) / 5;
        four  =  4 * (three- 1)/ 5;
        five  =  4 * (four - 1)/ 5;
        if( one%5==1 && two%5==1 && three%5==1 && four%5==1 && five%5==1){
            printf("�����һ������%d��\n",sum);
            printf("��һ����������������%d��\n",one);
            printf("�ڶ�����������������%d��\n",two);
            printf("��������������������%d��\n",three);
            printf("���ĸ���������������%d��\n",four);
            printf("�ڸ���������������%d��\n",five);
            break;
        }
    }
}
/*C ��ϰʵ��24������ָ��ð������*/
void fun24(void){
    //��ʼ������
    int arr[10]={31,1,89,50,22,9,60,20,11,100};
    //��������
    int i,j,temp,count=0;
    //���ѭ��
    for(i=0;i< 10;i++){
        //�ڲ�ѭ��
        for(j=0;j< 10-i;j++){
            int *p = &arr[j];//ʹ��ָ��ָ�� -> ����Ԫ�صĵ�ַ
            if( *p > *(p+1) ){//��ǰ��ַ �� ��һ����ַ ���бȽ�
               temp= *(p);  //����λ��
               *(p) = *(p+1);
               *(p+1) = temp;
               count++;
            }

        }

    }
    printf("ѭ��%d��\n",count);
    for(i=0;i< 10;i++){
        printf("%d\t",arr[i]);
    }
}
/*C ��ϰʵ��24������ָ�������*/
void fun25(void){
    //��ʼ������
    int arr[10]={31,1,89,50,22,9,60,20,11,100};
    //��������i,j����ѭ�� temp ��ʱ�洢Ԫ��  k ����Сֵ�±�
    int i,j,temp,s;

    for(i=0;i<10-1;i++){
        int *p = &arr[i];
        int *pmin = p;
        printf("i��ֵ%d ",*pmin);
        for(j=i+1;j<10;j++){
            printf("j��ֵ%d ",*(p+j));
            if(*pmin>arr[j]){
                pmin = &arr[j];
            }
        }
          printf("%p %d\n",pmin,*pmin);
        temp=*pmin;
        *pmin=*p;
        *p=temp;
        printf("\n");
        printf("��һ������:");
        for(s=0;s< 10;s++){
            printf("%d\t",arr[s]);
        }
        printf("\n");
        printf("\n");
    }
}
/*
 C ��ϰʵ��25������ժ��
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
 * ��֪���У�2/1��3/2,5/3,8/5 ...
 C ��ϰʵ��26��������ǰ20��֮��
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
c����ʵ��27����һ��3x3����ĶԽ���֮��
*/
void fun27(void){
    int arr[3][3];
    int i,j,sum=0;
    printf("���������֣�\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%3d",&arr[i][j]);
        }
    }
    for(i=0;i<3;i++){
        sum+=arr[i][i];
    }
    printf("\n�Խ���֮��Ϊ%d",sum);
}

/*
C����ʵ��28����2~1000֮�ڵ�����
*/
void fun28(void){
    int i,j,sum;//��������
    for(i=2;i<=1000;i++){//����1000���ڵ���
        sum=0;//��ʼֵ
        for(j=1;j<i;j++){//��1~��ֵi
            if(i%j==0){//ֻҪȡģ����0 ��j����i������
                sum+=j;//�ۼ�����֮��
            }
        }

        if(sum==i){//ֻҪ���Ӽ����������������Ǿ�������
            printf("%d\t",i);
        }
    }
}
/*
C����ʵ����ѭ���������֣��ж���ż����
*/
void fun29(void){
    int a=0,b=0,num,i;
    printf("���������֣�");
    for(i=0;i<5;i++){
        scanf("%d",&num);
        if(num%2==0)
            a++;
        else
            b++;
    }
    printf("\n����%d����ż��%d��",b,a);
}
/*
C����ʵ��30��ð������
*/
void fun30(void){
    int arr[]={4,3,1,9,5,8,6,7,2};
    int i,j,temp;
    for(i=0;i<9;i++){
       //j<9-i-1��Ŀ�ľ��Ǽ��ٶԱ�
       //ÿ��iѭ��һ�Σ�������������ŵ����
       //���Ժ�ߵ����ֶ�����Ҫ�ٴν��жԱ���
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













