#include <stdio.h>
//#include <windows.h>
#include <stdlib.h>


#include <sys/time.h>
 
const int W=30;
const int H=60;

//使用select实现精确到1微秒(0.000001秒)的sleep
void sleep_us(unsigned int nusecs)
{
    struct timeval	tval;
 
    tval.tv_sec = nusecs / 1000000;
    tval.tv_usec = nusecs % 1000000;
    select(0, NULL, NULL, NULL, &tval);
}

	
int clearMatrix(char (*block)[W][H] ) {
//	printf("%p\n",block);
	int i,j;
	for (i=0 ;i<W;i++) {
		for (j=0 ;j<H;j++) {
			(*block)[i][j] =' ';
		}
		(*block)[i][H-1 ]=0;
	}
}



void HideCursor() {
//	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
//
}
int main(int argc, char *argv[]) {
	HideCursor();

	int x=0,y=0;
	 
	char block[W][H];
	int blockx[4]={0,0,1,1};
	int blocky[4]={0,1,1,0};

	//printf("%p\n",block);
	
	clearMatrix(&block ); 
 
	
	for (int j=0;j<300;j++) {
		system("clear");
		clearMatrix( &block ); 
		
		int k;
		for (k=0 ;k<4;k++) {
			block[blockx[k]+x][blocky[k]+y]= 'O';
		}
		
		int i;
		
		for (i=0 ;i<W;i++) {
			printf("%s",block[i]);
			printf("\n");
		}
		y=y+1;
		if (y>H-1) {
			y=0;
		}
		system("rem");
		sleep_us(30000);
		//Sleep(150); 
	}
}
