if (NOT BUILD_CIRCLE_LOADER)
    return()
endif ()

set(CIRCLE_LOADER_SOURCES src/circle_loader.cc)

add_library(circle_loader SHARED ${CIRCLE_LOADER_SOURCES})

target_include_directories(circle_loader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(circle_loader PUBLIC onert_core)
target_link_libraries(circle_loader PRIVATE base_loader nnfw_common nnfw_coverage)
target_link_libraries(circle_loader PRIVATE circle_schema)

install(TARGETS circle_loader DESTINATION lib)
