/*
 * Project ArgonReceive
 * Description:
 * Author:
 * Date:
 */

int boardLed = D7; // This is the LED that is already on your device.
char dataBuffer[255+1] ;

void msgReceived(const char *event, const char *data)
{
  static int i = 0;
  Serial.printf( "[%d] [%s]:[%s]\n", ++i, event, (data ? data : "") );

  // Blink on message received
  digitalWrite(boardLed,HIGH);
  delay( 200 );
  digitalWrite(boardLed,LOW);

}

void setup() {
  Serial.begin(9600);
  Particle.process();

  pinMode(boardLed, OUTPUT);

  for( int i=0; i<3; i++) {
    digitalWrite(boardLed,HIGH);
    delay( 150 );
    digitalWrite(boardLed,LOW);

    delay( 200 );
  }

  Mesh.subscribe("PUBSUB", msgReceived);

  Particle.publish("AppVer", "ArgonSubscribe-v1");
}

void loop() {
}