# Master Sword Rebirth Engine
Run createall to create the solution(s).

## Compiling

### Windows
Use VS2022 or VS2019 with c++14 support.

### Linux
Use GCC 5.x and up.

## Commands
* ``sv_crashcfg <file name>`` - Used to keep track of last map in case of server crash. Mainly used for people who are running multiple servers that share the same assets.
* ``rescount`` - Prints the total count of precached resources in the server console.
* ``reslist <sound | model | decal | generic | event>`` - Separately prints the details of the precached resources for sounds, models, decals, generic and events in server console. Useful for managing resources and dealing with the goldsource precache limits. 
* ``rcon_adduser <ipaddress/CIDR>`` - Add a new IP address or CIDR range to RCON user list (This command adds a new IP address to the RCON user list. The specified IP or CIDR range is granted privileged access to server console. Without any Rcon users, access is allowed to anyone with a valid password)
* ``rcon_deluser <ipaddress> {removeAll}`` - Remove an IP address or CIDR range from RCON user list.
* ``rcon_users`` - List all IP addresses and CIDR ranges in RCON user list.

## Troubleshooting
Please see the [Valve Dev Wiki](https://developer.valvesoftware.com/wiki/Source_SDK_2013#Troubleshooting).

## Contributing
Feel free to help out fixing bugs, pull requests or whatever!

## CI
[![Deploy engine on Linux](https://github.com/MSRevive/MSREngine/actions/workflows/deploy-engine-linux.yml/badge.svg)](https://github.com/MSRevive/MSREngine/actions/workflows/deploy-engine-linux.yml)

## Credits
This would not have been possible if not for [ReHLDS](https://github.com/dreamstalker/rehlds)!
