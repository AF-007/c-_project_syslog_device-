/*generate  messages for approriate
 *events occured on uart it derived from class 
 *device interface and send it to logger class*/
/* Author : Afsal ks*/


#include "device.hpp"
#include "uart.hpp"

Uart::Uart(){}
Uart::~Uart(){}

void Uart::read(void)
{
/* uart read message generated  and send it to class logger */
	if(this->flag)
	{
		log.write("[LOG_INFO] [UART] read",LOG_INF);
	}
	else
	{
		log.write("[LOG_WARNING] [UART] not connected", LOG_WARN);
		
	}
}

void Uart::write(void)
{
/* uart write message generated send it to class logger*/
	if(this->flag)
	{
		log.write("[LOG_INFO] [UART] write", LOG_INF);
	}
	else
	{
		log.write("[LOG_WARNING] [UAR]T not connected", LOG_WARN);
		
	}
}

void Uart::open(void)
{
/* uart open message generated  and send it to class logger */

	if(!this->flag)
	{
		this->flag=1;
		log.write("[LOG_INFO] [UART] connected", LOG_INF);
	}
	else
	{
		log.write("[LOG_WARNING] [UART] already connected",LOG_WARN);
	}
}

void Uart::close(void)
{
/* uart close message generated  and send it to class logger */
	if(this->flag)
	{
		log.write("[LOG_INFO] [UART] disconnected",LOG_INF);
		this->flag=0;
	}
	else
	{
		log.write("[LOG_ERR] [UART] not connected",LOG_ERR);
	}
}

void Uart::check_status(void)
{
/* uart status checking  message generated  and send it to class logger*/
	if(this->flag)
	{
		log.write("[LOG_INFO] [UART] status: connected",LOG_INF);
	}
	else
	{
		log.write("[LOG_WARNING] [UART] status: disconnected",LOG_WARN);
	}
}

