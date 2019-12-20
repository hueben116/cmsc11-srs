#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


struct student{
    int studID;
    char surName[20];
    char firstName[20];
    char csSec[10];
    float hex1;
    float hex2;
    float hex3;
    char sub1[20];
    char sub2[20];
    char sub3[20];
};


//Subject Information
struct subject {
	int subjectCode[70];
	char subject[70][100];
	char title[70][100];
};

struct subject data = {};
int numberOfSubs;

void readSubs();

struct student cmsc11[70];

struct student Add(struct student addition);
struct student Update();
struct student Display();
struct student Read();
struct student Write();
struct student Enroll();
struct student writeSub();
struct subject Sub();
struct subject createSub();
void fileToSubject();
void subjectToFile();
void deleteSubj();
void updateSubs();
void searchsSub();
void tabs1(char word[]);
void tabs2(char word[]);
void tabs3(char word[]);
void tabs4(char word[]);
int i;

void structToFile();
void structToCsv();
void SubjectToCsv();
void searchStudent();
void FileToStruct();
void deleteStudent();
void displayOneStudent(int x);
void alphabetize();
void FiletoStructSubject();
int ToInteger(char st[]);

//To Arrange alphabetically the surnames
int toLower(char ch);
int toUpper(char ch);
char stringCompare(char s1[], char s2[]);


static int sNum = 0;
int numOfdata;
char getFile[50];

