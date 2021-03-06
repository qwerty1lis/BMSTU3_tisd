#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "instructions.h"
#include "struct.h"
#include "hash.h"
#include "bin_tree.h"
#include "binary_search_tree.h"

#define MAX_COUNT_COLLISIONS 10
#define LEN_HASH_TABLE 10

#define MODE_HASH_TABLE 1
#define MODE_BST 2 // BINARY SEARCH TREE.
#define MODE_BALANCED_TREE 3

#define FILE_OPEN_HASH "text/text.txt"

#define OK 0

int main(void)
{
    FILE *f = fopen(FILE_OPEN_HASH, "r");
    node_t *tree_avl = NULL; // АВЛ

    input_tree(f, &tree_avl);
    print_avl(tree_avl, "root", 0);

    printf("Балансировка:\n");
    print_avl(tree_avl, "root", 0);

    fclose(f);
    return OK;
}

// int main(void)
// {
//     char word[MAX_LEN_WORD];
//     int answer = -1;

//     FILE *f = fopen(FILE_OPEN_HASH, "r");

//     green();
//     printf("Выберите с чем желаете работать:\n\
//     \n1 - Хеш-таблица\
//     \n2 - Двоичное дерево поиска (ДДП)\
//     \n3 - Сбалансированное дерево (АВЛ)\n");
//     white();

//     int mode = scanf_answer();
//     if (mode > 3 || mode < 1)
//     {
//         red();
//         printf("Нет данного действия");
//         white();
//         return OK;
//     }

//     hash_s **hash_table = create_hash_table(f);

//     bin_search_s *root = NULL; // ДДП
//     bin_search_s *find_root = NULL;

//     node_t *tree_avl = NULL; // АВЛ
//     node_t *find_node_avl = NULL;

//     while (answer)
//     {
//         switch (mode)
//         {
//         case MODE_HASH_TABLE:
//             instruction_hash();
//             break;
//         case MODE_BST:
//             instruction_bst();
//             break;
//         case MODE_BALANCED_TREE:
//             instruction_bst();
//             break;
//         }

//         answer = scanf_answer();

//         switch (answer)
//         {
//         case 0:
//             break;
//         case 1:

//             switch (mode)
//             {
//             case MODE_HASH_TABLE:
//                 if (is_empty_hash_table(hash_table))
//                 {
//                     red();
//                     printf("Таблица пуста!\n");
//                     white();
//                 }
//                 else
//                 {
//                     yellow();
//                     output_hash_table(stdout, hash_table);
//                     white();
//                 }

//                 break;
//             case MODE_BST:
//                 if (root)
//                 {
//                     yellow();
//                     print_bin_search(root, "root", 0);
//                     white();
//                 }
//                 else
//                 {
//                     red();
//                     printf("Дерево пусто!\n");
//                     white();
//                 }
//                 break;
//             case MODE_BALANCED_TREE:
//                 if (tree_avl)
//                 {
//                     yellow();
//                     print_avl(tree_avl, "root", 0);
//                     white();
//                 }
//                 else
//                 {
//                     red();
//                     printf("Дерево пусто!\n");
//                     white();
//                 }

//                 break;
//             }
//             break;
//         case 2:
//             green();
//             printf("Введите слово, которое хотели бы добавить: ");
//             white();
//             scanf("%s", word);

//             switch (mode)
//             {
//             case MODE_HASH_TABLE:
//                 add_element_hash_table(stdin, hash_table, word);
//                 break;
//             case MODE_BST:
//                 insert_bin_search(&root, word);
//                 break;
//             case MODE_BALANCED_TREE:
//                 tree_avl = insert(tree_avl, word);
//                 break;
//             }
//             break;
//         case 3:
//             green();
//             printf("Введите слово, которое хотели бы удалить: ");
//             white();
//             scanf("%s", word);

//             switch (mode)
//             {
//             case MODE_HASH_TABLE:
//                 if (is_empty_hash_table(hash_table))
//                 {
//                     red();
//                     printf("Нет данного слова!\n");
//                     white();
//                 }
//                 else
//                 {
//                     del_element_hash_table(hash_table, word);
//                 }

//                 break;
//             case MODE_BST:
//                 if (root)
//                 {
//                     yellow();
//                     delete_bin_search(&root, word);
//                     white();
//                 }
//                 else
//                 {
//                     red();
//                     printf("Дерево пусто!\n");
//                     white();
//                 }
//                 break;
//             case MODE_BALANCED_TREE:
//                 if (tree_avl)
//                 {
//                     tree_avl = remove_tree(tree_avl, word);
//                 }
//                 else
//                 {
//                     red();
//                     printf("Дерево пусто!\n");
//                     white();
//                 }
//                 break;
//             }
//             break;
//         case 4:
//             green();
//             printf("Введите слово, которое нужно найти: ");
//             white();
//             scanf("%s", word);

//             value_s data = {0};

//             switch (mode)
//             {
//             case MODE_HASH_TABLE:
//                 data = find_hash(hash_table, word);
//                 if (!strcmp(data.name, ""))
//                 {
//                     red();
//                     printf("\nНет данного элемента.\n");
//                     white();
//                 }
//                 else
//                 {
//                     green();
//                     printf("Информация: %s.\n", data.name);
//                     white();
//                 }
//                 break;
//             case MODE_BST:
//                 if (root)
//                 {
//                     find_root = find_bin_search(root, word);

//                     if (find_root)
//                     {
//                         yellow();
//                         printf("Найдено: %s\n", find_root->data);
//                         white();
//                     }
//                     else
//                     {
//                         red();
//                         printf("\nНет данного элемента.\n");
//                         white();
//                     }
//                 }
//                 else
//                 {
//                     red();
//                     printf("Дерево пусто!\n");
//                     white();
//                 }
//                 break;
//             case MODE_BALANCED_TREE:
//                 if (tree_avl)
//                 {
//                     find_node_avl = find_avl(tree_avl, word);

//                     if (find_node_avl)
//                     {
//                         yellow();
//                         printf("Найдено: %s\n", find_node_avl->value);
//                         white();
//                     }
//                     else
//                     {
//                         red();
//                         printf("\nНет данного элемента.\n");
//                         white();
//                     }
//                 }
//                 else
//                 {
//                     red();
//                     printf("Дерево пусто!\n");
//                     white();
//                 }
//                 break;
//             }
//             break;
//         case 5:

//             switch (mode)
//             {
//             case MODE_HASH_TABLE:
//                 f = fopen(FILE_OPEN_HASH, "r");
//                 // fseek(f, 0, 0);
//                 green();
//                 printf("\nДобавлено %d элементов!\n", input_hash_table(f, hash_table));
//                 white();

//                 fclose(f);
//                 break;
//             case MODE_BST:
//                 f = fopen("text/text_bin_search.txt", "r");

//                 green();
//                 printf("Добавлено %d элементов!\n", input_bin_search(f, &root));
//                 white();

//                 fclose(f);
//                 break;
//             case MODE_BALANCED_TREE:
//                 f = fopen("text/text_bin_search.txt", "r");

//                 input_tree(f, &tree_avl);

//                 fclose(f);
//                 break;
//             }
//             break;
//         default:
//             printf("\33[31m");
//             printf("\t\t\t\t\t\t\t\t\t Нет данного действия.\n");
//             printf("\e[0m");
//             break;
//         }
//     }

//     green();
//     printf("Завершение программы!\n");
//     white();

//     destruct_hash_table(hash_table);
//     free(hash_table);

//     return OK;
// }