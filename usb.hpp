/* Author : Afsal ks*/

class Usb:public Device_interface
{
	public:
		Usb();
		~Usb();
		void open(void);
		void close(void);
		void read(void);
		void write(void);
		void check_status(void);
};
