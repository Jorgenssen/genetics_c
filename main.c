#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CHARSET "abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define OFFSPRINGS_COUNT 10
#define GENOM_LENGTH 27

void generate_random_string(char *dest);
void mutate_random_gen(char *dest);
size_t generate_random_gen_index();
char get_random_char();

int main() {
  srand(getpid());
  char init_genom[GENOM_LENGTH], pre_genom[GENOM_LENGTH], next_genom[GENOM_LENGTH];
  generate_random_string(init_genom);

  printf("------------\n");
  printf("Initial population: %s\n", init_genom);
  printf("Genom length: %li\n", strlen(init_genom));
  printf("Count of offsprings: %i\n", OFFSPRINGS_COUNT);
  printf("------------\n");
  printf("Offsprings:\n");
  printf("------------\n");

  strcpy(pre_genom, init_genom);
  strcpy(next_genom, init_genom);
  for (int i = 0; i < OFFSPRINGS_COUNT; i++) {
    mutate_random_gen(next_genom);
    printf("Population %i\n", i + 1);
    printf("Ancestor genom: %s\n", init_genom);
    printf("Previous genom: %s\n", pre_genom);
    printf("Actual genom  : %s\n", next_genom);
    printf("------------\n");
    memcpy(pre_genom, next_genom, GENOM_LENGTH);
  }
  printf("Mutation result\n");
  printf("Initial genom : %s\n", init_genom);
  printf("Final genom   : %s\n", next_genom);
  return 0;
}

void generate_random_string(char *dest) {
  int l = GENOM_LENGTH - 1;
  while (l --> 0) {
    *dest++ = get_random_char();
  }
  *dest = '\0';
}

void mutate_random_gen(char *dest) {
  size_t mutate_index = (double) rand() / RAND_MAX * (GENOM_LENGTH - 1);
  dest[mutate_index] = get_random_char();
}

size_t generate_random_gen_index() {
  return (double) rand() / RAND_MAX * (sizeof CHARSET - 1);
}

char get_random_char() {
  return CHARSET[generate_random_gen_index()];
}
