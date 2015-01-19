INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_GEN2 gen2)

FIND_PATH(
    GEN2_INCLUDE_DIRS
    NAMES gen2/api.h
    HINTS $ENV{GEN2_DIR}/include
        ${PC_GEN2_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GEN2_LIBRARIES
    NAMES gnuradio-gen2
    HINTS $ENV{GEN2_DIR}/lib
        ${PC_GEN2_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GEN2 DEFAULT_MSG GEN2_LIBRARIES GEN2_INCLUDE_DIRS)
MARK_AS_ADVANCED(GEN2_LIBRARIES GEN2_INCLUDE_DIRS)

