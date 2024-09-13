#include <iostream>
#include <string>
#include <memory>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <deque>
#include <queue>
#include <random>
#include <condition_variable>

using namespace std;

//Имитация загруженной работы программы.
int main1() {
    setlocale(LC_ALL, "Russian");

    cout << "Вычислительный процесс 1 начал работу" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    for (int i{}; i < 10; i++) {
        cout << "Вычислительный процесс 1 работает" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
    cout << "Вычислительный процесс 1 закончил работу" << endl;

    cout << "Вычислительный процесс 2 начал работу" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    for (int i{}; i < 10; i++) {
        cout << "Вычислительный процесс 2 работает" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    cout << "Вычислительный процесс 2 закончил работу" << endl;

    return 0;
}


// Описаывем процессы работы (несколько штук)
void proc1() {
    cout << "Вычислительный процесс 1 начал работу" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    for (int i{}; i < 10; i++) {
        cout << "Вычислительный процесс 1 работает поток " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
    cout << "Вычислительный процесс 1 закончил работу" << endl;

}

void proc2() {
    cout << "Вычислительный процесс 2 начал работу" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    for (int i{}; i < 10; i++) {
        cout << "Вычислительный процесс 2 работает поток " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    cout << "Вычислительный процесс 2 закончил работу" << endl;
}


void proc3(int a, int b) {
    cout << "Вычислительный процесс 3 начал работу" << endl;
    this_thread::sleep_for(chrono::milliseconds(6000));
    for (int i{}; i < 10; i++) {
        cout << "Вычислительный процесс 3 работает поток " << this_thread::get_id() << endl;
        a += b;
        cout << "a+b = " << a << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "Вычислительный процесс 3 закончил работу" << endl;
}

void proc4(int& a, int b) {
    cout << "Вычислительный процесс 3 начал работу" << endl;
    this_thread::sleep_for(chrono::milliseconds(6000));
    for (int i{}; i < 10; i++) {
        cout << "Вычислительный процесс 3 работает поток " << this_thread::get_id() << endl;
        a += b;
        cout << "a+b = " << a << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "Вычислительный процесс 3 закончил работу" << endl;
}


int  proc5(int a, int b) {
    cout << "Вычислительный процесс 3 начал работу" << endl;
    this_thread::sleep_for(chrono::milliseconds(6000));
    for (int i{}; i < 10; i++) {
        cout << "Вычислительный процесс 3 работает поток " << this_thread::get_id() << endl;
        a += b;
        cout << "a+b = " << a << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "Вычислительный процесс 3 закончил работу" << endl;
    return a;
}

int main2() {
    setlocale(LC_ALL, "Russian");
    cout << "Программа начала работу поток " << this_thread::get_id() << endl;

    thread th(proc1);

    //thread th1(proc3, 10 ,11);

    int a = 10;
    int b = 11;
    //thread th1(proc4, a, b);
    //thread th1(proc4, std::ref(a), b);

    int res;
    //thread th1([&res,a,b]() {
    //  res = proc5(a, b);
    //  });

    auto f = [&res, a, b]() { res = proc5(a, b); };
    thread th1(f);


    proc2();

    th.join();
    th1.join();

    //cout << "a = " << a<< endl;
    cout << "res = " << res << endl;
    cout << "Программа отработала поток " << this_thread::get_id() << endl;

    return 0;
}



class Test {
public:


    void proc1() {
        cout << "Вычислительный процесс 1 начал работу" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        for (int i{}; i < 10; i++) {
            cout << "Вычислительный процесс 1 работает поток " << this_thread::get_id() << endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
        }
        cout << "Вычислительный процесс 1 закончил работу" << endl;

    }

    void proc3(int a, int b) {
        cout << "Вычислительный процесс 3 начал работу" << endl;
        this_thread::sleep_for(chrono::milliseconds(6000));
        for (int i{}; i < 10; i++) {
            cout << "Вычислительный процесс 3 работает поток " << this_thread::get_id() << endl;
            a += b;
            cout << "a+b = " << a << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        cout << "Вычислительный процесс 3 закончил работу" << endl;
    }
        
    int  proc4(int a, int b) {
        cout << "Вычислительный процесс 3 начал работу" << endl;
        this_thread::sleep_for(chrono::milliseconds(6000));
        for (int i{}; i < 10; i++) {
            cout << "Вычислительный процесс 3 работает поток " << this_thread::get_id() << endl;
            a += b;
            cout << "a+b = " << a << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        cout << "Вычислительный процесс 3 закончил работу" << endl;
        return a;
    }
};

int main3() {
    setlocale(LC_ALL, "Russian");
    cout << "Программа начала работу поток " << this_thread::get_id() << endl;

    /*Test test;
    int res;
    auto f = [&res, &test]() { res = test.proc4(2, 7); };
    thread th1(f);
    proc2();
    th1.join();*/


    /*Test test;
    int res;
    
    thread th1(&Test::proc1, test);
    proc2();
    th1.join();*/

    Test test;
    int res;

    thread th1(&Test::proc3, test,33,77);
    proc2();
    th1.join();


    return 0;
}


//mutex
// lock_guard

class STimer {
    chrono::time_point<chrono::steady_clock> start, end;
    chrono::duration<float> delt;
public:
    STimer() {
        start = chrono::high_resolution_clock::now();
    }

    ~STimer() {
        end = chrono::high_resolution_clock::now();
        delt = end - start;
        float result = delt.count();
        cout << " Time for programm runing is " << result<< endl;

    }
};

mutex mtx;

void print(char ch) {

    
    //this_thread::sleep_for(chrono::milliseconds(2000));
    // lock_guard<mutex> lock(mtx);
    //mtx.lock();
    for (int i{}; i < 10; i++) {
        for (int i{}; i < 10; i++){
            cout << ch;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout << endl;
    }
    cout << endl;
    //mtx.unlock();
    //this_thread::sleep_for(chrono::milliseconds(2000));
}

int main4() {
    setlocale(LC_ALL, "Russian");
    cout << "Программа начала работу поток " << this_thread::get_id() << endl;

    //print('*');
    //print('%');
    
    thread t1(print,'*');
    thread t2(print, '%');

    t1.join();
    t2.join();

    return 0;
}



// deadlock

mutex mtx1;
mutex mtx2;

void print1() {

    mtx1.lock();

    this_thread::sleep_for(chrono::milliseconds(1));
    
    mtx2.lock();
    for (int i{}; i < 10; i++) {
        for (int i{}; i < 10; i++) {
            cout << '*';
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout << endl;
    }
    cout << endl;
    mtx2.unlock();
    mtx1.unlock();
    
}

void print2() {

    mtx2.lock();

    this_thread::sleep_for(chrono::milliseconds(1));

    mtx1.lock();
    for (int i{}; i < 10; i++) {
        for (int i{}; i < 10; i++) {
            cout << '#';
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout << endl;
    }
    cout << endl;
    mtx1.unlock();
    mtx2.unlock();

}

int main5() {
    setlocale(LC_ALL, "Russian");
    cout << "Программа начала работу поток " << this_thread::get_id() << endl;

    //print('*');
    //print('%');

    thread t1(print1);
    thread t2(print2);

    t1.join();
    t2.join();

    return 0;
}


mutex m;
recursive_mutex rm;

void func(int a) {

    rm.lock();
    cout << a << " ";
    this_thread::sleep_for(chrono::milliseconds(20));
    if (a == 1) {
        cout << endl;
        rm.unlock();
        return;
    }
    a--;
    func(a);
    rm.unlock();
}

int main6() {
    setlocale(LC_ALL, "Russian");
    cout << "Программа начала работу поток " << this_thread::get_id() << endl;

    

    thread t1(func, 10);
    thread t2(func, 20);

    t1.join();
    t2.join();

    //func(10);

    //unique_lock<mutex> ul(m, defer_lock);


    return 0;
}




template <typename T>
struct concurrent_queue {
    void push(T value) {
        std::lock_guard<std::mutex> lg(m);
        q.push_back(std::move(value));
    }

    bool empty() const {
        std::lock_guard<std::mutex> lg(m);
        return q.empty();
    }

    T pop() {
        if (empty()) {                  
            return -1;
        }
        std::lock_guard<std::mutex> lg(m);
        T result = q.front();
        q.pop_front();
        return result;
    }
private:
    mutable std::mutex m;
    std::deque<T> q;
};


void add(concurrent_queue<int>&q, int start) {
    
    for (int i{ start }; i < 20; i++) {
        cout << "add " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
        q.push(i);
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    cout << "stop " << this_thread::get_id() << endl;
}

void del(concurrent_queue<int>& q) {
    this_thread::sleep_for(chrono::milliseconds(550));
    while (!q.empty()) {
        cout << "del " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(300));
        cout << q.pop() << " ";
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    cout << "stop " << this_thread::get_id() << endl;
}



int main7() {
    setlocale(LC_ALL, "Russian");
    cout << "Программа начала работу поток " << this_thread::get_id() << endl;
    concurrent_queue<int> q;
    
        thread th1(add, std::ref(q),1);
        thread th2(del, std::ref(q));
        thread th3(del, std::ref(q));
        thread th4(del, std::ref(q));
        thread th5(del, std::ref(q));
        th1.join();
        th2.join();
        th3.join();
        th4.join();
        th5.join();
    return 0;
}






/*
std::mutex              g_lockprint;
std::mutex              g_lockqueue;
std::condition_variable g_queuecheck;
std::queue<int>         g_codes;
bool                    g_done;
bool                    g_notified;

void workerFunc(int id, std::mt19937& generator)
{
    // стартовое сообщение
    {
        std::unique_lock<std::mutex> locker(g_lockprint);
        std::cout << "[worker " << id << "]\trunning..." << std::endl;
    }
    // симуляция работы
    std::this_thread::sleep_for(std::chrono::seconds(1 + generator() % 5));
    // симуляция ошибки
    int errorcode = id * 100 + 1;
    {
        std::unique_lock<std::mutex> locker(g_lockprint);
        std::cout << "[worker " << id << "]\tan error occurred: " << errorcode << std::endl;
    }
    // сообщаем об ошибке
    {
        std::unique_lock<std::mutex> locker(g_lockqueue);
        g_codes.push(errorcode);
        g_notified = true;
        g_queuecheck.notify_one();
    }
}

void loggerFunc()
{
    // стартовое сообщение
    {
        std::unique_lock<std::mutex> locker(g_lockprint);
        std::cout << "[logger]\trunning..." << std::endl;
    }
    // до тех пор, пока не будет получен сигнал
    while (!g_done)
    {
        std::unique_lock<std::mutex> locker(g_lockqueue);
        //while (!g_notified) // от ложных пробуждений
        //      g_queuecheck.wait(locker);
        // 
        cout << "[logger] checked" << endl;
        g_queuecheck.wait(locker, [&]() {return !g_codes.empty(); });

        // если есть ошибки в очереди, обрабатывать их
        while (!g_codes.empty())
        {
            std::unique_lock<std::mutex> locker(g_lockprint);
            std::cout << "[logger]\tprocessing error:  " << g_codes.front() << std::endl;
            g_codes.pop();
        }
        g_notified = false;
    }
}

int main(){
    // инициализация генератора псевдо-случайных чисел
    std::mt19937 generator((unsigned int)std::chrono::system_clock::now().time_since_epoch().count());
    // запуск регистратора
    std::thread loggerThread(loggerFunc);
    // запуск рабочих
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i)
        threads.push_back(std::thread(workerFunc, i + 1, std::ref(generator)));
    for (auto& t : threads)
        t.join();
    // сообщаем регистратору о завершении и ожидаем его
    g_done = true;
    loggerThread.join();
    return 0;
}


*/


/*
std::condition_variable
wait - поток начинает спать
notify_one - пробуждает один поток
notify_all - пробуждает все потоки

*/
template <typename T>
struct concurrent_queue1 {
    void push(T value) {
        std::unique_lock<std::mutex> lg(m);
        q.push_back(std::move(value));
        lg.unlock();
        cv.notify_all();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lg(m);
        return q.empty();
    }

    T pop() {
        if (empty()) {
            cv.notify_all();
            return -1;
        }
        std::unique_lock<std::mutex> lg(m);
        T result = q.front();
        q.pop_front();
        cv.wait(lg);
        return result;
    }
private:
    mutable std::mutex m;
    std::deque<T> q;
    std::condition_variable cv;
};

void add1(concurrent_queue1<int>& q, int start) {

    for (int i{ start }; i < 10; i++) {
        this_thread::sleep_for(chrono::milliseconds(200));
        cout << "add " << i << "  " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
        q.push(i);
    }
    cout << "stop " << this_thread::get_id() << endl;
}

void del1(concurrent_queue1<int>& q) {
    this_thread::sleep_for(chrono::milliseconds(550));
    while (!q.empty()) {
        cout << "del " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(400));

        cout << q.pop() << " ";
        this_thread::sleep_for(chrono::milliseconds(400));
    }
    cout << "stop " << this_thread::get_id() << endl;
}

