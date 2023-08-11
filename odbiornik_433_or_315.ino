#include <VirtualWire.h>                      // dodaj bibliotekę obsługującą moduły RF

void setup()
{
  vw_set_rx_pin(11);                        // odbiornik podłączamy do pinu 11
  vw_setup(1000);                           // ustawiamy transmisję danych
  vw_rx_start();                            // Rozpoczynamy odbiór danych
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{

  uint8_t buf[VW_MAX_MESSAGE_LEN];          //definicja buforu odbioru danych
  uint8_t buflen = VW_MAX_MESSAGE_LEN;      //oraz dlugości otrzymanych danych

  if (vw_get_message(buf, &buflen))         // jeżeli do buforu danych dotarły dane oraz
  {
    int i;                                  //utwórz zmienną i
    String dane;                            //utwórz zmienną string dane

    for (i = 0; i < buflen; i++)            //jeżeli wartość i < 0 to odbieraj znaki
    {
      dane += char(buf[i]);                //do zmiennej string wprowadź wszystkie otrzymane znaki i je połącz
    }

    Serial.println(dane);
    if (dane == "ON")
    {
      digitalWrite(13, HIGH);
    }
    if (dane == "OFF")
    {
      digitalWrite(13, LOW);
    }
  }
}
