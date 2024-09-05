#include <iostream>
#include <string>
#include <memory>
#include <fstream>

//#include <filesystem>//после с++17
//#include <experimental/filesystem>

// std::ifstream - чтение файла
// std::ofstream - запись в файл
// std::fstream - универсальный класс для работы с файлом

//std::ios::out запись
//std::ios::in  чтение
//std::ios::app добавление при записи
//std::ios::binary работа с бинарным файлом

/*
Режимы открытия файлов
   app — открывает файл в режиме добавления;

   ate — переходит в конец файла перед чтением/записью;

   binary — открывает файл в бинарном режиме (вместо текстового режима);

   in — открывает файл в режиме чтения (по умолчанию для ifstream);

   out — открывает файл в режиме записи (по умолчанию для ofstream);

   trunc — удаляет файл, если он уже существует.

------------------------------------------------------------------------

ifstream по умолчанию работает в режиме ios::in;

ofstream по умолчанию работает в режиме ios::out;

fstream по умолчанию работает в режиме ios::in ИЛИ ios::out, 
что означает, что вы можете выполнять как чтение содержимого файла,
так и запись данных в файл.
*/

/*

Функции seekg() и seekp() принимают следующие два параметра:

   первый параметр — это смещение на которое следует переместить файловый указатель (измеряется в байтах);

   второй параметр — это флаг ios, который обозначает место, от которого следует отталкиваться при выполнении смещения.

Флаги ios, которые принимают функции seekg() и seekp() в качестве второго параметра:

   beg — cмещение относительно начала файла (по умолчанию);

   cur — cмещение относительно текущего местоположения файлового указателя;

   end — смещение относительно конца файла.

Положительное смещение означает перемещение файлового указателя в сторону конца файла,
тогда как отрицательное смещение означает перемещение файлового указателя в сторону начала файла.
*/




// ofstream
int main() {
    setlocale(LC_ALL, "Russian");


    std::string path = "test_ofstream.txt";
    std::ofstream o;
    o.open(path);
    if (o.is_open()) {
        o << "Test message! ";
        o << 555;
        std::string message {"Мое сообщение для записи в файл"};
        o << message << std::endl;
        o.close();
    }
    else {
        std::cout << "Error open file " << path;
    }
    return 0;
}

// ifstream
int main2() {
    setlocale(LC_ALL, "Russian");


    std::string path = "test_ofstream.txt";
    std::ifstream ifs;
    ifs.open(path);
    if (ifs.is_open()) {

        /*
        char c;
        while (ifs.get(c)){

            ifs.get(c);
            std::cout << c << std::endl;
        }
*/

        /*
        char c;
        while (ifs.get(c)){
          std::cout << c;
        }
        */  

        /*
        while (!ifs.eof()){
            std::string message;
            ifs >> message;
            std::cout << message << std::endl;
        }
        */
        /*
        while (!ifs.eof()){
            std::string message;
            std::getline (ifs,message);
            std::cout << message;
        }*/


        /*
        while (!ifs.eof()){
            std::string message;
            std::getline (ifs,message);
            std::cout << message << std::endl;
        }*/

        ifs.close();
    }
    else {
        std::cout << "Error open file " << path;
    }
    return 0;
}


int main3() {

    setlocale(LC_ALL, "Russian");
    //  SetConsoleCP(1251)
    //  SetConsoleCP(866)

    std::fstream ifs("test.txt", std::ios::out | std::ios::in | std::ios::app);
    if (ifs.is_open()) {
        ifs << "My first message\n";
        ifs.close();
    }

    ifs.open("test.txt", std::fstream::in);
    if (ifs.is_open()) {
        while (!ifs.eof()) {
            std::string str;
            std::getline(ifs, str);
            std::cout << str << std::endl;
        }
        ifs.close();
    }
    return 0;

}

class Point {

    int x;
    int y;
public:
    Point(int x = 0, int y = 0) :x{ x }, y{ y }{}
    friend std::ostream& operator<< (std::ostream&, const Point&);
    friend std::istream& operator>> (std::istream&, Point&);

};

