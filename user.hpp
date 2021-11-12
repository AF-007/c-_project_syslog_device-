/*Author : Fasila Latheef */

#include "device.hpp"
#include "usb.hpp"
#include "uart.hpp"
#include "ethernet.hpp"
#include <cstring>
#include <cstdlib>
void choose_write();
Device_interface* check_device(string );
void change_device(Device_interface *);
void menu(Device_interface *);
