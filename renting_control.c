#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char notification[8];
	char tuition[7];
	char kilometres[9];
	char removal[8];
		char delivery[8];
	char fault[99];
	char otv[7];
	char state[9];
} data_renting;

void continu(void);
void menu(void);
void createFile(void);
void loadData(void);
void listData(void);
void dataQuery(void);
void modifyData(void);

int main(void) {
	menu();
	return 0;
}
void continu(void) {
	printf("Press any key for continue: \n");
	getchar();
}

void menu(void) {
	int option;
	do {
	printf(" 1 Create file\n 2 Load data\n 3 List data\n 4 Query data\n 5 Modifi data\n 6 Finish\n");
	scanf("%i",&option);
	switch (option) {
		case 1:
			system("clear"); 
//			createFile();
			break;
		case 2:
			system("clear"); 
			loadData();
			break;
		case 3:
			system("clear"); 
			listData();	
			break;
		case 4:
			system("clear"); 
			dataQuery();
			break;
		case 5:
			system("clear"); 
			modifyData();
			break;
		}	
	} while (option!=6);
}

void createFile(void) {
	FILE *arch;
	arch=fopen("renting_control.dat","wb");
	if (arch==NULL) {
		printf("Opening file to write is NULL");
		exit(1);
	}
	fclose(arch);
	continu();
}

void loadData(void) {
	FILE *arch;
	arch=fopen("renting_control.dat","ab");
	if (arch==NULL) {
		printf("Opening file to load is NULL");
		exit(1);
	}
	data_renting data;
	printf("Notification: ");
	scanf("%s",&data.notification);
	printf("Tuition: ");
	scanf("%s",&data.tuition);
	printf("Kilometres: ");
	scanf("%s",&data.kilometres);
	printf("Removal: ");
	scanf("%s",&data.removal);
	printf("Delivery: ");
	scanf("%s",&data.delivery);
	printf("Fault: ");
	scanf("%s",&data.fault);
	printf("Otv: ");
	scanf("%s",&data.otv);
	printf("State:");
	scanf("%s",&data.state);
	fwrite(&data, sizeof(data_renting), 1, arch);
	fclose(arch);
	continu();
}

void listData(void) {
	FILE *arch;
	arch=fopen("renting_control.dat","rb");
	if (arch==NULL) {
		printf("Openig file for list is NULL");
		exit(1);
	}
	data_renting data;
	fread(&data, sizeof(data_renting), 1, arch);
	while (!feof(arch)) {
		printf("%s\t%s\t%s\t\t%s\t%s\t%s\t\t%s\t%s\n",data.notification,data.tuition,data.kilometres,data.removal,data.delivery,data.fault,data.otv,data.state);
		fread(&data, sizeof(data_renting), 1, arch);
	}
	fclose(arch);
	continu();
}

void dataQuery(void) {
	FILE *arch;
	arch=fopen("renting_control.dat","rb");
	if (arch==NULL) {
		printf("Opening file for query is NULL");
		exit(1);
	}
	char data_query[99];
	int exist=0;
	printf("Enter data to consult: ");
	scanf("%s",&data_query);
	data_renting data;
	fread(&data, sizeof(data_renting), 1, arch);
	while (!feof(arch)) {
		if (strcmp(data_query,data.tuition)==0||strcmp(data_query,data.otv)==0) {
		printf("%s\t%s\t%s\t\t%s\t%s\t%s\t\t%s\t%s\n",data.notification,data.tuition,data.kilometres,data.removal,data.delivery,data.fault,data.otv,data.state);
		exist=1;
		}
		fread(&data, sizeof(data_renting), 1, arch);
	}
	if (exist==0)
		printf("\n\nNO EXIST DATA\n\n");
	fclose(arch);
	continu();
}

void modifyData() {
	FILE *arch;
	arch=fopen("rentin_control.dat","ab");
	if (arch==NULL) {
		printf("Opening file for modify data is NULL");
		exit(1);
	}
	char mdata[99];
	int exist=0;
	data_renting data;
	printf("Enter data to modify: ");
	scanf("%s",&mdata);
	fread(&data, sizeof(data_renting), 1, arch);
	while (!feof(arch)) {
		if (strcmp(data.otv,mdata)==0) {
			printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",data.notification,data.tuition,data.kilometres,data.removal,data.delivery,data.fault,data.otv,data.state);
			exist=1;
			break;
	}
	fread(&data, sizeof(data_renting), 1, arch);
	}
	if (exist==0)
		printf("No exist data");
	fclose(arch);
}
