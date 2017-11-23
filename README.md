# Telecom - NTI Contest
## Status
**Solved** : 3 / 5 (A, B, D)

**Checked** : 2 / 5 (A, B)

**Pending** : 1 (D)

## Website
[Website](http://dep1.iszf.irk.ru/wlcomm/)

## Problems
### A:
Определить центр окружности (x0,y0), заданной на битовой матрице 400x400 (1 - окружность, 0 - нет окружности) и вычислить ее радиус (R) с точностью до дискрета матрицы. На битовой матрице может присутствовать незначительное количество (порядка 1% от числа единиц) случайных единиц, не лежащих на окружности.

![Пример](http://dep1.iszf.irk.ru/wlcomm/problem_files/1/problem1.png)

Программа должна читать значения матрицы с потока stdin и выдавать результат (три целых числа, разделенных пробелами - x0 y0 R) на stdout.

То есть программа должна запускаться, как
solution.exe <input.dat >output.dat

Скорость выполнения программы - не более 10 секунд
Примеры входных и выходных файлов присоединены.

**SOLVED** : YES

**CHECKED** : NO


### B:
По неизвестному каналу с шумами передается последовательность 1000 чисел, выбранных случайно из 6-значных простых чисел от 100003 до 199999 включительно. Числа разделены переводом строки.

За счет шумов в некоторых переданных числах возможна ошибка типа замены одного из символов на следующий за ним (инкремент по модулю 10) (1 заменяется на 2, 4 на 5, 9 на 0 и т.д.) без изменения остальных символов числа. Эта ошибка для каждого числа может возникнуть не более, чем 1 раз (т.е. если число передано ошибочно, то ошибка только в одном символе, в двух символах одновременно ошибки быть не может). Например 100003 может стать 101003 или 200003.

Найти элементы последовательности переданные с ошибками, по возможности исправить эти ошибки. Что невозможно исправить - отметить звездочкой (например 100004*).

Максимальное число баллов - за полностью верный ответ, за каждую ошибку снимается 1 балл.

Скорость выполнения программы - не более 10 секунд

**SOLVED** : YES

**CHECKED** : NO


### C:

Объект движется в плоскости XY равномерно по прямой параллельно оси Х слева направо (от больших отрицательных к большим положительным значениям X, см.рисунок). Скорость объекта неизвестна и находится в пределах от 0.01 до 0.1 км/сек. В некий момент он въезжает в облако акустических излучателей, расположенных также в этой плоскости в квадратном полигоне размером [-30..30км,-30..30км], никогда не приближаясь к ним сильно близко (ближе 1 км).

Каждый акустический излучатель излучает постоянно строго синхронизированную периодическую последовательность импульсов, представимую в виде:
ui(t)=Ai*cos2(t*wi+Bi)

Количество излучателей известно и равно 7.

Координаты каждого излучателя известны с точностью 0.01км и перечислены ниже. Циклические частоты повторения импульсов wi каждого излучателя различны,
известны и перечислены ниже. Начальные фазы Bi и амплитуды Ai неизвестны и могут быть различны, но постоянны для каждого из излучателей.

Скорость звука считать не зависящей от частоты звука и равной 0.3км/сек, спадание амплитуды принимаемого звука с расстоянием считать отсутствующим.

Исходный файл содержит запись звуковых последовательностей через 0.03 сек., принятой объектом с каждого излучателя, как функции времени. Длина файла (обычно >20 МБ) выбрана такой, что начало и конец последовательностей соответствует очень большой удаленности от облака излучателей. Первый столбец файла - время, остальные столбцы - данные от различных излучателей, разделеные пробелами. Данные в последовательные моменты времени разделены переводом строки.

Ваша программа на основе указанной информации и исходного файла записи звуковых последовательностей должна определить положение объекта в момент t=0 с точностью не хуже 2км и модуль его скорости с точностью не хуже 0.01км/c (в среднем, по результатам 5 испытаний на созданных организаторами трека тестовых файлах).
Время работы программы должно быть не более 5мин.

Программа должна читать исходные данные со стандартного потока stdin и передавать их на stdout.
То есть программа должна работать так:
solution.exe <input.dat >output2.dat

*Ввод*:
t u1 u2 u3 u4 u5 u6 u7 

...
...
...

*Вывод*:
x0 y0 Vx

Примеры входных и выходных файлов присоединены

Характеристики излучателей:

Положение xi(км)	Положение yi(км)	wi(радиан/сек)	
Излучатель 1	10	20	2
Излучатель 2	15	21	3
Излучатель 3	-10	-25	4
Излучатель 4	-7	-5	6
Излучатель 5	8	1	7
Излучатель 6	-17	-5	8
Излучатель 7	18	11	9

![Поясняющий рисунок](http://dep1.iszf.irk.ru/wlcomm/problem_files/3/plot.png)

**SOLVED** : NO

**CHECKED** : NO


### D:
Задача №4. "Перемешивание". Максимальная оценка 28 баллов.
Система передачи данных перемешивает в случайном порядке поступающие на ее вход данные блоками по n байт (n = 54) и
передает результат на выход. Порядок байт внутри блока не меняется, меняется только порядок блоков.

Необходимо написать две программы (кодировщик и декодировщик) для организации устойчивой передачи данных через такой канал. Тестовые файлы выбираются организаторами трека и представляют собой 4 файла примерно одинаковой длины (9-10Мб каждый) в последовательности: аудиозапись (в формате WAV), документ OOffice без изображений (в формате ODT), текстовый файл (в формате TXT) и изображение (в формате BMP).

Программа-кодировщик, написанная участником должна иметь имя encode_blocks и читать файл ввода (имя - первый аргумент строки вызова) и передавать в файл вывода (имя - второй аргумент строки вызова), учитывая тип файла (значения от 1 до 4: 1-WAV, 2-ODT, 3-TXT, 4-BMP) т.е. работать при вызове:

encode_blocks ВходнойФайл ВыходнойФайл типФайла

Программа-декодировщик, написанная участником, должна иметь имя decode_blocks и читать файл с файла, задаваемого в строке вызова первым аргументом и
передавать его в файл, задаваемым вторым аргументом программы, третий аргумент программы - тип файла (1-WAV, 2-ODT, 3-TXT, 4-BMP).
Т.е. работать при вызове:

decode_blocks ВходнойФайл ВыходнойФайл типФайла

Тестовая программа (mix_blocks), перемешивающая поток данных, сделанная
разработчиками задачи, читает файл, сгенерированный encode_blocks и передает в файл вывода для работы decode_blocks, т.е. работает при вызове:

mix_blocks ВходнойФайл ВыходнойФайл

Если размер входного файла не кратен размеру блока перемешивания (54 байт),
в конец файла (до его перемешивания) дописываются нули, чтобы сделать размер исходного файла кратным
размеру блока перемешивания. (Но восстановить надо файл оригинальной длинны, без дополнительных нулей.)

Тестирование решения представляет собой следующие операции:

1) Кодирование файла программой участника:
encode_blocks ВходнойФайл ЗакодированныйФайл типФайла
если работает дольше 1 минуты - задача не решена

2) Измерение размеров передаваемого файла ЗакодированныйФайл

3) пропуск закодированного файла через программу для перемешивания:

