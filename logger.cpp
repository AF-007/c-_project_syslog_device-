/* logger class which writes the messages 
 * generated from the device interface to 
 * the syslog and console with appropriate levels */
/* Author : Sagar M Krishnadas */

#include "logger.hpp"
#include <syslog.h>

Logger::Logger(){}
Logger::~Logger(){}

void Logger::write(const char* msg, int type)
{
/* write() function writes the messages into
 * syslog and console */
 
	if(to_syslog)
	{/* write to the syslog if enabled */
		if(type==1)
			syslog(LOG_INFO,"%s",msg);
		if(type==2)
			syslog(LOG_WARNING,"%s",msg);
		if(type==3)
			syslog(LOG_ERR,"%s",msg);
		system("clear");
	}
	if(to_console)
	{/* write to the console if enabled */
	       system("clear");
	       auto ct=chrono::system_clock::now();
	       time_t tmp=chrono::system_clock::to_time_t(ct);
	       string st1=ctime(&tmp);
	       if(!st1.empty() && st1[st1.length()-1]=='\n') st1.erase(st1.length()-1);
	       cout<<st1<<' '<<msg<<endl;
	}
}
