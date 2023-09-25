#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include < cstdio >
#include <cstdlib>
#include <ctime>

class CStr
{
    char* s;
    void generate (int length)//private-метод для генерации случайной строки заданной длины (<=20 строчных латинских букв + нуль, возвращает указатель на строку)
    {
        
        s = new char[length + 1]; 
        for (int i = 0; i < length; i++)
            s[i] = 'a' + rand() % 26; 
        s[length] = '\0';
    };
public:
    
    CStr() //конструктор по умолчанию (без параметров), создающий случайную строку случайной длины (от 1 до 20 символов) и использующий private-метод генерации
    {
        int len = 1 + rand() % 20;
        generate(len);

    };
    CStr (char* str) //конструктор с параметром «строка» (char *, заканчивается нулем)
    {
       s = new char[strlen(str)+1];
       strcpy (s, str);
    };
    CStr(int lenth) //конструктор с параметром «длина строки» (<=20), использующий private-метод генерации
    {
        generate(lenth);
    };
    CStr (CStr& obj) //конструктор копий
    {
        s = new char[strlen(obj.s) + 1];
        strcpy(s, obj.s);
    };
    ~CStr() //деструктор
    {
        delete[]s; 
    };
    CStr& operator=(CStr& obj1) //оператор присваивания объекта СStr, глубокое копирование из-за динамического выделения памяти
    {
        if (this == &obj1) 
            return *this;   //Проверка на самоприсваивание
        delete s; 
       // len = obj1.get_length() + 1;
        s = new char[obj1.get_length() + 1]; //динамическое выделение памяти
        strcpy(s, obj1.s);  
        return *this;      
    };
    CStr& operator=(char *str) 
    {
        s = new char[strlen(str) + 1]; 
        strcpy(s, str);  
        return *this;      
    };
   /* bool operator<(CStr& obj) //оператор сравнения > (или <) объектов CStr по их содержимому (сравнение строк)
    {
        if (strcmp(s, obj.s) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    };*/
  bool operator<(const CStr& ob)
    {
        if (strcmp(s, ob.s) < 0) 
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    int get_length()//метод, возвращающий длину строки.
    {
        return strlen(s);
    };
    friend std::ostream& operator<< (std::ostream& stream, CStr& obj) //friend-оператор вывода в поток 
    {
        stream << obj.s << std::endl;
        return stream;
    };

    void PrintX()
    {
        std::cout << s << std::endl;
    };
};

class CStrArray
{
    CStr* arr;
    int length;

public:
    CStrArray(int leng) //конструктор с параметром «длина массива»
    {
        arr = new CStr[leng];
        length = leng;
    };
    ~CStrArray() //деструктор
    {
        delete[]arr;
    };
    CStr& operator[](int index)
    {
        return arr[index];
    };
    void sort_by_content() //сортировка по содержимому строк (любая)
    {
        CStr VST;
        
        int i = 0;
        while (i < length - 1) 
        {
            if (arr[i] < arr[i + 1])
            {
                i = i + 1;
            }
            else
            {
                VST = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = VST;
                i = 0;
            }
        }
   
    }
    void sort_by_length() //сортировка по длине строк (любая)
    {
        CStr VST;// простейший алгоритм сортировки

        int i = 0;
        while (i < length - 1)
        {
            if (arr[i].get_length() < arr[i + 1].get_length())
            {
                i = i + 1;
            }
            else
            {
                VST = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = VST;
                i = 0;
            }
        }

    };
    bool check_sort() //проверка упорядоченности массива по содержимому строк.
    {
        int i = 0;
        int c = 0;
        while (i < length - 1)
        {
            if (arr[i] < arr[i + 1])
            {
                c=c;
            }
            else
            {
                c = c + 1;
            }
        }
        if (c == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
    friend std::ostream& operator<<(std::ostream& stream, CStrArray &obj) //оператор << (не выводить на экран массивы длиной больше 50).
    {
        for (int i = 0; i < obj.length; i++)
            stream << obj.arr[i];
        return stream;
    };
};

int main()
{
   /* CStr S1;
    S1.PrintX();
    char* d = new char[6] {'h','e','l','l','o','\0'};
    CStr S2(d);
    S2.PrintX();
    int o = 5;
    CStr S3(o);
    S3.PrintX();
    CStr S4(S3);
    S4.PrintX();*/
    srand( time (NULL));
    setlocale(LC_ALL, "rus");
    std::cout << "Введите длину массива " << std::endl;
    int len;
    std::cin >> len;

    CStrArray array(len);
    std::cout << array << std::endl;

   array.sort_by_content();
    std::cout << array << std::endl;

    bool t = array.check_sort();
    std::cout << t << std::endl;

    array.sort_by_length();
    std::cout << array << std::endl;
    
    
    

    
    //std::cout << std::endl;
    //char D[8];
    //CStr ST1(D);
   




}

