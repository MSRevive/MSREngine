set(PROJECT_NAME filesystem)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "BaseFileSystem.h"
    "filesystem_helpers.h"
    "FileSystem_Stdio.h"
    "precompiled.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Misc
    "../public/tier0/pointeroverride.asm"
)
source_group("Misc" FILES ${Misc})

set(Source_Files
    "BaseFileSystem.cpp"
    "filesystem_helpers.cpp"
    "FileSystem_Stdio.cpp"
    "public_amalgamation.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(VPC_Scripts
    "../vpc_scripts/loadaddress.vpc"
    "../vpc_scripts/platform_dirs.vpc"
    "../vpc_scripts/source_base.vpc"
    "../vpc_scripts/source_dll_base.vpc"
    "../vpc_scripts/source_dll_win32_base.vpc"
    "../vpc_scripts/source_dll_win32_debug.vpc"
    "../vpc_scripts/source_dll_win32_release.vpc"
    "../vpc_scripts/source_video_base.vpc"
    "../vpc_scripts/source_win32_base.vpc"
    "../vpc_scripts/version.vpc"
    "filesystem.vpc"
)
source_group("VPC Scripts" FILES ${VPC_Scripts})

set(ALL_FILES
    ${Header_Files}
    ${Misc}
    ${Source_Files}
    ${VPC_Scripts}
)

################################################################################
# Target
################################################################################

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
################################################################################
# Compile definitions
################################################################################

################################################################################
# Compile and link options
################################################################################