int main (void){
 system("COLOR F0");
    int menu;
    int pass, x=10;

	while (x!=0)
	{
    printf("\n\t\t\t\t\t\t__________________________________________________________________________________________________________");
    printf("\n\t\t\t\t\t\t|---------------~~WELCOME TO THE UNVIERSITY OF THE PHILIPPINES STUDENT REGISTRATION SYSTEM~~--------------|");
    printf("\n\t\t\t\t\t\t|_________________________________________________________________________________________________________|");
    printf("\n\n\t\t\t\t\t\tLOGIN\n\n");


    printf("\t\t\t\t\t\t\t\tInput the password: ");
	scanf("%d",&pass);
    fflush(stdin);

    system("cls");


	if (pass==10122019)
	{
        printf("\n\t\t\t\t\t____________________ ");
		printf("\n\t\t\t\t\t| Correct password! |");
        printf("\n\t\t\t\t\t|___________________|");
		x=0;

	 system("cls");
  		printf("\n\n\t\t\t==================================================MENU======================================================\n");
    		printf("\n\n\t\t==================WELCOME TO THE UNIVERSITY OF THE PHILIPPINES STUDENT REGISTRATION SYSTEM==============\n");
    		printf("\t\t\t\t\t\t\t\t\t\t	Press 1. CREATE A STUDENT RECORD\n\t\t\t\
								Press 2. UPDATE A STUDENT RECORD (STUDENT ID)\n\t\t\t\
								Press 3. DISPLAY ALL STUDENT RECORDS\n\t\t\t\
								Press 4. DELETE A STUDENT RECORD\n\t\t\t\
								Press 5. ENROLL\n\t\t\t\
								Press 6. SEARCH STUDENT RECORD\n\t\t\t\
								Press 7. CREATE SUBJECT RECORD\n\t\t\t\
								Press 8. UPDATE SUBJECT RECORD\n\t\t\t\
								Press 9. DISPLAY SUBJECT RECORD\n\t\t\t\
								Press 10. SEARCH SUBJECTS\n\t\t\t\
								Press 11. DELETE SUBJECT\n\t\t\t\
								Press 12. UPDATE SUBJECT\n\t\t\t");
    		printf("\n\t\t==================================================WARNING==================================================\n\t\t\t\t\tAny number outside 1 to 12. Exit\n\t\t===========================================================================================================\n");
    		printf("\t\t\t\t\t\t\tChoose one: ");
    		scanf("%d", &menu);
            fflush(stdin);
      }
    else
    {
       printf("\n\t\t\tWrong password, try another");

	}
	printf("\n");
   }

    while (menu >= 1 && menu <= 12) {
        int choice;
        switch (menu) {

            case 1:
            printf("\n\n\t\t==================================================MENU==================================================\n");
            printf("\n\n\t\t==================WELCOME TO THE UNIVERSITY OF THE PHILIPPINES STUDENT DATABASE SYSTEM==================\n");
            printf("\n\t\t\t\tPress 1. CREATE A STUDENT RECORD THROUGH INPUT\n\t\t\t\tPress 2. CREATE A STUDENT RECORD THROUGH TXT");
            printf("\n\t\t==========================================================================================================\n");
            printf("\t\t\t\t\t\t\tChoose one: ");
            scanf("%d", &choice);
            fflush(stdin);

            if (choice == 1) {
                if (sNum < 70) {
                cmsc11[sNum] = Add(cmsc11[sNum]);
                structToFile();
                alphabetize();
                break;
                } else {
                printf("\n\n\t\t\t\tStudent Directory is Full!");
                }
                break;
            }
            if ( choice == 2) {
                FileToStruct();
                break;
            }
            system("cls");

            break;
        case 2:
            if (sNum==0){
                    printf("\nThere are no Students Enrolled\n\n");
                    break;
                } else {
                    printf("Please enter Student ID No.: ");
                    Update();

                    break;
                }

        case 3:
            if (sNum==0){
                    printf("\nThere are no Students Enrolled\n\n");
                    break;
                } else {
                    Display();
                    break;


                }
		case 4:
		  if (sNum==0){
                    printf("\nThere are no Students Enrolled\n\n");
                    break;
                } else {
                    printf("Please enter Student ID No.: ");
                    deleteStudent();


                    break;
                }

		break;

        case 5:
        Enroll();


        break;

		case 6:
        searchStudent();


		break;

		case 7:
		createSub();
        subjectToFile();

		break;

		case 8:
		//UPDATE SUB
		updateSubs();


		break;

		case 9:
		fileToSubject();


		break;

		case 10:
        //Search Subject
        searchsSub();


		break;

		case 11:
		//Delete Subject
        deleteSubj();

		break;

		case 12:
        updateSubs();

		break;


        }
        if (menu >= 1 && menu <= 12) {
     		printf("\n\n\t\t\t==================================================MENU======================================================\n");
    		printf("\n\n\t\t==================WELCOME TO THE UNIVERSITY OF THE PHILIPPINES STUDENT REGISTRATION SYSTEM==============\n");
    		printf("\t\t\t\t\t\t\t\t\t\t	Press 1. CREATE A STUDENT RECORD\n\t\t\t\
								Press 2. UPDATE A STUDENT RECORD (STUDENT ID)\n\t\t\t\
								Press 3. DISPLAY ALL STUDENT RECORDS\n\t\t\t\
								Press 4. DELETE A STUDENT RECORD\n\t\t\t\
								Press 5. ENROLL\n\t\t\t\
								Press 6. SEARCH STUDENT RECORD\n\t\t\t\
								Press 7. CREATE SUBJECT RECORD\n\t\t\t\
								Press 8. UPDATE SUBJECT RECORD\n\t\t\t\
								Press 9. DISPLAY SUBJECT RECORD\n\t\t\t\
								Press 10. SEARCH SUBJECTS\n\t\t\t\
								Press 11. DELETE SUBJECT\n\t\t\t\
								Press 12. UPDATE SUBJECT\n\t\t\t");
    		printf("\n\t\t==================================================WARNING==================================================\n\t\t\t\t\tAny number outside 1 to 12. Exit\n\t\t===========================================================================================================\n");
    		printf("\t\t\t\t\t\t\tChoose one: ");
    		scanf("%d", &menu);
            fflush(stdin);
        } else {
            menu = 12;
        }

    }
     int choice=0;
     int choice2=0;

    printf("\n\t\tYour files will automatically be saved in the CSV file.\n\t\t Do you want save it also in .txt file? \n\t\tPress 1. Yes \n\t\tPress 2. No\n\n\t\tChoice:");
    scanf("%d",&choice);
    switch(choice){

        case 1:
        structToCsv();
        structToFile();
        printf("Program Terminated.");
        break;

        case 2:
        structToCsv();
        printf("\n\t\tAre you sure of you don't want it save on a .txt file? The program will then be terminated. \n\t\tPress 1. Yes \n\t\tPress 2. No\n\n\t\tChoice:");
        scanf("%d",&choice2);

        if(choice2=1){
            structToFile();
        }else {
            break;
        }


        break;




    printf("\n================================================================================================================================================");
    printf("\n==================================================================WARNING=======================================================================");
    printf("\n============================================================PROGRAM TERMINATED==================================================================");
    printf("\n================================================================================================================================================\n\n");


    }
    return 0;
}

struct student Add(struct student addition){

    printf("Enter Surname: ");
    scanf(" %19[^\n]s", &addition.surName);
    printf("Enter First Name: ");
    scanf(" %19[^\n]s", &addition.firstName);
    printf("Enter CMSC section: ");
    scanf(" %19[^\n]s", &addition.csSec);
    printf("Enter score for hex1: ");
    scanf(" %f", &addition.hex1);
    printf("Enter score for hex2: ");
    scanf(" %f", &addition.hex2);
    printf("Enter score for hex3: ");
    scanf(" %f", &addition.hex3);
    printf("Enter name for subject 2: ");
    scanf(" %s", &addition.sub2);
    printf("Enter name for subject 3: ");
    scanf(" %s", &addition.sub3);
    printf("\n");

    fflush(stdin);

    sNum++;
    addition.studID = sNum;

    alphabetize();

    return addition;
};


struct student Update(){
    int sIDN, found = 0, choice = 1, i;
    FILE *fp1, *fp2;

