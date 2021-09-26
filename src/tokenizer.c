
#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c)
{
  if (c == '\t' || c == ' ')
    return 1;
  else
    return 0;
}

int non_space_char(char c)
{
  if (c == '\t' || c == ' ' || c == '\0')
    return 0;
  else
    return 1;
}

char *word_start(char *str)
{
  /* If empty string, return zero pointer */
  if (*str == '\0')
    return '\0';
  
  while (space_char(*str)){
    str++;
  }
  return str;
}

char *word_terminator(char *word)
{
  while (non_space_char(*word)){
    word++;
  }
  return word;
}

int count_words(char *str)
{
  int count = 0;
  
  while (*str != '\0'){
    /* Find start of word */
    str = word_start(str);
    /* Find end of word */
    str = word_terminator(str);
    /* Increase word count */
    count++;
  }
  return count;
  
}
char *copy_str(char *inStr, short len)
{
  char *copyStr = (char*)malloc((len + 1) * sizeof(char));

  // Copy string
  for (int i = 0; i < len; i++){ 
    *copyStr++ = *inStr++;
  }
  *copyStr = 0;
  
  copyStr = copyStr - len;  // Return to start
  
  return copyStr;
}

char **tokenize(char *str)
{
  // Get word count
  int wordCount = count_words(str);
  
  // Allocate token vector
  char **tokens = (char**) malloc ((wordCount + 1) * sizeof(char*));

  char *end;
  str = word_start (str);

  for (int i = 0; i < wordCount; i++){
    // Measure next word
    int wordLen = word_terminator(str) - str;

    // Allocate storage for copy of this word
    char *copyStr = (char*) malloc ((wordLen + 1) * sizeof(char));

    // Copy Word
    copyStr = copy_str (str, wordLen);
    *tokens = copyStr;

    // Prepare for next word
    end = word_terminator(str);
    str = word_start(end);
    tokens++;
  }
  *tokens = 0;

  return tokens - wordCount;
}

void print_tokens(char **tokens)
{
  printf ("---- Printing tokens ----\n");

  int count = 0;
  while (*tokens != 0){
    printf ("[%d] %s\n", count, *tokens);
    count++;
    tokens++;
  }
}

void free_tokens(char **tokens)
{
  while (*tokens != 0){
    free (*tokens);
    tokens++;
  }
  printf ("---- Done freeing tokens ----\n");
}
