#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>


char slots[5][10]={"s1",
"s2",
"s3",
"s4",
"s5"};

char tempslots[5][10]={"s1",
"s2",
"s3",
"s4",
"s5"};



typedef struct times
{
   int id;
   int reserved;
   char name[15];

}times;

times timea[5];


int t(void){

time_t t;
time(&t);
printf("Date and Time : %s",ctime(&t));
return 0;

}

int slotcount = 5;
char empty[1]=" ";


typedef struct patient
{
   int id;
   char name[20];
   int age;
   char gender[20];
   int  reserved;
   char reservation[20];

}patient;

int passcounter=1;

patient patients[100];
int PatientsCount=0;


 int CheckPassword(int password){




     if (password == 1234){
     return 1 ;
     }

     else if (passcounter >= 3){
        printf("Too many wrong attempts closing system");
        Sleep(5000);
        exit(1);
     }
     else{

        passcounter+=1;
        return 0;
     }



}




void AddPatient(){
    char temp[10];
    int i;
    patient p;
    system("cls");
    printf("Enter Patient Name\n");
    scanf("%s",temp);
    strcpy(p.name,temp);
    printf("Enter Patient Age\n");
    scanf("%d",&i);
    p.age=i;
    p.id=PatientsCount;
    printf("Enter Patient Gender\n");
    scanf("%s",temp);
    strcpy(p.gender,temp);
    patients[PatientsCount]=p;
    printf("\nPatient Name : %s\nPatient age : %d\nPatient Gender : %s\n\n",patients[PatientsCount].name,patients[PatientsCount].age,patients[PatientsCount].gender);
    PatientsCount++;




}



void viewpatients(){
int i;
  for(i=0;i<PatientsCount;i++){
                printf("%d\n",patients[i].id);
                printf("%s\n",patients[i].name);
                 printf("%d\n",patients[i].age);
                 printf("%s\n",patients[i].gender);
                 printf("%d\n",patients[i].reserved);
                 printf("%s\n",patients[i].reservation);
                   printf("\n");
                   Sleep(10000);


              }

}

int checkid(int idd){
int i;
for(i=0;i<PatientsCount;i++){
      if(patients[i].id==idd)
               return 1;
}



                       return -1;

}


int checkreservation(int idd){
int i;
for(i=0;i<PatientsCount;i++){
       if(patients[i].id==idd&&patients[i].reserved==1)
               return -1;
}



                       return 1;

}

void EditPatient(){
    char temp[10];
    int id;
    int i;
    int x;
    patient p;
    system("cls");
    printf("Enter patient id\n");
    scanf("%d",&id);


    x = checkid(id);
    while(x==-1){
     printf("wrong id\n");
    printf("Enter valid id\n");
    scanf("%d",&id);
    x=checkid(id);
    }

    for(i=0;i<PatientsCount;i++){
               printf("Enter Patient Name\n");
                scanf("%s",temp);
                strcpy(p.name,temp);
                printf("Enter Patient Age\n");
               scanf("%d",&i);
               p.age=i;
               printf("Enter Patient Gender\n");
                  scanf("%s",temp);
                 strcpy(p.gender,temp);
                    p.id=id;
                   patients[id]=p;


               }


}







void ReserveTime(){

    int i,s,id;
    if(slotcount==0){
        printf("All time slots are reserved");

    }

    else {


        for(i=0;i<5;i++){
                if(timea[i].reserved==0)
        printf("%d %s\n",i+1,timea[i].name);


    }
    printf("\nenter patient id\n");
    scanf("%d",&id);
    int x;
     x = checkid(id);
    while(x==-1){
     printf("wrong id\n");
    printf("Enter valid id\n");
    scanf("%d",&id);
    x=checkid(id);
    }
     x = checkreservation(id);
    while(x==-1){
    printf("patient already has a reservation\n");
    printf("Enter another id\n");
    scanf("%d",&id);
    x=checkreservation(id);
    }
    printf("select time slot\n");
     scanf("%d",&s);
      for(i=0;i<PatientsCount;i++){
               if(patients[i].id==id){
                patients[i].reserved=1;
               strcpy(patients[i].reservation,timea[s-1].name);
               timea[s-1].reserved=1;
                timea[s-1].id=id;


               }

     }



     slotcount--;





    }


}

