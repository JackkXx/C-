#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define Max 100	
struct date{
	int year; //������� 
	int month;  //�����·� 
	int day;  //���ֵ��� 
	char address[20];  //���ֵ�ַ 
	int status;  //��ʶ�Ƿ��ѽ��� 
}; 
struct covid{
	char name[10]; //���� 
	char idCard[18];  //���֤�� 
	char tel[11];  //�绰���� 
	char address[20];  //��ַ 
	struct date first;  //��һ�� 
	struct date second;  //�ڶ��� 
};

typedef struct medical{
	int amount;  //��¼����Ϣ��������
    struct covid cov[Max]; 
}Medical;
 
void insert(Medical *index, int total);
void menu();
void seek(Medical *index);
void del(Medical *index);
void alter(Medical *index); 
void without(Medical *index);
void already(Medical *index);
void swap(int *p1, int *p2, int len); 
int judge(char idCard[], Medical *index);


void menu(){
	printf("-----------------��ӭ�����¹��������ϵͳ----------------\n\n");
	printf("               1.¼���������Ϣ\n");
	printf("               2.���ҽ�������Ϣ\n");
	printf("               3.��ʾ�Ѿ��������������Ϣ\n");
	printf("               4.��ʾδ�������������Ϣ\n");
	printf("               5.�޸Ľ�������Ϣ\n");
	printf("               6.ɾ����������Ϣ\n");
	printf("               0.�˳�ϵͳ\n\n");
	printf("----------------------------------------------------------\n\n");
	
}

/*
 ¼���������Ϣ 
*/
void insert(Medical *index, int total){
	int i;
	int sit = index->amount;
	char confirm;
	char idCard[18];
	for(i = 1; i <= total; i++){
		printf("\n\n----------��%d����������Ϣ-------------\n",i);
		printf("������������");
		scanf("%s",index->cov[sit].name);
		while(1){
			printf("���������֤�ţ�");
			fflush(stdin);
			scanf("%s",idCard); 
			if(judge(idCard, index)){
				printf("���֤�Ѵ��ڣ�����������! \n");
			}else{
				strcpy(index->cov[sit].idCard,idCard);
				break;
			}
			
		}
		
		printf("�����˵绰��");
		scanf("%s",index->cov[sit].tel);
		printf("�����˾�ס��ַ��");
		scanf("%s",index->cov[sit].address);
		printf("�������Ƿ�����˵�һ��(y/n)��");
		fflush(stdin); 
		scanf("%c",&confirm);
		if(confirm == 'y' || confirm == 'Y'){
			index->cov[sit].first.status = 1;
			printf("���������ʱ�䣨�ꡢ�¡��գ����ո�������룺");
			scanf("%d%d%d",&index->cov[sit].first.year,&index->cov[sit].first.month,&index->cov[sit].first.day);
			printf("���ֵ�ַ��");
			scanf("%s",index->cov[sit].first.address);
		}else{
			index->cov[sit].first.status = 0;
			index->cov[sit].second.status = 0;
			index->amount++;
			sit++;
			printf("��%d����������Ϣ¼��ɹ�...\n",i);
			continue;
		}
		printf("�������Ƿ�����˵ڶ���(y/n)��");
		fflush(stdin);  //ˢ��stain������ 
		scanf("%c",&confirm);
		if(confirm == 'y' || confirm == 'Y'){
			index->cov[sit].second.status = 1;
			printf("���������ʱ�䣨�ꡢ�¡��գ����ո�������룺");
			scanf("%d%d%d",&index->cov[sit].second.year,&index->cov[sit].second.month,&index->cov[sit].second.day);
			printf("���ֵ�ַ��");
			fflush(stdin);
			gets(index->cov[sit].second.address);
		}else{
			index->cov[sit].second.status = 0;
		}
		printf("��%d����������Ϣ¼��ɹ�...\n",i);
		index->amount++;
		sit++;
	}
	system("pause");
}

/*
 ���ҽ�������Ϣ 
*/
void seek(Medical *index){
	char name[10];
	printf("�����������������");
	scanf("%s",name);
	int i;
	for(i = 0; i < index->amount; i++){
		if(!strcmp(index->cov[i].name,name)){
			printf("���������֤�ţ�%s\n",index->cov[i].idCard);
			printf("�����˵绰���룺%s\n",index->cov[i].tel);
			printf("�����˵�ַ��%s\n",index->cov[i].address);
			if(index->cov[i].first.status){
				printf("��һ���������������������\n");
				printf("����ʱ�䣺%d�� %d�� %d��\n",index->cov[i].first.year,index->cov[i].first.month,index->cov[i].first.day);
				printf("���ֵ�ַ��%s\n\n",index->cov[i].first.address); 
				if(index->cov[i].second.status){
					printf("�ڶ����������������������\n");
					printf("����ʱ�䣺%d�� %d�� %d��\n",index->cov[i].first.year,index->cov[i].first.month,index->cov[i].first.day);
					printf("���ֵ�ַ��%s\n\n",index->cov[i].second.address);
				}
				
				else
				printf("�ڶ����������������δ����\n");
			}
            else{
            	printf("��һ���������������δ����\n");
            	printf("�ڶ����������������δ����\n");
			}
			break; 
		}
	} 
	if(i == index->amount)
	printf("δ�ҵ���������Ϣ.....\n");
}

