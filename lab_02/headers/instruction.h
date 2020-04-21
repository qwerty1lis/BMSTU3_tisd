#ifndef INSTRUCTION_H

#define INSTRUCTION_H

#include <stdio.h>

void instruction()
{
    printf("\33[33m");
    printf("\n\t\t\t\t\t\t\t\t\t\tМеню:\n\
    \t\t\t\t\t\t\t1. Вывести таблицу.\n\
    \t\t\t\t\t\t\t2. Вывести массив ключей.\n\
    \t\t\t\t\t\t\t3. Вывести список отечественной технической литературы по указанной отрасли.\n\
    \t\t\t\t\t\t\t4. Добавить литературу в конец таблицы.\n\
    \t\t\t\t\t\t\t5. Удалить литературу из таблицы по индексу.\n\
    \t\t\t\t\t\t\t6. Отсортировать и вывести таблицу.\n\
    \t\t\t\t\t\t\t7. Отсортировать массив ключей.\n\
    \t\t\t\t\t\t\t8. Посмотреть результат сортировок.\n\
    \t\t\t\t\t\t\t9. Перемешать таблицу (и массив ключей)\n\
    \t\t\t\t\t\t\t0. Выход.\n");
    printf("\33[32m");
    printf("\t\t\t\t\t\t\t\t\tВыберите действие: "); // упорядоченную по количеству страниц
    printf("\e[0m");
}

#endif