#include <bits/stdc++.h>
using namespace std;
int auto_id=0;//������id
int flag;//ѡ����� 
char t;//�Ե��ո� - �� 
struct Account{
	char codechar;
	char ps[20];
	int codeint;
	int year,month,day;
	double money;
}acc[200];
//���ȼ�:��֧���>��֧�ڸ������>����С 
//1��a��ǰ��0��b��ǰ 
bool cmp(Account a,Account b){
	//��a��b����֧�����ͬʱ 
    if(a.codechar==b.codechar){
    	//��a��b�ľ��������ͬʱ 
    	if(a.codeint==b.codeint){
    		//���ݽ���������� 
    		return a.money<b.money;	
    	}else{
    		//��֧�����ͬ���������ͬʱ 
    		return a.codeint<b.codeint;
    	} 
    }
	//��֧���ͬ,��a��ǰ�� 
	else{
    	return a.codechar=='a';
    }
}
void file_input(){
	FILE *fp;
	if((fp=fopen("data.txt","r+"))==NULL){
		printf("�޷����ļ�!�����Ƿ��������ļ���\n"); 
		exit(0);
	}else{
		cout<<"�ɹ����ļ�ָ�룡"<<endl;
		int i=0;
	    while(~fscanf(fp,"%c%d %d-%d-%d %lf %s\n",
		&acc[i].codechar,&acc[i].codeint,&acc[i].year,&acc[i].month,&acc[i].day,&acc[i].money,acc[i].ps)){
		printf("%c%d %d-%d-%d %.2f %s\n",acc[i].codechar,acc[i].codeint,acc[i].year,acc[i].month,acc[i].day,acc[i].money,acc[i].ps);
		printf("��%d���������\n",i+1);
		i++;
		auto_id++;
		}
	}
}
void hand_input(){
	//�Ե��س� 
	getchar();
	printf("��������֧��ϸ��");
	//���������� 
	scanf("%c%d",&acc[auto_id].codechar,&acc[auto_id].codeint);
	//�Ե��ո� 
	scanf("%c",&t);
	//year-month-day 
	scanf("%d%c%d%c%d",&acc[auto_id].year,&t,&acc[auto_id].month,&t,&acc[auto_id].day);
	//�Ե��ո�
	scanf("%c",&t);
	//��� 
	scanf("%lf",&acc[auto_id].money);
	//�Ե��ո�
	scanf("%c",&t);
	//��ע����
	scanf("%s",acc[auto_id].ps);
	auto_id++; 
	printf("�����ɹ�¼�룡\n");
	//printf("%c%d %d-%d-%d %.2f %s",acc[0].codechar,acc[0].codeint,acc[0].year,acc[0].month,acc[0].day,acc[0].money,acc[0].ps);
}
//ͳ�ƺ��� 
void statis(){
		double get=0,lose=0,sum=0;//getΪ�ۼ����룬loseΪ�ۼ�֧����sumΪ�ۼ���� 
		for(int i=0;i<auto_id;i++){
			if(acc[i].codechar=='a'){
				get+=acc[i].money;
				sum+=acc[i].money;
			}else{
				lose+=acc[i].money;
				sum-=acc[i].money;
			}
		}
		getchar();
		printf("�ۼ����룺%.2f,�ۼ�֧����%.2f,������:%.2f\n",get,lose,sum);
		printf("�Ƿ�������µĸ�����ϸ,����y������n\n");
		char yn;
		scanf("%c",&yn);
		int y,m;
		printf("���������֧�����л��ܵ��·�\n");
		scanf("%d%c%d",&y,&t,&m);
		if(yn=='y'){
	        sort(acc,acc+auto_id,cmp);
		    printf("����/֧�� ��ϸ��� ���\n");
		    for(int i=0;(i<auto_id)&&acc[i].year==y&&acc[i].month==m;i++){
			    if(acc[i].codechar=='a'){
			      if(acc[i].codeint==1)
		 	  	     printf("���� ����� %.2f\n",acc[i].money);
			  	  else if(acc[i].codeint==2)
			   		 printf("���� ��ѧ�� %.2f\n",acc[i].money);
			      else if(acc[i].codeint==3)
			  	     printf("���� ��� %.2f\n",acc[i].money);
			      }else{
				    if(acc[i].codeint==1)
				        printf("֧�� ѧϰ��Ʒ %.2f\n",acc[i].money);
					if(acc[i].codeint==2)
			        	printf("֧�� ������Ʒ %.2f\n",acc[i].money);
				    if(acc[i].codeint==3)
				        printf("֧�� ��� %.2f\n",acc[i].money);
			      }
		    }
		}
}
void output(){
	for(int i=0;i<auto_id;i++){
		printf("%c%d %d-%d-%d %.2f %s\n",acc[i].codechar,acc[i].codeint,acc[i].year,acc[i].month,acc[i].day,acc[i].money,acc[i].ps);
	}
}
void file_save(){
	FILE *fp;
	if((fp=fopen("data.txt","a+"))==NULL){
	printf("�޷����ļ�!�����Ƿ�������ļ���\n");
	exit(0);
	}else{
	for(int i=0;i<auto_id;i++){
			fprintf(fp,"%c%d %d-%d-%d %.2f %s\n",acc[i].codechar,acc[i].codeint,acc[i].year,acc[i].month,acc[i].day,acc[i].money,acc[i].ps);
		}
	}
	printf("����ɹ�!\n");
	fclose(fp);
}
void find(){
	printf("�������ڲ�����1(��2020-6-4)����������������2(��a2)\n");
	scanf("%d",&flag);
	if(flag==1){
		int y,m,d;
		printf("������Ҫ��ѯ������(��2020-6-4)\n");
		scanf("%d%c%d%c%d",&y,&t,&m,&t,&d);
		for(int i=0;i<auto_id;i++){
		  if(acc[i].year==y&&acc[i].month==m&&acc[i].day==d)  
	      printf("%c%d %d-%d-%d %.2f %s\n",acc[i].codechar,acc[i].codeint,acc[i].year,acc[i].month,acc[i].day,acc[i].money,acc[i].ps);
		}
	}else if(flag==2){
	   getchar();
	   printf("��������Ҫ�鿴�����(��a2)\n");
	   char Codechar;int Codeint; 
       scanf("%c%d",&Codechar,&Codeint);
       printf("%c%d",Codechar,Codeint);
	   for(int i=0;i<auto_id;i++){
	   	  if(acc[i].codechar==Codechar&&acc[i].codeint==Codeint)	  
	      printf("%c%d %d-%d-%d %.2f %s\n",acc[i].codechar,acc[i].codeint,acc[i].year,acc[i].month,acc[i].day,acc[i].money,acc[i].ps);
	   }
	}
}
int main(){
	while(true){
		printf("-----------------------------------------------------------------\n");
		printf("                            �˵���                               \n\n");
		printf("¼���˵���1��ͳ���˵���2,��ѯ�˵���3,�鿴������4,����������5,��ֹ��������0   \n"); 
		scanf("%d",&flag);
		if(flag==1){
			printf("�ֶ�������1���ļ�������2\n");
			scanf("%d",&flag);
			if(flag==1){
			  int cnt;
			  printf("��������Ҫ¼�������\n");
			  scanf("%d",&cnt);
		      while(cnt--){
			  hand_input();
		      }
			}else if(flag==2){
			file_input();
			}
		}else if(flag==2){
			statis();	
		}else if(flag==3){
	        find();	
		}else if(flag==4){
			output();
		}else if(flag==5){
			file_save();
		}else if(flag==0){
			printf("������֧ϵͳ���˳���\n");
			exit(0);
		} 
	}
	return 0;
} 
