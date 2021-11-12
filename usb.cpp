/*generate  messages for approriate
 *events occured on usb it derived from class device interface
 *and send it to logger class*/
/* Author : Afsal ks*/

#include "device.hpp"
#include "usb.hpp"

Usb::Usb(){};
Usb::~Usb(){};

void Usb::read(void)
{
/* usb read  message generates and  send it to class logger*/
	if(this->flag)
	{
		log.write("[LOG_INFO] [USB] read",LOG_INF);
	}
	else
	{
		log.write("[LOG_WARNING] [USB] not connected", LOG_WARN);
	}
}

void Usb::write(void)
{
/* usb write message generates and  send it to class logger*/
	if(this->flag)
	{
		log.write("[LOG_INFO] [USB] write", LOG_INF);
	} 
	else
	{
		log.write("[LOG_WARNING] [USB] not connected", LOG_WARN);
		
	}
}
void Usb::open(void)
{
/* usb open   message generates and  send it to class logger*/
	if(!this->flag)
	{
		this->flag=1;
		log.write("[LOG_INFO] [USB] connected", LOG_INF);
	}
	else
	{
		log.write("[LOG_WARNING] [USB] already connected",LOG_WARN);
	}
}
void Usb::close(void)
{
/* usb close  message generates and  send it to class logger*/
	if(this->flag)
	{
		
		log.write("[LOG_INFO] [USB] disconnected",LOG_INF);
		this->flag=0;
	}
	else
	{
		log.write("[LOG_ERR] [USB] not connected",LOG_ERR);
	}
}
void Usb::check_status(void)
{
/* usb status checking  message generates and  send it to class logger*/
	if(this->flag)
	{
		log.write("[LOG_INFO]  [USB] status: connected",LOG_INF);
	}
	else
	{
		log.write("[LOG_WARNING] [USB] status :  disconnected",LOG_WARN);
	}
}



