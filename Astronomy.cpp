#include "Astronomy.h"

#define PI      3.14159265358979323846
#define rad     (PI/180.0)
#define dayMs   (60.0 * 60.0 * 24.0) // really daySecs
#define J1970   2440588
#define J2000   2451545
#define e       rad * 23.4397 // obliquity of the Earth




Astronomy::Astronomy(unsigned long time, float lat, float lon) {
	_time = time;
	_lat = lat;
	_lon = lon;
}

void Astronomy::ping() {
	Serial.println("Inside of ping");
	Serial.println(PI * 10000.0);
}

celestialCoordinates Astronomy::getPosition() {
	celestialCoordinates theCoordinates;
	float lw  = rad * _lon * -1.0;
	float phi = rad * _lat;
	float d = toDays(_time);

	Serial.print("rad is ");
	Serial.println(rad);
	Serial.print("time is ");
	Serial.println(_time);
	Serial.print("_lon is ");
	Serial.println(_lon);
	Serial.print("_lat is ");
	Serial.println(_lat);

	Serial.print("lw is ");
	Serial.println((float)lw,12);
	Serial.print("phi is ");
	Serial.println((float)phi,12);
	Serial.print("d (as calculated by toDays) is ");
	Serial.println((float)d,12);

	float M = solarMeanAnomaly(d);
	float L = eclipticLongitude(M);
	Serial.print("M (as calculated by solarMeanAnomaly) is ");
	Serial.println((float)M,12);
	Serial.print("L (as calculated by eclipticLongitude) is ");
	Serial.println((float)L,12);
	theCoordinates = sunCoords(d);
	Serial.print("theCoordinates.DECLINATION is ");
	Serial.println((float)theCoordinates.DECLINATION,12);
	Serial.print("theCoordinates.RIGHTASCENSION is ");
	Serial.println((float)theCoordinates.RIGHTASCENSION,12);
	float H  = siderealTime(d, lw) - theCoordinates.RIGHTASCENSION;
	Serial.print("H (siderialTime) is ");
	Serial.println((float)H,12);

}

float Astronomy::toJulian(unsigned long time) { 
	return time / dayMs - 0.5 + J1970;
}
float Astronomy::fromJulian(float j) {
	return (j + 0.5 - J1970) * dayMs;
}

float Astronomy::toDays(unsigned long time) {
	return toJulian(time) - J2000; 
}

float Astronomy::solarMeanAnomaly(unsigned long time) { 
	return rad * (357.5291 + 0.98560028 * time); 
}

float Astronomy::eclipticLongitude(float M) {
  float C = rad * (1.9148 * sin(M) + 0.02 * sin(2 * M) + 0.0003 * sin(3 * M)); // equation of center
  float P = rad * 102.9372; // perihelion of the Earth
  return M + C + P + PI;
}

float Astronomy::rightAscension(float l, float b) {
	return atan2(sin(l) * cos(e) - tan(b) * sin(e), cos(l));
}

float Astronomy::declination(float l, float b) {
	return asin(sin(b) * cos(e) + cos(b) * sin(e) * sin(l));
}

float Astronomy::azimuth(float H, float phi, float dec) {
	return atan2(sin(H), cos(H) * sin(phi) - tan(dec) * cos(phi));
}

float Astronomy::altitude(float H, float phi, float dec) {
	return asin(sin(phi) * sin(dec) + cos(phi) * cos(dec) * cos(H));
}

float Astronomy::siderealTime(unsigned long d, float lw) {
	return rad * (280.16 + 360.9856235 * d) - lw;
}

celestialCoordinates Astronomy::sunCoords(unsigned long d) {
	Serial.print("inside sunCoords d is ");
	Serial.println(d);
	celestialCoordinates theCoordinates;
	float M = solarMeanAnomaly(d);
	// Serial.print("M (solarMeanAnomaly) is ");
	// Serial.println(M);
	float L = eclipticLongitude(M);
	// Serial.print("L (eclipticLongitude) is ");
	// Serial.println(L);
	theCoordinates.DECLINATION = Astronomy::declination(L, 0.0);
	theCoordinates.RIGHTASCENSION = Astronomy::rightAscension(L, 0.0);
	return theCoordinates;
}



