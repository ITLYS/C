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

