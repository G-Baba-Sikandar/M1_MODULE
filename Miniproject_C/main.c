#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <string.h>
void menu(void);
void password(void);
void namefun(void);
void searchfun(void);
void listfun(void);
void modifyfun(void);
void deletefun(void);
void exitfun(void);

int main(){
	system("color C");
	password();
	getch();
}

void namefun(){
	system("cls");
	printf("\n\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB NEW SECTION \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3\n");
	FILE *fptr;
	char name[100];
	char address[100];
	char gmail[100];
	double phone;
	char gender[8];
	fptr=fopen("baba.txt","ab+");//ab+ gives us the ability of writing the function and add the second data in the existing one...
	if(fptr==NULL){
		printf("\nFailed to create the required file.\n");
	}
	else{
		printf("\nName:\t");
		gets(name);
		printf("\nAddress:\t");
		gets(address);
		printf("\nGender:\t");
		gets(gender);
		printf("\nGmail:\t");
		gets(gmail);
		printf("\nPhone Number:\t");
		scanf("%lf",&phone);
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
	}
	fclose(fptr);
	system("cls");
	char ch;
	printf("\nDo you wanna add more datas.Press y for that:\n");
	Sleep(1000);
	fflush(stdin);
	while((ch=getch())=='y'){
		menu();
	}
}

void searchfun(){
	FILE *fptr;
	int flag=0;
	int res;
	char name[100];
	char address[100];
	char gmail[100];
	double phone;
	char gender[8];
	char name1[100];
	system("cls");
	fflush(stdin);
	printf("\n\xDB\xDB\xDB Enter the name of the person you want to see the detail:: \n");
	gets(name1);
	fptr=fopen("baba.txt","r");
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0){
		printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Record Found \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3\n");
		printf("----------------------------------------\n");
		printf("\xB3\xB2\xB2\xB2 Name:\t%s",name);
		printf("\xB3\xB2\xB2\xB2 Address:\t%s",address);
		printf("\xB3\xB2\xB2\xB2 Gender:\t%s",gender);
		printf("\xB3\xB2\xB2\xB2 Gmail:\t%s",gmail);
		printf("\xB3\xB2\xB2\xB2 Phone Number:\t%.0lf",phone);
		printf("----------------------------------------");
		flag=1;
		Sleep(1000);
		printf("Enter y for menu option.\n");
	while(getch()=='y'){
		menu();
	}
	}
}
	if(flag==0){
		system("cls");
		printf("No record found.");;
		printf("Enter a to enter file again or double y key to open menu section:\n");
		if(getch()=='a'){
			system("cls");
			searchfun();
		}

	}


	fclose(fptr);
}
void listfun(){
	FILE *fptr;
	char name[100],address[100],gmail[100],gender[8];
	double phone;
	int f;
	fptr=fopen("baba.txt","r");
	system("cls");
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB LIST SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3\n");
	printf("\n");
	while(fscanf(fptr,"%s %s %s %s %lf",name,address,gender,gmail,&phone)!=EOF){

		printf("------------------------------------------\n");
		printf("Name:%s\n",name);
		printf("Address:%s\n",address);
		printf("Gender:%s\n",gender);
		printf("Gmail:%s\n",gmail);
		printf("Phone:%.0lf\n",phone);
			f=1;
				printf("------------------------------------------");
				printf("\n\n");
		}
		Sleep(1000);
		printf("Enter y for menu section:");
		while(getch()=='y'){
			menu();
		}
			fclose(fptr);
			}



void modifyfun(){
	FILE *fptr,*fptr1;
	char name[100],address[100],gmail[100],gmail1[100],address1[100],name1[100],gender[8],gender1[8];
	int res,f=0;
	double phone,phone1;
	fptr=fopen("baba.txt","r");
	fptr1=fopen("temp.txt","a");
	system("cls");
	printf("Enter the name: ");
	gets(name1);
	system("cls");
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0)
		{
			f=1;
			printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB MODIFY SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3\n");
			printf("Enter the new address:");
			scanf("%s",address1);
			printf("Enter the gender:");
			scanf("%s",gender1);
			printf("Enter the new gmail:");
			scanf("%s",gmail1);
			printf("Enter the new phone number:");
			scanf("%lf",&phone1);
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address1,gender1,gmail1,phone1);

		}else{
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
		}
	}
	if(f==0){
		printf("Record Not found.");
			}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("baba.txt","w");
	fclose(fptr);
	fptr=fopen("baba.txt","a");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);

	}

	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	printf("\n\nPress y for menu option.");
	fflush(stdin);
	if(getch()=='y'){
		menu();
	}
}
void deletefun(){
	FILE *fptr,*fptr1;
	char name[100],address[100],gmail[100],gmail1[100],address1[100],name1[100],gender[8];
	int res,f=0;
	double phone,phone1;
	fptr=fopen("baba.txt","r");
	fptr1=fopen("temp.txt","a");
	system("cls");
	printf("Enter the CONTACT name that you want to delete: ");
	gets(name1);
	system("cls");
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0)
		{
			f=1;
			printf("Record deleted successfully");

		}else{
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
		}
	}
	if(f==0){
		printf("Record Not found.");
			}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("baba.txt","w");
	fclose(fptr);
	fptr=fopen("baba.txt","a");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);

	}

	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	printf("\n\nPress y for menu option.");
	fflush(stdin);
	if(getch()=='y'){
		menu();
	};
}
void exitfun(){
	system("cls");
	printf("\xDB\xDB\xDB\xDB TEAM MEMBERS \xDB\xDB\xDB\xDB");
	printf("\n\xDB RAJESH.");
	printf("\n\xDB BABA.");
	printf("\n\xDB sikandar");
}
void password(void){
	char passwords[20]={"password"};
	int j;
	int z;
	char name[40]="Enter your password";
	z=strlen(name);
	for(j=0;j<=16;j++){
		Sleep(50);
		printf("\xDB");
	}
	for(j=0;j<=z;j++){
		Sleep(60);
		printf(" %c",name[j]);
	}
	for(j=0;j<=16;j++){
		Sleep(50);
		printf("\xDB");
	}
	printf("\nPassword:");
	char ch,pass[20];
	char w='*';
	int i=0;
	while(ch!=13){
		ch=getch();
		if(ch!=13 && ch!=8){
			printf("%c",w);
			pass[i]=ch;
			i++;
		}
			}
	pass[i]='\0';
	if(strcmp(pass,passwords)==0){
		printf("\nCORRECT PASSWORD.");
		Sleep(1000);
		menu();
	}
	else{
		printf("You entered the wrong password.\n");
		Sleep(700);
		system("cls");
		password();
}

}


void menu(){
	system("cls");
	printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PHONEBOOK DIRECTORY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");
	printf("\n\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 1.Add New\n");
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 2.Search\n");
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 3.List\n");
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 4.Modify\n");
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 5.Delete\n");
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 6.Exit\n");
	switch(getch()){
		case '1':
			namefun();
			break;
		case '2':
			searchfun();
			break;
		case '3':
			listfun();
			break;
		case '4':
			modifyfun();
			break;
		case '5':
			deletefun();
			break;
		case '6':
			exitfun();
			break;
		default:
			system("cls");
			printf("Invalid Enter.\n");
			getch();
}
}
