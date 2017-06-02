add_definitions(-DFEATURE_PAL)

include_directories(${CLR_DIR}/src/dlls/dbgshim/)

add_executable_clr(netcore-debugger netcore-debugger.cpp)

target_link_libraries(netcore-debugger dbgshim ${DBGSHIM_LIBRARIES})

# add the install targets
install_clr(netcore-debugger)
