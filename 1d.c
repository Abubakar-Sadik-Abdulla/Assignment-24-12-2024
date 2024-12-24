#include <stdio.h>

float balance = 0.0;

void deposit(float amount) {
    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }
    balance += amount;
    printf("Deposited: %.2f. Current Balance: %.2f\n", amount, balance);
}

void withdraw(float amount) {
    if (amount <= 0 || amount > balance) {
        printf("Invalid or insufficient funds.\n");
        return;
    }
    balance -= amount;
    printf("Withdrew: %.2f. Current Balance: %.2f\n", amount, balance);
}

int main() {
    deposit(500);
    withdraw(200);
    deposit(300);
    withdraw(700);
    return 0;
}
