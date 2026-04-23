cmake_minimum_required(VERSION 3.10)

project(chapter16)

#add_dependencies()


function(configure_fltk_executable TARGET_NAME)
  target_include_directories(${TARGET_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/fltk-1.3.5
        ${CMAKE_BINARY_DIR}/fltk-1.3.5
        ${CMAKE_SOURCE_DIR}/GUI
        ../GUI
        ./
    )
    target_link_directories(${TARGET_NAME} PUBLIC ${CMAKE_BINARY_DIR}/fltk-1.3.5/lib/Debug)
    target_link_libraries(${TARGET_NAME} PUBLIC bookgui fltk fltk_images)
    if (APPLE)
        target_link_libraries(${TARGET_NAME} PUBLIC "-framework Cocoa")
    endif()
endfunction()

add_executable(chapter.16.5 chapter.16.5.cpp)
configure_fltk_executable(chapter.16.5)
add_executable(chapter.16.7 chapter.16.7.cpp)
configure_fltk_executable(chapter.16.7)


add_executable(assignment3 assignment3.cpp)
configure_fltk_executable(assignment3)