#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <crypt.h>

int main(void) {
  char *pass = NULL, *hashA = NULL;
  size_t lpass = 0, lhashA = 0;
  getline(&pass, &lpass, stdin);
  getline(&hashA, &lhashA, stdin);

  if (pass == NULL || hashA == NULL) {
    printf("error\n");
    return 0;
  }

  while(pass[strlen(pass) - 1] == '\n' || pass[strlen(pass) - 1] == '\r') pass[strlen(pass) - 1] = '\0';
  while(hashA[strlen(hashA) - 1] == '\n' || hashA[strlen(hashA) - 1] == '\r') hashA[strlen(hashA) - 1] = '\0';

  char *hashB = crypt(pass, "00");

  if (hashB == NULL)
    printf("error\n");
  else if (strcmp(hashA, hashB) == 0)
    printf("allow\n");
  else
    printf("deny\n");

  return 0;
}

