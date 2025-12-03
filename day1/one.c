#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *fptr;

  fptr = fopen("./input1.txt", "r");

  if (fptr == NULL)
    return 1;

  char buffer[128];
  int LEFT = 0;
  int RIGHT = 1;
  int MAX_DIAL = 99;
  int MIN_DIAL = 0;
  int currentPosition = 50;
  int zerosFound = 0;
  int index = 0;
  while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
    buffer[strcspn(buffer, "\n")] = '\0';
    if (buffer[0] != 'R' && buffer[0] != 'L')
      continue;
    int currentDirection = buffer[0] == 'R';
    char countBuffer[128];
    strcpy(countBuffer, buffer + 1);
    int count = atoi(countBuffer);

    if (count == 0) {
      continue;
    }
    printf("input %s, count %d, direction %d\n", buffer, count,
           currentDirection);
    if (currentDirection == LEFT) {
      currentPosition = currentPosition - count;
    } else {
      currentPosition = currentPosition + count;
    }
    if (currentPosition > MAX_DIAL) {
      currentPosition = currentPosition - (MAX_DIAL + 1);
    }
    if (currentPosition < MIN_DIAL) {
      currentPosition = (MAX_DIAL + 1) + currentPosition;
    }
    if (currentPosition == 0) {
      zerosFound = zerosFound + 1;
    }
    index = index + 1;
    printf("current index %d, current position: %d\n", index, currentPosition);
  }
  printf("Number of zeros found %d\n", zerosFound);

  fclose(fptr);

  return 0;
}
