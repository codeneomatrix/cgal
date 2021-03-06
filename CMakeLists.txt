# Top level CMakeLists.txt for CGAL-branchbuild
message( "== CMake setup ==" )
project(CGAL CXX C)

# Minimal version of CMake:
cmake_minimum_required(VERSION 2.8.11)

# option for branch build

option( CGAL_BRANCH_BUILD "Create CGAL from branch" ON)
mark_as_advanced( CGAL_BRANCH_BUILD )

include(${CMAKE_SOURCE_DIR}/Installation/cmake/modules/CGAL_SCM.cmake)

# add option for duplicate file detection
option( CGAL_REPORT_DUPLICATE_FILES "Switch on to start (naive) detection of duplicate source- and headerfiles in packages" OFF)

message( "== CMake setup (DONE) ==\n" )
# and finally start actual build
add_subdirectory( Installation )

# for releases, where dont_submit is honored
if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Documentation")
  option(BUILD_DOC "Build the doxygen documentation" OFF)
  if (BUILD_DOC)
    add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/Documentation" )
  endif(BUILD_DOC)
endif()
