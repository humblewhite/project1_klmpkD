#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Node {
  char name[255];
  Node *next, *prev;
} *head, *tail;

Node *createNode (char *name ) {
  Node *temp = (Node*)malloc(sizeof(Node));
  strcpy(temp->name, name);
  temp->next = temp->prev = NULL;
  return temp;
}

void pushHead (char *name) {
  Node *temp = createNode(name);
  if (!head) {
    head = tail = temp;
  } else {
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
}

void pushTail (char *name) {
  Node *temp = createNode(name);
  if (!head) {
    head = tail = temp;
  } else {
    temp->prev = head;
    tail->next = temp;
    tail = temp;
  }
}

// void pushMid (char *name) {
//   Node *temp = createNode(name);
//   if (!head) {
//     head = tail = temp;
//   } else if (strcmp(name, head->name) < 0) { //insert depan
//     pushHead(name);
//   } else if (strcmp(name, tail->name) > 0) { //insert blkg
//     pushTail(name);
//   } else {
//     Node *current = head;
//     while (strcmp(name, current->name) > 0) {
//       current = current->next;
//     }
//     temp->prev = current->prev;
//     temp->next = current;
//     current->prev->next = temp;
//     current->prev = temp;
//   }
// }

// void popHead () {
//   if (!head) {
//     return;
//   } else if (head == tail) {
//     head = tail = NULL;
//     free(head);
//   } else {
//     Node *temp = head->next;
//     head->next = temp->prev = NULL;
//     head = NULL;
//     free(head);
//     head = temp;
//   }
// }

// void popTail () {
//   if (!head) {
//     return;
//   } else if (head == tail) {
//     head = tail = NULL;
//     free(head);
//   } else {
//     Node *temp = tail->prev;
//     tail->prev = temp->next = NULL;
//     tail = NULL;
//     free(tail);
//     tail = temp;
//   }
// }

// void popMid (char *name) {
//   if (!head) {
//     return;
//   } else if (strcmp(name, head->name) == 0) {
//     popHead();
//   } else if (strcmp(name, tail->name) == 0) {
//     popTail();
//   } else {
//     Node *current = head;
//     while (strcmp(name, current->name) != 0) {
//       current = current->next;
//     }
//     if (!current) {
//       printf ("Nama tidak ditemukan\n");
//       return;
//     }
//     current->prev->next = current->next;
//     current->next->prev = current->prev;
//     free(current);
//     current = NULL;
//   }
// }

char dUname[5][25] = {"abc", "efg", "123"}, dPwd[5][25] = {"abc", "efg", "321"}; int w = 3;

void regist();
void start();

void viewSent () {

}
void userPage(char username[]);

void addFriend (char username[]) {
  pushHead(username);
  char friends[25];
  printf ("-----------------------------------------\n");
  printf (" [All User]\n");
  printf (" No. Username\n");
  int x = 1, flag = 0;
  for (int i = 0; i < w; i++) {
    if (strcmp(dUname[i], username) == 0) {
    } else printf (" %d   %s\n", x, dUname[i]); x++;
  }
  printf ("Which user do you want to add?\n");
  printf (">>"); scanf ("%s", friends);
  printf ("-- Your request has been sent to %s --\n", friends);
  printf ("Press enter to continue!\n"); getchar();
  pushTail(friends);
  userPage(username);
}

void userPage (char username[]) {
  printf ("Oo=====================================oO\n");
  printf ("Welcome, %s\n", username); time_t t; time(&t);
  printf ("Oo=====================================oO\n");
  printf ("Logged in: %s\n", ctime(&t));
  printf (" [All User]\n");
  printf (" No. Username\n");
  int x;
  for (int i = 0; i < w; i++) {
    printf (" %d   %s\n", i+1, dUname[i]); x = i;
  }
  printf (" %d   %s\n", x+1, username);
  printf ("-----------------------------------------\n");
  printf ("            >> m e n u <<\n");
  printf ("-----------------------------------------\n");
  printf (" [1] Add Friend\n");
  printf (" [2] Remove Friend\n");
  printf (" [3] View Inbox\n");
  printf (" [4] View Sent Request\n");
  printf (" [5] Add, Edit, Announce, Delete Note\n");
  printf (" [6] Log Out\n");
  printf ("-----------------------------------------\n");
  printf (">> ");
  int a; scanf ("%d", &a);
  if (a == 1) {
    addFriend(username);
  } else if (a == 2) {
    // rmvFriend(username);
  } else if (a == 3) {
    // viewInbox(username);
  } else if (a == 4) {
    // viewSend(username);
  } else if (a == 5) {
    // notes(username);
  } else if (a == 6) {
    start();
  }
}

void rmvFriend(char username[]){
  
}

void login () {
  char username[25], password[25];
  printf ("Oo=====================================oO\n");
  printf ("            STUDY NETWORK\n");
  printf ("Oo=====================================oO\n");
  printf (" [All User]\n");
  printf (" No. Username\n");
  for (int i = 0; i < 3; i++) {
    printf (" %d   %s\n", i+1, dUname[i]);
  }
  printf ("-----------------------------------------\n");
  printf (" [1] Register\n");
  printf (" [2] Login\n");
  printf (" [3] Exit\n");
  printf ("-----------------------------------------\n");
  printf (" Press 0 and enter to abort an operation\n");
  printf ("-----------------------------------------\n");
  printf (">> 2\n");
  printf ("-----------------------------------------\n");
  printf ("Username: ");
  scanf ("%s", username);
  printf ("Password: ");
  scanf ("%s", password);
  int flag = 0;
  for (int i = 0; i < 3; i++) {
    if (strcmp (username, dUname[i]) == 0) {
      if (strcmp (password, dPwd[i]) == 0) {
        flag = 1; break;
      }
    }
  }
  if (flag == 0) {
    printf ("The username and password you've entered are wrong.\n");
    printf ("Press enter to go to Register Menu\n"); getchar();
    regist();
  } else {
    printf ("\n--- Login Successfull ---\n");
    printf ("Press enter to continue\n"); getchar();
    userPage(username);
  }
}

void regist () {
  char username[25], password[25];
  printf ("-----------------------------------------\n");
  printf ("Please type in your username [lowercase || 1..24]: ");
  scanf ("%s", username);
  printf ("Please type in your password [lowercase || 1..24]: ");
  scanf ("%s", password);
  printf ("\n--- Registration Successfull ---\n");
  printf ("Press enter to continue!\n"); getchar();
  strcpy (dUname[4], username); w++;
  userPage (username);
}

void start () {
  printf ("Oo=====================================oO\n");
  printf ("            STUDY NETWORK\n");
  printf ("Oo=====================================oO\n");
  printf (" [All User]\n");
  printf (" No. Username\n");
  printf ("-----------------------------------------\n");
  printf (" [1] Register\n");
  printf (" [2] Login\n");
  printf (" [3] Exit\n");
  printf ("-----------------------------------------\n");
  printf (" Press 0 and enter to abort an operation\n");
  printf ("-----------------------------------------\n");
  printf (">> ");
  int a; scanf ("%d", &a);
  if (a == 1) {
    regist();
  } else if (a == 2) {
    login();
  } else if (a == 3 || a == 0) {
    exit(0);
  }
}

int main () {
  start();
  return 0;
}
