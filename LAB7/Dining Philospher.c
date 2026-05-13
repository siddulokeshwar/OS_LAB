#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 5
pthread_mutex_t forks[N];

void think(int id) {
    printf("Philosopher %d is thinking\n", id);
    sleep(1);
}

void eat(int id) {
    printf("Philosopher %d is eating\n", id);
    sleep(1);
}

void* philosopher(void* arg) {
    int id = *(int*)arg;
    int left = id;
    int right = (id + 1) % N;

    while (1) {
        think(id);
        if (id == N - 1) {
            pthread_mutex_lock(&forks[right]);
            printf("Philosopher %d picked up right fork %d\n", id, right);
            pthread_mutex_lock(&forks[left]);
            printf("Philosopher %d picked up left fork %d\n", id, left);
        } else {
            pthread_mutex_lock(&forks[left]);
            printf("Philosopher %d picked up left fork %d\n", id, left);
            pthread_mutex_lock(&forks[right]);
            printf("Philosopher %d picked up right fork %d\n", id, right);
        }
        eat(id);

        pthread_mutex_unlock(&forks[left]);
        printf("Philosopher %d released left fork %d\n", id, left);
        pthread_mutex_unlock(&forks[right]);
        printf("Philosopher %d released right fork %d\n", id, right);
    }
    return NULL;
}

int main() {
    pthread_t philosophers[N];
    int ids[N];
    for (int i = 0; i < N; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }
    for (int i = 0; i < N; i++) {
        pthread_mutex_destroy(&forks[i]);
    }
    return 0;
}
