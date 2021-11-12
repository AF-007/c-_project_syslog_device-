/* Author : Sagar M Krishnadas */

#include <cstring>
#include <iostream>
#include <chrono>
#include <cstdio>
#include <syslog.h>
#include <cstring>

#define LOG_INF  1
#define LOG_WARN 2
#define LOG_ERR  3

using namespace std;
class Logger
{
	public:
		bool to_console;
		bool to_syslog;
		Logger();
		~Logger();
		void write(const char*, int);
};
