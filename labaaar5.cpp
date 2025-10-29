#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <thread>
#include <mutex>

std::mutex file_mutex;
class Line {
    std::string name;
    int value;
    char mod;
public:
    std::string line = name + " " + std::to_string(value) + " " + mod;
    Line(std::string name, int value, char mod) : name(name), value(value), mod(mod) {}
    std::string getName() const { return name; }
    int getValue() const { return value; }
};

std::vector<std::string> readFile(const std::vector<std::string>& input_files) {
    std::vector<std::string> all_lines;
    for (int i = 0; i < input_files.size(); i++) {
        std::ifstream ifs(input_files.at(i));
        if (!ifs.is_open()) {
            std::cerr << "не удалось открыть файл " << input_files.at(i) << "\n";
            continue;
        }
        std::string line;
        while (std::getline(ifs, line)) {
            all_lines.push_back(line);
        }
        ifs.close();
    }
    return all_lines;
}

void writeFile(const std::string& name_file, const std::vector<std::string>& lines) {
    std::ofstream ofs(name_file);
    for (int i = 0; i < lines.size(); i++) {
        ofs << lines.at(i) << "\n";
    }
    ofs.close();
}

void divisionIntoObjects(std::vector<Line>& lines_division, const std::vector<std::string>& lines, size_t start, size_t end) {
    for (int i = start; i < end; i++) {
        std::stringstream space(lines.at(i));
        std::string name1; int description; char mod;
        space >> name1 >> description >> mod;
        Line line(name1, description, mod);
        file_mutex.lock();
        lines_division.push_back(line);
        file_mutex.unlock();
    }
}

std::vector<Line> divisionsWithThreads(const std::vector<std::string>& lines) {
    std::vector<Line> lines_division;
    std::vector<std::thread>threads;
    for (int i = 0; i < 4; i++) {
        size_t del = (lines.size() / 4);
        threads.push_back(std::thread(divisionIntoObjects, std::ref(lines_division), std::ref(lines), del * i, del * (i + 1)));
    }
    for (int i = 0; i < 4; i++) {
        threads.at(i).join();
    }
    return lines_division;
}

long findAvg(const std::vector<Line>& lines) {
    long sum = 0;
    long avg = 0;
    for (int i = 0; i < lines.size(); i++) sum += lines.at(i).getValue();
    avg = sum / lines.size();
    std::cout << avg << std::endl;
    return avg;
}

void printAvgFile(const std::vector<Line>& lines) {
    std::ofstream avg("more_than_avg.txt");
    long average = findAvg(lines);
    for (int i = 0; i < lines.size(); i++) {
        if (lines.at(i).getValue() > average) avg << lines.at(i).line << "\n";
    }
    avg.close();
}


void findName(const std::vector<Line>& lines_division, std::string find) {
    std::ofstream name("name.txt", std::ios::app);
    for (int i = 0; i < lines_division.size(); i++) {
        if (lines_division.at(i).getName() == find) name << lines_division.at(i).line << "\n";
    }
    name.close();
}


int main() {
    system("chcp 1251");

    std::vector<std::string> input_files = { "file0.txt", "file1.txt", "file2.txt", "file3.txt" };
    std::string output_file = "output.txt";

    std::clock_t start1 = clock();
    std::vector<std::string> all_lines = readFile(input_files);
    writeFile(output_file, all_lines);
    std::clock_t end1 = clock();
    double result1 = (end1 - start1) / 1000.0;
    std::cout << "oбъединение файлов выполнено за: " << result1 << "\n";

    std::vector<Line> lines_division = divisionsWithThreads(all_lines);
    std::string name;
    std::cout << "введите имя объекта для поиска: ";
    std::cin >> name;

    std::clock_t start2 = clock();
    findName(lines_division, name);
    std::clock_t end2 = clock();
    double resualt2 = (end2 - start2) / 1000.0;
    std::cout << "поиск и запись в name.txt заняли: " << resualt2 << "\n";

    std::clock_t start3 = clock();
    printAvgFile(lines_division);
    std::clock_t end3 = clock();
    double result3 = (end3 - start3) / 1000.0;
    std::cout << "время выполнения записи объектов с значением больше среднего: " << result3 << "\n";
    return 0;
}
