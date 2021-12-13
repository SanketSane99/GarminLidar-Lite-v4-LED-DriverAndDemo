# GarminLidarLitev4Led Driver And Demo
Adapted preexisting Arduino library to interface with the LidarLite_v4LED sensor using Mbed.


![image](https://user-images.githubusercontent.com/85893093/145903958-eeffc936-7194-41f8-ade3-3e680ac312af.png)
Garmin LIDAR-Lite v4 LED


The Garmin LIDAR-Lite v4 LED is a lidar sensor that is primarily interfaced with using the I2C or ANT interfaced. It is also configurable for SPI with user applications.
This library and Demo use I2C.


The following image shows the pin layout of the Lidar. Note that most of the pins are circular, except the first, which is rectangular and is the 5V input power source.

![image](https://user-images.githubusercontent.com/85893093/145903079-3c0971f5-d54d-42a2-804c-5f9ab2103091.png)

The next image shows the connections that should be made with the sensor.
![image](https://user-images.githubusercontent.com/85893093/145903112-b44d744b-04aa-4955-b27e-c6257c6156b1.png)


For this demo, the Bluefruit module is used. For pin connection and more info on the bluefruit module, see the following link:
https://os.mbed.com/users/4180_1/notebook/adafruit-bluefruit-le-uart-friend---bluetooth-low-/.

