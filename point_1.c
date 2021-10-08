#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*C语言---指针进阶*/

/*
 *调换两个元素的位置，由bubble_sort调用
 * ad1 ad2两个元素的地址
 * width 元素的字节数
 */
void swap(char *ad1,char *ad2,int width){
    int i;
    for(i=0;i<width;i++){
        //此处的调换是每个字节 每个字节的调换
        char tmp=*ad1;
             *ad1=*ad2;
             *ad2=tmp;
             ad1++;
             ad2++;
    }
}
/* 冒泡排序：支持各种数据类型
 * base 需要排序的数据起始地址
 * size 需要排序的元素数量
 * width 元素的字节数，也就是数据类型
 * cmp 如何比较两个元素的函数地址，需调用者定义该函数
 */
void bubble_sort(void *base,int size,int width,int (*cmp)(void *e1,void *e2)){
    int i=0,j=0;
    //外循环控制趟数
    for(i=0;i<size-1;i++){
        //内循环控制比较的次数
        for(j=0;j<size-1-i;j++){
            //根据函数指针，找到该函数，判断函数返回结果 大于0 需要调换两个元素的位置
            //base 起初是一个空类型指针，空类型指针无法确定步长值，所以无法base++,同时也无法进行解引用操作*base
            //所以我们把它转化为char *,char类型字节为1，容易掌控指针移动的步长值
            //比如需要排序的数据类型是int ,j=0,base+0*4 指向首元素，j=1,base+1*4 指向下一个元素 一次类推
           if(cmp((char *)base+j*width,(char *)base+(j+1)*width)>0){
               //调用swap 函数 调换位置
               swap((char *)base+j*width,(char *)base+(j+1)*width,width);
           }
        }
    }
}
struct stu{
  char name[20];
  int  age;
};
/*
 *比较两个元素方法，需调用者定义该函数
 *注：返回类型为整型。因为类型为空指针，比较的时候也需要转化类型
 */
int cmp_int(void *e1,void *e2){
    return *(int*)e1-*(int*)e2;
}
int cmp_age(void *e1,void *e2){
    return ((struct stu *)e1)->age-((struct stu*)e2)->age;
}
int cmp_name(void *e1,void *e2){
    return strcmp(((struct stu*)e1)->name,((struct stu*)e2)->name);
}

int main(void){
    struct stu s[]={{"张三",20},{"李四",30},{"王五",10}};
    int size = sizeof(s)/sizeof(s[0]);
    bubble_sort(s,size,sizeof(s[0]),cmp_name);
    for(int i=0;i<size;i++){
        printf("%d\t%s\n",s[i].age,s[i].name);
    }
}
//int main(void){
//    int arr[]={9,8,7,6,5,4,3,2,1,0};
//    int size = sizeof(arr)/sizeof(arr[0]);
//    bubble_sort(arr,size,sizeof(arr[0]),cmp_int);
//    for(int i=0;i<size;i++){
//        printf("%d\t",arr[i]);
//    }
//}

/*指针进阶--函数指针-------------------------------------------------*/
int main()
{
    //函数指针  是指向函数的指针，存放函数地址的指针

    //例如有一个函数 test();

    //&test 或 test 都表示函数的地址

    //函数指针赋值
    //int (*pfun)(int ,int);函数内部参数应与实际情况相应，此例仅用来表示函数指定的定义

   /*
     * signal 是一个函数声明
     * signal函数的参数有两个，第一个是int,第二个是函数指针，该函数指针 指向 的函数的参数是int，返回类型是void
     * signal函数的返回类型也是一个函数指针，该函数指针 指向的函数的参数是int 返回类型是void
     */
    void(* signal(int,void(*)(int)) )(int);
    //上下两个所表达的意思一样
    typedef void(* pfun_t)(int);
    pfun_t signal(int,pfun_t);
    
    
    int (*pf)(int,int);//函数指针
    int(*pfarr[4])(int,int);//函数指针数组
    for(int i=0;i<4;i++){
        printf("%d",pfarr[i](1,2));
    }
    int(*(*ppfarr)[4])(int,int);//指向函数指针数组的指针
    //ppfarr是一个数组指针，指针指向的数组有四个元素
    //指向数组的每个元素的类型是一个函数指针
  }