mix_blocks ЗакодированныйФайл ИскаженныйФайл

4) Декодирование файла программой участника:

decode_blocks ИскаженныйФайл РаскодированныйФайл типФайла

если работает дольше 1 минуты - задача не решена

5) Проверка идентичности файлов ВходнойФайл и РаскодированныйФайл

Если ВходнойФайл и РаскодированныйФайл идентичны, задача считается решенной
и в зависимости от размера файла ЗакодированныйФайл начисляются баллы.

За каждый правильно переданный файл начисляется 4 балла. Дополнительные баллы начисляются за все файлы, кроме ODT за переданный объем данных согласно формуле:

если d<0.7*R Доп.баллы=4

если d>1.1*R Доп.баллы=0

если 0.7*R<d<1.1*R Доп.баллы = 4*(1.1*R-d)/(1.1*R-0.7*R)

где R - размер исходного файла, d - размер передаваемого файла.

Таким образом, правильно передавший все файлы может получить от 16 до 28 баллов.

Ограничение на быстродействие алгоритма шифрации-дешифрации - по одной минуте на каждый.

**SOLVED** : NO
**CHECKED** : NO


### E:
Необходимо принять с некоторого удаленного объекта сообщение длиной M единиц. Для этого важно понять хватит ли для этого наших возможностей. В нашем распоряжении 5 каналов связи в каждом присутствует свой стационарный шум. Для анализа свойств шума в каждом канале была записана реализация шумового сигнала в N =1000 отсчетов. Также известно, что вероятность передачи данных (полезного сигнала) с удаленного объекта составляет 60%, т.е. 60% времени объект передает данные и 40% времени «молчит». Амплитуда полезного сигнала не постоянна, но для каждого канала известно распределение вероятности его амплитуды. В качестве иллюстрации на рисунке приведены: верхний левый - реализация шумового сигнала, нижний левый - распределение вероятности амплитуды полезного сигнала, нижний правый – пример реализации сигнала, соответствующий распределению на левом нижнем рисунке, правый верхний – пример принятого сигнала AR, представляющего сумму шума AN и полезного сигнала AS:
AR = AN + AS

