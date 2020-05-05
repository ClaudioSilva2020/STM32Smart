#include "stm32f4xx.h"
#include "core_cm4.h"


#define setBit(y, bit) (y->ODR|=(1<<bit)) //Seta o bit x do GPIOy
#define clrBit(y, bit) (y->ODR &=~(1<<bit)) //reseta o bit x do GPIOy


void delayMs(int n);

int main(){
	RCC->AHB1ENR |= 1; // Unlook the output digital
	
	
	GPIOA->MODER &= ~0x00000C00; // Reset all register of GPIOA
	GPIOA->MODER |= 0b00000000000000000000010100000000; // Enable GPIO 04 and 05 for output, just GPIO 05(0x00000400)
		
	while(1){
		setBit(GPIOA, 4);
		setBit(GPIOA, 5);
		delayMs(200);
		clrBit(GPIOA, 5);
		delayMs(700);
	}
	
}
void delayMs(int n){
	int i;
	for( ; n>0 ; n--)
		for(i=0;i<3195;i++);
	
}