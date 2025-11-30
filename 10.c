#include <stdio.h>
#include <string.h>

struct menu{    
    char itemname[50];
    float price;
    char category[20];
};

int main(){

    struct menu m[12]= {    

        //starters
        {"samosa" , 40 , "starter"},
        {"idli" , 60 , "starter"},

        // main course
        {"dosa" , 80, "main"},
        { "fried rice", 100 ,"main"},
        {"paneer roll" ,150, "main"},
        {"sandwich", 70 ,"main"},
        {"pasta"  , 120 , "main"},

            // drinks
        {"tea" , 30 ,"drink"},
        {"coffee", 55 , "drink"},
        {"cold drink" , 50,"drink"},

        //extras
        {"water bottle" ,20 , "extra"},
        {"ice cream", 90,"extra"},
    };

    int ch ,qty;
    float total = 0 , discount=0 ,final=0;
//printing menu
    printf(" *** MENU  *** \n");
//printing starters
    printf("\n---  STARTERS ---\n");
for(int i = 0; i<=1 ;i++){
    printf("%d. %-15srupees %.2f\n",i+1, m[i].itemname, m[i].price);}

//prinnting maincourse
printf("\n--- MAINCOURSE---\n");
for(int i=2; i <=6 ; i++){
    printf("%d. %-15s Rs %.2f\n", i+1 , m[i].itemname , m[i].price);}

//printing drinks
printf("\n---- DRINKS ---\n");
for(int i =7 ; i <= 9; i++){
    printf("%d. %-15s Rs %.2f\n", i+1, m[i].itemname , m[i].price) ;
}
 //printing extras
printf("\n--- EXTRAS ---\n");
for(int i = 10; i<= 11; i++){
    printf("%d. %-15s Rs %.2f\n", i+1, m[i].itemname ,m[i].price);
}

        //taking order
    while(1){
        printf("\n enter your choice (type 0 to exit): ");
        scanf("%d"  ,&ch);

        if(ch == 0){        //loop ends if ch =0
            break;}
        

        if(ch<1||ch>12){      //checking if customers choice is valid or not . 
            printf("invalid choice\n");
            continue;
        } 
        //taking input for qty
        printf("quantity: ");
         //calculating total
        scanf("%d" , &qty);

        total=total + (m[ch-1].price *qty);
    }

    if(total>=300){
        discount = total* 0.10; 
    }
       //final bill calculated
    final =total - discount;
//final bill printed with other details and a greeting
    printf("\n ----  BILL ---- \n");
    printf("total amount : %.2f\n" , total);
    printf("discount:   %.2f\n",discount);
    printf("final amount :%.2f\n", final);

    printf("\nthanks! visit again");

    return 0;
}
