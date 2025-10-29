#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <fstream>

std::mutex cout_mutex;

void printToConsole(const std::string& name) {
	if (cout_mutex.try_lock()) {
		for (int i = 0; i < 10; i++) {
			std::cout << "Выполняется поток " << name << ", поток " << i << std::endl;
		}
		cout_mutex.unlock();
	}
}

int main() {
	system("chcp 1251");
	std::thread thr1(printToConsole, "a");
	std::thread thr2(printToConsole, "b");
	thr1.join();
	thr2.join();
}
