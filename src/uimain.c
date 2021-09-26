#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tokenizer.h"
#include "history.h"

int main ()
{
  List *history = init_history();
  char word[100];

  do{
    printf ("Input a string to tokenize it or !<nums> for a special number, !h for full history, !q to quit:\n");

    // Gets input
    fgets (word, 100, stdin);

    // !<nums> - special num
    if (word[0] == '!' && isdigit(word[1])){
      int val = atoi (word + 1);
      printf ("H[%d] %s\n", val,  get_history (history, val));
    }
    // !h - full history
    else if (strcmp (word, "!h\n") == 0){
      print_history(history);
    }
    // !q - quit
    else if (strcmp (word, "!q\n") == 0){
      free_history(history);
      goto done;
    }
    // Tokenize string
    else {
      char **tokens = tokenize (word);
      print_tokens(tokens);
      free_tokens(tokens);

      // Add to history
      add_history (history, word);

    }
  }while (1);
  
  done:
  return 0;
 
}
