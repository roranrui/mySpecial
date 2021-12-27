cmake_minimum_required(VERSION 3.20)
project(C___Computer_Room_Reversation_System)

set(CMAKE_CXX_STANDARD 11)

add_executable(Computer_Room_Reversation_System
        main.cpp
        Identity.h
        student.cpp student.h
        teacher.cpp teacher.h
        administor.cpp administor.h
        globalFile.h
        computerRoom.h
        orderFile.cpp orderFile.h)
