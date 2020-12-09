
#include<stdio.h>
#include<stdlib.h>


/// Node Area
typedef struct user Node;
struct user{
    char name[50];
    char mail[50];
    int mobile_no;
    int acount_no;
    float amount;
    Node *next;

};
Node *Top;
/// Node Area end



/// function prototype area start
    void push();
    void print();
    int cash_in();
    int cash_out();
    void pop();
    int userCount();
    void sortedById(Node** head);
    Node* swap(Node* ptr1,Node* ptr2);
    void searchData();
    void updateInfo(Node *top);
/// function prototype end area



/// Data Push Function Area Start
void push(){
    Node* newNode = (Node *) malloc(sizeof(Node));

    printf("\n Enter User Account No   : ");
    scanf("%d",&newNode->acount_no);

    Node *temp = Top;
    while(temp != NULL){
        int same = newNode->acount_no;
        if(same == temp->acount_no || same == Top->acount_no){

            printf("\n\t Account Number Already Created ..!! \n");
            printf("\t Please Try Again !!\n");
            return ;
        }

        temp = temp->next;

    }

    printf(" Enter User Name         : ");
    scanf("%*c%[^\n]",newNode->name);
    printf(" Enter User Mail         : ");
    scanf("%*c%[^\n]",newNode->mail);
    printf(" Enter User Mobile No    : ");
    scanf("%d",&newNode->mobile_no);
    printf(" Add Money Creating time : ");
    scanf("%f",&newNode->amount);

    newNode->next = NULL;
    newNode->next = Top;
    Top = newNode;

    printf("\n New Account Created Successfully !!\n");


}
/// Data Push Function End Area



/// Pop Function Start
void pop(){

    int item;
    Node *temp;
    item = Top->acount_no;
    temp = Top;
    Top = Top->next;
    free(temp);
    printf("\n Account Delete Successfully !!\n");
}
/// Pop Function End



/// Any Node Delete Area Start

void findPosition(){
    Node *temp = Top;
    int i=1;
    printf("\n");
    while(temp != NULL){

        printf("\t Account No : %d \t For Delete Position : %d\n",temp->acount_no,i++);

        temp = temp->next;
    }
}

void deleteAny(){
    int position, flag = 0;
    printf("\n\tChoice Any ('1 to %d')Position For Delete Node : ",userCount());
    scanf("%d",&position);
    if(position <= userCount()){
        flag = 1;
        if(position == 1){
            Node *temp;
            temp = Top;
            Top = Top->next;
            free(temp);
        }else{
            Node *temp;
            temp = Top;
            for(int i=1; i<=position-2; i++){
                temp = temp->next;
            }
            Node *temp2;
            temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
        }

    }
    if(flag == 1){
        printf("\tUser Account Delete Successfully !!\n");
    }

}
/// Any Node Delete Area End



/// Cash in Area
int cash_in(){
    Node *temp = Top;
    int acNo,newMoney;
    float sum=0;
    printf("\tEnter User Bank Account Number : ");
    scanf("%d",&acNo);


    while(temp != NULL){

        if(acNo == temp->acount_no){
            printf("\tAdd Money  : ");
            scanf("%d",&newMoney);

            printf("\n\tCash In Successful !!\n");
            printf("\n\tAfter Cash In...");
            printf("\n\tUpdate Balance...\n\n");

            sum =  temp->amount + newMoney;

            printf("\tUser Name          : %s\n",temp->name);
            printf("\tUser Account No    : %d\n",temp->acount_no);
            temp->amount = sum;
            printf("\tNew Amount is      : %.2f\n",temp->amount);
        }

        temp = temp->next;
    }

}
/// Cash in End Area



/// Cash Out Area
int cash_out(){
    Node *temp = Top;
    int acNo,OutMoney;
    float del;
    printf("\tEnter User Bank Account Number : ");
    scanf("%d",&acNo);


    while(temp != NULL){

        if(acNo==temp->acount_no){
            printf("\tCash Out Money Amount  : ");
            scanf("%d",&OutMoney);
            if(temp->amount >= OutMoney){
                 del = temp->amount - OutMoney ;
                 printf("\tCash Out Successful !!\n");
            }else{
                 del =  OutMoney - temp->amount ;
                 printf("\tAmount Is Over Then Recent Money \n");
                 return 0;
            }
            printf("\n\tAfter Cash Out...");
            printf("\n\tUpdate Balance...\n\n");

            printf("\tUser Name        : %s\n",temp->name);
            printf("\tUser Account No    : %d\n",temp->acount_no);
            temp->amount = del;
            printf("\tNew Amount is      : %.2f\n",temp->amount);
        }
        temp = temp->next;
    }

}
/// Cash Out End Area


