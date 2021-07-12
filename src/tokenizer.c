#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

/* Return true (non-zero) if c is a non-whitespace character ('\t' or ' '). Zero terminator are not printable (therefore false)  */
int space_char(char c){
  if(c == '\t' || c == ' ')
    return 1;
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace character (not tab or space). Zero terminators are not printable (therefore false) */
int non_space_char(char c){
  if(c == '\t' || c == ' ')
    return 0;
  return 1;
}

/* Returns a pointer to the first character of the next space-separated word in zero-terminated str. Return a zero pointer if str does not contain any words. */
char *word_start(char *word){
  char *np = word;
  while((space_char(*np) != 1) && (*np != '\n') && (*np != '\0')){
    np++;
  }
  np++;
  return np;
}

/* Returns a pointer terminator char following *word. */
char *word_terminator(char *word){
  char *np = word;
  while(non_space_char(*np) == 1 && (*np != '\n') && (*np != '\0')){
    np++;
  }
  return np--;
}

/* Counts the number of words in the string argument. */
int count_words(char *str){
  char *np = str; //np means new pointer
  int count = 0;
  while(*np){
    np = word_start(np);
    count++;
    np = word_terminator(np);
  }
  return count;
}

/* Returns a freshly allocated new zero-terminated string cointaining <len> chars form <inStr> */
char *copy_str(char *inStr, short len){
  char *copy = (char *)malloc(len*sizeof(char));
  char *ncopy = copy;
  for(int i = 0; i < len; i++){
    *copy = *inStr;
    copy++;
    inStr++;
  }
  copy = '\0';
  return ncopy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated space-separated tokens from zero-termianated str. */
char **tokenize(char* str) {
  int len = count_words(str);
  char *st = str;
  char *end;
  char **tokens = (char **)malloc(len*sizeof(char *));
  char **copy = tokens;
  for(int i = 0; i < len; i++){
    end = word_terminator(st);
    tokens[i] = copy_str(st, end-st);
    st = word_start(st);
  }
  print_tokens(tokens);
  free_tokens(tokens);
  return copy;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  int i = 0;
  while(*tokens){
    printf("tokens[%d] = %s\n", i, *tokens);
    i++;
    *tokens++;
  }
}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens){
  while(*(tokens)){
      free(*tokens);
      *tokens++;
  }
}

void print (char *str){
  printf("String: %s", str);
}
