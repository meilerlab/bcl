CMAKE_MINIMUM_REQUIRED( VERSION 2.8.8)

SET( LIBRARY_NAME bclexamplenmr)
SET( LIBRARY_OBJECTS ${LIBRARY_NAME}-objects)
PROJECT( lib${LIBRARY_NAME})

SET(
  LIBRARY_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/example_nmr.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/example_nmr_rdc_container.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/example_nmr_residual_dipolar_coupling_least_square_deviation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/example_nmr_rosetta_noe_handler.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/example_nmr_rosetta_rdc_handler.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/example_nmr_signal.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/example_nmr_signal_1d.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/example_nmr_spectrum.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/example_nmr_star_noe_handler.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/example_nmr_star_rdc_handler.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/example_nmr_star_tag_categories.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/example_nmr_star_tag_category_data.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/example_nmr_star_tag_data.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/example_nmr_star_tags.cpp
)
MACRO_CHECK_CMAKE_DIRECTORY_LIST( ${CMAKE_CURRENT_SOURCE_DIR} "${LIBRARY_SOURCES}")

ADD_LIBRARY( ${LIBRARY_OBJECTS} OBJECT ${LIBRARY_SOURCES})

IF( LINK_NAMESPACE_ARCHIVES)
  ADD_LIBRARY( ${LIBRARY_NAME} STATIC $<TARGET_OBJECTS:${LIBRARY_OBJECTS}>)
ENDIF()

SET( SUBDIRECTORY_LIBRARY_NAME ${LIBRARY_NAME} PARENT_SCOPE)
SET( SUBDIRECTORY_LIBRARY_OBJECTS ${LIBRARY_OBJECTS} PARENT_SCOPE)
