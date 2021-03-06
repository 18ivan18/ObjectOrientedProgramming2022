# Писмен изпит по Обектно-ориентирано програмиране  

Дефинираните класове трябва да притежават всички необходими методи за осигуряване на правилен жизнен цикъл на обектите, вкл. голяма четворка и подходящи конструктори с параметри за създаване на обекти. 

Коректна реализация на семантика на преместването (“move semantics”) за всички класове носи бонус. 

Неспазването на добрите практики, ООП парадигмата, допускането на изтичане на памет (“memory leak”) или споделяне на памет за даден обект води до оценяване на съответната подточка с 0 точки.  

Допуска се използване на стандартните класове std::string и std::vector САМО в подточка Ж. 

## Задача  

A) Да се дефинира клас двойка SimplePair, който съдържа две полета – ключ и стойност, които са низове в динамичната памет с произволна дължина. Ключът започва задължително с малка латинска буква и съдържа само малки латински букви и знака '_'. При опит за инициализация на обект с некоректни данни, програмата да извежда подходящо текстово съобщение за грешка. 

Б) Да се дефинира клас за двойка InterpolationPair, който съдържа всички характеристики на класа SimplePair. За класа има следното допълнително ограничение – в стойността трябва да се среща поне един подниз, означаващ параметър, със следния синтаксис: %{<име_на_параметър>}, където <име_на_параметър> е последователност от малки латински букви. Не е позволено параметър да се среща повече от веднъж в дадена стойност. При опит за инициализация на обект с некоректни данни, програмата да извежда подходящо текстово съобщение за грешка. 

Пример: следният низ е валидна стойност за двойка от тип InterpolationPair: "My name is %{username}" 

В) Да се дефинира метод printValue за класа InterpolationPair, който изисква от потребителя да въведе низ, съответстващ на всеки един от параметрите в стойността на двойката, като извежда последователно имената на съответните параметри на екрана и изчаква потребителския вход. Всеки от въведените от потребителя низове трябва да са до 100 символа, ако потребителят въведе по-дълъг низ, останалите символи трябва да се отрязват. Методът да замества (интерполира) параметрите с въведеното съдържание и да извежда новия низ без да променя оригиналната стойност. 
Пример: за стойност за двойка от тип InterpolationPair: "My name is %{username}" програмата трябва да изиска от потребителя да въведе низ за username. Ако потребителят въведе, например, Georgi, се извежда "My name is Georgi". 
 

Г) Да се дефинира клас за двойка TagPair, който съдържа всички характеристики на класа SimplePair. За класа има следните допълнителни ограничения – стойността трябва задължително да започва и завършва с двойни кавички, ключът трябва задължително да завършва със символите _html. При опит за инициализация на обект с некоректни данни, програмата да извежда подходящо текстово съобщение за грешка. 

Пример: валидна двойка от типа TagPair: ключ – greeting_html и стойност – "How are `<b>`you? `</b>` `<br/>` `<hr/>`" 
 

Д) Да се дефинира метод printValue за класа TagPair, който разпознава следните 3 тагове в стойността на двойката: `<br/>`, <b> </b> и `<hr/>`.  Методът да извършва следните замествания на тези тагове като извежда новата стойност, без да изменя оригиналната двойка: 

- всяко срещане на таг `<br/>` се заменя с нов ред; 

- малките латински букви между отварящия таг <b> и затварящия таг </b> се заменят със съответните им главни латински букви, таговете се премахват, а останалите символи, ако има такива, не се променят; 

- всеки таг `<hr/>` се заменя с последователност от 20 знака '-', които се изписват на нов ред.  

Пример: за стойност за двойка от тип TagPair: "How are <b>you? </b> `<br/>` `<hr/>`" се извежда: 
How are YOU? 

-------------------- 

 

Е)  Да се дефинира клас за двойка ComplexPair, който съдържа всички характеристики на класа SimplePair, InterpolationPair и TagPair. Да се дефинира метод printValue, който първо прилага интерполация в низа на стойността (след въвеждане на стойности за параметрите), след това заменя всички тагове и накрая извежда получения резултат. 

