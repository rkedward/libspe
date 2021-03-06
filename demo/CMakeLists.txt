# This file is part of libspe, a C++ library to interface with spe files.
# Copyright (c) 2012 Karthik Periagaram <karthik.periagaram@gmail.com>
#
# libspe is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# libspe is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with libspe.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 2.8)

project(demo)

set(CMAKE_CXX_FLAGS "-g -O2 -Wall")

include_directories(..)
include_directories(../utils)
include_directories(/usr/include/eigen2)
include_directories(../eigen)

add_subdirectory(.. ${CMAKE_BINARY_DIR}/spe)
add_subdirectory(../utils ${CMAKE_BINARY_DIR}/spe/utils)
add_subdirectory(../eigen ${CMAKE_BINARY_DIR}/spe/eigen)

add_executable(demo demo.cpp)

target_link_libraries(demo spe)
target_link_libraries(demo speutils)
target_link_libraries(demo speutils-eigen)
