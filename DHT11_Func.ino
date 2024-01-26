//temp function for temp sensor
String getTemp() 
{
  DHT.read(DHT11_PIN);
  String temp = String(DHT.temperature);
  return temp;
}

String getHumid()
{
  DHT.read(DHT11_PIN);
  String humid = String(DHT.humidity);
  return humid;
}

int GetTemp() 
{
  DHT.read(DHT11_PIN);
  int temp = int(DHT.temperature);
  return temp;
}

int GetHumid()
{
  DHT.read(DHT11_PIN);
  int humid = int(DHT.humidity);
  return humid;
}