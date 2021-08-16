#include <stdio.h>
/*
 * C���� ѧϰ֮·
 * ������ 2021-8-4
 * ��Ҫ���ѧϰ��ָ�롣
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
/*��������
 *ʱ�临�Ӷ�O(n^2)  �ռ临�Ӷ�O(1)
 *���壺����һ��Ԫ�ؿ���һ��˳����������������˳����е����ݰ����Աȣ����β������
 */
void InsertionSort(int *arr, int size)
{
    int i, j, tmp;
    //����һ��Ԫ�ؿ���һ��˳����ӵڶ�����ʼֱ�����һ��Ԫ��
    for (i = 1; i < size; i++) {
        //��� ��ǰԪ�� < ǰһ��Ԫ��
        if (arr[i] < arr[i-1]) {
            // tmp ��¼��ǰԪ�ص�ֵ
            tmp = arr[i];
            //�������i�±�֮ǰ���ӡ�j , ... , 0��������Ԫ�ء� ע��j = i - 1
            //����Ҫ���� ÿ�α�������arr[j]Ԫ�� > tmp
            for (j = i - 1; j >= 0 && arr[j] > tmp; j--) {
                //���±�Ϊj��Ԫ�ظ�ֵ��j+1��Ԫ����
                arr[j+1] = arr[j];
            }
            /*For Example:arr[]={1,10,29,80,66,77,30,100,5,17}
             * �����������Ԫ��66ʱ arr[i] == 66
             * 66 С�� 80 ==> arr[i] < arr[i-1]
             * tmp �� 66  ==> tmp = arr[i];
             * �������i�±�֮ǰ������Ԫ��(�ұ�������ÿ�α�������arr[j]Ԫ�� ���� tmp )��
             *       ��һ��ѭ������������ j=3 arr[j]=80 80����66;
             *              Ԫ��Ϊ60��λ���ϣ���ֵ80; j--;
             *       �ڶ���ѭ�������������� ��Ϊ29 С�� 60,
             *               ����ѭ����
             *��ʱj=2��arr[j]=29,��Ϊ29 С�� 60��Ҳ�ʹ���60Ҫ����29�ĺ��
             *�ࣺ60Ҫ��ֵ��arr[j+1]��
             *arr[j+1] = tmp;
             */
            arr[j+1] = tmp;
        }
    }
}
/*ѡ������(��ѡ������)
 * ʱ�临�Ӷ�O(n^2) �ռ临�Ӷ�O(1)
 * ���壺����һ���ҵ���С���һ��Ԫ�غ���λ�ã��ٴӵڶ���Ԫ�ؿ�ʼ�����ҵ���С��ڶ���Ԫ�غ���
 *
 */
void select_sort(int *arr,int size){
    //i,j ���������ѭ����k ��¼��Сֵ�±ꣻtemp ��¼��Сֵ��
    int i,j,k,temp;
    // i < size-1 ? ֱ�����������������ĵ����ڶ���Ԫ�أ����ܺ͵�����һ�����бȽϣ�����������������һ��
    for(i=0;i<size-1;i++){
        //Ĭ�ϴ洢��ǰ�������±�
        k=i;
        for(j=i+1;j<size;j++){
            //arr[j]<arr[i]
            if(arr[j]<arr[k]){
                k=j;//k ��¼��Сֵ�±�
            }
        }
        //Ԫ�ص���λ��
        temp   = arr[k];
        arr[k] = arr[i];
        arr[i] = temp;
    }
}

//�����ṹ�崫��
void print1(struct Stu tmp){
    printf("name is %s\n",tmp.name);
    printf("age is %d\n",tmp.age);
    printf("sex is %s\n",tmp.sex);
}
//�����ṹ��ָ�봫��    �ᳫ�÷���   ���ɣ���ʡϵͳ�ռ�Ŀ�������������
void print2(struct Stu *tmp){
    printf("name is %s\n",tmp->name);
    printf("age is %d\n",tmp->age);
    printf("sex is %s\n",tmp->sex);
}
/*ָ��
 *ָ�����͵����壺
 *          1.������ָ������ò�����ʱ���ܹ����ʼ����ֽ�
 *          2.������ָ����ǰ��������߶����루������
 */
