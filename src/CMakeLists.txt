project(simple-utest-src)
set(src_include_dirs ${CMAKE_CURRENT_SOURCE_DIR}/header)

set(srcs assert.c entry.c log.c register.c)
add_library(simple-utest STATIC ${srcs})
target_include_directories(
  simple-utest
  PUBLIC $<BUILD_INTERFACE:${src_include_dirs}>
         $<INSTALL_INTERFACE:${PROJECT_SOURCE_DIR}/header>
         $<INSTALL_INTERFACE:${CMAKE_SOURCE_DIR}>)

# export configs
install(
  TARGETS simple-utest
  EXPORT SimpleUtestTargets
  DESTINATION lib)
