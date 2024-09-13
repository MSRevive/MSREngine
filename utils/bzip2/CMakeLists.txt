add_library(bzip2 STATIC)

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

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

target_sources(bzip2 PRIVATE ${ALL_FILES})