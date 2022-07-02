#pragma once

#include "appversion.h"

#include "osconfig.h"

#include "archtypes.h"
#include "asmlib.h"
#include "sse_mathfun.h"
#include "mathlib.h"

#include "sys_shared.h"
#include "crc32c.h"
#include "static_map.h"

#include "ed_strpool.h"
#include "strtools.h"

// Valve libs stuff
#include "tier0/platform.h"
#include "tier0/dbg.h"

#include "engine.h"
#include "platform.h"

#include "interface.h"
#include "iregistry.h"

#include "utlbuffer.h"
#include "utlrbtree.h"

// Testsuite
#include "osconfig.h"
#include "memory.h"
#include "rehlds/platform.h"

#include "bzip2/bzlib.h"
#include "igame.h"
#include "sys_linuxwnd.h"

#include "iengine.h"
#include "hookchains_impl.h"
#include "rehlds_interfaces.h"
#include "rehlds_interfaces_impl.h"
#include "rehlds_api.h"
#include "rehlds_api_impl.h"
#include "FlightRecorderImpl.h"
#include "flight_recorder.h"
#include "rehlds_security.h"

#include "dlls/cdll_dll.h"
#include "hltv.h"

const int TESTSUITE_PROTOCOL_VERSION_MINOR = 5;
const int TESTSUITE_PROTOCOL_VERSION_MAJOR = 0;
