#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>

char name_1[21],name_2[21];
float max_t;
int score_1[2],score_2[2];

void abstract();
void m_print();
void e_print();

int main(){
	char trigger;

label_1:
	system("cls");
	abstract();
	
label_2:
	m_print();
	
	if(score_1[0]!=2&&score_2[0]!=2){
		printf("�ƹ��ų� ������ ��⸦ �����մϴ�.");	
		trigger=getch();
			
		goto label_2;
	}
	
	e_print();
	trigger=getch();
	goto label_1;

	return 0;
}

void abstract(){
	
	printf("�ٴٸ��� ����\n\n");
	printf("3�� �ο��� 2�� ���� �̱� ���� �¸��Դϴ�.\n\n");
	printf("�������� �� ���Դϴ�.\n");
	
	printf("1�� �������� �̸��� �Է��ϰ� Enter>");
	scanf(" %s",name_1);
	printf("2�� �������� �̸��� �Է��ϰ� Enter>");
	scanf(" %s",name_2);
	
	printf("\n�ٴٸ��� ������ ���� �ð�(�� ����)�� �Է��ϰ� Enter>");
	scanf(" %f",&max_t);
	
}


void m_print(){
	
	system("cls");
	
	clock_t start, end;
	float gap;
	
	char rope[80]={};
	int i,k=37;
	
	for(i=0;i<=79;i++){
		rope[i]=' ';
	}
	
	for(i=k;i<=k+20;i++){
		rope[i]='O';
	}
	rope[k+4]='|';
	rope[k+10]='X';
	rope[k+16]='X';
 	
	start = clock();
	 
	while(1){
		char press;
		
		end = clock();
		gap =(float)(end - start)/(CLOCKS_PER_SEC);
		
		printf("%s: %.1f��","���ѽð�",max_t);
		printf("%30s: %.1f��","����ð�",gap);
	
		printf("\n\n\n\n%20s%30s%35s\n",name_1,"������",name_2);
		printf("%17d��, %d��%24c%32d��, %d��\n",score_1[0],score_1[1],31,score_2[0],score_2[1]);
		
		for(i=0;i<=100;i++){
			rope[i]=' ';
		}
	
		for(i=k;i<=k+20;i++){
			rope[i]='O';
		}
		rope[k+10]='|';
		rope[k+4]='X';
		rope[k+16]='X';
		
		for(i=0;i<=100;i++){
			printf("%c",rope[i]);
		}
		printf("\n%48c\n",30); 
		
			
		if(gap>=max_t){
			printf("\n ���ѽð� �ʰ�!\n"); 
			break;
		}
		
		if(k==31){
			printf("%s���� �̰���ϴ�.\n",name_1);
			score_1[0]++;
			score_2[1]++;
			break;
		}
		else if(k==43){
			printf("%s���� �̰���ϴ�.\n",name_2);
			score_1[1]++;
			score_2[0]++;
			break;
		}
		
		press= getch();		//1(user_1), 0(user_2)�� ��. 
		
		if(press=='1'){
			k--;
		}
		else if(press=='0'){
			k++;
		}
		system("cls");

	}
}

void e_print(){
	system("cls");
	
	printf("\n\n=========================================================\n\n");

	if(score_1[0]==2){
		printf("\t\t%s���� ����߽��ϴ�.\n\t\t������ �����մϴ�.\n\t\t����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .",name_1);}
	else{
		printf("\t\t%s���� ����߽��ϴ�.\n\t\t������ �����մϴ�.\n\t\t����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .",name_2);}
	printf("\n\n=========================================================\n\n");
}






