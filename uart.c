#include <avr/io.h>
#include <util/delay.h>
#define FOSC 16000000UL
#define BAUD 9600
#define MYUBRR FOSC / 16 / BAUD - 1

void USART_Init(unsigned int ubrr);
void USART_Transmit(unsigned char data);

int main(void) {
  USART_Init(MYUBRR);
  char msg = 'A';
  while (1) {
    USART_Transmit(msg);
  }
}

void USART_Init(unsigned int ubrr) {
  UBRR0H = (unsigned char)(ubrr >> 8);
  UBRR0L = (unsigned char)(ubrr);
  UCSR0B = (1 << RXEN0);
  UCSR0C = (3 << UCSZ00);
}

void USART_Transmit(unsigned char data) {
  while (!(UCSR0A & (1 << UDRE0)))
    ;

  UDR0 = data;
}
