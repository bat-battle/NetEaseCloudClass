#include <stdlib.h>
#include <stdio.h>

/**
 *                    _ooOoo_
 *                   o8888888o
 *                   88" . "88
 *                   (| -_- |)
 *                    O\ = /O
 *                ____/`---'\____
 *              .   ' \\| |// `.
 *               / \\||| : |||// \
 *             / _||||| -:- |||||- \
 *               | | \\\ - /// | |
 *             | \_| ''\---/'' | |
 *              \ .-\__ `-` ___/-. /
 *           ___`. .' /--.--\ `. . __
 *        ."" '< `.___\_<|>_/___.' >'"".
 *       | | : `- \`.;`\ _ /`;.`/ - ` : | |
 *         \ \ `-. \_ __\ /__ _/ .-` / /
 * ======`-.____`-.___\_____/___.-`____.-'======
 *                    `=---='
 *
 * .............................................
 *          佛祖保佑             永无BUG
 */

void fn0( void ), fn1( void ), fn2( void ), fn3( void ), fn4( void );

int main( void )
{
	atexit( fn0 );
	atexit( fn1 );
	atexit( fn2 );
	atexit( fn3 );
	atexit( fn4 );
	printf( "This is executed first.\n" );
    printf("main will quit now!\n");
	return 0;
}

void fn0()
{
	printf( "哎呦，我的小心脏啊，吓死宝宝了。竟然还真可以这样玩，扶我起来，我要继续学习！\n" );
}
void fn1()
{
	printf( "next.\n" );
}

void fn2()
{
	printf( "executed " );
}

void fn3()
{
	printf( "is " );
}

void fn4()
{
	printf( "This " );
}