/// Data Sorting Area

Node* swap(Node* ptr1,Node* ptr2){

    Node* temp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = temp;
    return ptr2;
}

void sortedById(Node** top){

    Node** temp;
    int i, j, swapped;

    for (i = 0; i <= userCount(); i++) {

        temp = top;
        swapped = 0;

        for (j=0; j<userCount()-i-1; j++) {

            Node* user1 = *temp;
            Node* user2 = user1->next;

            if (user1->acount_no > user2->acount_no) {

                *temp = swap(user1, user2);
                swapped = 1;
            }

            temp = &(*temp)->next;
        }

        if (swapped == 0)
            break;
    }
    printf("\tData Sorted Successful !!! \n");
}

/// Data Sorting End Area



/// User Data Update Area Start
void updateInfo(Node *top){

    int number,choce,flag =0;
    Node *temp = top;

    printf("\n\tEnter Account No : ");
    scanf("%d",&number);

    while(temp != NULL){
         if(temp->acount_no == number || Top->acount_no == number){
            flag = 1;
            printf("\n\tChoice '1' For Update User Name : ");
            printf("\n\tChoice '2' For Update User E-Mail : ");
            printf("\n\tChoice '3' For Update User Mobile Number : \n");

            printf("\n\tChoice Any One : ");
            scanf("%d",&choce);

            if(choce == 1){
                printf("\n\tEnter New User Name    : ");
                scanf("%*c%[^\n]",temp->name);

                printf("\tName Update Successful !!\n");
                break;

            }else if(choce == 2){
                printf("\n\tEnter New User E-mail    : ");
                scanf("%*c%[^\n]",temp->mail);

                printf("\tE-mail Update Successful !!\n");
                break;

            }else if(choce == 3){
                printf("\n\tEnter New User Mobile Number    : ");
                scanf("%d",&temp->mobile_no);

                printf("\tMobile Number Update Successful !!\n");
                break;
            }
        }

        temp = temp->next;

    }

    if(flag == 0)
        printf("\n\tAccount Not Found !!\n");

}

/// User Data Update Area End



/// Data Searching Area Start
void searchData(){
    int x,flag = 0;
    Node *temp = Top;
    printf("\tPlease Enter Account No For Search Data : ");
    scanf("%d",&x);

    while(temp != NULL){
        if(temp->acount_no == x){
            flag =1;
            printf("\n\tUser Name        : %s\n",temp->name);
            printf("\tUser Mail        : %s\n",temp->mail);
            printf("\tUser Mobile No   : 0%d\n",temp->mobile_no);
            printf("\tUser Account No  : %d\n",temp->acount_no);
            printf("\tTotal Money      : %.2f\n",temp->amount);
            break;
        }

        temp = temp->next;
    }

    if(flag == 0)
        printf("\tData Not Found !!\n");

}
/// Data Searching Area End



/// User Count Area
int userCount(){
    Node *temp = Top;
    int count = 0;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
/// User Count End Area




/// Data Display Function Area Start
void print(){
    Node *temp = Top;
    while(temp != NULL){
        printf("\n\tUser Name        : %s\n",temp->name);
        printf("\tUser Mail        : %s\n",temp->mail);
        printf("\tUser Mobile No   : 0%d\n",temp->mobile_no);
        printf("\tUser Account No  : %d\n",temp->acount_no);
        printf("\tTotal Amount     : %.2f\n",temp->amount);
        temp = temp->next;
        printf("\n");
    }
    printf("\n");
}
/// Data Display Function End Area



int main(){

    int choice = 0;

    while(choice != 9){

        printf("\n\n Choose one from the below options");
        printf("\n 1. Create Account For New User");
        printf("\n 2. For Print All Data ");
        printf("\n 3. For Cash In, Money Added User Account");
        printf("\n 4. For Cash Out, Money Removed User Account");
        printf("\n 5. For Delete User");
        printf("\n 6. For Sorting User Data, Sorted By User AC Number");
        printf("\n 7. For Searching User Information");
        printf("\n 8. For Update User Information");
        printf("\n 9. For Exit This Program\n");

        printf("\n Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                push();
                break;
            case 2:
                print();
                break;
            case 3:
                cash_in();
                break;
            case 4:
                cash_out();
                break;
            case 5:
                //pop();
                findPosition();
                deleteAny();
                break;
            case 6:
                sortedById(&Top);
                break;
            case 7:
                 searchData();
                break;
            case 8:
                updateInfo(Top);
                break;
            case 9:
                printf("Exiting....\n\n");
                break;
            default:
                printf("Please Enter valid choice : ");
        };

    }

    return 0;

}
