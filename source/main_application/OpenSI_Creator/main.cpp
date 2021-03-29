//
#include <iostream>
#include <chrono>
#include <thread>

int main() {
	std::cout << "Hello World!\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return 0;
}
//