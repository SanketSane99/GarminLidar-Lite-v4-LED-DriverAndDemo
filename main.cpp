#include "mbed.h"
#include "LIDARLite_v4LED.h"

LIDARLite_v4LED lidar;
I2C i2c(p9, p10);

Serial pc(USBTX, USBRX);

int main() {
    pc.baud(9600);    
    i2c.frequency(200000);
    int distance;
    int temperature;
    bool connected;
    
    connected = lidar.begin(0xC4, i2c);
    pc.printf("%d\n\r",connected); 
    
    while(1) {
        
        distance = lidar.getDistance();
        temperature = lidar.getBoardTemp();
        pc.printf("distance = %i\n", distance);
        pc.printf("temperature = %i\n", temperature);
        wait(3);
    }
}
