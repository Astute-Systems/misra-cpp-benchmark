// BEGIN violation
extern "C" long sensor_read();

long use_sensor() {
    return sensor_read();
}
// END violation
