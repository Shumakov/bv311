#include "iostream"
#include <map>
#include <string>

using namespace std;

int main(){
    setlocale(LC_ALL, "rus");

    multimap<string, int> persons;

    persons.emplace ("Bob1", 18);
    persons.emplace ("Bob2", 28);
    persons.emplace ("Bob3", 38);
    persons.emplace ("Bob4", 48);
    persons.emplace ("Bob", 58);
    persons.emplace ("Bob6", 68);
    persons.emplace ("Bob7", 78);
    persons.emplace ("Bob", 88);
    persons.emplace ("Bob", 98);
    persons.emplace ("Bob", 108);


    // Вывод
    for (auto p : persons)
        cout << p.first <<" - " << p.second << endl;

    auto f = persons.find ("Bob");
    if (f != persons.end())
        cout <<"find : "<< f->first <<" - " << f->second << endl;

    f = persons.find ("Bob");
    if (f != persons.end())
        cout <<"find : "<< f->first <<" - " << f->second << endl;


    cout << endl<< endl;


    // Вариант 1

    //count(key) - Возвращает количество элементов в multimap ключах, ключи которых соответствуют указанному параметру ключу.
    // Функция-член возвращает число элементов в диапазоне
    // lower_bound(key), upper_bound(key)
    // имеющий значение ключа key.

    int num =  persons.count("Bob"); // Количество совпадений в контейнере
    f = persons.find ("Bob");
    for (int i{} ; i < num; i++, f++)
        cout <<"find : "<< f->first <<" - " << f->second << endl;

    cout << endl<< endl;

    // Вариант 2

    //lower_bound(key) - Возвращает итератор, указывающий на первый элемент в контейнере multimap с ключом,
    // который больше или равен указанному ключу.

    //upper_bound(key)  - Возвращает первый элемент в multimap том, что с ключом, превышающим указанный ключ.


    for(auto iter = persons.lower_bound("Bob");
        iter != persons.upper_bound("Bob") && iter != persons.end();
        iter++) {
         cout <<"find : "<< iter->first <<" - " << iter->second << endl;
    }

    return 0;
}
