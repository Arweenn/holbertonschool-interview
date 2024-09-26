#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdbool.h>

void print_sandpile(int[3][3]);
int is_stable(int[3][3]);
void stabilize_sandpile(int[3][3], int[3][3]);
void sandpiles_sum(int[3][3], int[3][3]);

#endif /* SANDPILES_H */