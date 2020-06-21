#include <bits/stdc++.h>
using namespace std;
int auto_id=0;//自增长id
int flag;//选项代号 
char t;//吃掉空格 - 等 
struct Account{
	char codechar;
	char ps[20];
	int codeint;
	int year,month,day;
	double money;
}acc[200];
//优先级:收支类别>收支内各种类别>金额大小 
//1是a在前，0是b在前 
bool cmp(Account a,Account b){
	//当a和b的收支类别相同时 
    if(a.codechar==b.codechar){
    	//当a和b的具体类别相同时 
    	if(a.codeint==b.codeint){
    		//根据金额升序排列 
    		return a.money<b.money;	
    	}else{
    		//收支类别相同，具体类别不同时 
    		return a.codeint<b.codeint;
    	} 
    }
	//收支类别不同,让a在前面 
	else{
    	return a.codechar=='a';
    }
}
void file_input(){
	FILE *fp;
	if((fp=fopen("data.txt","r+"))==NULL){
		printf("无法打开文件!请检查是否建立输入文件！\n"); 
		exit(0);
	}else{
		cout<<"成功打开文件指针！"<<endl;
		int i=0;
	    while(~fscanf(fp,"%c%d %d-%d-%d %lf %s\n",
		&acc[i].codechar,&acc[i].codeint,&acc[i].year,&acc[i].month,&acc[i].day,&acc[i].money,acc[i].ps)){
		printf("%c%d %d-%d-%d %.2f %s\n",acc[i].codechar,acc[i].codeint,acc[i].year,acc[i].month,acc[i].day,acc[i].money,acc[i].ps);
		printf("第%d条读入完成\n",i+1);
		i++;
		auto_id++;
		}
	}
}
void hand_input(){
	//吃掉回车 
	getchar();
	printf("请输入收支明细：");
	//输入编码类别 
	scanf("%c%d",&acc[auto_id].codechar,&acc[auto_id].codeint);
	//吃掉空格 
	scanf("%c",&t);
	//year-month-day 
	scanf("%d%c%d%c%d",&acc[auto_id].year,&t,&acc[auto_id].month,&t,&acc[auto_id].day);
	//吃掉空格
	scanf("%c",&t);
	//金额 
	scanf("%lf",&acc[auto_id].money);
	//吃掉空格
	scanf("%c",&t);
	//备注内容
	scanf("%s",acc[auto_id].ps);
	auto_id++; 
	printf("本条成功录入！\n");
	//printf("%c%d %d-%d-%d %.2f %s",acc[0].codechar,acc[0].codeint,acc[0].year,acc[0].month,acc[0].day,acc[0].money,acc[0].ps);
}
//统计函数 
void statis(){
		double get=0,lose=0,sum=0;//get为累计收入，lose为累计支出，sum为累计余额 
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
		printf("累计收入：%.2f,累计支出：%.2f,净收入:%.2f\n",get,lose,sum);
		printf("是否输出该月的各笔明细,是输y，否输n\n");
		char yn;
		scanf("%c",&yn);
		int y,m;
		printf("请输入对收支类别进行汇总的月份\n");
		scanf("%d%c%d",&y,&t,&m);
		if(yn=='y'){
	        sort(acc,acc+auto_id,cmp);
		    printf("收入/支出 明细类别 金额\n");
		    for(int i=0;(i<auto_id)&&acc[i].year==y&&acc[i].month==m;i++){
			    if(acc[i].codechar=='a'){
			      if(acc[i].codeint==1)
		 	  	     printf("收入 生活费 %.2f\n",acc[i].money);
			  	  else if(acc[i].codeint==2)
			   		 printf("收入 奖学金 %.2f\n",acc[i].money);
			      else if(acc[i].codeint==3)
			  	     printf("收入 稿费 %.2f\n",acc[i].money);
			      }else{
				    if(acc[i].codeint==1)
				        printf("支出 学习用品 %.2f\n",acc[i].money);
					if(acc[i].codeint==2)
			        	printf("支出 生活用品 %.2f\n",acc[i].money);
				    if(acc[i].codeint==3)
				        printf("支出 玩具 %.2f\n",acc[i].money);
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
	printf("无法打开文件!请检查是否建立输出文件！\n");
	exit(0);
	}else{
	for(int i=0;i<auto_id;i++){
			fprintf(fp,"%c%d %d-%d-%d %.2f %s\n",acc[i].codechar,acc[i].codeint,acc[i].year,acc[i].month,acc[i].day,acc[i].money,acc[i].ps);
		}
	}
	printf("保存成功!\n");
	fclose(fp);
}
void find(){
	printf("根据日期查找输1(如2020-6-4)，根据类别查找输入2(如a2)\n");
	scanf("%d",&flag);
	if(flag==1){
		int y,m,d;
		printf("请输入要查询的日期(如2020-6-4)\n");
		scanf("%d%c%d%c%d",&y,&t,&m,&t,&d);
		for(int i=0;i<auto_id;i++){
		  if(acc[i].year==y&&acc[i].month==m&&acc[i].day==d)  
	      printf("%c%d %d-%d-%d %.2f %s\n",acc[i].codechar,acc[i].codeint,acc[i].year,acc[i].month,acc[i].day,acc[i].money,acc[i].ps);
		}
	}else if(flag==2){
	   getchar();
	   printf("请输入你要查看的类别(如a2)\n");
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
		printf("                            菜单栏                               \n\n");
		printf("录入账单输1，统计账单输2,查询账单输3,查看所有输4,保存数据输5,终止程序输入0   \n"); 
		scanf("%d",&flag);
		if(flag==1){
			printf("手动输入输1，文件读入输2\n");
			scanf("%d",&flag);
			if(flag==1){
			  int cnt;
			  printf("请输入需要录入的条数\n");
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
			printf("个人收支系统已退出！\n");
			exit(0);
		} 
	}
	return 0;
} 
