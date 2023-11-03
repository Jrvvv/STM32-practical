#include <stdint.h>

uint32_t x;
uint32_t y = 0x11223344;

int main(void){
  while(1) {
    x++;
    y--;
  }

  return 0;
}