#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

void wrong_unlock() {
    m.unlock();       // undefined behavior
}

int main() {
    std::thread t1(wrong_unlock);
    t1.join();
}
