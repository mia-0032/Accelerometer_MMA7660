/*****************************************************************************/
//	Function:    Get the accelemeter of the x/y/z axis. 
//  Hardware:    Grove - 3-Axis Digital Accelerometer(±1.5g)
//	Arduino IDE: Arduino-1.0
//	Author:	 Frankie.Chu		
//	Date: 	 Jan 10,2013
//	Version: v0.9b
//	by www.seeedstudio.com
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
/*******************************************************************************/

#include <Wire.h>
#include "MMA7660.h"
MMA7660 accelemeter;
void setup()
{
	accelemeter.init();  
	SerialUSB.begin(9600);
}
void loop()
{
	int8_t x;
	int8_t y;
	int8_t z;
	float ax,ay,az;
	accelemeter.getXYZ(&x,&y,&z);
	
	SerialUSB.print("x = ");
    SerialUSB.println(x); 
    SerialUSB.print("y = ");
    SerialUSB.println(y);   
    SerialUSB.print("z = ");
    SerialUSB.println(z);
	
	accelemeter.getAcceleration(&ax,&ay,&az);
    SerialUSB.println("accleration of X/Y/Z: ");
	SerialUSB.print(ax);
	SerialUSB.println(" g");
	SerialUSB.print(ay);
	SerialUSB.println(" g");
	SerialUSB.print(az);
	SerialUSB.println(" g");
	SerialUSB.println("*************");
	delay(500);
}


