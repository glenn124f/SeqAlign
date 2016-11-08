#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int initialize(int gp,int s1, int s2,int a[][s1+1],int tr[][s1+1]);
int display(int s1, int s2, int a[][s1+1]);
int calculate(int s1, int s2, char str1[], char str2[], int gp,int m,int mm, int a[][s1+1],int tr[][s1+1]);
int traceback(int s1,int s2,int tr[][s1+1],char str1[], char str2[]);


int main(int argc, char *argv[]){

	int s1=atoi(argv[3]);
	int s2=atoi(argv[4]);

	int a[s2+1][s1+1];
	int tr[s2+1][s1+1];

	for (int i = 0; i <= s2 ; i++)
	{
		for (int j = 0; j <= s1; j++)
		{
			a[i][j]=0;
		}
	}

	for (int i = 0; i <= s2 ; i++)
	{
		for (int j = 0; j <= s1; j++)
		{
			tr[i][j]=0;
		}
	}

	char str1[s1];
	char str2[s2];




	char y[s1];

	strcpy(str1,argv[1]);
	strcpy(str2,argv[2]);

	int gp=atoi(argv[5]);
	int m=atoi(argv[6]);
	int mm=atoi(argv[7]);


	

	printf("Seq1:%s\nSeq2:%s\n", str1,str2);
	//display(s1,s2, a);

	initialize(gp, s1, s2, a, tr);
	//printf("Displaying initialized Array \n");
	//display(s1,s2,a);
	//printf("Calculating....\n");
	calculate(s1,s2,str1,str2,gp,m,mm,a,tr);
	printf("===================\n");
	printf("Scoring Matrix\n");
	//printf("Displaying final array \n");
	display(s1,s2, a);
	printf("===================\n");
	printf("Traceback Matrix\n");
	display(s1,s2,tr);
	printf("===================\n");
	printf("ALIGNMENT\n");
	traceback(s1,s2,tr,str1,str2);

}


int initialize(int gp,int s1, int s2, int a[][s1+1],int tr[][s1+1]){
	int k=gp;
	for (int i = 1; i <= s1; i++)
	{
		a[0][i]=k*i;
		tr[0][i]=2;

	}
	for (int i = 1; i <= s2; i++)
	{
		a[i][0]=k*i;
		tr[i][0]=3;
	}
}

int display(int s1, int s2, int a[][s1+1]){
	for (int i = 0; i <= s2 ; i++)
	{
		for (int j = 0; j <= s1; j++)
		{
			printf("%3d\t",a[i][j]);
		}
		printf("\n");
	}
}

int calculate(int s1, int s2, char str1[], char str2[], int gp, int m, int mm, int a[][s1+1], int tr[][s1+1]){
	int t,v1,v2,v3,maximum;
	for (int i = 1; i <= s2; i++)
	{
		for (int j = 1; j <= s1; j++)
		{
			if( str1[j-1] == str2[i-1] )
				t=m;
			else
				t=mm;

			v1=a[i-1][j-1] + t;
			v2=a[i][j-1] + gp;
			v3=a[i-1][j] + gp;

			maximum = v1 > v2 ? (v1 > v3 ? v1 : v3) : (v2 > v3 ? v2 : v3) ;

			if(v1==maximum){
				tr[i][j]=1;
			}
			else if(v2==maximum){
				tr[i][j]=2;
			}
			else if(v3==maximum){
				tr[i][j]=3;
			}

			a[i][j]=maximum;
		}
	}
}

int traceback(int s1,int s2,int tr[][s1+1], char str1[], char str2[]){
	int i,j,k;
	char x[200];
	char y[200];
	char z[200];
	for(int i=0;i<200;i++){
		z[i]=' ';
	}
	printf("Calculating");
	i=s2;
	j=s1;
	k=0;
	int gcx=0;
	int gcy=0;
	while(1){
		if(tr[i][j]==1){
			
			x[k]=str1[j-1];
			y[k]=str2[i-1];
			k++;
			i=i-1;
			j=j-1;
		}
		else if(tr[i][j]==2){
			
			x[k]=str1[j-1];
			y[k]='_';
			gcy++;
			k++;
			j=j-1;
		}
		else if(tr[i][j]==3){
			
			x[k]='_';
			gcx++;
			y[k]=str2[i-1];
			k++;
			i=i-1;
		}
		else{
			break;
		}

	}


	for(int i=0;i<=(k-1);i++){
		if(x[i]==y[i]){
			z[i]='|';
		}
		else{ 
			if(x[i]=='_' || y[i]=='_'){
				z[i]='-';
			}
			else{
				z[i]='.';
			}
		}
	}
	//printf("%d\n",k);
	printf("\nSeq1:");
	for(int l=(k-1);l>=0;l--){
		printf("%2c",x[l]);
	}
	printf("\nMtch:");
	for(int l=(k-1);l>=0;l--){
		printf("%2c",z[l]);
	}
	printf("\nSeq2:");
	for(int l=(k-1)	;l>=0;l--){
		printf("%2c",y[l]);
	}
	printf("\n");
}