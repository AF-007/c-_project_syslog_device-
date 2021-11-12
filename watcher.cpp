/*
 * Watcher program is an independent program which reads syslog
 * in Linux (var/log/syslog).
 * Filters based on device (say USB) and different levels (say LOG_ERR) 
 * and dump it to a console.
 * 
 * How to execute:
 * g++ -o watcher watcher.cpp
 * ./watcher -n 100 -d usb -l log_info
 * 
 * n - number of lines
 * d - device  (say usb,uart, ethernet)
 * l - levels  (say log_err, log_warning, log_info)*/
/* Author : Nitheesh ks */
 
#include <getopt.h>
#include <fstream>
#include <string.h>
#include <iostream>
#include <unistd.h>

using namespace std;

using namespace std;

void seek_line(FILE *fp, int line)
{
/* 
 * seek_line function seeks for the last 'line' number of lines.
 * 'line' is the number of lines given via command line ( -l 100 ) and
 * place fp overthere.
 */
	int i=0,pos;
	fseek(fp,0,SEEK_END);
	pos=ftell(fp);
	while(pos)
	{
		if(!fseek(fp,--pos,SEEK_SET))
		{
			if(fgetc(fp)=='\n')
			{
				i++;
				if(i==line)
				{
					break;
				}
			}
		}
	}
	return ;
}

bool match_occured(char* buf,  char* value)
{
/*
 * match_occured function checks whether the given device (-d usb) and
 * level (-l log_info) is matching with syslog data .
 * If match occured, return true else return false 
 */
	string s = string(buf);
	size_t found = s.find(value);

	if (found!=string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

char *prog_name;
void help()
{
/*
 * If the given command is wrong or missing something it will print an
 * alert msg.
 */
	cout<<"\nRequired format: "<<prog_name<<" -n <int> -d <string> -l <string>\n";
}

char* upper(char* s)
{
/*
 *  Converts lower case to upper case letters
 */
	int n = 0;
	while(s[n] != 0)
	{
		s[n] = toupper(s[n]);
		n++;
	}
	return(s);
}

int main(int argc, char *argv[])
{
/*
 * Reads l, n, d via command line
 * Dumps last 'numlines' syslog to console and keeps monitering syslog.
 * If any new log is written to syslog it will be displayed to the
 * console. 
 */
	int c;
	char* numlines = NULL;
	char* device = NULL;
	char* levels = NULL;
	prog_name = argv[0];
	char buf[500];

	while(1)
	{
		int option_index = 0;
		static struct option long_options[] =
		{
			{"numlines", required_argument, 0, 'n'},
			{"device", required_argument, 0, 'd'},
			{"levels", required_argument, 0, 'l'},
		};
		c = getopt_long(argc, argv, "n:l:d:", long_options, &option_index);
		if (c == -1) break;
		switch (c)
		{
		case 'n':
			numlines = optarg;
			break;
		case 'd':
			device = optarg;
			break;
		case 'l':
			levels = optarg;
			break;
		}
	}

	if (!(device && levels && numlines))
	{
		help();
		return 1;
	}

	char needle[100];
	sprintf(needle, "[%s] [%s]",upper(levels),upper(device));
	printf("Needle: %s\n", needle);

	FILE *fp=fopen("/var/log/syslog","r");

	seek_line(fp, atoi(numlines)+1);
	int n = 0;
	long last = ftell(fp);

	while(1)
	{
		fseek(fp,0,SEEK_END);
		if(ftell(fp) == last)
		{
			sleep(0.1);
			continue;
		}
		fsetpos(fp, (const fpos_t*) &last);

		while(!feof(fp))
		{
			int x = fgetc(fp);
			if(x == EOF) break;
			buf[n] = (unsigned char) x;
			
			if(buf[n] != '\n')
			{
				n++;
				continue;
			}
			buf[n] = 0;
			if(match_occured(buf, needle))
			{
				cout<<buf<<endl;
			}
			n = 0;
		}
		last = ftell(fp);
	}

	return 0;
}
