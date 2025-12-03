#include <stdio.h>
#include <string.h>

struct menu {    
    char itemname[50];
    float price;
    char category[20];
};

// fxns prototypes
void printmenu(struct menu m[]);
float takeorder(struct menu m[]);
void printbill(float total);
void savebill(float total);

int main() {

    struct menu m[12] = {    

        //starters
        {"samosa" , 40 , "starter"},
        {"idli" , 60 , "starter"},

        //main course
        {"dosa",80, "main"},
        {"fried rice", 100, "main"},
        {"paneer roll" ,150, "main"},
        {"sandwich" ,70 , "main"},
        {"pasta" , 120,"main"},

        //drinks
        {"tea"  ,30 ,"drink"},
        {"coffee" , 55 ,"drink"},
        {"cold drink" ,50 ,"drink"},

        //extras
        {"water bottle" ,20 , "extra"},
        {"ice cream", 90,"extra"}
    };

    printmenu(m);              
    float total = takeorder(m); 
    printbill(total);    
    savebill(total);    //filehandling function
    return 0; }


//function for printing menu
     void printmenu(struct menu m[]) {

//printing menu
    printf(" ***MENU****\n");

    printf("\nSTARTERS\n");
    for(int i = 0; i <= 1; i++)
    printf("%d. %-15s Rs %.2f\n", i+1, m[i].itemname, m[i].price);

    printf("\nMAIN COURSE\n");
    for(int i=2 ; i<= 6 ;i++)
    printf("%d. %-15s Rs %.2f\n", i+1, m[i].itemname, m[i].price);

    printf("\nDRINKS\n");
    for(int i =7;i<=9 ; i++)
    printf("%d. %-15s Rs %.2f\n", i+1 ,m[i].itemname , m[i].price);

    printf("\nEXTRAS\n");
    for(int i =10 ; i <= 11; i++)
    printf("%d. %-15s Rs %.2f\n", i+1,m[i].itemname , m[i].price);
}

//function for taking order
    float takeorder(struct menu m[]) {
    int ch, qty;
    float total = 0;

    while(1){
        printf("\nEnter your choice (0 to exit): "); //user input
        scanf("%d", &ch);

        if(ch == 0)
            break;

        if(ch<1 || ch>12) { //checking choice
            printf("Invalid choice.\n");
            continue; }
        
         printf("Quantity: ");
        scanf("%d" , &qty);

        total += m[ch-1].price * qty;
        }
    return total;
}

//function for bill printing
    void printbill(float total) {

    float discount = 0;

    if(total>=300)  //discount check
        discount = total*0.10;

    float final = total-discount;
//printing the final bill
    printf("\n---- BILL ----\n");
    printf("Total amount : %.2f\n" , total);
    printf("Discount     : %.2f\n", discount);
    printf("Final amount : %.2f\n", final);

    printf("\nBill saved to bill.txt\n");
    printf("Thanks! Visit again!\n");
}
//file handling function
    void savebill(float total) {

    float discount =0;
    if(total >= 300)
    discount=total * 0.10;

    float final = total -discount; //final amount computed

    FILE *fptr;
    fptr=fopen("bill.txt", "w");   //file opened file in write form

    if(fptr == NULL) {
    printf("file doesnt exist\n");
    return;
    }
//writing into file
    fprintf(fptr, "---- BILL ----\n");
    fprintf(fptr, "Total amount : %.2f\n" ,total);
    fprintf(fptr, "Discount     : %.2f\n" , discount);
    fprintf(fptr, "Final amount : %.2f\n"  , final);
    fprintf(fptr, "\nThank you for visiting!\n");

    fclose(fptr);//file closed
}
