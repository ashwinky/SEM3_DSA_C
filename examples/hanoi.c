// a program to demonstrate tower of hanoi problem algorithm for user provided number of disks

#include <stdio.h>

void hanoi(int n, char source, char destination, char aux) {
  if (n == 1) {
    // base case
    printf("Move disk 1 from %c to %c\n", source, destination);
    return;
  }

  hanoi(n - 1, source, aux, destination);  // move n-1 disks from source to aux

  printf("Move disk %d from %c to %c\n", n, source, destination);

  hanoi(n - 1, aux, destination, source);  // move n-1 disks from aux to destination
}

int main() {
  int n;  // number of disks
  printf("Enter number of disks: ");
  scanf("%d", &n);

  hanoi(n, 'A', 'C', 'B');

  return 0;
}