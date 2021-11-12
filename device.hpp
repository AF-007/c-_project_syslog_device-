/*parent class of  usb, uart, ethernet */
/* Author : Afsal ks*/

#include <iostream>
#include "logger.hpp"
using namespace std;

class Device_interface
{
	protected:
		int flag,senable,cenable;
		Logger log;
	public:
		Device_interface();
		~Device_interface();
		virtual void open(void)=0;
		virtual void close(void)=0;
		virtual void read(void)=0;
		virtual void write(void)=0;
		virtual void check_status(void)=0;
		void enable_console();
	    void enable_syslog();
		void disable_console();
		void disable_syslog();

};