    fp1 = fopen("database.txt","r+");


    scanf(" %d", &sIDN);

    for (i = 0; cmsc11[i].studID!=0; i++){
        if( sIDN == cmsc11[i].studID) {

            printf("Found!\n");
            found = 1;
            break;
        } else {
            printf("Student ID Number does not exist.");
            scanf(" %d", &sIDN);
        }
    }

    if (found == 1){
        while (choice>=1 && choice<=7){
            int updateInt = 0;
            float updateFlt = 0;

            printf("\n================================================================================================================================================");
            printf("\n\tStudent ID: \t\t%d",cmsc11[i].studID);
            printf("\n\tName: \t\t\t%s, %s", cmsc11[i].surName, cmsc11[i].firstName);
            printf("\n\tCMSC11 Section: \t%s", cmsc11[i].csSec);
            printf("\n\tHex 1: \t\t\t%.2f", cmsc11[i].hex1);
            printf("\n\tHex 2: \t\t\t%.2f", cmsc11[i].hex2);
            printf("\n\tHex 3: \t\t\t%.2f\n\n", cmsc11[i].hex3);
            printf("\n\tSubject 2: \t\t\t%s", cmsc11[i].sub2);
            printf("\n\tSubject 3: \t\t\t%s\n\n", cmsc11[i].sub3);
            printf("What do you want to update? Please choose from the choices (1-8) Enter [0] to go back to the Menu: \n\n1. Surname\n\n2. First Name\n\n3. CMSC11 Section\n\n4. Hex 1 Score\n\n5. Hex 2 Score\n\n6. Hex 3 Score\n\n7. Subject 2\n\n8. Subject 3\n[INPUT]: ");
            scanf(" %d", &choice);
            fflush(stdin);
            printf("\n================================================================================================================================================\nEdit:");

            switch (choice){
            case 1:
                scanf(" %49[^\n]s",&cmsc11[i].surName);
                break;

            case 2:
                scanf(" %49[^\n]s",&cmsc11[i].firstName);
                break;

            case 3:
                scanf(" %49[^\n]s",&cmsc11[i].csSec);
                break;

            case 4:
                scanf(" %f",&updateFlt);
                cmsc11[i].hex1 = updateFlt;
                break;

            case 5:
                scanf(" %f",&updateFlt);
                cmsc11[i].hex2 = updateFlt;
                break;

            case 6:
                scanf(" %f",&updateFlt);
                cmsc11[i].hex3 = updateFlt;
                break;
			case 7:
				scanf(" %49[^\n]s",&cmsc11[i].sub2);
				break;
			case 8:
				 scanf(" %49[^\n]s",&cmsc11[i].sub3);
				 break;





            }

        }
        }
        else {
        printf("\n================================================================================================================================================");
        printf("\nNo Records.\n");
        printf("\n================================================================================================================================================");
        }
        printf("\nEXIT\n\n");
};

struct student Display(){
    float sum1=0, sumhex1= 0,sumhex2= 0,sumhex3= 0, counter = 0, var1 = 0, var2 = 0, var3 = 0, sdhex1 = 0, sdhex2 = 0, sdhex3 = 0, sdhextotal = 0, total = 0, array[70], max1 = 0, max2 =0, max3 = 0, min1, min2, min3;
    printf("%d", cmsc11[0].studID);
        printf("\n\t=====================================================================================================================================================");
         printf("\n\tStudent ID:  \t\tLast Name,  First Name:  CMSC11 Section:  Subject 1:  Subject2:  Subject3:  Score 1:  Score 2: Score 3:  Total Score: \tGrade:  ");
        min1 = cmsc11[0].hex1;
        min2 = cmsc11[0].hex2;
        min3 = cmsc11[0].hex3;
    int i;
	for (i=0; i<sNum; i++){
        sum1=cmsc11[i].hex1+cmsc11[i].hex2+cmsc11[i].hex3;
        sumhex1+=cmsc11[i].hex1;
        sumhex2+=cmsc11[i].hex2;
        sumhex3+=cmsc11[i].hex3;
        counter++;
        printf("\n\n%03d\t", cmsc11[i].studID);
        printf("%s,", cmsc11[i].surName);
        tabs1(cmsc11[i].surName);
        printf(" %s", cmsc11[i].firstName);
        tabs2(cmsc11[i].firstName);
        printf("\t%s", cmsc11[i].csSec);
        tabs1(cmsc11[i].csSec);
        printf("%s\t", cmsc11[i].sub1);
        printf("%s", cmsc11[i].sub2);
        tabs3(cmsc11[i].sub2);
        printf("%s", cmsc11[i].sub3);
        printf("%.2f\t", cmsc11[i].hex1);
        printf("%.2f\t", cmsc11[i].hex2);
        printf("%.2f\t", cmsc11[i].hex3);
        printf("%.2f", sum1);


        if(sum1 > 135){
            printf("\tHD");
        }else if(sum1<=134 && sum1>=120){
            printf("\tD");
        }else if(sum1<=100 && sum1>=119){
            printf("\tP");
        }else if(sum1<=75 && sum1>=99){
            printf("\tC");
        }else if(sum1<=74){
            printf("\tF");
        }
        total+= sum1;
		array[i] = sum1;


        if (cmsc11[i].hex1 > max1) {
            max1 = cmsc11[i].hex1;
        }
        if (cmsc11[i].hex2 > max2) {
            max2 = cmsc11[i].hex2;
        }
        if (cmsc11[i].hex3 > max3) {
            max3 = cmsc11[i].hex3;
        }
        if (cmsc11[i].hex1 < min1 ) {
            min1 = cmsc11[i].hex1;
        }
        if (cmsc11[i].hex2 < min2) {
            min2 = cmsc11[i].hex2;
        }
        if (cmsc11[i].hex3 < min3) {
            min3 = cmsc11[i].hex3;
        }
    }

