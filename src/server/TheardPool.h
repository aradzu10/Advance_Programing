/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#ifndef REVERSI_THEARDPOOL_H
#define REVERSI_THEARDPOOL_H


#include "Task.h"
#include <queue>
#include <pthread.h>
using namespace std;
class ThreadPool {
public:
    ThreadPool(int threadsNum);
    void addTask(Task *task);
    void terminate();
    virtual ~ThreadPool();
private:
    queue<Task *> tasksQueue;
    pthread_t* threads;
    void executeTasks();
    bool stopped;
    pthread_mutex_t lock;
    static void *execute(void *arg);
};


#endif //REVERSI_THEARDPOOL_H
