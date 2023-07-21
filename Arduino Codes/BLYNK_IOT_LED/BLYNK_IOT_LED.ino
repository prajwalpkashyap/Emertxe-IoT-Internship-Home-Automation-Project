#define BLYNK_TEMPLATE_ID "TMPL3FIEEBhFK"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "P7pFb4t7pc_U4UEzkFzh15u6iGf8SEE1" 
/* Should not share this above authorization token to anyone, else they can control our device if they get it */

#include <SPI.h> 
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

#define LED     2

char auth[] = BLYNK_AUTH_TOKEN;

/*To Call the Function when the Value changes on the VIRTUAL PIN - V0 */
BLYNK_WRITE(V0)
{
  /*To Read the Values on V0 PIN */
  int value = param.asInt();

  if(value)
  {
    /*Turn ON the LED */
    digitalWrite(LED, HIGH);
  }

  else
  {
    /*Turn OFF the LED */
    digitalWrite(LED, LOW);
  }
}

void setup() 
{
  // put your setup code here, to run once:
  /*To COnnect the Device (Arduino) to the BLYNK CLOUD */
  Blynk.begin(auth);

  /*To Configure the LED as OUTPUT */
  pinMode(LED, OUTPUT);
  
}

void loop() 
{
  // put your main code here, to run repeatedly:
  Blynk.run();
}
