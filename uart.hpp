/* Author : Afsal ks*/

class Uart:public Device_interface{
	public:
		Uart();
		~Uart();
		void open(void);
		void close(void);
		void read(void);
		void write(void);
		void check_status(void);
};
