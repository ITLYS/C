#include <stdio.h>
/*C语言---指针进阶*/

/*指针进阶---函数指针*/
int main(){
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
int main(){
    //数组指针，其实是指针 是指向数组的指针
//    int arr[5]={1,2,3,4,5};//arr == &arr[0] 首元素地址；&arr 整个数组的地址
//    //（*p）为一个指针；  [5]一个数组； int(*p)[5]一个指向整型数组的指针
//    int(*p)[5]=&arr;
//    //一维数组 ------------------------------------
//    for(int i=0;i<5;i++){
//        printf("%d ",(*p)[i]);//其一
//        printf("%d ",*(p+i)); //其二
//    }
    //二维数组 ------------------------------------
    void fun1();
    int arr1[3][4]={{1,2,3,4},{4,5,6,7},{7,8,9,10}};
    //arr1  首元素地址  {1,2,3,4}为首元素地址，
    fun1(arr1,3,4);
    return 0;
}
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