void CancleTime(){
    int id,i,j;

    printf("enter patient id\n");
    scanf("%d",&id);
     int x;
     x = checkid(id);
    while(x==-1){
     printf("wrong id\n");
    printf("Enter valid id\n");
    scanf("%d",&id);
    x=checkid(id);
    }
    for(i=0;i<=PatientsCount;i++){
               if(patients[i].id==id){
                 patients[i].reserved=0;
                 strcpy(patients[id].reservation,"");



               }


               for(i=0;i<=PatientsCount;i++){
                   for(j=0;j<5;j++){

               if(patients[i].id==timea[j].id){
                 timea[j].reserved=0;



               }
                   }


     }

                 slotcount++;


}}


void ViewPatient(){
    int id,i;
printf("Enter patient ID\n");
scanf("%d",&id);
 int x = checkid(id);
    while(x==-1){
     printf("wrong id\n");
    printf("Enter valid id\n");
    scanf("%d",&id);
    x=checkid(id);
    }
for(i=0;i<PatientsCount;i++){
    if(patients[i].id==id){

        printf("Patient name is %s\n",patients[i].name);
        printf("Patient age is %d\n",patients[i].age);
        printf("Patient gender is %s\n",patients[i].gender);

    }

}

}

void ViewReservation(){

       int id,i,count=0;

for(i=0;i<PatientsCount;i++){
    if(patients[i].reserved==1){
        printf("Patient name is %s\n",patients[i].name);
        printf("Patient age is %d\n",patients[i].age);
        printf("Patient gender is %s\n",patients[i].gender);
        printf("Patient reservation is %s\n",patients[i].reservation);

    }

 else {
    printf("no reservations today");
 }



}



}

void initilize(){



    timea[0].id=1;
    strcpy(timea[0].name,"2 pm to 2:30 pm");
     timea[0].reserved=0;

     timea[1].id=2;
    strcpy(timea[1].name,"2:30 pm to 3 pm");
     timea[1].reserved=0;

     timea[2].id=3;
    strcpy(timea[2].name,"3 pm to 3:30 pm");
     timea[2].reserved=0;

     timea[3].id=4;
    strcpy(timea[3].name,"4 pm to 4:30 pm");
     timea[3].reserved=0;

     timea[4].id=5;
    strcpy(timea[4].name,"4:30 pm to 5 pm");
     timea[4].reserved=0;

}



int main()
{

    int k=0;
initilize();


    int i=0;
    int mode;
    int s;
    int b;
    int y;


    while(1){
    system("cls");
    printf("**************************\n");
    printf("Press 1 for Admine mode\n");
    printf("Press 2 for User mode\n");
    printf("Press 3 to Exite\n");
    printf("**************************\n");
    scanf("%d",&mode);
    k=0;

    if(mode==1){

        system("cls");
        printf("Enter password\n");
        scanf("%d",&b);
        int e = CheckPassword(b);
        while(e==0){
            printf("wrong password\n");
            scanf("%d",&b);
        e = CheckPassword(b);
        }
        if (e == 1){
            passcounter=1;
            printf("welcome");
            Sleep(1000);
            system("cls");

       while(1){
            if(k==1){break;}
            y=0;
        system("cls");
        t();
        printf("**************************\n");
        printf( "1 Add patient");
        printf( "\n2 Edit patient");
        printf( "\n3 Reserve time");
        printf( "\n4 Cancel time ");
        printf( "\n5 Change mode \n");
        printf("**************************\n");
        scanf("%d",&s);
        switch(s){
            case(1):{

                while(y!=2){
                AddPatient();
                printf( "Patient Added !");
                printf( "\n1 Add another");
                printf( "\n2 back\n");
                scanf("%d",&y);



                }
               break;

            }
          case(2):{
                     EditPatient();
                     printf("Patient edited\n");
                     Sleep(2000);

            break;

          }

           case(3):{
                 ReserveTime();
                 printf("\nTime reserved");
                 Sleep(2000);

            break;

          }

           case(4):{

            CancleTime();
            printf("\nTime canceled");
              Sleep(2000);
            break;

           }

           case(5):{

             k=1;
             break;

           }




        }


        }

        }







    }
    if(mode==2){

        system("cls");
        printf("**************************\n");
        printf( "1 View patient record");
        printf( "\n2 View todays reservation");
         printf( "\n3 Change mode \n");
         printf("**************************\n");
        scanf("%d",&s);

            switch(s){
            case(1):{

                while(y!=2){
                ViewPatient();
                printf( "\n1 view another");
                printf( "\n2 return\n");
                scanf("%d",&y);



                }
                y=0;
               break;

            }
          case(2):{
                      while(y!=2){
                     ViewReservation();
                     printf( "\npress 2 to return\n");
                     scanf("%d",&y);}
                     y=0;

            break;
            }

             case(3):{

             k=1;
             break;

           }

          }



    }
    if(mode==3){

        exit(0);
    }

    }


    return 0;
}
