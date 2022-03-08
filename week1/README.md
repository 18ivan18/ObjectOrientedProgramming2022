# Разделна компилация

## Какво е компилация изобщо?
Това е процесът на създаване на изпълними файлове с машинен код от подадени входни файлове. В езика С++ така наречените source файлове играят ролята на входни. Те обикновено са с разширение `.cpp`, `.cxx`, `.cc`. За процесът на компилация използваме помощни програми наречени компилатори. Някои известни такива са `Microsoft Visual C++ compiler` за Windows, GCC (Gnu C Compiler), Clang - за UNIX системи.   

Примерите тук са правени от следната машина:
```console
uname -sr
Linux 5.4.0-99-generic

g++ --version
g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
```

## Какъв е процесът на компилация?
Всеки С++ source файл трябва да бъде превърнат в object файл.

Source файловете могат да използват други файлове, познати като header файлове, като използват `#include` директивата. Header файловете обикновено имат разширение `.h`, `.hpp`, или `.hxx`. Понякога нямат разширение изобщо като например всикчи файлове в С++ стандартната библиотека. Разширенията нямат значение за препроцесора.

Първата стъпка, която ще изпълни компилаторът, е препроцесорът. За всеки source файл препроцесорът ще изпълни всички препроцесорни директиви - те се разпознават с това, че започват с #. Например `#include` директивата ще бъде директно заменена със съдържането на съответния header файл. Препроцесорът създава `translation unit`.

`g++ -E main.cpp -o main.ii` - Creates the preprocessed file

```
g++ -c main.cpp
g++ -c print.cpp 
g++ -c sum.cpp 
g++ -o cpp-app sum.o print.o main.o
cpp-app 
1 + 2 = 3
1.5 + 2.5 = 4
```


```
g++ -E main-guarded.cpp 
# 1 "main-guarded.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "main-guarded.cpp"
# 1 "guarded.hpp" 1



class A
{
public:
    A(int a) : m_a(a) {}
    void setA(int a) { m_a = a; }
    int getA() const { return m_a; }

private:
    int m_a;
};
# 2 "main-guarded.cpp" 2


int main()
{
    A a(5);
    a.setA(0);
    return a.getA();
}

g++ -o guarded main-guarded.cpp
```
No problems


```
g++ -E main-unguarded.cpp 
# 1 "main-unguarded.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "main-unguarded.cpp"
# 1 "unguarded.hpp" 1
class A
{
public:
    A(int a) : m_a(a) {}
    void setA(int a) { m_a = a; }
    int getA() const { return m_a; }

private:
    int m_a;
};
# 2 "main-unguarded.cpp" 2
# 1 "unguarded.hpp" 1
class A
{
public:
    A(int a) : m_a(a) {}
    void setA(int a) { m_a = a; }
    int getA() const { return m_a; }

private:
    int m_a;
};
# 3 "main-unguarded.cpp" 2

int main(int argc, char *argv[])
{
    A a(5);
    a.setA(0);
    return a.getA();
}
g++ -o unguarded main-unguarded.cpp 
main-unguarded.cpp:2:0:

unguarded.hpp:1:7: error: redefinition of 'class A'
 class A {
       ^
In file included from main-unguarded.cpp:1:0:
unguarded.hpp:1:7: error: previous definition of 'class A'
 class A {
       ^
```
