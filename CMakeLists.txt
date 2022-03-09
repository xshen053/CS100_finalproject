CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(task_scheduler
        main.cpp

)



ADD_EXECUTABLE(test
	Tests/unit_test.cpp
	
)

TARGET_LINK_LIBRARIES(test gtest)