void funPointer(){
    int arr[]={10,20,30,40,50,60,70,80,90,100};
    int *p_arr[LENGTH],i;
    for(i=0;i<LENGTH;i++){
        p_arr[i]=&arr[i];
        /*Such As:
         *      &arr[i]       ������Ԫ�صĵ�ַ
         *      *p_arr[i]     �ɴ�ӡ����Ԫ��
         *       p_arr[i] ==  &arr[i]
         */
        printf("����Ԫ��: %d ,���ڵ�λ�ã�%p\n",*p_arr[i],&arr[i]);
    }
}

/*��һ����Χ�ڵ�ˮ�ɻ���*/
void fun6(){
    int i,x,y,z;
    for(i=100;i<1000;i++){
        x = i % 10;//ȡ��λ�ϵ�����
        y = i / 10 % 10;//ȡʮλ�ϵ���
        z = i / 100 % 10;//ȡ��λ�ϵ���
        if(i == (x*x*x+y*y*y+z*z*z)){
            printf("%d %d %d\n",z,y,x);
            printf("����һ��ˮ�ɻ���: %d\n",i);
        }
    }
}
/*ð������*/
void bubble_sort(int arr[], int len) {
    int i, j, temp;
    int count=0;
    for (i = 0; i < len - 1; i++){
        printf("=== ��һ��ѭ��i=%d,===\n", i);
        for (j = 0; j < len - 1 - i; j++){
            count++;
            printf("��������%d\n",count);
            printf("�ڶ���ѭ��j=%d,С��%d\n", j,(len - 1 - i));
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*��һ����Χ�ڵ�����*/
void fun5(){
    int i,j;//����ѭ����ʼֵ
    for(i = 2;i < 100;i++){//2-100��Χ��ȡ����
        for(j=2;j<i;j++){//��2 - i��Χ�ڣ���i����
            if(i%j==0){//��������i����ֵ����ôi�Ͳ�������
               break;
            }
        }
        /*����2һֱ������i������û�з��֣���ôi��������*/
        if(i==j){
            printf("����һ������%d\n",i);
        }
    }
}

/*쳲��������У���������*/
void fun4(){
    int i,num;//����i ѭ����ʼֵ��num ����
    printf("������������");
    scanf("%d",&num);//��������������30����
    int month[num];//����һ�����飬������ month[30]�����û�����������仯

    month[0]=month[1]=1;//���������е�һ�����µ���������
    for (i=0; i<num; i++) {
        if (i==0 || i==1) {//����ǵ�һ�����£�����������1
            printf("��%d����   ����:1\n",i+1);
        }
        else {//�ӵ������¿�ʼ
           // ��ǰ��������  = ��-1���������� + ��-2����������
            month[i]=month[i-1]+month[i-2];
            printf("��%d����   ����: %d\n",i+1,month[i]);//��ӡ

        }
    }
}

/*����˳������*/
void fun3(){
    int x,y,z,t;
    printf("�������������֣����磺30,20,62����");
    scanf("%d,%d,%d",&x,&y,&z);
    if (x>y) { /*����x,y��ֵ*/
           t=x;x=y;y=t;
       }
       if(x>z) { /*����x,z��ֵ*/
           t=z;z=x;x=t;
       }
       if(y>z) { /*����z,y��ֵ*/
           t=y;y=z;z=t;
       }
        printf("��С��������: %d %d %d\n",x,y,z);
}

/*�������*/
void fun2()
{
    double i;
    double bonus1,bonus2,bonus4,bonus6,bonus10,bonus;
    printf("��ľ������ǣ�\n");
    scanf("%lf",&i);
    bonus1=100000*0.1;//����10���  ��10%����
    bonus2=bonus1+100000*0.075;//  10w ~ 20w  ��7.5%����
    bonus4=bonus2+200000*0.05; //  20w ~ 40w  ��5%����
    bonus6=bonus4+200000*0.03; //  40w ~ 60w  ��3%����
    bonus10=bonus6+400000*0.015;// 60w ~ 100W ��1.5%����
    if(i<=100000) {
        bonus=i*0.1;
        printf("�������Ϊ��%lf",bonus);
    } else if(i<=200000) {
        bonus=bonus1+(i-100000)*0.075;
        printf("\n����10���,��0.1����;��ɽ��Ϊ��%lf",bonus1);
        printf("\n10w ~ 20w֮��,��0.075����;��ɽ��Ϊ��%lf",(i-100000)*0.075);
        printf("\n�ܽ���Ϊ��%lf",bonus);
    } else if(i<=400000) {
        bonus=bonus2+(i-200000)*0.05;
        printf("\n����10���,��0.1����;��ɽ��Ϊ��%lf",bonus1);
        printf("\n10w ~ 20w֮��,��0.075����;��ɽ��Ϊ��%lf",bonus2);
        printf("\n20w ~ 40w֮��,��0.05����;��ɽ��Ϊ��%lf",(i-200000)*0.05);
        printf("\n�ܽ���Ϊ��%lf",bonus);
    } else if(i<=600000) {
        bonus=bonus4+(i-400000)*0.03;
        printf("\n����10���,��0.1����;��ɽ��Ϊ��%lf",bonus1);
        printf("\n10w ~ 20w֮��,��0.075����;��ɽ��Ϊ��%lf",bonus2);
        printf("\n20w ~ 40w֮��,��0.05����;��ɽ��Ϊ��%lf",bonus4);
        printf("\n40w ~ 60w֮��,��0.03����;��ɽ��Ϊ��%lf",(i-400000)*0.03);
        printf("\n�ܽ���Ϊ��%lf",bonus);
    } else if(i<=1000000) {
        bonus=bonus6+(i-600000)*0.015;
        printf("\n����10���,��0.1����;��ɽ��Ϊ��%lf",bonus1);
        printf("\n10w ~ 20w֮��,��0.075����;��ɽ��Ϊ��%lf",bonus2);
        printf("\n20w ~ 40w֮��,��0.05����;��ɽ��Ϊ��%lf",bonus4);
        printf("\n40w ~ 60w֮��,��0.03����;��ɽ��Ϊ��%lf",bonus6);
        printf("\n60w ~ 100w֮��,��0.015����;��ɽ��Ϊ��%lf",(i-600000)*0.015);
        printf("\n�ܽ���Ϊ��%lf",bonus);
    } else{
        bonus=bonus10+(i-1000000)*0.01;
        printf("\n����10���,��0.1����;��ɽ��Ϊ��%lf",bonus1);
        printf("\n10w ~ 20w֮��,��0.075����;��ɽ��Ϊ��%lf",bonus2);
        printf("\n20w ~ 40w֮��,��0.05����;��ɽ��Ϊ��%lf",bonus4);
        printf("\n40w ~ 60w֮��,��0.03����;��ɽ��Ϊ��%lf",bonus6);
        printf("\n60w ~ 100w֮��,��0.015����;��ɽ��Ϊ��%lf",bonus10);
        printf("\n����100���,��0.01����;��ɽ��Ϊ��%lf",(i-1000000)*0.01);
        printf("\n�ܽ���Ϊ��%lf",bonus);
    }


    printf("\n");
}

/*�žų˷���*/
void fun1(){
    int i,j;//����ѭ����ʼֵ
    for(i=1;i<10;i++){
        for(j=1;j<=i;j++){
            if(i * j >9){ //��if ��ҪĿ����Ϊ�˱��ʽÿ�ж���
                printf("%d x %d = %d  ",i,j,i*j);//��ӡ���ʽ
            }else{
                printf("%d x %d = %d   ",i,j,i*j);//��ӡ���ʽ
            }

        }
        printf("\n\n");
    }

}
