/* Author : Afsal ks*/

class Ethernet:public Device_interface
{
	public:
		Ethernet();
		~Ethernet();
		void open(void);
		void close(void);
		void read(void);
		void write(void);
		void check_status(void);
	
};