/*
 ɾ����������Ϣ 
*/ 
void del(Medical *index){
	char name[10];
	printf("ɾ����Ӧ�����˵�������");
	scanf("%s",name);
	int i, sit, flag = 0;
	for(i = 0; i < index->amount; i++){
		if(!strcmp(index->cov[i].name,name)){
			sit = i;
			while(sit <= index->amount){
				index->cov[sit] = index->cov[sit+1];
				sit++;
			}
			index->amount--;
			flag = 1;
			break;
		}
	}
	if(flag){
		printf("ɾ���ɹ�!\n");
	}else{
		printf("ɾ��ʧ�ܣ�δ�ҵ�����������Ϣ.......\n");
	}
}

/*
 �޸Ľ�������Ϣ 
*/
void alter(Medical *index){
	char name[10];
	char confirm;
	printf("������˵�������");
	scanf("%s",name);
	int i;
	for(i = 0; i < index->amount; i++){
		if(!strcmp(index->cov[i].name,name)){
		    printf("������������");
			scanf("%s",index->cov[i].name);
			printf("���������֤�ţ�");
			scanf("%s",index->cov[i].idCard); 
			printf("�����˵绰��");
			scanf("%s",index->cov[i].tel);
			printf("�����˾�ס��ַ��");
			scanf("%s",index->cov[i].address);
			printf("�������Ƿ�����˵�һ��(y/n)��");
			fflush(stdin); 
			scanf("%c",&confirm);
			if(confirm == 'y' || confirm == 'Y'){
				index->cov[i].first.status = 1;
				printf("���������ʱ�䣨�ꡢ�¡��գ����ո�������룺");
				scanf("%d%d%d",&index->cov[i].first.year,&index->cov[i].first.month,&index->cov[i].first.day);
				printf("���ֵ�ַ��");
				scanf("%s",index->cov[i].first.address);
			}else{
				index->cov[i].first.status = 0;
				index->cov[i].second.status = 0;
				continue;
			}
			printf("�������Ƿ�����˵ڶ���(y/n)��");
			fflush(stdin);  //ˢ��stain������ 
			scanf("%c",&confirm);
			if(confirm == 'y' || confirm == 'Y'){
				index->cov[i].second.status = 1;
				printf("���������ʱ�䣨�ꡢ�¡��գ����ո�������룺");
				scanf("%d%d%d",&index->cov[i].second.year,&index->cov[i].second.month,&index->cov[i].second.day);
				printf("���ֵ�ַ��");
				fflush(stdin);
				gets(index->cov[i].second.address);
			}else{
				index->cov[i].second.status = 0;
			}
			printf("��������Ϣ�޸ĳɹ�...\n");
			break;
		}
	} 
	if(i == index->amount){
		printf("δ�ҵ���������Ϣ...\n\n");
	}
	system("pause");
}

/*
 ��ʾ����δ�������������Ϣ 
*/ 
void without(Medical *index){
	int i, flag = 0;
	printf("����\t���֤��\t�绰\t��ס��ַ\t�������\n");
	for(i = 0; i < index->amount; i++){
		if(index->cov[i].first.status == 0 && index->cov[i].second.status == 0){
			printf("%s\t%s\t\t%s\t\t%s\t���붼δ����\n",index->cov[i].name,index->cov[i].idCard,index->cov[i].tel,index->cov[i].address);
			flag = 1;
		}
	}
	if(!flag){
		printf("\n��ʱû��δ�����������......\n"); 
	}
}


