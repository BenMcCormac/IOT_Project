void motor()
{
  boolean open, close;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };	// Buffer to store the returned UID
  uint8_t uidLength;				// Length of the UID (4 or 7 bytes depending on ISO14443A card type
  uint8_t lock = 0;         //Lock will change with a button on the website

  if(lock == 0)             
  {
    uint8_t keya[6] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
    open = nfc.mifareclassic_AuthenticateBlock(uid, uidLength, 4, 0, keya);   //when the RFID is authenticated
    if(open)
    {
      for(int posDegrees = 90; posDegrees >= 0; posDegrees -= 2)      //opens the lid
      {
        servo1.write(posDegrees);
        delay(20);
      }
      lcd.clear();
      lcd.print("The lid is open!");

      delay(1000);
    }

    //Tap Again to close
    close = nfc.mifareclassic_AuthenticateBlock(uid, uidLength, 4, 0, keya);   //when the RFID is authenticated
    if(close)
    {
        for(int posDegrees = 0; posDegrees <= 90; posDegrees += 2)        //reset to closed
      {
        servo1.write(posDegrees);
        delay(20);
      }
      lcd.clear();
      lcd.print("The lid is closed!");
    }
  }
  else
  {
    //When I learn how to receive info from the server this will lock someone out of the function
  }
}
uint8_t mPosition()
{
  
}