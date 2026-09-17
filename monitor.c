#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t mutex;

void charge(int id) {
    sem_wait(&mutex);
    printf("Robot %d charging\n", id);
    sem_post(&mutex);
}

int main() {
    sem_init(&mutex, 0, 1);
    charge(1);
    charge(2);
}