void swap(int *p1, int *p2, int len){
	int i, j;
	for(i = 0, j = 0 ; i < len; i++, j++){
		p1[i] = p1[i] ^ p2[j];
		p2[j] = p1[i] ^ p2[j];
		p1[i] = p1[i] ^ p2[j];
	}
}
/*
 ��ʾ�����Ѿ������������ 
*/ 
void already(Medical *index){
	int i, n, p, k, amount1 = 0, amount2 = 0;
	
	//ͳ�Ƶ�һ��͵ڶ����Ѿ����ֵ����� 
	for(i = 0; i < index->amount; i++){
		if(index->cov[i].first.status){
			amount1++;
		}
		if(index->cov[i].second.status){
			amount2++;
		}	
	}
	
	if(amount1 == 0){
		printf("\n-------------------�Ѿ����ֵ�һ�����----------------------\n"); 
		printf("\n  >> >> û�н��ֵ�һ�����.......\n\n");
		return;
	}
	
	int deal[amount1][4], sit = 0;
	for(i = 0; i < index->amount; i++){
		if(index->cov[i].first.status){
			deal[sit][0] = i;
			deal[sit][1] = index->cov[i].first.year;
			deal[sit][2] = index->cov[i].first.month;
			deal[sit][3] = index->cov[i].first.day;
			sit++;
		}			
	}
	
	for(i = 0; i < amount1; i++){
		for(n = i + 1; n < amount1; n++){
			if(deal[i][1] > deal[n][1]){
				swap(deal[i],deal[n],4);
			}
			if(deal[i][1] == deal[n][1]){
				if(deal[i][2] > deal[n][2]){
					swap(deal[i],deal[n],4);
				}
				if(deal[i][2] == deal[n][2]){
					if(deal[i][3] > deal[n][3]){
						swap(deal[i],deal[n],4);
					} 
				}
			}
		}
	}
	printf("-------------------�Ѿ����ֵ�һ�����----------------------\n"); 
	printf("����\t���֤��\t�绰\t��ס��ַ\t����ʱ��\n");
	for(i = 0; i < amount1; i++){
		n = deal[i][0];
		printf("%s\t%s\t\t%s\t\t%s\t%d��%d��%d��\n",index->cov[n].name,index->cov[n].idCard,index->cov[n].tel,index->cov[n].address,
		deal[i][1],deal[i][2],deal[i][3]);
		
	}
	
	if(amount2 == 0){
		printf("\n-------------------�Ѿ����ֵڶ������----------------------\n"); 
		printf("\n  >> >> û�н��ֵڶ������.......\n\n");
		return;
	}
	
	int deal2[amount2][4];
	sit = 0;
	for(i = 0; i < index->amount; i++){
		if(index->cov[i].second.status){
			deal2[sit][0] = i;
			deal2[sit][1] = index->cov[i].second.year;
			deal2[sit][2] = index->cov[i].second.month;
			deal2[sit][3] = index->cov[i].second.day;
			sit++;
		}
				
	}
	
	for(i = 0; i < amount2; i++){
		for(n = i + 1; n < amount2; n++){
			if(deal2[i][1] > deal2[n][1]){
				swap(deal2[i], deal2[n], 4);
			}
			if(deal2[i][1] == deal2[n][1]){
				if(deal2[i][2] > deal2[n][2]){
					swap(deal2[i],deal2[n],4);
				}
				if(deal2[i][2] == deal2[n][2]){
					if(deal2[i][3] > deal2[n][3]){
						swap(deal2[i],deal2[n],4);
					} 
				}
			}
		}
	}
	printf("\n-------------------�Ѿ����ֵڶ������----------------------\n"); 
	printf("����\t���֤��\t�绰\t��ס��ַ\t����ʱ��\n");
	for(i = 0; i < amount2; i++){
		n = deal2[i][0];
		printf("%s\t%s\t\t%s\t\t%s\t%d��%d��%d��\n",index->cov[n].name,index->cov[n].idCard,index->cov[n].tel,index->cov[n].address,
		deal2[i][1],deal2[i][2],deal2[i][3]);
		
	}
	
} 

/*
	�ж���������֤���Ƿ��ظ�
	����ظ�������1�����򣬷���0 
*/ 
int judge(char idCard[], Medical *index){
	int i;
	for(i = 0; i < index->amount; i++){
		if(!strcmp(index->cov[i].idCard,idCard)){
			return 1;
		}
	}
	return 0;
} 

int main(){
	Medical index;
	index.amount = 0; 
	while(1){
		int choose,total;
		menu();
		printf("���������ѡ��");
		scanf("%d",&choose);
		switch(choose){
			case 1:
			    printf("������¼���������");
				scanf("%d",&total); 
				insert(&index,total);
				break;
			case 2:
			    if(index.amount == 0){
			    	printf("   >> ��ǰ��������ϢΪ��......\n");
				}else{ 
					seek(&index);
				}
				printf("\n");
				system("pause");
				break;
			case 3:
				if(index.amount == 0){
			    	printf("   >> ��ǰ��������ϢΪ��......\n");
				}else{ 
					already(&index);
				}
				printf("\n");
				system("pause");
				break;
			case 4:
				if(index.amount == 0){
			    	printf("   >> ��ǰ��������ϢΪ��......\n");
				}else{ 
					without(&index);
				}
				printf("\n");
				system("pause");
				break;		
			case 5:
				alter(&index);
				break;
			case 6:
				if(index.amount == 0){
			    	printf("   >> ��ǰ��������ϢΪ��......\n");
				}else{ 
					del(&index);
				}	
				system("pause");
				break; 
			case 0:
                 printf("��ӭ�´�ʹ�ã�\n");
                 exit(0);	
		}
		system("cls");  //���� 
	}
	
	return 0;
} 
