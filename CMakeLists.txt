cmake_minimum_required(VERSION 3.2)
project(day1 VERSION 0.1.0 LANGUAGES C CXX)

if(UNIX)
 
	message("current platform: Linux ")
    add_executable(day1 day1/src/day1.cpp)
    target_link_libraries(day1 ${CURSES_LIBRARIES})
    set(CPACK_PROJECT_NAME ${PROJECT_NAME})
    set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
    include(CPack)
 
elseif(WIN32)
	message(" Windows ")
    add_executable(win_day1 win32/day1.cc)
    message("current platform: Windows ")
else()
 
	message("current platform: unkonw ")
 
endif()
