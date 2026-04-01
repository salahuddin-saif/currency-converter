#include <stdio.h>

int main() {
    int choice;
    double amount, result;

    printf("=============================\n");
    printf("       CURRENCY CONVERTER      \n");
    printf("=============================\n");

    do {
        // Menu
        printf("\nChoose Conversion:\n");
        printf("1. USD to BDT\n");
        printf("2. BDT to USD\n");
        printf("3. USD to EUR\n");
        printf("4. AUD to BDT\n");
        printf("5. BDT to AUD\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 0) {
            printf("Exiting program. Thank you!\n");
            break;
        }

        // Ask for amount
        printf("Enter the amount: ");
        scanf("%lf", &amount);

        // Conversion logic
        if(choice == 1) {
            result = amount * 108; // USD to BDT
            printf("%.2lf USD = %.2lf BDT\n", amount, result);
        }
        else if(choice == 2) {
            result = amount / 108; // BDT to USD
            printf("%.2lf BDT = %.2lf USD\n", amount, result);
        }
        else if(choice == 3) {
            result = amount * 0.95; // USD to EUR
            printf("%.2lf USD = %.2lf EUR\n", amount, result);
        }
        else if(choice == 4) {
            result = amount * 85.09; // AUD to BDT
            printf("%.2lf AUD = %.2lf BDT\n", amount, result);
        }
        else if(choice == 5) {
            result = amount * 0.012; // BDT to AUD
            printf("%.2lf BDT = %.2lf AUD\n", amount, result);
        }
        else {
            printf("Invalid choice! Try again.\n");
        }

    } while(choice != 0);

    return 0;
}
