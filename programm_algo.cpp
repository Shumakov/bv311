#include "iostream"
#include <vector>
#include <string>
#include <algorithm> //Для работы разных алгоритмов
#include <functional>
#include <numeric>
#include <random>


//advance(it, 4); - пердвигаем итератор на заданное смещение !!!!!!!!!!!!!!!!!!!!!
//https://habr.com/ru/post/330644/  Красно-черные деревья


using namespace std;

struct Person{
    string name;
    double score;
    Person (string n, double s) :name{ n }, score{ s }{}
    bool operator() (const Person& p) {
        return p.score > 180;
    }

    bool operator< (const Person& p){

        if (name[0] == p.name[0]){
            //cout << (int)name[0] << "==" << (int)p.name[0] << endl;
            return score < p.score;
        }
        return name < p.name;
    }
};

vector<Person> people{
    Person("Иван", 190),
    Person("Петя", 90),
    Person("Федя", 100),
    Person("Анна", 55),
    Person("Катя", 181),
    Person("Таня", 188),
    Person("Нина", 170),
    Person("Жанна", 100),
    Person("Коля", 99)
};

#define SORT
#ifdef SORT
// алгоритмы
// sort

// Предикат
bool sort_direction (int a,int b){
    return a > b;// от большего к меньшему!
}

int main(){
    setlocale(LC_ALL, "rus");

    vector <int> v {1,2,3,4,5,7,6,8,9};

    for (auto a : v)
        cout << a << " ";
    cout << endl;

    sort (v.begin(),v.end(),sort_direction);
    for (auto a : v)
        cout << a << " ";
    cout << endl;

    const int size = 9;
    int mass[size] {1,2,3,4,5,7,6,8,9};

    for (auto a : mass)
        cout << a << " ";

    cout << endl;

    sort (mass,mass+size);
    for (auto a : mass)
        cout << a << " ";
    cout << endl;

    for (auto a : people)
        cout << a.name << " " << a.score << endl;
    cout << endl;

    sort (people.begin(), people.end());
    //sort (people.begin(),people.end(), [](const Person& p1,const Person& p2 ){   
    //     return p1.score > p2.score;
    //});

    for (auto a : people)
        cout << a.name << " " << a.score << endl;
    cout << endl;

    return 0;
}
#endif

//#define FIND
#ifdef FIND

// алгоритмы
// find find_if find_not_if
int main(){
    setlocale(LC_ALL, "rus");

    vector <int> v {1,2,3,4,5,7,6,8,9,9};

    for (auto a : v)
        cout << a << " ";
    cout << endl;

    auto fi = find (v.begin(),v.end(),9);

    if (fi != v.end()){
        cout << (*fi) << endl;
    }else{
        cout << "Not find" << endl;
    }

   vector<Person> people{
        Person("Иван", 190),
        Person("Петя", 90),
        Person("Федя", 100),
        Person("Анна", 55),
        Person("Катя", 181),
        Person("Таня", 188),
        Person("Нина", 170),
        Person("Жанна", 100)
    };

    for (auto a : people)
        cout << a.name << " " << a.score << endl;
    cout << endl;


    auto fi1 = find_if(people.begin(),people.end(), [](const Person& p1){
        return p1.score > 100;
    });

    if (fi1 != people.end())
        cout << (*fi1).name << " " << (*fi1).score << endl;

    cout << endl;

    fi1 = people.begin(); 
    while (true){
        fi1 = find_if(fi1,people.end(), [](const Person& p1){
            return p1.score > 100;
        });
        if (fi1 != people.end()){
            cout << (*fi1).name << " " << (*fi1).score << endl;
            fi1++;
        }else{
            break;
        }

    }
    return 0;
}

#endif



//#define COPY
#ifdef COPY
// алгоритмы
// copy  copy_if
int main(){
   setlocale(LC_ALL, "rus");

   vector<Person> people{
        Person("Иван", 190),
        Person("Петя", 90),
        Person("Федя", 100),
        Person("Анна", 55),
        Person("Катя", 181),
        Person("Таня", 188),
        Person("Нина", 170),
        Person("Жанна", 100)
    };

    for (auto a : people)
        cout << a.name << " " << a.score << endl;
    cout << endl;

    vector<Person> fi;

    copy_if (people.begin(), people.end(),back_inserter(fi),[](const Person& p1){
        return p1.score > 100;
    });

    for (auto a : fi)
        cout << a.name << " " << a.score << endl;
    cout << endl;

    return 0;
}
#endif

//#define REMOVE

#ifdef REMOVE
// алгоритмы
// remove, remove_if
int main(){
   setlocale(LC_ALL, "rus");

   vector<int> vi {1,2,3,4,5,5,6,7,8,8,9,0};

    for (auto v : vi)
        cout << v << endl;
    cout << endl;

   auto result = remove (vi.begin(),vi.end(), 8);

  cout << "------------------"<<*result << endl;
  for (auto v : vi)
        cout << v << endl;
    cout << endl;

  vi.erase (result, vi.end());
  for (auto v : vi)
        cout << v << endl;
    cout << endl;


   vector<Person> people{
        Person("Иван", 190),
        Person("Петя", 90),
        Person("Федя", 100),
        Person("Анна", 55),
        Person("Катя", 181),
        Person("Таня", 188),
        Person("Нина", 170),
        Person("Жанна", 100)
    };

    for (auto a : people)
        cout << a.name << " " << a.score << endl;
    cout << endl;


    auto res = remove_if (people.begin(), people.end(),[](const Person& p1){
        return p1.score > 100;
    });


    people.erase (res, people.end());

    for (auto a : people)
        cout << a.name << " " << a.score << endl;
    cout << endl;

    string str = "Моя строка для проврки работы алгоритма";

    cout << str << endl;

    str.erase (remove (str.begin(), str.end(),' '), str.end());

    cout << str << endl;

    return 0;
}
#endif


 
//#define MAXEL 
#ifdef MAXEL