    float averagehex1 = 0, averagehex2 = 0, averagehex3 = 0, averagetotal = 0, vartotal = 0, maxtotal = 0, mintotal;
    averagehex1 = sumhex1/sNum;
    averagehex2 = sumhex2/sNum;
    averagehex3 = sumhex3/sNum;
    averagetotal = total/sNum;
    mintotal = array[0];

    for (i=0; i<sNum; i++){
        if (array[i] > maxtotal) {
            maxtotal = array[i];
        }
        if (array[i] < mintotal ) {
            mintotal = array[i];
        }
        var1+= (cmsc11[i].hex1-(averagehex1))*(cmsc11[i].hex1-(averagehex1));
        var2+= (cmsc11[i].hex2-(averagehex2))*(cmsc11[i].hex2-(averagehex2));
        var3+= (cmsc11[i].hex3-(averagehex3))*(cmsc11[i].hex3-(averagehex3));
        vartotal += (array[i]-(averagetotal))*(array[i]-(averagetotal));

    }

        sdhex1 = sqrt(var1/sNum);
        sdhex2 = sqrt(var2/sNum);
        sdhex3 = sqrt(var3/sNum);
		sdhextotal = sqrt(vartotal/sNum);

        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tLowest: \t%.2f", min1);
        printf("\t\t%.2f", min2);
        printf("\t\t%.2f", min3);
        printf("\t\t%.2f", mintotal);
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tHighest: \t%.2f", max1);
        printf("\t\t%.2f", max2);
        printf("\t\t%.2f", max3);
        printf("\t\t%.2f", maxtotal);
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tAverage: \t%.2f", averagehex1);
        printf("\t\t%.2f", averagehex2);
        printf("\t\t%.2f", averagehex3);
        printf("\t\t%.2f", averagetotal);
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tSD: \t\t%.2f", sdhex1);
        printf("\t\t%.2f", sdhex2);
        printf("\t\t%.2f", sdhex3);
		printf("\t\t%.2f", sdhextotal);

        printf("\n\t================================================================================================================================================");

};

struct student Read(){

FILE *fPointer;
int i=0;

fPointer=fopen("database.txt","r+");
printf("\nStudent ID:\t\tLast Name, First Name:\t\tCMSC11 Section\t\tSubject 1:\tSubject2:\tSubject3:\tScore 1:\tScore 2:\tScore 3:");

numOfdata = 0;
while(!feof(fPointer)){

fscanf(fPointer,"%d,%[^,],%[^,],%[^,],%d,%d,%d,%[^,]s,%[^,]s,%[^\n]s",&cmsc11[i].studID,&cmsc11[i].firstName[20],&cmsc11[i].surName[20],&cmsc11[i].csSec,//
&cmsc11[i].hex1,&cmsc11[i].hex2,&cmsc11[i].hex3,&cmsc11[i].sub1,&cmsc11[i].sub2,&cmsc11[i].sub3);

numOfdata++;

printf("%d",cmsc11[i].studID);
printf("%s",cmsc11[i].firstName);
printf("%s",cmsc11[i].surName);
printf("%s",cmsc11[i].csSec);
printf("%s",cmsc11[i].sub1);
printf("%s",cmsc11[i].sub2);
printf("%s",cmsc11[i].sub3);
printf("%d",cmsc11[i].hex1);
printf("%d",cmsc11[i].hex2);
printf("%d",cmsc11[i].hex3);


i++;
}

fclose(fPointer);
alphabetize();


};

int toLower(char ch) {
	if(ch >= 'A' && ch <= 'Z') {
		ch = ch + 32;
	}
	return ch;
}

int toUpper(char ch) {
	if(ch >= 'a' && ch <= 'z') {
		ch = ch - 32;
	}
	return ch;
}

