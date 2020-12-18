#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

typedef struct {
    int n;
    volatile int cur;
    sem_t szero;
    sem_t sodd;
    sem_t sevn;
} ZeroEvenOdd;

ZeroEvenOdd* zeroEvenOddCreate(int n) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*) malloc(sizeof(ZeroEvenOdd));
    obj->n = n;

    obj->cur = 1;
    sem_init(&obj->szero, 0, 1);
    sem_init(&obj->sodd, 0, 0);
    sem_init(&obj->sevn, 0, 0);
    return obj;
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.

void printNumber(int x) {
    printf("%d", x);
} 

void zero(ZeroEvenOdd* obj) {
    while(obj->cur<obj->n) {
        sem_wait(&obj->szero);
        printNumber(0);
        // printNumber(obj->cur);
        if (obj->cur%2==1) {
            sem_post(&obj->sodd);
        } else {
            sem_post(&obj->sevn);
        }
    }
    
}

void even(ZeroEvenOdd* obj) {
    while(obj->cur<obj->n){
        sem_wait(&obj->sevn);
        printNumber(obj->cur);
        obj->cur++;
        sem_post(&obj->szero);
    }
}

void odd(ZeroEvenOdd* obj) {
    while(obj->cur<obj->n) {
        sem_wait(&obj->sodd);
        printNumber(obj->cur);
        obj->cur++;
        sem_post(&obj->szero);
    }
}

void zeroEvenOddFree(ZeroEvenOdd* obj) {
    if(NULL!=obj) {
        sem_destroy(&obj->szero);
        sem_destroy(&obj->sodd);
        sem_destroy(&obj->sevn);
        free(obj);
    }
}

int main() {
    ZeroEvenOdd *f=zeroEvenOddCreate(100);
    pthread_t tidz, tido, tide;

    pthread_create(&tido, NULL, (void *)&odd, (void *)f);
    pthread_create(&tide, NULL, (void *)&even, (void *)f);
    pthread_create(&tidz, NULL, (void *)&zero, (void *)f);

    pthread_join(tidz, NULL);
    pthread_join(tido, NULL);
    pthread_join(tide, NULL);
}