#include "Astronomy.h"

#define PI      3.14159265358979323846
#define rad     (PI/180.0)
#define dayMs   (60.0 * 60.0 * 24.0) // really daySecs
#define J1970   2440588
#define J2000   2451545



Astronomy::Astronomy(long time, float lat, float lon) {
	_time = time;
	_lat = lat;
	_lon = lon;
}

void Astronomy::ping() {
	Serial.println("Inside of ping");
	Serial.println(PI * 10000.0);
}

void Astronomy::getPosition() {
	float lw  = rad * _lon * -1.0;
	float phi = rad * _lat;
	float d = toDays(_time);
	Serial.print("rad is ");
	Serial.println(rad);
	Serial.print("time is ");
	Serial.println(_time);
	Serial.print("_lon is ");
	Serial.println(_lon);
	Serial.print("lw is ");
	Serial.println(lw);
	Serial.print("phi is ");
	Serial.println(phi);
	Serial.print("d is ");
	Serial.println(d);
	float M = solarMeanAnomaly(d);
	float foo = eclipticLongitude(M);
	Serial.print("M is ");
	Serial.println(M);
	Serial.print("foo is ");
	Serial.println(foo);
}

float Astronomy::toJulian(long time) { 
	return time / dayMs - 0.5 + J1970;
}
float Astronomy::fromJulian(float j) {
	return (j + 0.5 - J1970) * dayMs;
}

float Astronomy::toDays(long time) {
	return toJulian(time) - J2000; 
}

float Astronomy::solarMeanAnomaly(long time) { 
	return rad * (357.5291 + 0.98560028 * time); 
}

float Astronomy::eclipticLongitude(float M) {
  float C = rad * (1.9148 * sin(M) + 0.02 * sin(2 * M) + 0.0003 * sin(3 * M)); // equation of center
  float P = rad * 102.9372; // perihelion of the Earth
  return M + C + P + PI;
}





