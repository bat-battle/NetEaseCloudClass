#include<stdio.h>

int main()
{
	int tag = 10;
	int bigInt = 2147483647 + 1;
	char age = 10;
	char name = 'A';
//    char my = "a";
//    char *address = "上海市打浦桥";

	double core = 98.5;
	double myCore = 98;
    int intCore = 99.5;
	float money = 99.99;
	float myMoney = 99;

	int *ptr = 0;
	int *ptr0 = 10;
    //*ptr = 1;
	int *ptr1 = NULL; 
//    *ptr1 = 100;
	int *ptr2 = &tag;
	char buff[10];
    char *myBuff = buff;

//	10 = 10; 10=9; //作为左值不能是常量？No，这个应该认识吧，const int MAX = 100
	//那么问题来了，我们如何创造空间，使10=10可以通过呢？

	//赋值语句充要条件：
	//赋值语句两边类型必须严格一致或编译器可做类型的隐式转化
	//左值必须有空间，且大小合适、地址合法；

    printf("老铁，感谢有缘一起学习C语言，除了跟着这套课程走，为了更好地解决大家实操中的问题，可以加QQ群676593534，及时交流。群里还有很多精致资料哦，我这这里等你！");
    return 0;


}
