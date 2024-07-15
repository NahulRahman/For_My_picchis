#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t lock; // Create a mutex
int counter = 0; // Shared counter

void* increment_counter(void* args) {
    for (int i = 0; i < 10; i++) { // Each thread attempts to increment the counter 10 times
        if (pthread_mutex_trylock(&lock) == 0) { // Attempt to lock the mutex
            // Critical section
            counter++;
            cout << "Counter incremented to " << counter << " by thread " << pthread_self() << endl;
            pthread_mutex_unlock(&lock); // Unlock the mutex
        } else {
            // If the mutex is not available, do some other work or sleep
            // Here, we simply sleep for a short time before trying again
            usleep(100); // Sleep for 100 microseconds
        }
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&lock, NULL); // Initialize the mutex

    // Create two threads
    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock); // Destroy the mutex

    cout << "Final counter value: " << counter << endl;
    return 0;
}
