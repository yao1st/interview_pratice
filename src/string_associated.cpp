//
// Created by senseadmin on 18-7-6.
//

#include "string_associated.h"

void reverse(char *p_begin, char *p_end)
{
    if (p_begin == NULL || p_end == NULL || p_end - p_begin < 0)
    {
        throw "Invalid Input!\n";
    }

    while (p_begin <= p_end)
    {
        char tmp = *p_begin;
        *p_begin = *p_end;
        *p_end = tmp;

        p_begin++;
        p_end--;
    }
}

void reverseSentence(char *sentence)
{
    if (sentence == NULL)
        throw "Invalid Input\n";
    char *p_begin = sentence;
    char *p_end = sentence;
    while (*p_end != '\0')
    {
        p_end++;
    }

    reverse(p_begin, p_end - 1);

    p_begin = sentence;
    p_end = sentence;
    while (*p_end != '\0')
    {
        while (*p_end != ' ' && *p_end != '\0')
        {
            p_end ++;
        }

        reverse(p_begin, p_end - 1);

        p_begin = p_end + 1;
        p_end = p_begin;
    }
}

void printCharArray(char *arr, int length)
{
    for (int i = 0; i < length - 1; ++i) {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

void leftRotationWord(char *word, int length, int index)
{
    if (word == NULL || length < 1 || index >= length)
        throw "Invalid Input\n";
    char *p_begin = word;
    char *p_end = word + index -1;
    reverse(p_begin, p_end);
    p_begin = word + index;
    p_end = word + length - 2;
    reverse(p_begin, p_end);
    p_begin = word;
    reverse(p_begin, p_end);
}