# s21_matrix

## Описание

s21_matrix - это реализация библиотеки для работы с матрицами на языке C. Проект разработан как часть образовательной программы, направленной на углубление понимания операций с матрицами, управления памятью и программирования на C.

Библиотека разработана на языке C стандарта C11 с использованием компилятора gcc.</br>
Библиотека оформлена как статическая с названием `s21_matrix.a`.</br>
Проект полностью покрыт unit-тестами с использованием библиотеки Check.

## Реализованные функции

1. **create_matrix** - Создание матрицы;
2. **remove_matrix** - Очистка и уничтожение матрицы;
3. **eq_matrix** - Сравнение матриц;
4. **sum_matrix** - Сложение матриц;
5. **sub_matrix** - Вычитание матриц;
6. **mult_matrix** - Умножение матриц;
7. **mult_number** - Умножение матрицы на число;
8. **transpose** - Транспонирование матрицы;
9. **determinant** - Вычисление определителя матрицы;
10. **calc_complements** - Вычисление матрицы алгебраических дополнений;
11. **inverse_matrix** - Поиск обратной матрицы.

## Сборка и использование

Для сборки библиотеки и запуска тестов используется Makefile со следующими целями:

- `make all`: сборка всего проекта;
- `make clean`: очистка файлов сборки;
- `make test`: запуск unit-тестов;
- `make s21_matrix.a`: сборка статической библиотеки;
- `make gcov_report`: генерация отчета о покрытии тестами в формате HTML.

## Лицензия

Этот проект является частью образовательной программы [School21](https://21-school.ru/) - образовательный проект от Сбер для разработчиков