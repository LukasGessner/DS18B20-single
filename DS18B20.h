/*	MIT License
*
*	Copyright (c) 2020 Lukas Gessner
*
*	Permission is hereby granted, free of charge, to any person obtaining a copy
*	of this software and associated documentation files (the "Software"), to deal
*	in the Software without restriction, including without limitation the rights
*	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*	copies of the Software, and to permit persons to whom the Software is
*	furnished to do so, subject to the following conditions:
*
*	The above copyright notice and this permission notice shall be included in all
*	copies or substantial portions of the Software.
*
*	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*	SOFTWARE.
*/

#ifndef DS18B20_h
#define DS18B20_h

#include "mbed.h"

#ifdef USE_DS18B20

#define OWI_SKIP_ROM 0xCC
#define DS18B20_START 0x44
#define DS18B20_READ_SCRATCH_PAD 0xBE

class OWI
{
	public:
		OWI(PinName pin);
		void sendByte(unsigned char data);
		unsigned char receiveByte();
		unsigned char detectPresence();
		
	private:
		void write0();
		void write1();
		unsigned char readBit();
		DigitalInOut owi_io;
};
#endif

#ifdef USE_DS18B20
class DS18B20
{
	public: 
		DS18B20(PinName pin);
		float readTemp();
	
	private:
		OWI DS18B20_OWI;
};

#endif