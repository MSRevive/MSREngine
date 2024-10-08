if(WIN32)
	add_executable(dedicated WIN32)
else()
	add_executable(dedicated)
endif()

################################################################################
# Target Properties
################################################################################
# if(MSVC)
# 	target_compile_options(dedicated PUBLIC /arch:SSE2)
# else()
# 	target_compile_options(dedicated PUBLIC -msse2)
# endif()

set_common_properties(dedicated)

target_link_libraries(dedicated PRIVATE
	$<$<PLATFORM_ID:Windows>:ws2_32>
	$<$<PLATFORM_ID:Windows>:winmm>
	$<$<PLATFORM_ID:Linux>:dl>
)

# Include directories
target_include_directories(dedicated PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	${BASEDIR}/src
	${BASEDIR}/src/common
	${BASEDIR}/src/engine
	${BASEDIR}/src/public
	${BASEDIR}/src/public/rehlds
)

target_compile_definitions(dedicated PRIVATE
	LAUNCHER_FIXES
	DEDICATED
	_CONSOLE
)

if (UNIX)
	set_target_properties(dedicated PROPERTIES OUTPUT_NAME "hlds_linux")
endif(UNIX)

################################################################################
# Source groups
################################################################################
set(Resources
	$<$<PLATFORM_ID:Windows>:${CMAKE_CURRENT_SOURCE_DIR}/icon.ico>
	$<$<PLATFORM_ID:Windows>:${CMAKE_CURRENT_SOURCE_DIR}/resource.h>
	$<$<PLATFORM_ID:Windows>:${CMAKE_CURRENT_SOURCE_DIR}/dedicated.rc>
)
source_group("Resources" FILES ${Resources})

set(Misc
	"../public/tier0/pointeroverride.asm"
)
source_group("Misc" FILES ${Misc})

set(Source_Files
	"../common/commandline.cpp"
	"dedicated.h"
	"dedicated_exports.cpp"
	"precompiled.h"
	"public_amalgamation.cpp"
	"sys_ded.cpp"
	"sys_ded.h"
	$<$<PLATFORM_ID:Windows>:${CMAKE_CURRENT_SOURCE_DIR}/sys_window.cpp>
	$<$<PLATFORM_ID:Windows>:${CMAKE_CURRENT_SOURCE_DIR}/conproc.cpp>
	$<$<PLATFORM_ID:Windows>:${CMAKE_CURRENT_SOURCE_DIR}/conproc.h>
	$<$<PLATFORM_ID:Linux>:${CMAKE_CURRENT_SOURCE_DIR}/sys_linux.cpp>
	$<$<PLATFORM_ID:Linux>:${CMAKE_CURRENT_SOURCE_DIR}/dbg.cpp>
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
	$<$<PLATFORM_ID:Windows>:${BASEDIR}/src/common/TextConsoleWin32.cpp>
	$<$<PLATFORM_ID:Windows>:${BASEDIR}/src/common/TextConsoleWin32.h>
	$<$<PLATFORM_ID:Linux>:${BASEDIR}/src/common/TextConsoleUnix.cpp>
	$<$<PLATFORM_ID:Linux>:${BASEDIR}/src/common/TextConsoleUnix.h>
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

target_sources(dedicated PRIVATE ${ALL_FILES})