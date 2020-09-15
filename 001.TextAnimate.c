#include <stdio.h>
int main(int argc, char *argv[])
{
	const int W=20;
	const int H=20;
	 
	char block[W][H];
	int blockx[3]={0,0,1,1};
	int blocky[3]={0,1,1,0};
	
	int i,j;
	for (i=0 ;i<10;i++) {
		for (j=0 ;j<10;j++) {
			block[i][j] ='.';
		}
		block[i][10]=0;
	}
	
	for (;;) {
		system("cls");
		for (i=0 ;i<10;i++) {
			printf(block[i]);
			printf("\n");
		}
	}
}
