#include <stdlib.h>
#include <stdio.h>
#include "history.h"

List* init_history ()
{
  List *history = (List*) malloc(sizeof(List));

  history->root = NULL;

  return history;
}

void add_history (List *list, char *str)
{
  printf ("How about in here?");
  Item *currNode = list->root;
  Item *newNode = (Item*) malloc(sizeof(Item));
  newNode->str = str;

  // If first item
  if (currNode->next == NULL){
    printf ("Did you get here by chance?");
    // Create a head
    newNode->id = 1;
    list->root = newNode;
    newNode->next = NULL;
  }
  // Insert to the end of the list
  else {
    while (currNode->next != NULL){
      currNode = currNode->next;
    }
    currNode->next = newNode;
    newNode->id = currNode->id + 1;
    newNode->next = NULL;
  }
}

char *get_history (List *list, int id)
{
  Item *currNode = list->root;

  // If history is empty
  if (currNode->next == NULL)
    return "History is empty";
  
  while (currNode->next != NULL){
    if (currNode->id = id)
      return currNode->str;
  }
  // Final Check
  if (currNode->id = id)
    return currNode->str;
  
  return "No such ID";  // ID doesn't exist 
  
}

void print_history (List *list)
{
  Item *currNode = list->root;

  while (currNode->next != NULL){
    printf ("%s\n", currNode->str);
    currNode = currNode->next;
  }
  printf ("%s\n", currNode->str);
  
}
