#include <VirtualWire.h>             // dodaj bibliotekę obsługującą moduły RF
void setup()
{
  pinMode(2, INPUT_PULLUP);         //pin decyzyjny
  pinMode(3, INPUT_PULLUP);         //pin decyzyjny
  vw_set_tx_pin(11);               // nadajnik RF podłączamy do pinu 11
  vw_setup(1000);                  // ustawiamy prędkość transmisji
}
void loop()
{
  //if (digitalRead(2) == LOW)
  //{
    char mesage[] = {'O','N'};           //utworz tablice
    vw_send((uint8_t *)mesage, 2);     //wysylamy w postaci znaków
    vw_wait_tx();                   // poczekaj az cala zawartosc tablicy zostanie wyslana
    delay(100);                    //odczekaj 100ms
  //}
  /*
  else if (digitalRead(3) == LOW)
  {
    char mesage[] = {'O','F','F'};           //utworz tablice
    vw_send((uint8_t *)mesage, 3);     //wysylamy w postaci znaków
    vw_wait_tx();                   // poczekaj az cala zawartosc tablicy zostanie wyslana
    delay(100);                    //odczekaj 100ms
  }
*/
}
