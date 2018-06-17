#include <stdio.h>  
  
int  main( int argc, char ** argv ) 
{  
        printf("%s\n",__FUNCTION__);  
  
        return 0;  
}  
  
  
int before_main()  
{  
        printf("%s\n",__FUNCTION__);  
        printf("Hi～,i am called before the main function!");
  
        return 0;  
}  
  
int after_main()  
{  
        printf("%s\n",__FUNCTION__);  
        printf("Hi～,i am called after the main function!");
  
        return 0;  
}  
  
typedef int func();  
  
#pragma data_seg(".CRT$XIU")  
static func * before[] = { before_main };  
  
#pragma data_seg(".CRT$XPU")  
static func * after[] = { after_main };  
  
#pragma data_seg()  
