#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

pthread_mutex_t mutex; // Create a mutex
int account_balance = 300000; // Initial account balance

void* withdraw(void *amount) {
    int withdraw_amount = *((int*)amount);

    pthread_mutex_lock(&mutex);
    if (account_balance >= withdraw_amount) {
        account_balance -= withdraw_amount;
        cout << "Withdrawn: " << withdraw_amount << ", Current balance: " << account_balance << endl;
    } else {
        cout << "Insufficient funds for withdrawal of: " << withdraw_amount << endl;
    }
    pthread_mutex_unlock(&mutex); // Unlock the mutex after accessing the critical section
    return NULL;
}

void* deposit(void *amount) {
    int deposit_amount = *((int*)amount);

    pthread_mutex_lock(&mutex);
    account_balance += deposit_amount;
    cout << "Deposited: " << deposit_amount << ", Current balance: " << account_balance << endl;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t th[4]; // Create an array for 4 thread identifiers
    pthread_mutex_init(&mutex, NULL);

    int withdraw_amounts[3] = {20, 2000, 60};
    int deposit_amount = 40000;

    for (int i = 0; i < 3; i++) {
        pthread_create(&th[i], NULL, withdraw, &withdraw_amounts[i]);
    }

    pthread_create(&th[3], NULL, deposit, &deposit_amount);

    for (int i = 0; i < 4; i++) {
        pthread_join(th[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    cout << "Final account balance: " << account_balance << endl;
    return 0;
}
