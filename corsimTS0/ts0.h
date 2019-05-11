#ifndef TS0_2015

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>
#include <cstring>
#include <math.h>
#include <string>

/*
	The basic functions that will be used are declared
		GetMsgInfo()	: Used to read the Message Info to determine the type of message.
		GetVehMsg()		: Used to read message if the Message Type is Vehicle Message
		CompVehInfo()	: Used to Compare the vehicle Info
		ReadFile()		: Used to read the binary .TSD file
*/

int processTS0file(std::string &inputname);
void GetMsgInfo();
void CompMsgInfo();
void GetVehMsg();
void CompVehInfo();
void ReadFile();
inline float ft2m( int ft )		{ return ft*0.3048; };
inline float fts2kmh( int fts )	{ return fts*1.09728; };

#endif