char stringCompare(char s1[], char s2[]) {
int i;
	for(i=0;s1[i]!='\0';i++) {
		if(i==0){
			s1[i] = toUpper(s1[i]);
			s2[i] = toUpper(s2[i]);
		}

		if(i!=0){
			s1[i] = toLower(s1[i]);
			s2[i] = toLower(s2[i]);
		}
	}

i = 0;
	while(s1[i]==s2[i] && s1[i]!='\0' && s2[i]!='\0'){
		i++;
	}
	if (s1[i]>s2[i]) {
		return 1;
	} else if (s1[i]<s2[i]) {
		return -1;
	} else if (s1[i]==s2[i]) {
		return 0;
	}
}
struct student Enroll() {
	Sub();
	int i, numID, input;
	int IDfound1=-1, IDfound2=-1;
	int subChoice;
	bool x = true;
	char test[100] = {};
		while(x) {
			printf("Input ID Number of Student: ");
			scanf("%d", &numID);
				for(i=0;i<numOfdata;i++) {
					if(numID==cmsc11[i].studID) {
						IDfound1 = i;
						break;
					} else {
						IDfound1 = -1;
					}
				}
				if(IDfound1 == -1) {
					printf("\nID Number of Student does not Exist\n");
				}
			printf("Input ID Number of Subject: ");
			scanf("%d", &input);
				for(i=0;i<numOfdata;i++) {
					if(input==data.subjectCode[i]) {
						IDfound2 = i;
						sprintf(test, "%s", data.subject[i]);
						break;
					} else {
					IDfound2 = -1;
					}
				}
				if(IDfound2 == -1) {
					printf("\nID Number of Subject does not Exist\n");
				}
			printf("Subject to Replace:\nType 2 for [sub2] = %s\nType 3 for [sub3] = %s\n[Input]: ", cmsc11[IDfound1].sub2, cmsc11[IDfound1].sub3);
			scanf("%d", &subChoice);
			char *ptr1, *ptr2;
			ptr1 = cmsc11[IDfound1].sub2;
			ptr2 = cmsc11[IDfound1].sub3;
				if(subChoice==2) {
					sprintf(ptr1, "%s", data.subject[i]);
					printf("\nReplaced with %s\n",ptr1);
					break;
				} else if (subChoice==3) {
					sprintf(ptr2, "%s", data.subject[i]);
					printf("\nReplaced with %s\n",ptr2);
					break;
				} else {
					printf("\n[INVALID]\n");
				}
			printf("\n\t================================================================================================================================================");
		}
}
struct subject Sub() {
	char *fp1;
	char *fp2;
	int *fp3;
	int i;
	numberOfSubs=0;
		for( i=0; data.subjectCode[i] > 9; i++) {
			numberOfSubs++;
			fp1 = data.subject[i];
			fp2 = data.title[i];
			fp3 = &data.subjectCode[i];
			printf("\tSubject: %s", fp1);
			printf("\t\tSubject ID: %d", *fp3);
			printf("\t\tSubject Title: %s\n", fp2);
	}
	printf("\n\t================================================================================================================================================");
}
struct subject createSub(){
	char add[100];
	char addTitle[100];
	int subID;
	int i;
	int id = 1+numberOfSubs;
	int subss;
	data.subjectCode[numberOfSubs]=id;
	int choice;

	printf("INPUT MANUALLY OR INPUT FROM FILE\n");
	printf("Press 1: INPUT MANUALLY\nPress 2: INPUT FROM FILE\n");
	printf("Choice: ");
	scanf("%d",&choice);
    fflush(stdin);

	switch(choice){

	case 1:
        printf("Subject Code to Add: ");
        scanf(" %[^\n]", data.subject[numberOfSubs]);
        printf("Subject Title to Add: ");
        scanf(" %[^\n]", data.title[numberOfSubs]);
        subjectToFile();
        printf("\n\t================================================================================================================================================");
        break;
	case 2:
		FiletoStructSubject();
		break;
}
}

