Problem 1/ C++ Project
Create a Linux based C++ application which supports the following,
    1. A Logger Class which could be used to log messages to console or syslog
    2. Log should support different levels like INFO/WARNING/ERROR
    3. Log level set for a specific module should be independent of other modules
    4. Develop DeviceInterface class which could read data from UART, USB, ETHERNET
    5. DeviceInterface class should support methods - open, close, check status, read, write
    6. Develop UserInterface class which provides access to any of the supported device
    7. User should be able to perform open, close, check status, read, write, enable logs irrespective of the desired device interface

Output :
Use multiple Linux terminals to send data to virtual interfaces like UART/USB/ETH
Run this application in another shell, which should be able to read and dump the data based on set log level

Environment :
Linux command line
