void setup()
{
  pinMode(15, OUTPUT);
  ledcAttachPin(15, 0); // atribui um pino a um canal.
  ledcSetup(0, 1000, 10); // configura um canal para trabalhar a uma determinada frequência e resolução.
  
}
void loop()
{
  for (int i = 0; i < 1024; i++)//aumenta
  {
    ledcWrite(0, i); //escreve   o duty cycle ao canal.(a função ledc)
    delay(2);
  }
  for (int i = 1023; i > 0; i--)//diminui
  {
    ledcWrite(0, i);
    delay(2);
  }
}
