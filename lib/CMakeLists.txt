# Copyright 2011,2012 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

########################################################################
# Setup library
########################################################################
include(GrPlatform) #define LIB_SUFFIX

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})

list(APPEND gen2_sources
	center_ff.cc
	clock_recovery_zc_ff.cc
	command_gate_cc.cc
	global_vars.cc
	reader_decoder.cc
	reader_f.cc
	tag_decoder_f.cc
)

set(gen2_sources "${gen2_sources}" PARENT_SCOPE)
if(NOT gen2_sources)
	MESSAGE(STATUS "No C++ sources... skipping lib/")
	return()
endif(NOT gen2_sources)

add_library(gnuradio-gen2 SHARED ${gen2_sources})
target_link_libraries(gnuradio-gen2 ${Boost_LIBRARIES} ${GNURADIO_ALL_LIBRARIES})
set_target_properties(gnuradio-gen2 PROPERTIES DEFINE_SYMBOL "gnuradio_gen2_EXPORTS")

if(APPLE)
    set_target_properties(gnuradio-gen2 PROPERTIES
        INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib"
    )
endif(APPLE)

########################################################################
# Install built library files
########################################################################
install(TARGETS gnuradio-gen2
    LIBRARY DESTINATION lib${LIB_SUFFIX} # .so/.dylib file
    ARCHIVE DESTINATION lib${LIB_SUFFIX} # .lib file
    RUNTIME DESTINATION bin              # .dll file
)
