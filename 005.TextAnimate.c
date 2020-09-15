#include <stdio.h>
#include <windows.h>

const int W=20;
const int H=20;
	
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
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

}
int main(int argc, char *argv[]) {
	HideCursor();

	int x=0,y=0;
	 
	char block[W][H];
	int blockx[4]={0,0,1,1};
	int blocky[4]={0,1,1,0};

	//printf("%p\n",block);
	
	clearMatrix(&block ); 
 
	
	for (;;) {
		system("cls");
		clearMatrix( &block ); 
		
		int k;
		for (k=0 ;k<4;k++) {
			block[blockx[k]+x][blocky[k]+y]= 'O';
		}
		
		int i;
		
		for (i=0 ;i<W;i++) {
			printf(block[i]);
			printf("\n");
		}
		y=y+1;
		if (y>7) {
			y=0;
		}
		system("rem");
		
		Sleep(150); 
	}
}