void structToFile(){
    int i;
    FILE *fPointer, *fPointer2;
    //fpointer reads the file with r+
    fPointer = fopen("database.txt","r+");
    //fpointer2 makes the file with w+
    fPointer2 = fopen("add.txt","w+");
    fclose(fPointer);
    fclose(fPointer2);
    //closes the file
    rename("temp.txt","database.txt");

    //a+ edits the file, you can add on it.
    fPointer=fopen("database.txt", "a+");

    for(i=0;i<numOfdata;i++) {
        char array1[100]={};
        char input[100]={};

        sprintf(input, "%d", cmsc11[i].studID);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].surName);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].firstName);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].csSec);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].sub1);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].sub2);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].sub3);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%f", cmsc11[i].hex1);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%f", cmsc11[i].hex2);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%f", cmsc11[i].hex3);
			strcat(array1,input);
				if(i==0) {
					fprintf(fPointer, "%s", array1);
				} else {
					fprintf(fPointer, "\n%s", array1);
				}
		}
	fclose(fPointer);


    };
    void structToCsv(){
    int i;
    FILE *fPointer, *fPointer2;
    //fpointer reads the file with r+
    fPointer = fopen("database.csv.","r+");
    //fpointer2 makes the file with w+
    fPointer2 = fopen("add.csv","w+");
    fclose(fPointer);
    fclose(fPointer2);
    //closes the file

    remove("database.csv");
    rename("temp.txt","database.csv");

    //a+ edits the file, you can add on it.
    fPointer=fopen("database.csv", "a+");

    for(i=0;i<numOfdata;i++) {
        char array1[100]={};
        char input[100]={};

        sprintf(input, "%d", cmsc11[i].studID);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].surName);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].firstName);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].csSec);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].sub1);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].sub2);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].sub3);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%f", cmsc11[i].hex1);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%f", cmsc11[i].hex2);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%f", cmsc11[i].hex3);
			strcat(array1,input);
				if(i==0) {
					fprintf(fPointer, "%s", array1);
				} else {
					fprintf(fPointer, "\n%s", array1);
				}
		}
	fclose(fPointer);
    };

    void AtoZ(){
int d;
		for(d=0;d<numOfdata;d++) {
			char x, z;
			int i = 0, y = 0;

		for(;i<numOfdata-1;i++) {
			if(stringCompare(cmsc11[i].firstName, cmsc11[i+1].surName)==1) {
				cmsc11[i] = cmsc11[i+1];
				cmsc11[i+1] = cmsc11[i];
			}
		}
		}
};

void searchStudent(){
    int check=0;
	char lastN[20];
    int i;

    printf("Input Last Name: ");
    scanf(" %s",lastN);

    for(i=0;i<numOfdata;i++){
        if(stringCompare(lastN,cmsc11[i].surName)==0){

               displayOneStudent(i);

        } else {
            ++check;
        }

        if(check == numOfdata){
            printf("Not found.");
        }

		printf("\n\t================================================================================================================================================");
    }
}

struct student writeSub(){

	FILE *fp;
	fp = fopen("database.txt", "w+");
	printf("Input Subject Code: ");
	scanf("%d", &data.subjectCode);



	printf("Input name of Subject: ");
	scanf("%s", &data.subject);

	printf("Input title: ");
	scanf("%s",&data.title);



}

void FileToStruct(){
    FILE *fpointer,*pointer2;
    char getFile[50];

    printf("Input the file name: ");
    scanf(" %[^\n]s", &getFile);
	fpointer = fopen(getFile,"r+");
	fclose(fpointer);
    fpointer = fopen(getFile,"a+");
	numOfdata=0;
	int i=0;

   if(fpointer == NULL){
       printf("Invalid");
   }
		do{

		    fscanf(fpointer," %d, %[^,], %[^,], %[^,], %f, %f, %f, %[^,], %[^,], %[^\n]\n",&cmsc11[sNum].studID,&cmsc11[sNum].surName,&cmsc11[sNum].firstName,&cmsc11[sNum].csSec,&cmsc11[sNum].hex1,&cmsc11[sNum].hex2,&cmsc11[sNum].hex3,&cmsc11[sNum].sub1,&cmsc11[sNum].sub2,&cmsc11[sNum].sub3);

            if(cmsc11[sNum].studID == 0){
                break;
            }
            numOfdata++;
            sNum++;

		}while (cmsc11[sNum-1].studID != 0);

         printf("\nTotal number of students enrolled = [%d]\n\n", numOfdata);


	fclose(fpointer);

	alphabetize();

}
void deleteStudent(){
    int sIDN, found = 0, choice = 1, i, j;

    scanf("%d", &sIDN);
    fflush(stdin);

    for (i = 0; i < sNum; i++){
        if( sIDN == cmsc11[i].studID) {

            printf("Found!\n");
            found = 1;
            for (j = i; j < sNum; j++) {
               cmsc11[j] = cmsc11[j+1];
            }
            sNum--;
            break;
        }
    }
}
void displayOneStudent(int x){

    int sum1 = cmsc11[x].hex1+cmsc11[x].hex2+cmsc11[x].hex3;

     printf("\n\n%03d", cmsc11[x].studID);
        printf("\t\t\t%s,%s", cmsc11[x].surName, cmsc11[x].firstName);
        printf("\t\t\t%s", cmsc11[x].csSec);
        printf("\t\t%s", cmsc11[x].sub1);
        printf("\t\t%s", cmsc11[x].sub2);
        printf("\t\t%s", cmsc11[x].sub3);
        printf("\t\t%.3f", cmsc11[x].hex1);
        printf("\t\t%.3f", cmsc11[x].hex2);
        printf("\t\t%.3f", cmsc11[x].hex3);
        printf("\t\t%.3f", sum1);

}

