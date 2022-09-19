// a program to demonstrate tower of hanoi problem algorithm for user provided number of disks

#include <stdio.h>

void hanoi(int count, char source, char aux, char destination) {
  if (count == 1) {  // base case
    printf("Move disk 1 from %c to %c\n", source, destination);
    return;
  }

  hanoi(count - 1, source, destination, aux);  // move count-1 disks from source to aux

  printf("Move disk %d from %c to %c\n", count, source, destination);

  hanoi(count - 1, aux, source, destination);  // move count-1 disks from aux to destination
}

int main() {
  int n;  // number of disks
  printf("Enter number of disks: ");
  scanf("%d", &n);

  hanoi(n, 'A', 'B', 'C');

  return 0;
}
