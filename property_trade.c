#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

int end=1,last=0,j,note;
struct flat{
    char code[10];
    char type[10];
    char dimension[20];
    int floor, price;
    char status[10];
    char place[20];

};

struct pass{
    char username[20];
    char password[20];

};

void reg(struct pass p[10]){
    ++end;
    printf("\n\nENTER NEW USERNAME : ");
    scanf("%s",p[end].username);
     printf("\nENTER NEW PASSWORD : ");
    scanf("%s",p[end].password);

    printf("\n\nNEW REGISTRATION SUCCESSFUL, TRY LOGGING-IN ");
    
}

int login(struct pass p[10]){
    char un[20],pw[20];
    int again;
    do
    {
    printf("\n\nENTER USERNAME : ");
    scanf("%s",un);
    printf("\nENTER PASSWORD : ");
    scanf("%s",pw);
    int count=end;
    while(count){
        if(strcmp(p[end].username,un)==0 && strcmp(p[end].password,pw)==0 )
       { 
        printf("\n>>> LOGGED IN AS ");
        printf(" ' %s '\n",un);
        return 0;}
        --count;

    }  


        printf("\n\nINVALID CREDENTIALS !\n");
        printf("\nPRESS 1 TO TRY AGAIN\nPRESS 0 TO NEW REGISTER");
        scanf("%d",&again);
    
    }while(again);
    return 0;
}

void cflat(struct flat f[10]){

    ++last;
    strcpy(f[last].code,"BAN27");
    strcpy(f[last].type,"2BHK");
    strcpy(f[last].dimension,"1,221 sq.ft");
    f[last].floor=7;
    strcpy(f[last].place,"BANGALORE");
    strcpy(f[last].status,"ACTIVE");
    
    int lower = 51, upper = 62;
    srand(time(0));
    f[last].price = (rand() % (upper - lower + 1)) + lower;


 
    ++last;
    strcpy(f[last].code,"CHE38");
    strcpy(f[last].type,"3BHK");
    strcpy(f[last].dimension,"1,430 sq.ft");
    f[last].floor=8;
    strcpy(f[last].place,"CHENNAI");
    strcpy(f[last].status,"ACTIVE");
    
    lower = 63;
    upper = 74;
    srand(time(0));
    f[last].price = (rand() % (upper - lower + 1)) + lower;

    ++last;
    strcpy(f[last].code,"DEL25");
    strcpy(f[last].type,"2BHK");
    strcpy(f[last].dimension,"970 sq.ft");
    f[last].floor=5;
    strcpy(f[last].place,"DELHI");
    strcpy(f[last].status,"ACTIVE");
    
    lower = 52;
    upper = 61;
    srand(time(0));
    f[last].price = (rand() % (upper - lower + 1)) + lower;

    ++last;
    strcpy(f[last].code,"HYD39");
    strcpy(f[last].type,"3BHK");
    strcpy(f[last].dimension,"1,350 sq.ft");
    f[last].floor=9;
    strcpy(f[last].place,"HYDERABAD");
    strcpy(f[last].status,"ACTIVE");
    
    lower = 63;
    upper = 71;
    srand(time(0));
    f[last].price = (rand() % (upper - lower + 1)) + lower;

    ++last;
    strcpy(f[last].code,"MUM36");
    strcpy(f[last].type,"3BHK");
    strcpy(f[last].dimension,"1,244 sq.ft");
    f[last].floor=6;
    strcpy(f[last].place,"MUMBAI");
    strcpy(f[last].status,"ACTIVE");
    
    lower = 59;
    upper = 66;
    srand(time(0));
    f[last].price = (rand() % (upper - lower + 1)) + lower;

    ++last;
    strcpy(f[last].code,"KOL24");
    strcpy(f[last].type,"2BHK");
    strcpy(f[last].dimension,"890 sq.ft");
    f[last].floor=4;
    strcpy(f[last].place,"KOLKOTA");
    strcpy(f[last].status,"ACTIVE");
    
    lower = 47;
    upper = 51;
    srand(time(0));
    f[last].price = (rand() % (upper - lower + 1)) + lower;



}

