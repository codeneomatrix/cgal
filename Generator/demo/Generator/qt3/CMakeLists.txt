# This is the CMake script for compiling a CGAL application.

project( generator ) 

CMAKE_MINIMUM_REQUIRED(VERSION 2.6.2)

find_package(CGAL COMPONENTS Qt3 )
include( ${CGAL_USE_FILE} )

find_package(Qt3-patched)
# FindQt3-patched.cmake is FindQt3.cmake patched by CGAL developers, so
# that it can be used together with Qt5: all its variables are prefixed
# by "QT3_" instead of "QT_".

if ( CGAL_FOUND AND CGAL_Qt3_FOUND AND QT3_FOUND )

  # use the Qt MOC preprocessor on classes that derives from QObject
  include( Qt3Macros-patched )
  qt3_generate_moc("${CMAKE_CURRENT_SOURCE_DIR}/generator.cpp" generator.moc )


  # The executable itself.
  add_executable  ( generator 
    generator.cpp generator.moc
    )

  add_to_cached_list( CGAL_EXECUTABLE_TARGETS generator )

  target_link_libraries( generator  ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES} )

else()

  message(STATUS "NOTICE: This demo requires CGAL and Qt3, and will not be compiled.")

endif()
