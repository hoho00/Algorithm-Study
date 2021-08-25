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
		printf("아무거나 누르면 경기를 시작합니다.");	
		trigger=getch();
			
		goto label_2;
	}
	
	e_print();
	trigger=getch();
	goto label_1;

	return 0;
}

void abstract(){
	
	printf("줄다리기 게임\n\n");
	printf("3번 싸워서 2번 먼저 이긴 팀의 승리입니다.\n\n");
	printf("참가팀은 두 팀입니다.\n");
	
	printf("1번 참가팀의 이름을 입력하고 Enter>");
	scanf(" %s",name_1);
	printf("2번 참가팀의 이름을 입력하고 Enter>");
	scanf(" %s",name_2);
	
	printf("\n줄다리기 게임의 제한 시간(초 단위)을 입력하고 Enter>");
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
		
		printf("%s: %.1f초","제한시간",max_t);
		printf("%30s: %.1f초","경과시간",gap);
	
		printf("\n\n\n\n%20s%30s%35s\n",name_1,"기준점",name_2);
		printf("%17d승, %d패%24c%32d승, %d패\n",score_1[0],score_1[1],31,score_2[0],score_2[1]);
		
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
			printf("\n 제한시간 초과!\n"); 
			break;
		}
		
		if(k==31){
			printf("%s팀이 이겼습니다.\n",name_1);
			score_1[0]++;
			score_2[1]++;
			break;
		}
		else if(k==43){
			printf("%s팀이 이겼습니다.\n",name_2);
			score_1[1]++;
			score_2[0]++;
			break;
		}
		
		press= getch();		//1(user_1), 0(user_2)로 둠. 
		
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
		printf("\t\t%s팀이 우승했습니다.\n\t\t게임을 종료합니다.\n\t\t계속하려면 아무 키나 누르십시오 . . .",name_1);}
	else{
		printf("\t\t%s팀이 우승했습니다.\n\t\t게임을 종료합니다.\n\t\t계속하려면 아무 키나 누르십시오 . . .",name_2);}
	printf("\n\n=========================================================\n\n");
}






