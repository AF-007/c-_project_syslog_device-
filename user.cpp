/* User interface which allow the users to perform certian
 * functions on devices such as USB, UART and ETHERNET.
 * User can enable and disable the log write to syslog and console
 * User can switch the devices */
/*Author : Fasila Latheef */
 
#include "user.hpp"

Device_interface *usb=new Usb();
Device_interface *uart=new Uart();
Device_interface *e_net=new Ethernet();
Device_interface *dev = NULL;

int s_toggle=0,c_toggle=1;
char n;

void choose_write(Device_interface* dev){
/*Enable or disable writing options to syslog and console*/
	if(s_toggle==0){
		cout<<"Enable write to syslog(y/n)\n";
		cin>>n;
		n=tolower(n);
		switch(n){
			case 'y':
				s_toggle=1;
				dev->enable_syslog();
				break;
			case 'n':
				break;
		}
	}
	else if(s_toggle==1){
		cout<<"Disable write to syslog(y/n)\n";
		cin>>n;
		n=tolower(n);
		switch(n){
			case 'y':
				s_toggle=0;
				dev->disable_syslog();
				break;
			case 'n':
				break;
		}
	}
	if(c_toggle==0){
		cout<<"Enable write to console(y/n)\n";
		cin>>n;
		n=tolower(n);
		switch(n){
			case 'y':
				c_toggle=1;
				dev->enable_console();
				break;
			case 'n':
				break;
		}
	}
	else if(c_toggle==1){
		cout<<"Disable write to console(y/n)\n";
		cin>>n;
		n=tolower(n);
		switch(n){
			case 'y':
				c_toggle=0;
				dev->disable_console();
				break;
			case 'n':
				break;
		}
	}
	system("clear");
}

Device_interface* check_device(string a){
/*check which device is user choosed currently
 * and set the object corresponding to class*/
	if(a=="usb") dev = usb;
	if(a=="uart") dev = uart;
	if(a=="ethernet") dev = e_net;
	return dev;
}

Device_interface* d=NULL;

void change_device(Device_interface * d){
/*Allows user to change the devices*/
	int b;
	if(d==usb){
		cout<<"choose 1.Uart or 2.Ethernet\n";
		cin>>b;
		switch(b){
			case 1:
				d=uart;
				s_toggle=0;
				c_toggle=1;
				menu(d);
				break;
			case 2:
				d=e_net;
				s_toggle=0;
				c_toggle=1;
				menu(d);
				break;
		}
	}
	if(d==uart)
	{
		cout<<"choose 1.USB or 2.Ethernet\n";
		cin>>b;
		switch(b){
			case 1:
				d=usb;
				s_toggle=0;
				c_toggle=1;
				menu(d);
				break;
			case 2:
				d=e_net;
				s_toggle=0;
				c_toggle=1;
				menu(d);
				break;
		}
	}
	if(d==e_net)
	{
		cout<<"choose 1.Uart or 2.Usb\n";
		cin>>b;
		switch(b){
			case 1:
				d=uart;
				s_toggle=0;
				c_toggle=1;
				menu(d);
			case 2:
				d=usb;
				s_toggle=0;
				c_toggle=1;
				menu(d);
		}
	}
}
void menu(Device_interface *dev)
{
/*Display the options that user can do and call correspondig
 *functions from Device_interface class*/
	if(dev == NULL)
	{
		cout<<"Invalid input\n";
		return;
	}
	int n;
	while(1)
	{
		cout<<"1.Open\n2.Close\n3.Read\n4.Write\n5.Check status\n6.Update enable or disable\n7.Change device\n8.Exit"<<endl;
		cin>>n;
		switch(n){
			case 1:
				dev->open();
				break;

			case 2:
				dev->close();
				break;

			case 3:
				dev->read();
				break;

			case 4:
				dev->write();
				break;

			case 5:
				dev->check_status();
				break;

			case 6:
				choose_write(dev);
				break;

			case 7:
				change_device(dev);
				break;

			case 8:
				exit(0);
				break;
		}
	}
}

int main(int argc, char **argv){

	string s="";
	for(int i=1;i<argc;i++) s=s+argv[i];
	int len=s.length();
	for(int x=0; x<len;x++) s[x]=tolower(s[x]);
	Device_interface *p = check_device(s);
	menu(p);
	return 0;
}
