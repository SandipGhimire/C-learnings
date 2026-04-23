#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

void threadA() {
    for (int i = 0; i < 5; i++) {
        lock_guard<mutex> lock(mtx);
        cout << "Thread A: Processing..." << endl;
    }
}

void threadB() {
    for (int i = 0; i < 5; i++) {
        lock_guard<mutex> lock(mtx);
        cout << "Thread B: Processing..." << endl;
    }
}

int main() {
    thread t1(threadA);
    thread t2(threadB);

    t1.join();
    t2.join();

    return 0;
}