std::ostream& operator<< (std::ostream& io, const Point& point) {
    io << point.x << " " << point.y;
    return io;
}

std::istream& operator>> (std::istream& io, Point& point) {
    io >> point.x >> point.y;
    return io;
}
// save class as text
int main4() {
    setlocale(LC_ALL, "Russian");
    //  SetConsoleCP(1251)
    //  SetConsoleCP(866)

    std::string path = "object.txt";
    Point point{ 10,20 };

    std::fstream ifs(path, std::ios::out | std::ios::in | std::ios::app);

    if (!ifs.is_open()) {
        std::cout << "Error open file " << path;
        return 0;
    }
    ifs << point << '\n';
    ifs.close();


    ifs.open(path, std::fstream::out | std::fstream::in | std::fstream::app);
    if (!ifs.is_open()) {
        std::cout << "Error open file " << path;
        return 0;
    }
    Point p2;
    std::cout << p2 << std::endl;
    ifs >> p2;
    ifs.close();
    std::cout << p2 << std::endl;
    return 0;
}

// save class as binary
int main5() {
    setlocale(LC_ALL, "Russian");
    //  SetConsoleCP(1251)
    //  SetConsoleCP(866)

    std::string path = "object2.txt";
    Point point{ 10,20 };
    Point point1{ 40,50 };
    Point point2{ 60,70 };

    std::fstream ifs(path, std::fstream::out | std::fstream::in | std::fstream::app | std::fstream::binary);

    if (!ifs.is_open()) {
        std::cout << "Error open file " << path;
        return 0;
    }
    ifs.write((char*)&point, sizeof(Point));
    ifs.write((char*)&point1, sizeof(Point));
    ifs.write((char*)&point2, sizeof(Point));
    ifs.close();

    ifs.open(path, std::fstream::out | std::fstream::in | std::fstream::app);
    if (!ifs.is_open()) {
        std::cout << "Error open file " << path;
        return 0;
    }
    while (true) {
        Point p;
        ifs.read((char*)&p, sizeof(Point));
        if (ifs.eof())
            break;
        std::cout << p << std::endl;
    }
    ifs.close();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    ifs.open(path, std::fstream::out | std::fstream::in | std::fstream::app);
    ifs.seekg(sizeof(Point));
    Point p;
    ifs.read((char*)&p, sizeof(Point));
    std::cout << p << std::endl;

    return 0;
}

/* int argc, char* argv[]   количество аргументов, значения аргументов */
int main6(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    std::cout << argv[0] << std::endl;

    if (argc > 1) {
        std::cout << argv[1] << std::endl;
    }

    // пример работы с файлом (просмотр в цикле).
    return 0;
}



/*

namespace fs = std::filesystem;
int main7(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");

    auto Path = fs::current_path();
    std::cout << "cur path:" << Path << std::endl;
    if (!fs::exists("new_folder")) {
        if (fs::create_directory("new_folder")) {
            std::cout << "create directory\n";
        }
        else {
            std::cout << "error create directory\n";
        }
    }

    //return 0;


    fs::current_path("new_folder");//перееходим в папку new_folder
    std::ofstream file("1.txt");
    file << "this file in new folder\n";
    file.close();

    if (fs::exists("1.txt"))
        std::cout << "file is create\n";

    fs::current_path("..");
    fs::copy("new_folder", "create");
    //fs::rename("new_folder", "C:/tmp/old_folder");
    //std::cout << "directory rename & copy\n";
    //fs::remove_all("create");//удаляет папку со всем его сождержимым
    //fs::remove();//удаляет файл или пустую папку
    //fs::remove_all("C:/tmp/old_folder");
    //if (fs::exists("../../Debug")) {
    //        std::cout << "have Debug\n";
    //}

    return 0;
}


class MyException : std::exception {
    int index;
public:
    MyException(int ind) :std::exception() {
        index = ind;
    }
    int getIndex() const { return index; }

};

class MyMass {
    static const int size = 10;
    int mass[10];
public:
    int& operator[] (int i) {
        if (i<0 || i >size)
            throw MyException(i);
        return mass[i];
    }
};

void foo(int value) {
    if (value < 0) {
        //throw value;
        //throw "Отрицательное значение";
        //throw std::exception("Erorr");
        //throw 123.56;
    }
    std::cout << "Value is " << std::endl;
}

// Исключения
int main8(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    /*try {
        std::string path = "test_ofstream.txt";
        std::ifstream ifs;
        ifs.exceptions(std::ifstream::badbit | std::ifstream::failbit);
        std::cout << "Попытка открыть файл" << std::endl;
        ifs.open(path);
        std::cout << "Файл открыт" << std::endl;
    }
    catch (std::fstream::failure ex) {
        std::cout << ex.what() << std::endl;
        std::cout << ex.code() << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }*/


    //foo(11);

    /*try {        
        foo(-12);
    }
    catch (int i) {
        std::cout << "int error " << i << std::endl;
    }
    catch (const char* er) {
        std::cout << "const char* error " << er << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    catch(...){
        std::cout << "Что-то пошло не так!" << std::endl;
    }

    MyMass mass;
    std::cout << mass[12] << std::endl;
    // попробовать поймать базовый класс!!!!

    try {        
        std::cout << mass[12] << std::endl;
    }catch(MyException& ex) {
        std::cout << "wrong index " << ex.getIndex() << std::endl;
    }


    return 0;
}

*/


