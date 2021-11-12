/* Author: Afsal ks */

#include "device.hpp"

Device_interface::Device_interface()
{
	log=Logger();
	log.to_console = true;
	log.to_syslog = false;
	this->flag=0;
	cenable=1;
}

Device_interface::~Device_interface(){}
void Device_interface::enable_console()
{
		log.to_console = true;
		cenable=1;

}

void Device_interface::enable_syslog()
{

		log.to_syslog = true;
		senable=1;

}

void Device_interface::disable_console()
{
		log.to_console=false;
		cenable=0;
}

void Device_interface::disable_syslog()
{
		log.to_syslog=false;
		senable=0;

}


