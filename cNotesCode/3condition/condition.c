#include<stdio.h>

int main(void)
{
	char *class = "大三";
	int join_in_bat_to_battle = 1;
	if (class == "大三" && join_in_bat_to_battle)
	{
		printf("恭喜你，很快就可以加入心仪企业赚高薪啦!\n");
	}
	else{
		printf("哦，NO！我目前还没有方向没有目的地在独自复习着令人心碎的C语言，My gold help me ！\n");
	} 
    int arr[] = {1};
    //括号里的表达式改为以下情况，你能正确判断出来“真”还是“假”吗，实践试试，会让你有更多收获
    if ('\0') 
    {
        //NULL == 0; NULL - 1; -1; 1 + 1; 9.1 - 1.1; 2 % 3; 2 / 3; 'a'; arr; arr[0]; arr - arr ;
        //arr - arr[0] ;arr - 1; arr + 10; &arr; '0'; "0"; '\0'; "\0", '\n', "\n";   
        printf("the result is true.\n");
    }
	int age = 18;
	switch (age)
	{
		case 2:
			printf("宝宝，你好 !");
			break;
		case 6:
			printf("小朋友，你好 !");
			break;
		case 12:
			printf("少年，你好 !");
			break;
		case 16:
			printf("青少年，你好 !");
			break;
		case 18:
			printf("成年人，你好 !");
			break;
		case 67:
			printf("爷爷，你好 !");
			break;
		default:
			printf("对你的年龄我还没有对应的问候方式 ");
			break;
	}

	return 0;
}
