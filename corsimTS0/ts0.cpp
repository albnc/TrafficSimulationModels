/* ----------------------------------------------------------------------
*	Name of the file: BIN_TO_ASCII.CPP
*	This C++ File was created to read the output from the Binary .tsd file 
*	that is generated by TSIS and convert it into an ASCII readable format.
*	DHULIPALA [2002]
-------------------------------------------------------------------------*/
#include "ts0.h"
#include <ctime>

int inhandle, outhandle, bytes;

unsigned int msg_name;
unsigned int msg_length;
unsigned int sim_time;
unsigned int inst_id;
unsigned int inst_id_count;
unsigned int request_type;
unsigned int i,vehicle;
unsigned int nodea, nodeb, cnode;
unsigned int veh_id, fleet, veh_type, veh_length, driver;
unsigned int lane_id;
int veh_pos;
unsigned int prev_usn, turn_code, queue;
float acc;
unsigned int vel, lane_change, target_lane, dest_node;
unsigned int leader_id, follower_id, prev_lane;

FILE *input, *output;
char tempchar;

unsigned int link_id, thru_code;

double htemp;
long hlink;
unsigned int hi, hlocation, hveh_id, htime_step;
int haccel, hvelocity, hpos;
char hbuffer[70];

int processTS0file(std::string &inputname)
{	
			
	std::string outputname;
	
	//	Create input and output filenames	
	outputname = inputname;
	std::string::iterator it = outputname.end();
	outputname.replace( it-3, it, "txt");
		
	// check for errors with the filenames provided at the commandline
	if( (input=fopen(inputname.c_str(), "rb") ) == NULL )
	{
		fprintf( stderr, "Error Opening Input File: %s \n", inputname.c_str());
		exit(1);
	}
	if( (output=fopen(outputname.c_str(), "w") ) == NULL )
	{
		fprintf( stderr, "Error Opening Output File: %s \n", outputname.c_str());
		exit(1);
	}
	inhandle = fileno(input);
	outhandle = fileno(output);
	ReadFile();
	
	fclose( input );
	fclose( output );

	
	int t = clock();
	printf( "%.3f s\n", float(t)/CLOCKS_PER_SEC);
	return 0;
}

void ReadFile()
{
	fprintf(output, "Time \tLinkID \tVeh_id \tFleet \tVehTyp \tVehLen \tDriver \tLaneID \tVehpos \tPUSN \tTurncode \tQueue \tAcc \tVel \tLnChg \tTrgLn \tDstnod \tLeadID \tFollowID \tPrevLane \n");

	// The actual scanning of file starts after the first 16 bytes.
	// The first 16 bytes of File represent the Header Information
	lseek( inhandle, 16,SEEK_SET );

	// Keep reading data until the end of file is reached
	while( !eof(inhandle) )
	{
		// First read the msg info into local variables for comparasion
		GetMsgInfo();

		// Check to see if this is the vehicle info to capture
		if( msg_name == 3001 && request_type == 14000 )
		{
			// Since vehicle message read number of vehicles in message and length
			CompVehInfo();

			// Read all the vehicles snapshot in the message
			for( int i=0; i<inst_id_count; i++ )
			{
				// read individual vehicle message
				GetVehMsg();

				// Write to output file
				fprintf(output, "%4u \t%8u \t%4u \t%4u \t%4u \t%5.1f \t%4u \t%4u \t%5.1f \t%8u \t%4u \t%4u \t%5.1f \t%5.1f \t%4u \t%4u \t%4u \t%8u \t%8u \t%4u \n",
					sim_time, inst_id,
					veh_id, fleet, veh_type, ft2m(veh_length), driver, lane_id,
					ft2m(veh_pos), prev_usn, turn_code, queue,
					ft2m(acc), fts2kmh(vel), lane_change, target_lane, dest_node, 
					leader_id, follower_id, prev_lane );
			}
		}
		else
		{
			CompMsgInfo();
			// Go to next message if message info type is not vehicle
		}
	}
}

void GetMsgInfo()
{
	// Message info consists of:
	//	message_name	4 bytes
	//	message_len		4 bytes
	//	sim_time		4 bytes
	//	request_type	4 bytes

	bytes = read( inhandle, &msg_name, 4 );
	bytes = read( inhandle, &msg_length, 4 );
	bytes = read( inhandle, &sim_time, 4 );
	bytes = read( inhandle, &request_type, 4 );
}

void CompVehInfo()
{
	// Since we are not concerned with the first 28 bytes
	// skip to the next 
	fseek( input, 28, SEEK_CUR );

	// read the important fields into local variables
	// inst_id_count represents how many vehicles wrapped into message
	bytes = read( inhandle, &inst_id, 4 );
	bytes = read( inhandle, &inst_id_count, 2 );
}

void CompMsgInfo()
{
	// skip to the next
	lseek( inhandle, msg_length-4, SEEK_CUR );
}

void GetVehMsg()
{
	// capture all the attributes into local variables
	// for persistence into output file
	bytes = read( inhandle, &veh_id, 4 );
	bytes = read( inhandle, &fleet, 1 );
	bytes = read( inhandle, &veh_type, 1 );
	bytes = read( inhandle, &veh_length, 1 );
	bytes = read( inhandle, &driver, 1 );
	bytes = read( inhandle, &lane_id, 1 );
	bytes = read( inhandle, &veh_pos, 4 );
	bytes = read( inhandle, &prev_usn, 2 );
	bytes = read( inhandle, &turn_code, 1 );
	bytes = read( inhandle, &queue, 1 );
	
	bytes = read( inhandle, &tempchar, 1 );
	acc = float(tempchar);
	
	bytes = read( inhandle, &vel, 1 );
	bytes = read( inhandle, &lane_change, 1 );
	bytes = read( inhandle, &target_lane, 1 );
	bytes = read( inhandle, &dest_node, 2 );
	bytes = read( inhandle, &leader_id, 4 );
	bytes = read( inhandle, &follower_id, 4 );
	bytes = read( inhandle, &prev_lane, 1 );
}