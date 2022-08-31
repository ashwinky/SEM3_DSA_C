#include <stdio.h>

void towerOfHanoi(int disks, char source, char auxiliary, char destination) {
  if (disks == 0)
    return;
  else if (disks == 1) {
    printf("%c %c\n", source, destination);
    return;
  }

  towerOfHanoi(disks - 1, source, destination, auxiliary);
  printf("%c %c\n", source, destination);
  towerOfHanoi(disks - 1, auxiliary, source, destination);
}

int main() {
  int n;
  printf("Enter N: ");
  scanf("%d", &n);
  towerOfHanoi(n, 'a', 'b', 'c');
  return 0;
}
