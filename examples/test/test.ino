#include <Time.h>
#include <TimeLib.h>

#include <Astronomy.h>

//Astronomy foo(1362441600, 50.5, 30.5); for debugging
Astronomy foo(1477256305, 50.5, 30.5);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  foo.getPosition();
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println("HELLO");
//  foo.ping();
//  Serial.println(foo);

}
