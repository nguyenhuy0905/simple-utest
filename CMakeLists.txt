cmake_minimum_required(VERSION 3.21)
project(
  simple-utest
  LANGUAGES C
  VERSION 0.5)

# standards
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(includes ${CMAKE_CURRENT_SOURCE_DIR}/simple-utest.h)

# compilation options
set(is_gcc_like "$<COMPILE_LANG_AND_ID:C,ARMClang,AppleClang,Clang,GNU,LCC>")
set(is_mvsc_like "$<COMPILE_LANG_AND_ID:C,MSVC>")

option(TEST_SIMPLE_UTEST "Test this thing" OFF)

add_compile_options("$<${is_gcc_like}:-pedantic;-Wall;-Wextra;-Wformat=2>"
                    "$<${is_mvsc_like}:-W3>")
add_subdirectory(src)
if(TEST_SIMPLE_UTEST)
  add_subdirectory(test)
endif()

install(
  EXPORT SimpleUtestTargets
  FILE SimpleUtestTargets.cmake
  DESTINATION ${PROJECT_SOURCE_DIR}/lib/cmake/simple-utest)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)
configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/SimpleUtestConfigs.cmake"
  INSTALL_DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake/simple-utest"
  NO_SET_AND_CHECK_MACRO NO_CHECK_REQUIRED_COMPONENTS_MACRO)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/SimpleUtestConfigsVersion.cmake"
  VERSION "${simple-utest_VERSION_MAJOR}.${simple-utest_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/SimpleUtestConfigs.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/SimpleUtestConfigsVersion.cmake
        DESTINATION ${PROJECT_SOURCE_DIR}/lib/cmake/simple-utest)
