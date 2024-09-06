set(PROJECT_NAME hlds)

################################################################################
# Source groups
################################################################################
set(Resources
    "icon.ico"
    "resource.h"
)
source_group("Resources" FILES ${Resources})

set(Source_Files
    "../common/commandline.cpp"
    "../public/tier0/pointeroverride.asm"
    "conproc.cpp"
    "conproc.h"
    "dedicated.h"
    "dedicated_exports.cpp"
    "precompiled.h"
    "public_amalgamation.cpp"
    "sys_ded.cpp"
    "sys_ded.h"
    "sys_window.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(Source_Files__common
    "../common/minidump.cpp"
    "../common/minidump.h"
    "../common/ObjectList.cpp"
    "../common/ObjectList.h"
    "../common/SteamAppStartUp.cpp"
    "../common/SteamAppStartUp.h"
    "../common/textconsole.cpp"
    "../common/textconsole.h"
    "../common/TextConsoleWin32.cpp"
    "../common/TextConsoleWin32.h"
)
source_group("Source Files\\common" FILES ${Source_Files__common})

set(Source_Files__engine
    "../engine/mem.cpp"
)
source_group("Source Files\\engine" FILES ${Source_Files__engine})

set(Source_Files__vgui
    "vguihelpers.cpp"
    "vguihelpers.h"
)
source_group("Source Files\\vgui" FILES ${Source_Files__vgui})

set(VPC_Scripts
    "../vpc_scripts/loadaddress.vpc"
    "../vpc_scripts/platform_dirs.vpc"
    "../vpc_scripts/source_base.vpc"
    "../vpc_scripts/source_exe_base.vpc"
    "../vpc_scripts/source_exe_win_win32_base.vpc"
    "../vpc_scripts/source_exe_win_win32_debug.vpc"
    "../vpc_scripts/source_exe_win_win32_release.vpc"
    "../vpc_scripts/source_video_base.vpc"
    "../vpc_scripts/source_win32_base.vpc"
    "../vpc_scripts/version.vpc"
    "dedicated.vpc"
)
source_group("VPC Scripts" FILES ${VPC_Scripts})

set(ALL_FILES
    ${Resources}
    ${Source_Files}
    ${Source_Files__common}
    ${Source_Files__engine}
    ${Source_Files__vgui}
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
