#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

List* init_history ()
{
  List *history = (List*) malloc(sizeof(List));

  history->root = NULL;

  return history;
}

void add_history (List *list, char *str)
{
  Item *currNode = list->root;
  Item *newNode = (Item*) malloc(sizeof(Item));
  newNode->next = NULL;

  // If first item in list
  if(currNode == NULL){
    list->root = newNode;
    newNode->id = 0;
  }
  // Insert to end of list 
  else{
    while(currNode->next != NULL){
      currNode = currNode->next;
    }
    currNode->next = newNode;
    newNode->id = currNode->id + 1;
  }
  // Copy string
  int len = 0;
  
  while (*str != '\0'){
    len++;
    str++;
  }
  
  str = str-len;
  char *copyStr = (char*) malloc(sizeof(char));
  copyStr = copy_str(str, len);
  
  newNode->str = copyStr;
}

char *get_history (List *list, int id)
{
  Item *currNode = list->root;

  // If history is empty
  if (currNode == NULL)
    return "History is empty";

  // Traverse list for it
  while (currNode != NULL){
    if (currNode->id == id)
      return currNode->str;
    currNode = currNode->next;
  }
  
  return "No such ID";  // ID doesn't exist 
  
}

void print_history (List *list)
{
  Item *currNode = list->root;

  while (currNode != NULL){
    printf ("H[%d] %s\n", currNode->id, currNode->str);
    currNode = currNode->next;
  }
}

void free_history (List *list)
{
  Item *currNode;

  while (list->root != NULL){
    currNode = list->root;
    list->root = list->root->next;
    free(currNode->str);
    free(currNode);
  }
  free(list);
}
