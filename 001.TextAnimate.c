#include <stdio.h>
#include <windows.h>

const int W=20;
const int H=20;
	
 
 
int main(int argc, char *argv[]) {
 
	char block[W][H];
 	int i,j;
	for (i=0 ;i<W;i++) {
		for (j=0 ;j<H;j++) {
			 block[i][j] ='.';
		}
		block[i][H-1 ]=0;
	}
	
 
		system("cls");
	 
	 
	 
		
		for (i=0 ;i<W;i++) {
			printf(block[i]);
			printf("\n");
		}
  
}
