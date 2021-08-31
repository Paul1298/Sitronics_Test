# Sitronics_Test

Железнодорожная сеть задана набором станций. Между некоторыми станциями проложены пути. Длина путей задается целыми числами. Пути двунаправленные одноколейные (поезда, идущие по одному пути навстречу друг другу сталкиваются). Станция - точка (поезда, оказавшиеся на станции в один момент времени, сталкиваются). Маршруты поездов заданы списком станций, через которые они проезжают. Скорости поездов одинаковые (скажем, равны единице). Поезда начинают движение одновременно. После достижения конечной станции поезд исчезает. Поезд представляет собой точку.

*Дополнение: маршруты состоят как минимум из 2х станций.*

**Формат входного файла:**

В первой строке входного файла два числа: station_num и path_num, где station_num — количество станций в железнодорожной сети, а path_num — количество путей между станциями.
Станции нумеруются с нуля.
Следующие path_num строк содержат по три числа — номер станции отправления, номер станции прибытия и длина пути между ними.
Следующая строка содержит route_num - кол-во маршрутов (поездов). Следующие route_num строк - списки номеров станций, через которые проезжают поезда.

**Формат выходного файла:**

Отчёт о произошедших столкновениях или их отсутствии.

В input.txt содержатся входные данные для примера с двумя столкновениями между станциями.
