project(simple-utest-test)
set(test_include_dirs ${CMAKE_SOURCE_DIR}/header ${CMAKE_SOURCE_DIR}/test)

set(tests custom-struct-assert.c custom-struct.c test-something.c
          test-something-more.c)

add_executable(test-simple-utest ${tests})
target_link_libraries(test-simple-utest simple-utest)
add_custom_command(
  TARGET test-simple-utest
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:test-simple-utest>"
          "${CMAKE_SOURCE_DIR}/$<TARGET_FILE_NAME:test-simple-utest>"
  COMMENT "Place test executable in project root")
