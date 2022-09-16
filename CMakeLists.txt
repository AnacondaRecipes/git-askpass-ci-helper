cmake_minimum_required(VERSION 3.10)

project(git-askpass-ci-helper)

add_executable(git-askpass-ci-helper git-askpass-ci-helper.c)

install(TARGETS git-askpass-ci-helper
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}")