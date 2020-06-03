#include <iostream.h>
#include <time.h>
#include <fstream.h>
#include <qstring.h>

#include "writelogfile.h"

void writeLogFile(QString msg)
{
	ofstream logFile("logfile.log", ios::app);
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%Y-%m-%d %X";
	char dataTime[20];
	
	strftime(dataTime, 20, format, timeinfo);
	if(!logFile)
	{
		cerr << "Файл не может быть открыт" << endl;
		return;
	}
	
	logFile << "[" << dataTime << "] #" << msg.simplifyWhiteSpace() << endl;;
	logFile.close();
	return;
}