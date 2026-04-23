#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

void task1() {
    for(int i=0;i<3;i++){
        lock_guard<mutex> lock(mtx);
        cout << "Task 1 running" << endl;
    }
}

void task2() {
    for(int i=0;i<3;i++){
        lock_guard<mutex> lock(mtx);
        cout << "Task 2 running" << endl;
    }
}

void task3() {
    for(int i=0;i<3;i++){
        lock_guard<mutex> lock(mtx);
        cout << "Task 3 running" << endl;
    }
}

int main() {
    thread t1(task1);
    thread t2(task2);
    thread t3(task3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}