void readSubs() {
	int i;
	int checker=0;
	FILE *p1,*p2;
	p1 = fopen("file1.txt", "r+");
	p2 = fopen("temp.txt", "w+");
	fclose(p1);
    fclose(p2);
	remove("file1.txt");
    rename("temp.txt", "file1.txt");
	p1 = fopen("file1.txt", "a+");
		for(i=0;i<=numberOfSubs;i++) {
		if(cmsc11[i].studID!=0) {
				if(i==0) {
					fprintf(p1, "%d, %s, %s",
													data.subjectCode[i],
													data.subject[i],
													data.title[i]
													);
				} else {
					fprintf(p1, "\n%d, %s, %s",
													data.subjectCode[i],
													data.subject[i],
													data.title[i]
													);
				}
		}
	}
	fclose(p1);
}

//Function to Read the Existing Subjects Information
void fileToSubject() {
	FILE *fPointer;
	fPointer = fopen("file1.txt", "r+");
	int i=0;
	printf("ID\tSUBJECT\t\tTITLE\n");
	numberOfSubs=0;
        while(!feof(fPointer)) {
			numberOfSubs++;
			fscanf(fPointer, "%d, %[^,], %[^\n]", &data.subjectCode[i],data.subject[i],data.title[i]);
			printf("[%d]\t", data.subjectCode[i]);
			printf("[%s]", data.subject[i]);
			tabs1(data.subject[i]);
			printf("[%s]", data.title[i]);
			printf("\n");
			i++;
		}
	printf("\nTotal number of Subjects = [%d]\n", numberOfSubs);
	fclose(fPointer);
}

void searchsSub() {
	int idNumber, i;
	int error=1;
	while(error==1) {
	printf("Input ID Number of Subject: ");
	scanf("%d", &idNumber);
		for(i=0;i<=numberOfSubs;i++) {
			if(idNumber==data.subjectCode[i]) {
				system("cls");
				printf("Subject Code\tSubject ID\tSubject Title\n");
				printf("[%d]\t\t", data.subjectCode[i]);
				printf("[%s]", data.subject[i]);
				tabs1(data.subject[i]);
				printf("[%s]\n\n", data.title[i]);
				system("pause");
				error=2;
				break;
			} else if(i==numberOfSubs) {
				system("cls");
				printf("\nID Number of Subject does not Exist\n");

				printf("1. [Continue]\t 2. [Back to Menu]\n Choice: ");
				scanf("%d", &error);
					if(error!=1) {
						system("cls");
						break;
					} else {
						printf("Input ID Number of Subject: ");
						scanf("%d", &idNumber);
					}
			}
		}
	}
}

void updateSubs() {
	int idExist;
	int idNumber, i;
	FILE *fPointer,*pointer2;
	fPointer = fopen("file1.txt", "r+");
		while(idExist==0) {
			printf("Input ID number of Subject: ");
			scanf("%d", &idNumber);
			idExist=0;
				for(i=0;i<numberOfSubs;i++) {
					if(i>numberOfSubs && idNumber!=data.subjectCode[i]) {
						printf("ID Number does not Exist");
						idExist = 0;
					} else if(idNumber==data.subjectCode[i]) {
						idExist = i;
						printf("SUBJECT ID\tSUBJECT CODE\t\tSUBJECT TITLE\n");
						printf("[%d]\t", data.subjectCode[i]);
						printf("[%s]", data.subject[i]);
						tabs1(data.subject[i]);
						printf("[%s]\n", data.title[i]);
						break;
					}
				}
		}
	idNumber=1+idExist;
	char cha[100]={};
	char userInput[50]={};
	sprintf(userInput, "%d", idNumber);
	strcat(cha,userInput);
	strcat(cha,",");
	printf("\nInput Subject Code Name: ");
	scanf(" %[^\n]", userInput);
	strcat(cha,userInput);
	strcat(cha,",");
	printf("\nInput Subject Title Name: ");
	scanf(" %[^\n]", userInput);
	strcat(cha,userInput);

	int counter=0;
	char str[100];
	pointer2 = fopen("temp.txt", "w+");
    	while (!feof(fPointer)) {
        	fgets(str, 100, fPointer);
				if(counter!=idExist) {
					fprintf(pointer2, "%s", str);
				} else if(counter==idExist&&counter==numberOfSubs){
					fprintf(pointer2, "%s\n", cha);
			  	 }
       		counter++;
       	}
	fclose(fPointer);
	fclose(pointer2);
	remove("file1.txt");
	rename("temp.txt", "file1.txt");
	fileToSubject();
}

void tabs1(char word[]) {
	int counter=0;
		while(word[counter]!='\0') {
			counter++;
		}
		if(counter<10) {
			printf("\t");
		}
		if(counter<=5) {
			printf("\t");
		}
		if(counter<14&&counter>=10) {
			printf("\t");
		}
}

void tabs2(char word[]) {
	int counter=0;
		while(word[counter]!='\0') {
			counter++;
		}
		if(counter<10) {
			printf("\t");
		}
		if(counter<=5) {
			printf("\t");
		}
		if(counter<14&&counter>=10) {
			printf("\t");
		}
		if(counter<24) {
			printf("\t");
		}
}