// алгоритмы
// max_element min_element, minmax_element

int main(){
   setlocale(LC_ALL, "rus");

   vector<int> vi {1,2,3,4,5,5,6,7,8,8,9,0};

   for (auto v : vi)
        cout << v << endl;
    cout << endl;


   auto result = max_element (vi.begin(), vi.end());

   cout << *result << endl;


   list<int> li {1,2,3,4,5,5,6,7,8,8,9,0};

   for (auto v : li)
        cout << v << endl;
    cout << endl;


   auto result1 = max_element (vi.begin(), vi.end());

   cout << *result1 << endl;

   const int size = 12;
   int mass[size] =  {1,2,3,4,5,5,6,7,8,8,9,0};

   for (auto v : mass)
        cout << v << endl;
    cout << endl;

   auto result2 = max_element (mass, mass+size);
   cout << *result2 << "  "<< result2-mass<< endl;


   auto result3 = minmax_element (vi.begin(), vi.end());

    cout << *(result3.first) << "  "<< *(result3.second)<< endl;


   return 0;
}

#endif

//#define ACCU 
#ifdef ACCU

// алгоритмы
// #include <numeric>
// сумма, произведение

int main(){
   setlocale(LC_ALL, "rus");

   vector<int> vi {1,2,3,4,5};

   for (auto v : vi)
        cout << v << endl;
    cout << endl;

    cout << "Sum = "<<accumulate (vi.begin(), vi.end(), 0)<< endl;

    cout << "Sum = "<<accumulate (begin(vi), end(vi), 0)<< endl;

    int mass[] =  {1,2,3,4,5};
    cout << "Sum = "<<accumulate (begin(mass), end(mass), 0)<< endl;


///////////////////////

    cout << "P = "<<accumulate (begin(vi), end(vi), 1,[](int a, int b){
            return a*b;
    })<< endl;


    cout << "P = "<<accumulate (begin(vi), end(vi), 1,[](int a, int b){
            if (b % 2 == 0)
                return a*b;
            return a;
    })<< endl;



    //"1-2-3-4-5"
    cout << "STR = "<<accumulate (begin(vi), end(vi), string(""),[](string a, int b){
            return a+"-"+to_string(b);
    })<< endl;

    cout << "STR = "<<accumulate (begin(vi), end(vi), to_string(vi[0]),[](string a, int b){
            return a+"-"+to_string(b);
    })<< endl;


    cout << "STR = "<<accumulate (next(begin(vi)), end(vi), to_string(vi[0]),[](string a, int b){
            return a+"-"+to_string(b);
    })<< endl;

    return 0;
}


#endif

#ifdef EQ
// алгоритмы
//
// equal и mismatch


struct Point {

    int x,y;
    Point (int x = 0, int y=0): x{x}, y{y}{}

};


int main10(){
   setlocale(LC_ALL, "rus");

// сказать про разность длин!!!
// + сортировка

   vector<int> vi {1,2,3,4,5};

   list<int> li {11,2,3,4,5};

   for (auto v : vi)
        cout << v << endl;
    cout << endl;

   for (auto v : li)
        cout << v << endl;
    cout << endl;

    cout << equal (begin(vi), end(vi) , begin(li))<< endl;
    cout << equal (begin(vi), end(vi) , begin(li), end(li))<< endl;

    // где разность 
    auto a=  mismatch (begin(vi), end(vi) , begin(li), end(li));
    cout << *a.first << " " <<*a.second << endl;



    vector <Point> pv1 = {Point(1,3), Point(2,5), Point(6,7)};
    vector <Point> pv2 = {Point(1,3), Point(2,5), Point(6,7)};


    cout << equal (begin(pv1), end(pv1) , begin(pv2), end(pv2), [](const Point& p1, const Point& p2){
                return p1.x == p2.x && p1.y == p2.y;

        })<< endl;

    return 0;
}



// алгоритмы
//
//  for_each
int main(){
   setlocale(LC_ALL, "rus");

   vector<int> vi {1,2,3,4,5};

   for (auto v : vi)
        cout << v << endl;
    cout << endl;

   for_each(begin(vi), end (vi), [](int v){
                cout << v << endl;
    });
    cout << endl;

    return 0;
}

#endif


//   unique  unique_copy
int main12() {
    setlocale(LC_ALL, "rus");

    vector<int> vi{ 1,2,2,2,2,3,4,4,4,5};

    for (auto v : vi)
        cout << v << endl;
    cout << endl;


    auto u = unique(begin(vi), end(vi));

    vi.erase(u, end(vi));

    for (auto v : vi)
        cout << v << endl;
    cout << endl;

    vector <int> vi2;

    unique_copy(begin(vi), end(vi), back_inserter(vi2));

    for (auto v : vi2)
        cout << v << endl;
    cout << endl;

    return 0;
}

// алгоритмы
// random_shuffle Отсортировать массив в случайном порядке 

int main777() {
    setlocale(LC_ALL, "rus");

    vector<int> vi{ 1,2,3,4,5,6};

    for (auto v : vi)
        cout << v << " ";
    cout << endl;

    auto rd = std::random_device{}; 
    auto rng = std::default_random_engine{ rd() };
    auto rng2 = std::mt19937(rd());

    shuffle(begin(vi), end(vi),rng2);
    for (auto v : vi)
        cout << v << " ";
    cout << endl;


    return 0;
}