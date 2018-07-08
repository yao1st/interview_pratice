//
// Created by senseadmin on 18-7-6.
//

#include "string_associated.h"

int main()
{
    char sentence[] = "I am a student.";
    int length = sizeof(sentence) / sizeof(sentence[0]);
    reverseSentence(sentence);
    printCharArray(sentence, length);
    char word[]= "student";
    length = sizeof(word) / sizeof(word[0]);
    leftRotationWord(word, length, 2);
    printCharArray(word, length);
    return 0;
}