// Пространство имен!
// Обьединение
// Вложение
// Безимянное пространство



//void printMessage(char* m) {
//    std::cout << m << std::endl;
//}
//
//void printMessage(char* m) {
//    std::cout << m << std::endl;
//    std::cout << m << std::endl;
//    std::cout << m << std::endl;
//    std::cout << m << std::endl;
//}


int main9(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    
    return 0;
}



/*

int main()
{
    using namespace std;

    ifstream inf("SomeText.txt");

    // Если мы не можем открыть файл для чтения его содержимого,
    if (!inf)
    {
        // то выводим следующую ошибку и выполняем функцию exit()
        cerr << "Uh oh, SomeText.txt could not be opened for reading!" << endl;
        exit(1);
    }

    string strData;

    inf.seekg(6); // перемещаемся к 6-му символу первой строки
    // Получаем остальную часть строки и выводим её на экран
    getline(inf, strData);
    cout << strData << endl;

    inf.seekg(9, ios::cur); // перемещаемся вперед на 9 байт относительно текущего местоположения файлового указателя
    // Получаем остальную часть строки и выводим её на экран
    getline(inf, strData);
    cout << strData << endl;

    inf.seekg(-14, ios::end); // перемещаемся на 14 байт назад относительно конца файла
    // Получаем остальную часть строки и выводим её на экран
    getline(inf, strData);
    cout << strData << endl;

    return 0;
}


int main()
{
    using namespace std;
 
    // Мы должны указать как in, так и out, поскольку используем fstream
    fstream iofile("SomeText.txt", ios::in | ios::out);
 
    // Если мы не можем открыть iofile,
    if (!iofile)
    {
        // то выводим сообщение об ошибке и выполняем функцию exit()
        cerr << "Uh oh, SomeText.txt could not be opened!" << endl;
        exit(1);
    }
 
    char chChar;
 
    // Пока есть данные для обработки
    while (iofile.get(chChar))
    {
        switch (chChar)
        {
        // Если мы нашли гласную букву,
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
 
            // то перемещаемся на один символ назад относительно текущего местоположения файлового указателя
            iofile.seekg(-1, ios::cur);
 
            // Поскольку мы выполнили операцию поиска, то теперь можем переключиться на запись данных в файл.
            // Заменим найденную гласную букву символом #
            iofile << '#';
 
            // Теперь нам нужно вернуться назад в режим чтения файла.
            // Выполняем функцию seekg() к текущей позиции
            iofile.seekg(iofile.tellg(), ios::beg);
 
            break;
        }
    }
 
    return 0;
}


https://ravesli.com/urok-209-funktsional-klassov-ostream-i-ios-formatirovanie-vuvoda/
*/

