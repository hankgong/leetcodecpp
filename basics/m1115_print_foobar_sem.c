#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

typedef struct {
    int n;
    sem_t f;
    sem_t b;
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;

    sem_init(&obj->f, 0, 1);
    sem_init(&obj->b, 0, 0);

    // sem_post(&obj->f);
    return obj;
}

void printFoo() {
    printf("foo");
}

void printBar() {
    printf("bar");
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&obj->f);
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        sem_post(&obj->b);
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&obj->b);
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        sem_post(&obj->f);
    }
}

void fooBarFree(FooBar* obj) {
    sem_destroy(&obj->f);
    sem_destroy(&obj->b);
    free(obj);
}

int main() {
    FooBar *f=fooBarCreate(5);

    pthread_t tidf, tidb;

    pthread_create(&tidb, NULL, (void *)&bar, (void *)f);
    pthread_create(&tidf, NULL, (void *)&foo, (void *)f);

    pthread_join(tidf, NULL);
    pthread_join(tidb, NULL);
}