# LR5
ЛР5. Шаблоны классов

Реализовать шаблон структуры данных «вектор» по аналогии с std::vector.

Методы класса:
1) Конструктор
2) Конструктор копирования
3) Деструктор
4) Оператор присваивания (=)
5) Оператор []
6) at
7) front
8) back
9) data
10) empty
11) size
12) reserve
13) capacity
14) clear
15) insert
16) erase
17) push_back
18) pop_back
19) resize
20) swap

По аналогии с std::vector, в исключительных ситуациях должны бросаться стандартные
исключения.

Память для элементов вектора выделять в виде непрерывной области памяти. Если для
нового элемента вектора выделенной памяти хватает, выделения памяти не происходит.
Если для нового элемента памяти не хватает, производится выделение новой области
памяти размером ⌊𝑛 ⋅ 𝑘⌋, где 𝑛 – память под текущее кол-во элементов вектора, 𝑘 –
коэффициент. Коэффициент принять равным 1.5.

Например:

size (размер) capacity (вместительность)

1--------------1

2--------------2

3--------------3

4--------------4

5--------------6

6--------------6

7--------------9

8--------------9

9--------------9

10-------------13

11-------------13

12-------------13

13-------------13

14-------------19

Продемонстрировать работу контейнера на стандартных типах данных и пользовательском
типе.
