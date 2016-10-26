#ifndef Astronomy_included
#define Astronomy_included


#include <Arduino.h>

typedef struct {
	float DECLINATION;
	float RIGHTASCENSION;
} celestialCoordinates;


class Astronomy {

	public:
		Astronomy(unsigned long time, float lat, float lon);
		void ping();
		celestialCoordinates getPosition();
	private:
		unsigned long _time;
		float _lat;
		float _lon;
		float toJulian(unsigned long time);
		float fromJulian(float j);
		float toDays(unsigned long time);
		float solarMeanAnomaly(unsigned long time);
		float eclipticLongitude(float M);
		float rightAscension(float l, float b);
		float declination(float l, float b);
		float azimuth(float H, float phi, float dec);
		float altitude(float H, float phi, float dec);
		float siderealTime(unsigned long d, float lw);
		celestialCoordinates sunCoords(unsigned long d);
};




#endif