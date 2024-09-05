#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <cstring>

using namespace std;

// Базовый класс Анализатор
class Analizator {
protected:
    std::ostream& io;
    Analizator(std::ostream& io) :io{ io } {}
public:
    virtual void check(char c) = 0;
};

//  Анализатор букв
class AnalizatorGl : public Analizator {
public:
    AnalizatorGl(std::ostream& io = cout) :Analizator(io) {}

    void check(char c) override {
        char val[] = "AaEeYyUuIiOo";
        for (int i{}; i < sizeof(val); ++i)
            if (c == val[i]) {
                io << c << std::endl;
            }
    }
};

//  Анализатор цифр
class AnalizatorDig : public Analizator {
public:

    AnalizatorDig(std::ostream& io = cout):Analizator(io) {}

    void check(char c) override {
        char val[] = "1234567890";
        for (int i{}; i < sizeof(val); ++i)
            if (c == val[i]) {
                io << c << std::endl;
            }
    }
};

// Контроллер
class Controller {
public:

    vector<unique_ptr<Analizator>> analizators;

    void run(const char* c) {

        int size = strlen(c);
        for (int i{}; i < size; ++i){
            for (auto it = analizators.begin();
                 it != analizators.end();
                 ++it)
                (*(*it)).check(c[i]);
        }
    }
};

int main() {

    setlocale(LC_ALL, "Russian");

    Controller  c;
    c.analizators.push_back(make_unique<AnalizatorGl>());

    fstream ifs;
    ifs.open("dig.txt", std::fstream::out);
    if (!ifs.is_open()) {
        std::cout << "Error open file " << "dig.txt";
        return 0;
    }
    c.analizators.push_back(make_unique<AnalizatorDig>(ifs));
    c.run("asdfgh33jkl2");

    ifs.close();

    return 0;
}