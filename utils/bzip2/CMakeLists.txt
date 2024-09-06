set(PROJECT_NAME bzip2)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "bzlib_private.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "blocksort.c"
    "bzlib.c"
    "compress.c"
    "crctable.c"
    "decompress.c"
    "huffman.c"
    "randtable.c"
)
source_group("Source Files" FILES ${Source_Files})

set(VPC_Scripts
    "../../vpc_scripts/platform_dirs.vpc"
    "../../vpc_scripts/source_base.vpc"
    "../../vpc_scripts/source_lib_base.vpc"
    "../../vpc_scripts/source_lib_win32_base.vpc"
    "../../vpc_scripts/source_lib_win32_debug.vpc"
    "../../vpc_scripts/source_lib_win32_release.vpc"
    "../../vpc_scripts/source_video_base.vpc"
    "../../vpc_scripts/source_win32_base.vpc"
    "../../vpc_scripts/version.vpc"
    "bzip2.vpc"
)
source_group("VPC Scripts" FILES ${VPC_Scripts})

set(ALL_FILES
    ${Header_Files}
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
