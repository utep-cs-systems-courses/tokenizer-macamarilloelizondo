#include <stdio.h>
#include "tokenizer.h"

int main()
{
  char in[100];
  printf("Welcome to Tokenizer \n");
  printf("Enter for tokenizing: \n >>");
  fgets(in, 100, stdin);
  char *p = in;
  char *made = *tokenize(p);
  return 0;
}
