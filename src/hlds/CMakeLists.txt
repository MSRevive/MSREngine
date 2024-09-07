set_common_properties(hlds)

# Disable C++ exceptions, which is enabled by default with CMake?
# if (MSVC)
# 	target_compile_options(hlds PUBLIC /EHs-c-)
# else()
# 	target_compile_options(hlds PUBLIC -fno-exceptions)
# endif()

target_link_libraries(hlds PRIVATE
	$<$<PLATFORM_ID:Windows>:ws2_32>
	$<$<PLATFORM_ID:Windows>:winmm>
)

# Include directories
target_include_directories(hlds PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	${BASEDIR}/src/common
	${BASEDIR}/src/engine
	${BASEDIR}/src/public
	${BASEDIR}/src/public/rehlds
)

target_compile_definitions(hlds PRIVATE
	LAUNCHER_FIXES
	DEDICATED
)

if (UNIX)
	set_target_properties(hlds PROPERTIES OUTPUT_NAME "hlds_linux")

	target_compiler_definitions(hlds PRIVATE
		_stricmp=strcasecmp
		_strnicmp=strncasecmp
		_strdup=strdup
		_vsnprintf=vsnprintf
	)
endif(UNIX)

################################################################################
# Source groups
################################################################################
set(Resources
	$<$<PLATFORM_ID:Windows>:"icon.ico">
	$<$<PLATFORM_ID:Windows>:"resource.h">
	$<$<PLATFORM_ID:Windows>:"hlds.rc">
)
source_group("Resources" FILES ${Resources})

set(Misc
	"../public/tier0/pointeroverride.asm"
)
source_group("Misc" FILES ${Misc})

set(Source_Files
	"../common/commandline.cpp"
	"hlds.h"
	"hlds_exports.cpp"
	"precompiled.h"
	"public_amalgamation.cpp"
	"sys_ded.cpp"
	"sys_ded.h"
	$<$<PLATFORM_ID:Windows>:"sys_window.cpp">
	$<$<PLATFORM_ID:Windows>:"conproc.cpp">
	$<$<PLATFORM_ID:Windows>:"conproc.h">
	$<$<PLATFORM_ID:Linux>:"sys_linux.cpp">
	$<$<PLATFORM_ID:Linux>:"dbg.cpp">
)
source_group("Source Files" FILES ${Source_Files})

set(Common
	"../common/minidump.cpp"
	"../common/minidump.h"
	"../common/ObjectList.cpp"
	"../common/ObjectList.h"
	"../common/SteamAppStartUp.cpp"
	"../common/SteamAppStartUp.h"
	"../common/textconsole.cpp"
	"../common/textconsole.h"
	$<$<PLATFORM_ID:Windows>:"../common/TextConsoleWin32.cpp">
	$<$<PLATFORM_ID:Windows>:"../common/TextConsoleWin32.h">
	$<$<PLATFORM_ID:Linux>:"../common/TextConsoleUnix.cpp">
	$<$<PLATFORM_ID:Linux>:"../common/TextConsoleUnix.h">
)
source_group("Common" FILES ${Common})

set(Engine
	"../engine/mem.cpp"
)
source_group("Engine" FILES ${Engine})

set(VGUI
	"vguihelpers.cpp"
	"vguihelpers.h"
)
source_group("VGUI" FILES ${VGUI})

set(ALL_FILES
	${Resources}
	${Misc}
	${Source_Files}
	${Common}
	${Engine}
	${VGUI}
)

target_sources(hlds PRIVATE ${ALL_FILES})

add_executable(hlds ${ALL_FILES})