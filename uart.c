#include <avr/io.h>
#include <util/delay.h>
#define FOSC 16000000UL
#define BAUD 9600
#define MYUBRR (FOSC / 16UL / BAUD - 1)
//
// #define ASYNCHRONOUS (0 << UMSEL00)
// #define PARITY_MODE (0 << UPM00)
// #define STOP_BITS (0 << USBS0)
// #define DATA_BIT (3 << UCSZ00)
//
// void USART_Init(unsigned int ubrr);
// void USART_Transmit(unsigned char data);
//
// int main(void) {
//   USART_Init(MYUBRR);
//   char msg = 'A';
//   while (1) {
//     USART_Transmit(msg);
//     _delay_ms(1000);
//   }
// }
//
// void USART_Init(unsigned int ubrr) {
//   UBRR0H = (unsigned char)(ubrr >> 8);
//   UBRR0L = (unsigned char)(ubrr);
//   UCSR0C = ASYNCHRONOUS | PARITY_MODE | STOP_BITS | DATA_BIT;
//   UCSR0B = (1 << TXEN0) | (1 << RXEN0);
// }
//
// void USART_Transmit(unsigned char data) {
//   while ((UCSR0A & (1 << UDRE0)) == 0)
//     ;
//
//   UDR0 = data;
// }
//
int main(void) {
  // UBRR0H = (MYUBRR >> 8);
  UBRR0H = (unsigned char)(MYUBRR >> 8);
  UBRR0L = (unsigned char)MYUBRR;
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

  while (1) {
    while (!(UCSR0A & (1 << UDRE0))) {
    }
    UDR0 = 'A';
    _delay_ms(1000);
  }
}
