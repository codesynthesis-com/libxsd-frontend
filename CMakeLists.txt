cmake_minimum_required(VERSION 3.16)

project(libxsd-frontend
    VERSION 0.0.1
    LANGUAGES CXX
)

include(GNUInstallDirs)

# ------------------------------------------------------------
# Sources
# ------------------------------------------------------------

file(GLOB_RECURSE LIBXSD_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/libxsd-frontend/*.cxx"
)

if(NOT LIBXSD_SOURCES)
    message(FATAL_ERROR "No xsd-frontend .cxx source files found")
endif()

add_library(xsd-frontend SHARED ${LIBXSD_SOURCES})

add_library(libxsd-frontend::xsd-frontend ALIAS xsd-frontend)

set_target_properties(xsd-frontend PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    OUTPUT_NAME xsd-frontend
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(xsd-frontend
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# ------------------------------------------------------------
# libcutl dependency
# ------------------------------------------------------------
find_package(libcutl REQUIRED)
find_package(XercesC REQUIRED)
target_link_libraries(xsd-frontend PUBLIC libcutl::cutl XercesC::XercesC)

# ------------------------------------------------------------
# Install library
# ------------------------------------------------------------

install(TARGETS xsd-frontend
    EXPORT libxsd-frontendTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# ------------------------------------------------------------
# Install headers
# ------------------------------------------------------------

file(GLOB_RECURSE LIBXSD_HEADERS CONFIGURE_DEPENDS
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/libxsd-frontend/*.hxx"
    "${CMAKE_CURRENT_SOURCE_DIR}/libxsd-frontend/*.ixx"
    "${CMAKE_CURRENT_SOURCE_DIR}/libxsd-frontend/*.txx"
)

foreach(header IN LISTS LIBXSD_HEADERS)
    get_filename_component(header_dir "${header}" DIRECTORY)

    install(
        FILES "${CMAKE_CURRENT_SOURCE_DIR}/${header}"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${header_dir}"
    )
endforeach()

# ------------------------------------------------------------
# CMake package
# ------------------------------------------------------------

set(XSD_FRONTEND_CMAKE_INSTALL_DIR
    "${CMAKE_INSTALL_LIBDIR}/cmake/libxsd-frontend"
)

install(
    EXPORT libxsd-frontendTargets
    FILE libxsd-frontendTargets.cmake
    NAMESPACE libxsd-frontend::
    DESTINATION "${XSD_FRONTEND_CMAKE_INSTALL_DIR}"
)

file(GENERATE
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/libxsd-frontendConfig.cmake"
    CONTENT
"include(\"\${CMAKE_CURRENT_LIST_DIR}/libxsd-frontendTargets.cmake\")
"
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/libxsd-frontendConfig.cmake"
    DESTINATION "${XSD_FRONTEND_CMAKE_INSTALL_DIR}"
)

# ------------------------------------------------------------
# pkg-config
# ------------------------------------------------------------

set(XSD_FRONTEND_PKGCONFIG_INSTALL_DIR
    "${CMAKE_INSTALL_LIBDIR}/pkgconfig"
)

file(GENERATE
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/libxsd-frontend.pc"
    CONTENT
"prefix=${CMAKE_INSTALL_PREFIX}
exec_prefix=\${prefix}
libdir=\${exec_prefix}/${CMAKE_INSTALL_LIBDIR}
includedir=\${prefix}/${CMAKE_INSTALL_INCLUDEDIR}

Name: libxsd-frontend
Description: XSD frontend library
Version: ${PROJECT_VERSION}
Libs: -L\${libdir} -lxsd-frontend
Cflags: -I\${includedir}
"
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/libxsd-frontend.pc"
    DESTINATION "${XSD_FRONTEND_PKGCONFIG_INSTALL_DIR}"
)
