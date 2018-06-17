#include <stdio.h>  

#if 0
The constructor attribute causes the function to be called automatically before 
execution enters main (). Similarly, the destructor attribute causes the function 
to be called automatically after main () completes or exit () is called. 
Functions with these attributes are useful for initializing data that is used 
implicitly during the execution of the program.

more infoformation: https://gcc.gnu.org/onlinedocs/gcc-6.2.0/gcc/Common-Function-Attributes.html#Common-Function-Attributes
#endif 
  
__attribute__((constructor)) void before_main_to_run()  
{  
    printf("Hi～,i am called before the main function!\n");
    printf("%s\n",__FUNCTION__);  
}  

__attribute((constructor)) void before_main_to_run_two()  
{  
    printf("Hi～,i am called before the main function!\n");
    printf("%s\n",__FUNCTION__);  
}  
  
__attribute__((destructor)) void after_main_to_run()  
{  
    printf("%s\n",__FUNCTION__);  
    printf("Hi～,i am called after the main function!\n");
}  
  
__attribute((destructor)) void after_main_to_run_two()  
{  
    printf("%s\n",__FUNCTION__);  
    printf("Hi～,i am called after the main function!\n");
}  
int main( int argc, char ** argv )  
{  
    printf("i am main function, and i can get my name(%s) by this way.\n",__FUNCTION__);  
    return 0;  
}  
