/*
 * 以单词为单位翻转句子，单词内部的字幕顺序不变
 */

#include  <stdio.h>
#include  <string.h>

//将begin到end之间的字符串翻转
void Reverse(char *begin, char* end)
{
    if (begin == NULL || end == NULL)
      return;

    while (begin < end) {
        char c = *begin;
        *begin = *end;
        *end = c;
        begin++;
        end--;
    }
}

//翻转句子中的单词
char *ReverseSentence(char * string)
{
    if (string == NULL || strlen(string) <= 1)
      return string;

    //先翻转句子
    Reverse(string, string + strlen(string) - 1);

    //翻转句子中的每个单词
    char *end = string;
    char *begin = string;
    while (*end != '\0') {
        while (*end != ' ' && *end != '\0')
          end++;
        Reverse(begin, end - 1);
        if (*end != '\0') 
          end++;
        begin = end;
    }
    return string;
}