void tabs3(char word[]) {
	int counter=0;
		while(word[counter]!='\0') {
			counter++;
		}
		if(counter<=8) {
			printf("\t");
		}
		if(counter<6) {
			printf("\t");
		}
}

void tabs4(char word[]) {
	int counter=0;
		while(word[counter]!='\0') {
			counter++;
		}
		if(counter<=8) {
			printf("\t");
		}
		if(counter<=6) {
			printf("\t");
		}
}

//Function to delete subject
void deleteSubj() {
		//int idExist=-1;
	//int idNumber, i;
	FILE *fPointer,*pointer2;
	char getFile[40];
	char ch;
    int delete_sub;
    int n = 1;

	printf("Enter name of file: ");
	scanf("%s", getFile);
    fPointer = fopen(getFile, "r");
    ch = getc(fPointer);
   while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fPointer);
    }
    printf("\nEnter Subject ID to be deleted: ");
    scanf("%d", &delete_sub);
    pointer2 = fopen("temp.txt", "w");
    ch = 'A';
    if (n == 1){
        printf("CMSC11 cannot be deleted");
    }else{
        while (ch != EOF){
        ch = getc(fPointer);
        }if (n != delete_sub){
            putc(ch, pointer2);
        }
    }
    fclose(fPointer);
    fclose(pointer2);
    remove(getFile);
    rename("temp.txt", getFile);
    fPointer = fopen(getFile, "r");
    fclose(fPointer);
}

//subject to file
void subjectToFile() {
	int i;
	int checker=0;
	FILE *p1,*p2;
	p1 = fopen(getFile, "r+");
	p2 = fopen("temp.txt", "w+");
	fclose(p1);
    fclose(p2);
	p1 = fopen(getFile, "a+");
		for(i=0;i<=numberOfSubs;i++) {
		if(cmsc11[i].studID!=0) {
				if(i==0) {
					fprintf(p1, "%d, %s, %s",
													data.subjectCode[i],
													data.subject[i],
													data.title[i]
													);
				} else {
					fprintf(p1, "\n%d, %s, %s",
													data.subjectCode[i],
													data.subject[i],
													data.title[i]
													);
				}
		}
	}
	fclose(p1);
}

	void alphabetize() {
int d;
struct student p1={};
		for(d=0;d<numOfdata;d++) {
			char x, z;
			int i = 0, y = 0;

		for(;i<numOfdata-1;i++) {
			if(stringCompare(cmsc11[i].surName, cmsc11[i+1].surName)==1) {

				p1 = cmsc11[i];
				cmsc11[i] = cmsc11[i+1];
				cmsc11[i+1] = p1;
			}
		}
		}
		structToFile();
}

void FiletoStructSubject(){
	char getFiles[50];
    printf("Input the file name: ");
    fgets(getFiles, 50, stdin);
    getFiles[strcspn(getFiles, "\n")] = 0;
    printf("%s\n", getFiles);
	fflush(stdin);
    FILE *fptr = fopen(getFiles, "r");
	numOfdata=0;
	int i=0;
	char temp[10];
	if(fptr == NULL){
		printf("File not found!\n");
	}
		while(!feof(fptr)) {
           fscanf(fptr, "\n%[^,],%[^,],%[^\n]",&temp,&data.subject[numberOfSubs],&data.title[numberOfSubs]);
           data.subjectCode[numberOfSubs] = ToInteger(temp);
                    numberOfSubs++;
                   
				   if(feof(fptr)){
					   	break;
				   }
		}
	fclose(fptr);

	alphabetize();

}
void SubjectToCsv(){
	 int i;
    FILE *fPointer, *fPointer2;
    fPointer = fopen("subdata.csv.","r+");

    fPointer2 = fopen("add.csv","w+");
    fclose(fPointer);
    fclose(fPointer2);

    fPointer=fopen("subdata.csv", "a+");

    for(i=0;i<numOfdata;i++) {
        char array1[100]={};
        char input[100]={};

        sprintf(input, "%d", cmsc11[i].studID);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].surName);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].firstName);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].csSec);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].sub1);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].sub2);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", cmsc11[i].sub3);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%f", cmsc11[i].hex1);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%f", cmsc11[i].hex2);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%f", cmsc11[i].hex3);
			strcat(array1,input);
				if(i==0) {
					fprintf(fPointer, "%s", array1);
				} else {
					fprintf(fPointer, "\n%s", array1);
				}
		}
	fclose(fPointer);
}

int ToInteger(char st[]){
    int i = 0, integer = 0, sign = 1;
    if (st[0] == '-'){
        i = 1;
        sign = -1;
    }
    for (i = i; st[i] != 00; i++){
        integer = integer * 10 + st[i] - 48;
    }
    return(integer*sign);
};