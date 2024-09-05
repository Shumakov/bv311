#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

class Cell {
        public:
            int value {};
            bool isRun{};

            void run (){
                while (isRun){
                    this_thread::sleep_for(chrono::milliseconds(10));
                    value = (rand() % 9) + 1;
                }
            }
    };


class Bandit {
public:
    Cell c1,c2,c3;
    bool isRun{};

    void run(){

        c1.isRun = c2.isRun = c3.isRun = isRun = true;

        thread t1(&Cell::run, &c1);
        thread t2(&Cell::run, &c2);
        thread t3(&Cell::run, &c3);
        t1.detach();
        t2.detach();
        t3.detach();
    }

};

int main() {
    setlocale(LC_ALL, "Russian");


    cout << std::thread::hardware_concurrency() << endl;

    Bandit b;

    thread t (&Bandit::run,&b);
    t.detach();

    do{
        char ch = getchar();

        if (ch == 'v'){
            cout << b.c1.value <<" " << b.c2.value<< " " << b.c3.value << endl;
            continue;
        }

        if (ch == 'x'){
            b.isRun = 0;
            break;
        }
    }while (true);

    return 0;
}