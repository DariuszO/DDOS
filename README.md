# DDOS
[![Software License](https://img.shields.io/badge/license-GNU%20GPL%20V2-green.svg?style=flat-square)](LICENSE) [![Version](https://img.shields.io/badge/version-1.0.0-red.svg?style=flat-square)](https://github.com/maelsan/DDOS)
[![OS](https://img.shields.io/badge/OS-Linux-orange.svg?style=flat-square)](https://github.com/torvalds/linux)

## Installation
You need to use `make` for generate the binary `DDOS`.

After, he should be into the `bin` folder.

## Use

    -h [--help]
    -v [--version]
    -t [--target]
    -s [--time] (default: 3600) -> Time of the operation
    -p [--port] (default: 80)
    -f [--frequency] (default: 10) -> simultaneous requests

    Example :
    ./DDOS -t 12.45.32.123 -s 2400 -p 20 -f 200

## Licence
The GNU GENERAL PUBLIC LICENSE V2 (GNU GPL V2). Please see License File for more information.
