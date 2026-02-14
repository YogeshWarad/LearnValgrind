#include <thread>
#include <iostream>

int counter = 0;

void work() {
    for (int i = 0; i < 1000000; i++) {
        counter++;   // RACE!!
    }
}

int main() {
    std::thread t1(work);
    std::thread t2(work);

    t1.join();
    t2.join();

    std::cout << counter << "\n";
}
