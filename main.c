#include <stdbool.h>
#include <stdio.h>

#define BANK_BANNER "src/bank_banner.txt"


void display(const char *filename){

    FILE *file = fopen(filename, "r");

    if(file == NULL){
        printf("Could not open our banking system.");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
    printf("%s", line);  
    }
}

void checkBalance(float balance){
    printf("\nYour current balance is: $%.2f.", balance);
}

float deposit(float balance){
    float deposit_money = 0.0f;
    printf("\nEnter the amount to deposit: ");
    scanf("%f", &deposit_money);

        balance += deposit_money;
        printf("\n$%.2f deposited successfully.", deposit_money);
        printf("\nYou're total balance is now $%.2f.", balance);
        return balance;
}


float withdraw(float balance){
    float withdraw_money = 0.0;
    printf("\nEnter the amount to withdraw: ");
    scanf("%f", &withdraw_money);
    
    if(withdraw_money > balance){
        printf("\nInvalid operation.");
        printf("\nUnsufficient money on bank account to perform this operation.");
    }else{
        balance -= withdraw_money;
        printf("\n$%.2f withdrawn successfully.", withdraw_money);
        printf("\nYou're total balance is now $%.2f.", balance);
    }
        return balance;
}


void mainMenu(){

    bool running_program = true;
    float balance = 1000.0f;

while (running_program){
    int choice;
    display(BANK_BANNER);
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = deposit(balance);
                break;
            case 3:
                balance = withdraw(balance);
                break;
            case 4:
                printf("\nThank you for using our bank. See you soon!\n");
                return; // Exit the menu
            default:
                printf("\nInvalid operation.");
        }
        printf("\nPress Enter to return to the main menu...");
        while (getchar() != '\n');  // consume newline left by scanf
        char buffer[10]; // Flush remaining input
        fgets(buffer, sizeof(buffer), stdin);
    
}
}


int main(){

    bool running_program = true;

    while (running_program){
        mainMenu();
        break;
    }
    
    return 0;

}