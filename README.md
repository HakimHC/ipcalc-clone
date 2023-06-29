## ipcalc-clone

#### My implementation, in C, of the ```ipcalc``` utilty.

ipcalc is an IPv4 Netmask/Broadcast/etc calculator, made for educational purposes.
It takes an IPv4 address and netmask and calculates the resulting broadcast, network, Cisco wildcard mask, and host range.
It is also intended to be a teaching tool and presents the results as easy-to-understand binary values.

This repository is just my small implementation of this command-line utility.

#### My approach

I decided to use GNU's ```argp``` to parse the arguments and options of this program.
This program admits the following arguments:
* IP Address
* [Netmask] (optional -> defaults to 255.255.255.0)

and the following options:
* -b, --nobinary:   Surpress the bitwise output
* -c, --color:      Display ANSI color codes
* -V, --version:    Print program version
* -?, --help:       Give a help list
* --usage:          Give a short usage message

#### Compilation && Usage
To build this project, it is enough to simply call ```make```.
After finishing compilation, the program can be run with
```./myipcalc```
and the object files may be cleaned with ```make clean``` or ```m̀ake fclean```.

#### GNU GPLv3
This repository is released under the GNU GPLv3 license. For more information, check out the LICENSE file.

This version of ipcalc-clone does not yet support calculation of broadcast, network, and host range.
#### Work in progress
