/*
file   : softi2c.cpp
author : shentq
version: V1.0
date   : 2015/7/5

Copyright 2015 shentq. All Rights Reserved.

Copyright Notice
No part of this software may be used for any commercial activities by any form or means, without the prior written consent of shentq.

Disclaimer
This specification is preliminary and is subject to change at any time without notice. shentq assumes no responsibility for any errors contained herein.
*/

#include "i2c.h"

SOFTI2C::SOFTI2C(GPIO* SCLPin, GPIO* SDAPin)
{
	sclPin = SCLPin;
	sdaPin = SDAPin;
}	
void SOFTI2C::begin(uint32_t speed)
{
	setSpeed(speed);
	sdaPin->mode(OUTPUT_PP);
	sclPin->mode(OUTPUT_PP);
}
int8_t SOFTI2C::setSpeed(uint32_t speed)
{
	_speed = speed;
	switch(_speed)
	{
		case 400000:
			_delayTimes = 4;
			break;
		case 300000:
			_delayTimes = 8;
			break;
		case 200000:
			_delayTimes = 16;
			break;
		case 100000:
			_delayTimes = 32;
			break;
		default:
			_delayTimes = _speed;
			break;
	}
	return 0;
}
uint32_t SOFTI2C::readConfig()
{
	return _speed;
}
void SOFTI2C::start()
{
	sdaPin->mode(OUTPUT_PP);
	sdaPin->set();
	sclPin->set();delay_us(_delayTimes);
	sdaPin->reset();delay_us(_delayTimes);
	sclPin->reset();

}

void SOFTI2C::stop()
{
	sdaPin->mode(OUTPUT_PP);
	sclPin->reset();
	sdaPin->reset();delay_us(_delayTimes);
	sclPin->set();delay_us(_delayTimes);
	sdaPin->set();
}
int8_t SOFTI2C::waitAck()
{
	uint8_t cErrTime = 5;
	sdaPin->mode(INPUT_PU);
	sclPin->set();delay_us(_delayTimes);
	while(sdaPin->read())
	{
		cErrTime--;
		delay_us(_delayTimes);
		if(cErrTime == 0)
		{
			sdaPin->mode(OUTPUT_PP);
			stop();
			return -1;
		
		}
	
	}
	sclPin->reset();delay_us(_delayTimes);
	return 0;
}
int8_t SOFTI2C::sendAck()
{
	sdaPin->mode(OUTPUT_PP);
	sdaPin->reset();delay_us(_delayTimes);
	sclPin->set();delay_us(_delayTimes);
	sclPin->reset();delay_us(_delayTimes);

	return 0;
}
int8_t SOFTI2C::sendNoAck()	
{
	sdaPin->mode(OUTPUT_PP);
	sdaPin->set();delay_us(_delayTimes);
	sclPin->set();delay_us(_delayTimes);
	sclPin->reset();delay_us(_delayTimes);
 return 0;
}
int8_t SOFTI2C::sendByte(uint8_t byte)
{
	int8_t ret = 0;

	uint8_t ii = 8;
	sdaPin->mode(OUTPUT_PP);
	while( ii-- )
	{
		sclPin->reset();
		sdaPin->write(byte & 0x80);delay_us(_delayTimes);
		byte += byte;//<<1
		sclPin->set();delay_us(_delayTimes);
		sclPin->reset();delay_us(_delayTimes);
	}
	ret = waitAck();
  return ret;
}
int8_t	SOFTI2C::send7BitsAddress(uint8_t slaveAddress)
{
	int8_t ret = 0;
	sendByte(slaveAddress);
	return ret;
}

uint8_t SOFTI2C::receiveByte(void)
{
	uint8_t i = 8;
	uint8_t byte = 0;
	sdaPin->mode(INPUT_PU);
	while(i--)
	{
		byte += byte;
		sclPin->reset();delay_us(_delayTimes);
		sclPin->set();delay_us(_delayTimes);
		byte |= sdaPin->read();
	}
	sclPin->reset();delay_us(_delayTimes);

	return byte;
}
int8_t SOFTI2C::writeByte(uint8_t slaveAddress,uint8_t regAddress,uint8_t data)
{
	int8_t ret = 0;
		start();
	
    if (send7BitsAddress(slaveAddress) == -1)
        ret = -1;
		
    if (sendByte(regAddress) == -1)
        ret = -2;

    if (sendByte(data) == -1)
        ret = -3;
		
		stop();

    delay_us(10);      
    return ret;
}
int8_t SOFTI2C::writeByte(uint8_t slaveAddress,uint8_t regAddress,uint8_t* data,uint16_t numToWrite)
{
	int8_t ret = 0;
		start();

    if (send7BitsAddress(slaveAddress) == -1)
        ret = -1;
		
    if (sendByte(regAddress) == -1)
        ret = -2;

		while(numToWrite--)
		{
			sendByte(*data++);
			if (waitAck() == -1)
					ret = -3;
		}
		
		stop();

    delay_us(10);      
    return ret;
}
int8_t 	SOFTI2C::readByte(uint8_t slaveAddress,uint8_t regAddress,uint8_t* data)
{

	int8_t ret = 0;
		start();

    if (send7BitsAddress(slaveAddress) == -1)
        ret = -1;


    if (sendByte(regAddress) == -1)
        ret = -2;

		start();

    if (sendByte(slaveAddress + 1) == -1)
        ret = -3;

		*data = receiveByte();
		sendNoAck();
		stop();

	return ret;
}
int8_t 	SOFTI2C::readByte(uint8_t slaveAddress,uint8_t regAddress,uint8_t* data,uint16_t numToRead)
{
	int8_t ret = 0;
	int i = 0;
	
		start();

    if (send7BitsAddress(slaveAddress) == -1)
        ret = -1;


    if (sendByte(regAddress) == -1)
        ret = -2;

		start();
    if (send7BitsAddress(slaveAddress + 1) == -1)
        ret = -3;
		
		while(numToRead)
		{
			*data++ = receiveByte();
			numToRead--;
			i++;
			if(numToRead == 0)
			{
				sendNoAck();
				stop();
				ret = 0;
			}
			else
				sendAck();
		}

	return ret;
}
int8_t SOFTI2C::waitBusy(uint8_t slaveAddress)
{
	int8_t ret;
	uint8_t i = 0;
	do
	{
		start();
		ret = send7BitsAddress(slaveAddress);
		sendAck();
		sendByte(slaveAddress);
		stop();
		if(i++==100)
		{
			return -1;
		}
	}while(ret != 0);//如果返回值不是0，继续等待
	return 0;
	return 0;
}
