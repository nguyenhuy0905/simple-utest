project(simple-utest-src)
set(src_include_dirs ${CMAKE_CURRENT_SOURCE_DIR}/header)

set(srcs assert.c entry.c log.c register.c)
add_library(simple-utest STATIC ${srcs})
target_include_directories(
  simple-utest PUBLIC $<BUILD_INTERFACE:${src_include_dirs}>
                      $<INSTALL_INTERFACE:header>)

# export configs
install(
  TARGETS simple-utest
  EXPORT SimpleUtestTargets
  DESTINATION lib)

install(FILES header/.deps.h header/assert.h header/assert.module.h
              header/entry.h header/log.h header/register.h
        DESTINATION lib/header)
