/*generate  messages for approriate
 * events occured on ethernet it derived from class device interface  
 * and send it to logger class */
/* Author : Afsal ks*/

#include "device.hpp"
#include "ethernet.hpp"

Ethernet::Ethernet()
{

}
Ethernet::~Ethernet()
{
	
}
void Ethernet::read(void)
{
/* ethernet read message generated  and send it to class logger*/
	if(this->flag)
	{
		log.write("[LOG_INFO] [ETHERNET] read",LOG_INF);
	}
	else
	{
		log.write("[LOG_WARNING] [ETHERNET] not connected", LOG_WARN);
		
	}	
}
void Ethernet::write(void)
{
/*  ethernet write message generated  and send it to class logger*/
	if(this->flag)
	{
		log.write("[LOG_INFO] [ETHERNET] write", LOG_INF);
	}
	else
	{
		log.write("[LOG_WARNING] [ETHERNET] not connected", LOG_WARN);
		
	}
}
void Ethernet::open(void)
{
/*  ethernet open message generated  and send it to class logger*/
	if(!this->flag)
	{
		this->flag=1;
		log.write("[LOG_INFO] [ETHERNET] connected", LOG_INF);
	}
	else
	{
		log.write("[LOG_WARNING] [ETHERNET] already connected",LOG_WARN);
	}
}
void Ethernet::close(void)
{
/*  ethernet close message generated  and send it to class logger*/
	if(this->flag)
	{
		log.write("[LOG_INFO] [ETHERNET] disconnected",LOG_INF);
		this->flag=0;
	}
	else
	{
		log.write("[LOG_ERR] [ETHERNET] not connected",LOG_ERR);
	}
}
void Ethernet::check_status(void)
{
/*  ethernet status checking message generated  and send it to class logger*/
	if(this->flag)
	{
		log.write("[LOG_INFO]  [ETHERNET] status : connected",LOG_INF);
	}
	else
	{
		log.write("[LOG_WARNING] [ETHERNET]  status : disconnected",LOG_WARN);
	}
}