![Иллюстрация](http://dep1.iszf.irk.ru/wlcomm/problem_files/5/pic.png)

Верхний левый рисунок – пример шумового сигнала, нижний левый рисунок – пример распределения вероятности амплитуды полезного сигнала, пример реализации сигнала, соответствующий распределению на левом нижнем рисунке, правый верхний – пример принятого сигнала, представляющего сумму шума и полезного сигнала.


Из рисунка видно, что сигналы в каналах очень слабые, таким образом, рассматривается задача обнаружения сигнала (есть сигнал/нет сигнала). Решение о том, что в принятом сигнале присутствует полезный сигнал, принимается на основе сравнения амплитуды принятого сигнала с пороговым уровнем, если амплитуда больше или равна порогу, считаем, что полезный сигнал присутствует и отсутствует в противном случае. Пороговый уровень должен быть таким, чтобы сумма вероятности пропуска сигнала и вероятности ложных тревог (вероятность превышения шумом порога) была минимальной.

Если использование только одного из представленных каналов не позволяет решить задачу, тогда нужно задействовать несколько каналов и принимать решение о наличии сигнала голосованием – при условии, что хотя бы в двух каналах сигнал выше порогового уровня, то принимаем решение - полезный сигнал присутствует. Для каждого канала известна потребляемая мощность. При использовании нескольких каналов суммируется и их энергопотребление.

Таким образом, необходимо проанализировать представленные шумовые сигналы и гистограммы распределения полезного сигнала, определить пороговый уровень и принять решение о том, какие каналы нужно задействовать, для приема сообщения длинной М=50 с наименьшими энергетическими затратами, так чтобы с вероятностью 99% в сообщении было не более 2 ошибок.

Максимальное число баллов - за полностью верный ответ, включающий:

1. Номера каналов; (3 балла)

2. Найдены соответствующие им пороговые уровни; (10 баллов)

3. Определена вероятность того, что будет верно обнаружен единичный полезный сигнал (с точность до 4-го знака); (15 баллов)

4. Определена вероятность того, что сообщение будет передано с не более чем 2 ошибками (с точность до 4-го знака); (5 баллов)

5. Рассчитана энергия для приема одного сигнала. (2 балла)

В задаче (3):

за ошибку в четвертом знаке снимается 5 балла.

за ошибку в третьем знаке снимается 15 баллов.

В задаче (4):

за ошибку в четвертом знаке снимается 2 балла.

за ошибку в третьем знаке снимается 5 баллов.

Скорость выполнения программы - не более 10 секунд

## Examples:
- [Problem A](http://dep1.iszf.irk.ru/wlcomm/problem_files/1/examples.zip)
- [Problem B](http://dep1.iszf.irk.ru/wlcomm/problem_files/2/examples.zip)
- [Problem C](http://dep1.iszf.irk.ru/wlcomm/problem_files/3/examples.zip)
- [Problem D](http://dep1.iszf.irk.ru/wlcomm/problem_files/4/examples.zip)
- [Problem E](http://dep1.iszf.irk.ru/wlcomm/problem_files/5/examples.zip)
