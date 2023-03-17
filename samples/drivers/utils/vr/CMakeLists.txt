add_library(util_vr STATIC vrpathreg.h vrpathreg.cpp)
target_include_directories(util_vr PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(CORE_FILES
        ../../../../src/jsoncpp.cpp
)

set(VRCORE_FILES
        ../../../../src/vrcore/dirtools_public.cpp
        ../../../../src/vrcore/envvartools_public.cpp
        ../../../../src/vrcore/pathtools_public.cpp
        ../../../../src/vrcore/sharedlibtools_public.cpp
        ../../../../src/vrcore/hmderrors_public.cpp
        ../../../../src/vrcore/vrpathregistry_public.cpp
        ../../../../src/vrcore/strtools_public.cpp
)

add_compile_definitions(VRCORE_NO_PLATFORM)
add_library(vrcore STATIC ${VRCORE_FILES} ${CORE_FILES})
target_include_directories(vrcore PUBLIC ../../../../src ${OPENVR_INCLUDE_DIR})
target_link_libraries(vrcore PRIVATE ${OPENVR_LIBRARIES})

target_link_libraries(util_vr PRIVATE ${OPENVR_LIBRARIES} vrcore)
target_include_directories(util_vr PRIVATE ${OPENVR_INCLUDE_DIR})