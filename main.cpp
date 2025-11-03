#include <iostream>
#include <chrono>
#include <functional>

void measure_time(const std::function<void()> &func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " microseconds\n";
}

int main() {
    measure_time([] {
        for (volatile int i = 0; i < 100000000; ++i);
    });
}
