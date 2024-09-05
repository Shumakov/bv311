#include <iostream>
#include <functional> //- Полиморфная обертка функций
#include <vector>

using namespace std;


//Функтор
class Counter {
    int cnt;
public:
    Counter(int start) : cnt{ start } {};
    Counter() : Counter(0) {};

    int operator() (bool direct = true) {
        if (direct)
            return cnt++;
        return cnt--;
    }
    void resetTo(int start) { cnt = start; }
};

// Пример использования нашего функтора (счетчика)
void useCntr() {
    const int maxCnt{ 5 };
    Counter cnt1{};
    Counter cnt2{ 100 };
    for (int i{ 0 }; i < maxCnt; ++i)
    {
        std::cout << "cnt1: " << cnt1(0) << '\n';
        std::cout << "cnt2: " << cnt2(0) << '\n';
    }
    std::cout << '\n';
    cnt1.resetTo(10);
    cnt2.resetTo(200);
    for (int i{ 0 }; i < maxCnt; ++i)
    {
        std::cout << "cnt1: " << cnt1(0) << '\n';
        std::cout << "cnt2: " << cnt2(0) << '\n';
    }
    std::cout << '\n';
}

//Полиморфная обертка функций
void foo1() {
    cout << "foo1() is work" << endl;
}
void foo2() {
    cout << "foo2() is work" << endl;
}

int sum(int a, int b) {
    return a + b;
}

void fun(int a) {
    if (a > 10 && a < 40) {
        cout <<"fun - " << a << endl;
    }
}

void fun2(int a) {
    if (!(a % 2)) {
        cout << "fun2 - " << a << endl;
    }
}

void doWork(vector<int>& vc) {

    for (auto v : vc) {
        fun(v);
    }
}

void doWork(vector<int>& vc, function<void(int)> fun) {

    for (auto v : vc) {
        fun(v);
    }
}

void doWork(vector<int>& vc, vector <function<void(int)>> funcs) {

    for (auto v : vc) {
        for (auto fun : funcs)
            fun(v);
    }
}

int main_1() {
    setlocale(LC_ALL, "rus");

    void(*func)(int); // просто указатель

    func = fun;

    function<void()> f; // обертка над указателем на функцию
    f = foo1;
    f();
    f = foo2;
    f();

    function<int(int, int)> f2; // обертка над указателем на функцию

    f2 = sum;
    cout << f2(5, 6) << endl;

    vector<int> vc = { 1,2,3,45,67,33,221,88,99,22 };
    doWork(vc, fun);
    vector<function<void(int)>> funcs = { fun,fun2 };
    doWork(vc, funcs);

    return 0;
}

class Test {
    public:
    int i{100};

    void Message (){
        cout << "Test Message "  << i << endl;
    }

    void test_lambda(){
        auto f = [this](){
            this->i = 789;
            this->Message();
        };
        f();
    }
};

// Лямбда выражения
int main() {
    setlocale(LC_ALL, "rus");

    // контекст = & , , ,  mutable, this  -> тип данных
    //[](){};
    //[](передаваемые аргументы){тело функции};

    // = контекст по значению (только для чтения)
    // = контекст по значению (полная копия) mutable
    // &  контекст по ссылке

    int p{100};

    function<void(int)> ff = [&p](int u){
        cout << "Лямбда функция " <<  u << endl;
        p++;
    };

    ff(100);
    cout << p<< endl;

    auto auto_f = [&p](int u){
        cout << "Лямбда функция " <<  u << endl;
        p++;
    };

    auto_f(99);

    auto auto_f1 = [&p](int u){
        cout << "Лямбда функция " <<  u << endl;
        p++;
        return u+u;
    };
    auto result = auto_f1(99);

    p = 1;
    cout << p<< endl;
    auto auto_f2 = [p](int u) mutable -> double{
        cout << "Лямбда функция " <<  u << endl;
        p++;
        return u+u;
    };
    auto result2 = auto_f2(99);
    cout << p<< endl;

    //int p = 0;
    //vector<int> vc = { 1,2,3,45,67,33,221,88,99,22 };
    //doWork(vc, [p](int a)/*mutable*/ {
    //    cout << a << endl;
    //   });

    Test t;

    t.test_lambda();

    return 0;
}