Ж) Да се реализира клас KNYAML, който реализира модифициран YAML формат. Обект от този клас съдържа в себе си множество от двойки от четирите типа, описани по-горе (позволено е използване на стандартните класове от std). При опит за инициализация на обект с множество от двойки, в което има два еднакви ключа, програмата да извежда подходящо текстово съобщение за грешка. Обект от клас KNYAML може да се копира, като при извършване на копие той и новият обект имат еднакви двойки – ключ-стойност, но не поделят памет помежду си.  

З) Да се предефинира оператор [] за KNYAML, който по подаден ключ извежда на стандартния изход стойността на дадената двойка без възможност за нейната промяна. Не е нужно операторът да връща стойност. 
Пример: Ако обект knyaml от клас KNYAML съдържа горният примерен обект от клас TagPair, операторът knyaml["greeting_html"] би трябвало да изведе на стандартния изход текста от предишния пример. 

Да се дефинира шаблон на клас ResizableSet за множество от уникални елементи от тип Т. Броят на елементите в множеството е произволен и добяването на елемент към него винаги е възможно при наличие на оперативна памет. Копирането на елемент трябва да бъде забранено. 

Да се реализират: 

- метод за добавяне на елемент в множество; ако елементът вече съществува в множеството, методът трябва да извежда грешка с подходящо съобщение;  

- метод за изтриване на елемент от множество; ако елементът е успешно изтрит от множеството, методът връща стойност true, а в противен случай false. 

**Бонус:** Да се реализират методи за добавяне и премахване на елемент с константна сложност. 


Да се дефинира шаблон на клас `ResizableSet` за множество от уникални елементи от тип Т. Броят на елементите в множеството е произволен и добяването на елемент към него винаги е възможно при наличие на оперативна памет. Копирането на елемент трябва да бъде забранено. 

Да се реализират: 

- метод за добавяне на елемент в множество; ако елементът вече съществува в множеството, методът трябва да извежда грешка с подходящо съобщение;  
- метод за изтриване на елемент от множество; ако елементът е успешно изтрит от множеството, методът връща стойност true, а в противен случай false. 
Бонус: Да се реализират методи за добавяне и премахване на елемент с константна сложност. 

Да се реализира специализация на шаблона ResizableSet за модифициран YAML формат от двойки с име KNYAML, който се състои от множество от уникални двойки от типовете, дефинирани в точки А), Б), Г) и Е).  
Две двойки се считат за равни тогава, когато техните ключове съвпадат. 

# Решения 
## Compiled with
```
$ g++ --version 
g++ (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

`./compileAndRun.sh` or `./compileAndRun.sh 2> /dev/null` if you don't want to see any errors

which is a script that runs

```bash
g++ *.cpp -c
g++ *.o -o main
cat input.txt | main
rm main
```

where `input.txt` is a file in the same directory.

```
$ cat input.txt
Ivan
Ivan
Arabadzhiyski
Ivan
Dancing bears getting tortured
```
## Expected output
```
Simple Pair must begin with small letter
username: My name is Ivan
Interpolation Pair must contain atleast one interpolation string.

first: second: My name is Ivan Arabadzhiyski
Interpoltaion strings must be unique.

Interpolation strings cannot be empty.

Interpolation strings must contain only small letters.

"How are YOU? 
 --------------------"
Key must end with _html.

Value must start and end with '"'.

name: "How are YOU?, Ivan 
 --------------------"
Interpolation strings must contain only small letters.

"How YOU doin' 

 --------------------"
Element already in the set.

Element already in the set.

Element already in the set.

fact: "Do you think DANCING BEARS GETTING TORTURED is important?"
Element already in the set.
```

or 

```
username: My name is Ivan
first: second: My name is Ivan Arabadzhiyski
"How are YOU? 
 --------------------"
name: "How are YOU?, Ivan 
 --------------------"
"How YOU doin' 

 --------------------"
fact: "Do you think DANCING BEARS GETTING TORTURED is important?"
```

without the error messages