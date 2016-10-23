#ifndef Astronomy_included
#define Astronomy_included


#include <Arduino.h>

class Astronomy {

	public:
		Astronomy(long time, float lat, float lon);
		void ping();
		void getPosition();
	private:
		long _time;
		float _lat;
		float _lon;
		float toJulian(long time);
		float fromJulian(float j);
		float toDays(long time);
		float solarMeanAnomaly(long time);
		float eclipticLongitude(float M);
};


#endif