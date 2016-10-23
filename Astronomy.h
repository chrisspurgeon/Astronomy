#ifndef Astronomy_included
#define Astronomy_included


#include <Arduino.h>

typedef struct {
	float DECLINATION;
	float RIGHTASCENSION;
} celestialCoordinates;


class Astronomy {

	public:
		Astronomy(long time, float lat, float lon);
		void ping();
		celestialCoordinates getPosition();
	private:
		long _time;
		float _lat;
		float _lon;
		float toJulian(long time);
		float fromJulian(float j);
		float toDays(long time);
		float solarMeanAnomaly(long time);
		float eclipticLongitude(float M);
		float rightAscension(float l, float b);
		float declination(float l, float b);
		float azimuth(float H, float phi, float dec);
		float altitude(float H, float phi, float dec);
		float siderealTime(long d, float lw);
		celestialCoordinates sunCoords(long d);
};




#endif