var SunCalc = require('./suncalc');
console.log("Hello world");

var date = new Date(),
    lat = 34.25,
    lng = -118.25;

var sunPos = SunCalc.getPosition(date, lat, lng);
var moonPos = SunCalc.getMoonPosition(date, lat, lng);

console.log("The date is " + date);
console.log("Sun position is " + sunPos.azimuth + " and " + sunPos.altitude * 180.0 / 3.141592);


console.log("Moon position is " + moonPos.azimuth + " and " + moonPos.altitude * 180.0 / 3.141592);
