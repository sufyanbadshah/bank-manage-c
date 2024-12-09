#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max_acc 100

//acc structure
typedef struct 
{
    int accountNum;
    char name[50];
    float balance;
}account;

 account accounts[max_acc];
int accCount=0;

//for addicng account
void addAccount(){
 if(accCount >= max_acc){
printf("limit reached.\n");
    return;}

 account newAccount;
printf("Enter Account Number: ");
 scanf("%d", &newAccount.accountNum);
 printf("Enter Your Name: ");
 scanf(" %[^\n]", newAccount.name);
    printf("Enter Initial Balance: ");
    scanf("%f", &newAccount.balance);

    accounts[accCount++] = newAccount;
    printf("Account added successfully! \n");
}
//  delete account
void deleteAccount(){
    int accountNum;
printf("Enter Account Number: ");
scanf("%d",&accountNum);

 for (int i=0; i<accCount; i++) {
    if(accounts[i].accountNum == accountNum){
      for(int j=i;j<accCount - 1; j++){
accounts[j] = accounts[j + 1];
 }
    accCount--;
  printf("Account deleted successfully!\n");
return;
}
    }
 printf("Account not found.\n");
}

// cash deposit
void depositCash(){
int accountNum;
 float amount;
 printf("Enter Account Number: ");
 scanf("%d",&accountNum);
 printf("Enter Amount to Deposit: ");
 scanf("%f",&amount);

for(int i = 0; i < accCount; i++){
if(accounts[i].accountNum == accountNum){
      accounts[i].balance += amount;
      printf("Amount successfully deposited. \n Balance: %.2f\n",accounts[i].balance);
    return;
     }
    }
    printf("Account not found.\n");
}

//cash withdrawl
void withdrawCash(){
    int accountNum;
    float amount;
printf("Enter Account Number: ");
scanf("%d", &accountNum);
    printf("Enter Amount to Withdraw: ");
    scanf("%f",&amount);

for(int i = 0; i < accCount; i++){
if(accounts[i].accountNum == accountNum){
  if(accounts[i].balance>=amount){
accounts[i].balance -= amount;
    printf("Amount successfully withdrawn. \n Balance: %.2f\n",accounts[i].balance);
    } 
    else {
  printf("Insufficient balance.\n");
    }
      return;
}
    }
    printf("Account not found.\n");
}

//display account details
void displayAccounts(){
    if(accCount == 0){
printf("No accounts were found.\n");
return;
}
printf("\nAccount Details:\n");
  printf("-------------------------------------------------\n");
    printf("Account Number | Name | Balance\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < accCount; i++) {
    printf("%-15d | %-20s | %.2f\n",
 accounts[i].accountNum, accounts[i].name, accounts[i].balance);
    }
    printf("-------------------------------------------------\n");
}
//for choices
int main(){
 int choice;
 while (10>1){
 printf("\n ITUS Bank Management System\n");
 printf("1.Add Account\n");
   printf("2.Delete Account\n");
      printf("3.Deposit Cash\n");
     printf("4.Withdraw Cash\n");
  printf("5.Display Accounts\n");
    printf("6.Exit\n");
   printf("Select An Option: ");
      scanf("%d",&choice);
 switch(choice){
 case 1:
addAccount();
break;
    case 2:
deleteAccount();
break;
    case 3:
depositCash();
break;
    case 4:
withdrawCash();
break;
    case 5:
displayAccounts();
break;
    case 6:
printf("AllahHafiz!\n");
return 0;
    default:
printf("Invalid choice.try again.\n");
}
}
}





