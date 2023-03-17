set(TARGET_NAME pathreg_test)

add_executable(${TARGET_NAME} src/main.cpp)


set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET_NAME}>)

target_link_libraries(${TARGET_NAME} PRIVATE util_vr)