int dflat(struct flat f[10]){
        printf("\n\n---------------------\n");
        for(j=1;j<=last;++j){
            printf("\nCODE : %s",f[j].code);
            printf("\nSTATUS : %s",f[j].status);
            printf("\nTYPE : %s",f[j].type);
            printf("\nFLOOR : %d",f[j].floor);
            printf("\nDIMENSION : %s",f[j].dimension);
            printf("\nPLACE : %s",f[j].place);
            printf("\nPRICE : Rs %d Lacs",f[j].price);

            printf("\n\n---------------------\n");
}
    return 0;    
        //printf("\n\n---------------------\n");
}
void bill(struct flat f[10],int note);
int pflat(struct flat f[10]){
    char pcode[10];
    printf("\n\t\t||||||------ THIS IS PURCHASING INTERFACE -------||||||\n");
    printf("\nENTER THE PROPERTY CODE : ");
    scanf("%s",pcode);
    char cond[10];
    strcpy(cond,"ACTIVE");
    for(j=1;j<=last;++j){
        if(strcmp(f[j].code,pcode)==0 ){
            if(strcmp(f[j].status,cond)==0){

                printf("\n\n\n\t\t>>>>>>>> !!!! PROPERTY PURCHASE SUCCESSFUL !!!! <<<<<<<<\n");
                strcpy(f[j].status,"INACTIVE");
                note=j;
                bill(f,note);
                return 0;
            }
            else
            {printf("\nTHIS PROPERTY IS !! INACTIVE !!\n");
             return 0;}
        }
        
            
            
        
    }
    printf("\nNO MATCHING PROPERTY FOUND \n");
    return 0;

}

void bill(struct flat f[10],int note){
    printf("\n\n---------- PURCHASED PROPERTY DETAILS ---------- \n");

    printf("\nCODE : %s",f[note].code);
            printf("\nTYPE : %s",f[note].type);
            printf("\nFLOOR : %d",f[note].floor);
            printf("\nDIMENSION : %s",f[note].dimension);
            printf("\nPLACE : %s",f[note].place);

            printf("\n\n\n-------- BILL RECEIPT ----------------\n");
            float base=(float)(f[note].price);
            printf("\n*VERIFIED PURCHASE FROM < SWITCH_ONLINE INDIA >*\n");
            printf("\n\nDATE : %s  \tTIME : %s",__DATE__,__TIME__);
            printf("\n\nBASE PRICE :    INR %.2f lacs", base);
            float gst= (0.12*base);
            printf("\n\nGST (12%%) :     + %.2f lacs",gst );
            float dis=(0.05*base);
            printf("\n\nDISCOUNT (5%%) : - %.2f lacs",dis);
            printf("\n\nTOTAL :         INR %.2f lacs",(base + gst -dis));

            printf("\n\n-------WWW.SWITCH_ONLINE.CO.IN-------\n\n");
}







int main (){
    int i,choice;
    int repeat=0;
    struct pass p[10];
    struct flat f[10];
    strcpy(p[1].username,"dini");
    strcpy(p[1].password,"1234");
    printf("\n\n---***--- WELCOME TO -SWITCH_ONLINE INDIA- SITE ---***---\n");
    printf("\n            SEAMLESS PROPERTY TRADING\n");
do{
    printf("\nLOGIN TO CONTINUE \n\n1-LOGIN\n2-REGISTER\n");
    scanf("%d",&choice);
    switch(choice){
        case 1 :
        login(p);
        break;

        case 2 :
        reg(p);
        break;
    }
    printf("\n\nPRESS 1 TO LOGIN / REGISTER\nPRESS 0 TO CONTINUE ");
    scanf("%d",&repeat);
}while(repeat);

cflat(f);
do{
    printf("\n\n\t-*-*-*- MENU -*-*-*-\n\n\t1-View Flats\n\t2-View Plots\n\t3-Purchase Flats\n\t4-Purchase Plots\n\t5-Logout\n");
    scanf("%d",&choice);
    switch(choice){
        case 1 :
        
        dflat(f);
        break;

       /* case 2 :
        dplot();
        break;*/

        case 3 :
        pflat(f);
        break;

        case 5 :
        printf("\n\n<<< LOGGED-OUT --- \n\nTHANK YOU , VISIT AGAIN !! \nWe are SWICTH_ONLINE INDIA\n\n");
        int exit;
    printf("\n\nPRESS 0 TO EXIT PROGRAM \n ");
    scanf("%d",&exit);
    if(!exit)
    {return 0;}
        //return 0;
    }
    printf("\nPRESS 1 TO MENU\nPRESS 0 TO CLOSE\n");
    scanf("%d",&repeat);
}while(repeat);
     
     printf("\nTHANK YOU , VISIT AGAIN ! \nWe Are SWITCH_ONLINE INDIA \n\n") ;
     int exit;
    printf("\n\nPRESS 0 TO EXIT PROGRAM \n ");
    scanf("%d",&exit);
    if(!exit)
    {return 0;}
    //return 0;
}