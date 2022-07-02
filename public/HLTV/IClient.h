/*
*
*    This program is free software; you can redistribute it and/or modify it
*    under the terms of the GNU General Public License as published by the
*    Free Software Foundation; either version 2 of the License, or (at
*    your option) any later version.
*
*    This program is distributed in the hope that it will be useful, but
*    WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*    General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program; if not, write to the Free Software Foundation,
*    Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*    In addition, as a special exception, the author gives permission to
*    link the code of this program with the Half-Life Game Engine ("HL
*    Engine") and Modified Game Libraries ("MODs") developed by Valve,
*    L.L.C ("Valve").  You must obey the GNU General Public License in all
*    respects for all of the code used other than the HL Engine and MODs
*    from Valve.  If you modify this file, you may extend this exception
*    to your version of the file, but you are not obligated to do so.  If
*    you do not wish to do so, delete this exception statement from your
*    version.
*
*/

#pragma once

class IWorld;
class InfoString;
class IClient: virtual public ISystemModule {
public:
	virtual ~IClient() {}

	virtual bool Connect(INetSocket *socket, NetAddress *adr, char *userinfo) = 0;
	virtual void Send(unsigned char *data, int length, bool isReliable) = 0;
	virtual void Disconnect(const char *reason = nullptr) = 0;
	virtual void Reconnect() = 0;
	virtual void SetWorld(IWorld *world) = 0;
	virtual int GetClientType() = 0;
	virtual char *GetClientName() = 0;
	virtual InfoString *GetUserInfo() = 0;
	virtual NetAddress *GetAddress() = 0;
	virtual bool IsActive() = 0;
	virtual bool IsHearingVoices() = 0;
	virtual bool HasChatEnabled() = 0;

#ifdef HLTV_FIXES
	virtual void SetUpdateRate(int updaterate) = 0;
	virtual void SetRate(int rate) = 0;
#endif // HLTV_FIXES
};

#define CLIENT_INTERFACE_VERSION "client001"