/*指针进阶---数组指针*/
//int main(){
//    //数组指针，其实是指针 是指向数组的指针
//    int arr[5]={1,2,3,4,5};//arr == &arr[0] 首元素地址；&arr 整个数组的地址
//    //（*p）为一个指针；  [5]一个数组； int(*p)[5]一个指向整型数组的指针
//    int(*p)[5]=&arr;
//    //一维数组 ------------------------------------//    for(int i=0;i<5;i++){
//        printf("%d ",(*p)[i]);//其一
//        printf("%d ",*(p+i)); //其二
//    }
//    //二维数组 ------------------------------------
//    void fun1();
//    int arr1[3][4]={{1,2,3,4},{4,5,6,7},{7,8,9,10}};
//    //arr1  首元素地址  {1,2,3,4}为首元素地址，
//    fun1(arr1,3,4);
//    return 0;
//}
/*int (*p)[4] 为一个数组指针；
 *row  行
 *column 列
 */
void fun1(int (*p)[4],int row ,int column){
    int i,j;
    for(i=0;i<row;i++){//外层控制行
        for(j=0;j<column;j++){//内层控制列
           //*(p+i) 相当于找到了当前行的数组 arr[i]
           //*(p+i)+j 相当于找到了当前行的数组的当前列arr[i][j]
           //然后取地址 *(*(p+i)+j)
            printf("%d\t",*(*(p+i)+j));//其一

            printf("%d\t",(*(p+i))[j]);//其二
        }
        printf("\n");
    }
}

/*指针进阶---指针数组*/
//int main(){
//    //指针数组，其实是数组，其目的用来存放指针的
//    //----------------入门用法----------------
//    int a=10,b=20,c=30,d=40,e=50;
//    //存放整型指针的数组  也就是指针数组
//    int * parr[5]={&a,&b,&c,&d,&e};

//    for(int i=0;i<5;i++){
//        // parr[i]获取到的是地址 ，这时‘*’为解引用操作符：根据地址获取存储的值
//        printf("%d ",*(parr[i]));

//    }
//    //----------------初级用法----------------
//    int arr1[3]={1,2,3};
//    int arr2[3]={4,5,6};
//    int arr3[3]={7,8,9};
//    int * parr1[3] = {arr1,arr2,arr3};
//    for(int x=0;x<3;x++){
//        for(int y=0;y<3;y++){
//             printf("%d\t",*(parr1[x]+y));
//        }
//         printf("\n");

//    }
//    return 0;
//}

/*指针进阶---字符指针*/
//int main()
//{
//    char *p = "abcd";
//    *p  =  'W';
//    以上为错误语法示范，部分编译器无法识别该错误
//    注释：
//    //当我们把一个常量字符串的地址交给char类型的指针p时，
//    //最好在指针p前定义 const 进行修饰
//    //以免部分编译器 无法识别该错误(指：对一个常量指针进行赋值,C中是不允许的)
//    const char *p = "abcd";
//    printf("%s",p);
//    return 0;
//}

/*相关笔试*/
//int main(){
//    char arr1[] = "aaaa";
//    char arr2[] = "aaaa";
//    //虽然是相同的字符串，但是系统给两个变量的是不同的存储地址
//    char * pc1  = "aaaa";
//    char * pc2  = "aaaa";
//    //直接把字符串地址赋值给指针的时候，这个字符串是一个常量。
//    //内存，索性将两个相同常量，存储到一个的地址，然后赋值 给两个指针

//    printf("数组arr1 与 数组arr 相比较:\n");
//    if(&arr1 == &arr2){
//        printf("相同\n");
//    }else{
//       printf("不同\n");
//    }
//    printf("指针pc1 与 指针pc2 相比较:\n");
//    if(pc1 == pc2){
//        printf("相同");
//    }else{
//       printf("不同");
//    }
//    return 0;
//}
