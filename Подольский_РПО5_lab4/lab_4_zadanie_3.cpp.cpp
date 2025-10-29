#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>

std::mutex vector_mutex;
void printToVector(std::vector<std::string>& vect, const std::string& name) {
	vector_mutex.lock();
	for (int i = 0; i < 10; i++)
	{
		vect.push_back("я строка студента Подольский в потоке " + name + ",это моя " + std::to_string(i) + "попытка");
	}
	vector_mutex.unlock();
}

int main() {
	system("chcp 1251");
	std::vector<std::string>vectr;
	std::string stringi = "aaaa";
	std::string strbingi = "bbbb";
	std::thread thread1(printToVector, std::ref(vectr), stringi);
	thread1.join();
	std::thread thread2(printToVector, std::ref(vectr), strbingi);
	thread2.join(); /*Вызвано исключение : нарушение доступа для чтения.this->_Myproxy было 0xFFFFFFFFFFFFFFFF.*/
	for (int i = 0; i < vectr.size(); i++) {
		std::cout << vectr.at(i);
	}

}