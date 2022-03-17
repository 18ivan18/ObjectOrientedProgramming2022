# Unit testing

> Definition

The testing of individual software components (units).

> Какво представлява unit?

Unit е най-малката частица код, която може да се test-ва (или си заслужава да се тества).
Обикновено това може да е цял модул, но обикновенно е функция или метод.
Има 1 или няколко входа и **един** изход.


|Language|Test framework|
|:--:|:--:|
|C++       |CppUnit, doctest|
|C#        |NUnit, csUnit   |
|Java      |JUnit, Jtest    |
|JavaScript|JSUnit, QUnit   |

*Here are listed some of the most famous frameworks*

> Какъв подход се използва за писане на unit тестове?

- най-използвания подход е test \- function \- expected value
- идеята е, че тестваме точно определена функционалност
- В помощ на unit test-овете влизат method stubs, mock objects, fakes и test harnesses, 
като идеята е, че те ни позволяват да се фокусираме над това, което тестваме
- Целта на unit test-овете е да изолират всяка една част на програмата и да покажат, че е коректна.
- Unit test-овете намират проблеми от рано в development пр](https://github.com/doctest/doctest)n testing.)*

## Code coverage

Code coverage is a measurement of how many lines/blocks/arcs of your code are executed while the automated tests are running.

## White vs Black box testing

- Black Box Testing is a software testing method in which the internal structure/design/implementation of the item being tested is not known to the tester.
- White Box Testing is a software testing method in which the internal structure/design/implementation of the item being tested is known to the tester.

## Кой пише unit тестове?

- Usually the software developers write the tests (the programmers that write the code).

## Benefits of unit testing

- Unit testing increases confidence in changing / maintaining code
- Codes are more reusable. Because the code is more modular due to being able to be unit tested.
- The cost of fixing a defect detected during unit testing is lesser in comparison to that of defects detected at higher levels.
- Debugging is easy.

## Some real life example

Lets say you have a program comprising of two units and the only test you perform is system testing. (You skip unit and integration testing.)
During testing, you find a bug. Now, how will you determine the cause of the problem?

Soo:

- Is the bug due to an error in unit 1?
- Is the bug due to an error in unit 2?
- Is the bug due to errors in both units?
- Is the bug due to an error in the interface between the units?
- Is the bug due to an error in the test or test case?

## Doctest
[Линк към Doctest repo-то](https://github.com/doctest/doctest)

# Test Driven Development (TDD)
**Test-driven development (TDD)** is a software development process that relies on the repetition of a very short development cycle:

- first the developer writes a failing test case that defines a desired improvement or new function;
- then produces code to pass the test;
- and finally refactors the new code to acceptable standards.

Test-driven development is related to the test-first programming concepts of extreme programming, and often linked to an agile programming approach. In its pure form, TDD has benefits, but it also has drawbacks. But we can use some practices to improve quality of code in our projects.

TDD workflow could be described as repetition of following steps (shown on picture):

- define which feature should be implemented;
- add a test(s) for defined use cases;
- compile, run tests and check do we have any error;
- write the code, make test work;
- refactor code;
- repeat tests, fix the code if there are failing tests;
- commit changes;
- switch to the next feature (repeat the whole process starting from the first step).

![asd](TDD.png)

## Unit testing and frameworks
As you know, software testing includes many different forms of tests:

- unit tests;
- integration tests;
- regression tests;
- acceptance tests;
- performance tests.
In this article we'll talk mostly about unit testing, although some of these techniques could be also used for other test types.

Unit testing is a method by which individual units of source code are tested to determine if they are correctly working. A unit is the smallest testable part of an application. In procedural programming a unit may be an individual function or procedure. Unit tests are usually created by developers. The goal of unit testing is to isolate each part of the program, and show that the individual parts are correctly working. A unit test is a strict, written contract that the piece of code must satisfy.

Use of unit tests has several benefits:

- facilitate changes — unit tests allow programmers to refactor code at a later date, and be sure that code still works correctly;
- simplify integration — unit testing may reduce uncertainty in the units themselves and can be used in a bottom-up testing style approach. By testing the parts of a program first, and then testing the sum of its parts, integration testing becomes much easier;
- unit testing provides a sort of living documentation for the system. Developers can look at the unit test's code to gain a basic understanding of the implemented API.

## Unit testing frameworks
To simplify development of unit tests, unit test frameworks are usually used. Unit testing framework should provide following functionality:

- Writing unit tests should be simple and obvious for new users.
- Framework should allow advanced users to perform non-trivial tests.
- Test module should be able to have many small test cases and developer should be able to group them into test suites.
- At the beginning of the development users may want to see verbose and descriptive error message, whereas during the regression testing they may just want only to know if are any failed tests.
- For small test modules execution time should prevail over compilation time: users don't want to wait a minute to compile a test that takes a second to run.
- For long running and complex tests users may want to be able to see the test's progress.
- Execution of individual tests should be independent of other tests. For example, termination (crashing) of one test shouldn't lead to skipping of all other tests.
- Simple tests shouldn't require an external library.
- Almost any programming language now has several unit testing frameworks. The most widely spread are frameworks from so called `xUnit` family of frameworks (JUnit, CppUnit, NUnit, etc.). Frameworks from this family are very simple in use, and share common features & architecture. Each of such frameworks consists from:

- Assertions, that check individual conditions;
- Test cases, that combine several assertions, based on some common functionality;
- Test suites, that combine several tests, logically related to each other;
- Fixtures, that provide setup of data or state, needed for execution of some tests, and cleanup of state and/or data after the test is finished. (Some frameworks provide separate per-test case, per-test suite, and/or global fixtures)
- Frameworks also include execution monitor, that controls how tests are executed, and collects data about failed tests.
## How to organize tests
Usually unit tests should be created for all publicly exposed functions — free functions not declared as static, and all public functions of classes, including public constructors and operators. Unit tests should cover all main paths through functions, including different branches of conditionals, loops, etc. Your unit test should handle both trivial, and edge cases, providing wrong and/or random data, so you will be able to test error handling. You can find more advices on unit tests code organization in **[following article](https://geosoft.no/unittesting.html)**.

Test cases are often combined into test suites by some criteria — common functionality, different use cases for same functions, common fixtures, etc. Fixtures are used to perform setup and cleanup of data that are needed to perform test cases — this also allows unit tests to be very short and easy to understand.

There are some recommended ways to implement tests:

- your test case should test only one thing;
- test case should be short;
- test should run fast, so it will possible to run it very often;
- each test should work independent of other tests. Broken test shouldn't prevent other tests from execution;
- tests shouldn't be dependent on the order of their execution.
- Some people argues, that combining of all test cases into big functions, improves readability of code, and make it more concise. But there are arguments against this approach (some of them are mentioned in following document):

- if fatal error happens, or an exception is thrown by some check, then the rest of tests will be skipped and there is no way to prevent this;
- there is no way to perform only checks for a particular subsystem of the tested unit.

Testability of code also depends on its design. Sometimes it's very hard to write unit tests, because functionality to be tested is hidden behind many interfaces, or there are many dependencies, so it's hard to set up the test correctly. There are some suggestions on how code should be written to allow easier writing of unit tests for it:

- code should be loosely coupled — class or function should have as few dependencies as possible;
- avoid creation of particular instances of complex classes inside your class. It's better to pass pointers/references to these classes to your class/function — this will allow to use mocking to test your code;
- you should try to minimize public API that is provided by class — it's better to write several classes, that perform separate tasks, instead of creating one class, that does everything.
More advice on writing testable code you can find in following blog post.

## Mocking
In a unit test, mock objects can simulate behavior of complex, real (non-mock) objects and they are very useful when a real object is impractical or impossible to incorporate into a unit test. If an object has any of the following characteristics, it may be useful to use a mock object instead:

- supplies non-deterministic results (e.g., current time or current temperature);
- has states that are difficult to create or reproduce (e.g. a network error);
- slow (e.g. a complete database, which would have to be initialized before the test);
- does not exist yet, or may change behavior;
- would have to include information and methods exclusively for testing purposes (and not for its actual task).

Mock objects have the same interface as real objects they mimic, allowing a client object to remain unaware of whether it's using a real object, or a mock object. Many available mock object frameworks allow the programmer to specify which, and in what order, methods will be invoked on a mock object, and what parameters will be passed to them, as well as what values that will be returned. Thus, the behavior of a complex object, such as a network socket, can be emulated by a mock object, allowing the programmer to discover whether the object being tested responds appropriately to the wide variety of states, such objects may be in.

Typical workflow looks following way:

- you should have an interface for class that you will test, so you can have mocked class and real-world class;
- you create a mocked class using some framework (you can also write it yourself, but it's bad idea);
- you have a code, that you want to test against mocked object;
- you create a test case that will use your mocked object instead of real-world one. Inside this test case you do following:
  - you create an instance of mocked class;
  - you setup behavior and expectations on mocked object — which methods should be called (or not called), which data will be returned for a particular call, etc.
  - you run your code that will use mocked object some way;
  - after execution of your code, you evaluate results of execution and check expectations against actual results — usually this is done automatically by framework, when a mocked object is destroyed.

# Задачи

## За всички задачи да бъдат напиасни тестове със 100% code coverage 

> Задача 1

1. Да се дефинира клас Dictionary, който представлява тълковен речник. Нека речникът се състои от двойки дума\-тълкуване. В един речник не може да има повече от 500 такива двойки.
- да се дефинира подходящ клас, описващ една двойка дума тълкувание със следните методи
    - `init(const char*, const char*)` - инициализира структурата
    - `copy()` - връща нова структура, копие на оригиналната
    - `print()` - принтира двойката на екрана по подходящ начин
    - `deleteDynamic()` - зачиства динамичната памет
- за класа `Dictionary` да се дефинират:
    - `init(Record*, int)` - инициализира речника с масив от двойки
    - `print()` - принтира съдържанието на речника
    - `add(const Record&)` - добавя нова двойка към речника
    - `remove(const char*)` - премахва дадена двойка, като търсенето става по думата
    - `findMeaning(const char*)` - връща значението на дадена дума
    - `getByIndex(int index)` - връща значението на двойка с номер index
    - `sort()` - сортира двойките лексикографски по първи член на двойката (не по значението)
    - `deleteDynamic()` - обичайното 

> Задача 2. 
Да се създаде

```enum Position {JUNIOR_DEV, DEV, SENIOR_DEV, QA, MANAGER};```

Да се създаде структура `Developer` със следните полета:
- mId - идентификационен номер в компанията. Представлява случайно генерирано 4-цифрено число.
- mFirstName;
- mLastName;
- mPosition - позиция, която заема. Една от константите Position.

Да се реализират функции:
- за инициализация на полетата на developer;
- за зачистване на диманичната памет  на developer;
- за записване на Developer във файл. При записване във файл developer-a да се добавя на края на съществуващия файл;
- за четене на полетата на Developer от файл;
- за принтиране на стандартния изход. Използвайте записването във файл.

Помислете как можете да добавите поле на Developer, което представлява прекия мениджър на developer-a и може да се заема само от друг Developer, чиято позиция е Manager.

П.П. Знанията за решаване на тази задача ще дойдат малко по-късно.

# Домашно
Напишете тестове за класът `Vector` от миналата седмица.