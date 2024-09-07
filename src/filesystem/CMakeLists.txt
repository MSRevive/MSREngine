set_common_properties(filesystem)

target_link_libraries(filesystem PRIVATE
	$<$<PLATFORM_ID:Windows>:psapi>
)

# Include directories
target_include_directories(filesystem PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	${BASEDIR}/src/common
	${BASEDIR}/src/engine
	${BASEDIR}/src/public
	${BASEDIR}/src/public/rehlds
)

if (UNIX)
	target_compiler_definitions(filesystem PRIVATE
		_stricmp=strcasecmp
		_strnicmp=strncasecmp
		_strdup=strdup
		_vsnprintf=vsnprintf
	)
endif(UNIX)

################################################################################
# Source groups
################################################################################
set(Misc
	"../public/tier0/pointeroverride.asm"
)
source_group("Misc" FILES ${Misc})

set(Source_Files
	"BaseFileSystem.cpp"
	"filesystem_helpers.cpp"
	"FileSystem_Stdio.cpp"
	"public_amalgamation.cpp"
	$<$<PLATFORM_ID:Linux>:"linux_support.cpp">
	$<$<PLATFORM_ID:Linux>:"pathmatch.cpp">
)
source_group("Source Files" FILES ${Source_Files})

set(Header_Files
	"BaseFileSystem.h"
	"filesystem_helpers.h"
	"FileSystem_Stdio.h"
	"precompiled.h"
	$<$<PLATFORM_ID:Linux>:"linux_support.h">
)
source_group("Header Files" FILES ${Header_Files})

set(ALL_FILES
	${Misc}
	${Source_Files}
	${Header_Files}
)

target_sources(filesystem PRIVATE ${ALL_FILES})