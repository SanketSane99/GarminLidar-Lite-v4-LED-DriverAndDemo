

//DEMO 1: Control Vehicle Using Bluefruit and Use Lidar to Avoid Collision
#include "mbed.h"
#include "LIDARLite_v4LED.h"
#include "Motor.h"
LIDARLite_v4LED lidar; //lidar
I2C i2c(p9, p10); //i2c with lidar
Motor left_motor(p21,p6,p5); //dc motor
Motor right_motor(p22,p7,p8); //dc motor
RawSerial blue(p28, p27); //bluefruit



int main() {
    pc.baud(9600);    
    blue.baud(9600);
    i2c.frequency(200000);
  
    //connect to device using default address
    uint8_t address = LIDARLITE_ADDR_DEFAULT; 
    bool connected = lidar.begin(address, i2c);
   
    
    
    int lidarDistance;
    bool old_stop = 0; //save old value of stop to detect transition
    bool stop = true; //current stop boolean (true if object is within certain range of lidar)
    char bnum = 0; 
    char bhit = 0;
    float speed = 1;
    while(1) {
        
        lidarDistance = lidar.getDistance(); //get distance
        
        stop = lidarDistance <= 30; //stop when object is within 30 cm of lidar
        if(stop && !old_stop){ 
            left_motor.speed(0);
            right_motor.speed(0);    
        }
        old_stop = stop;
       
        if(blue.readable()){
          
            if(blue.getc() == '!'){
               
                if(blue.getc() == 'B'){ 
                 
                    bnum = blue.getc();
                    bhit = blue.getc();
                    //pc.printf("bnum: %c\n\r", bnum);
                    //pc.printf("bhit: %c\n\r",bhit);
            
                    if(bhit == '1'){
                       
                        switch(bnum){
                            case '5': //move forward
                                if(!stop){
                                    left_motor.speed(speed);
                                    right_motor.speed(speed);
                                }
                             
                                
                                break;
                    
                            case '6': //move backward
                                
                                left_motor.speed(-speed);
                                right_motor.speed(-speed);
                                
                                break;
                    
                            case '7': //turn left
                                
                                left_motor.speed(speed);
                                right_motor.speed(-speed);
                                
                                break;
                    
                            case '8': //turn right
                                
                                left_motor.speed(-speed);
                                right_motor.speed(speed);
                                
                                break;
                        }
                    }
                    else if(bhit == '0'){
                         left_motor.speed(0);
                         right_motor.speed(0);
                        
                    }
                }
            
            }
            
            
        }
        wait(.1);
    }
}



/*

//DEMO 2: Print out some distances and temperatures
#include "mbed.h"
#include "LIDARLite_v4LED.h"

LIDARLite_v4LED lidar;
I2C i2c(p9, p10);
Serial pc(USBTX, USBRX);


int main() {
    pc.baud(9600);
    i2c.frequency(200000);
    
    //connect to device using default address   
    uint8_t address = LIDARLITE_ADDR_DEFAULT; 
    bool connected = lidar.begin(address, i2c);
    pc.printf("connected: %d\n\r",connected);
    
    //change the device address
    lidar.setI2Caddr(0x63, true);
    connected = lidar.begin(0x63, i2c);
        
    
    
    
    
    while(true){
        
     
       
        pc.printf("distance = %i\n\r", lidar.getDistance()); //get and print distance
       
        pc.printf("board temperature = %i C\n\r", lidar.getBoardTemp()); //get and print board temperature
        pc.printf("SOC temperature = %i C\n\r", lidar.getSOCTemp()); //get and print SOC temperature
        
        
        wait(0.5);
    }
    
    
    
    
}   

*/