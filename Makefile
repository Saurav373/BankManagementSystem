CXX = g++
CXXFLAGS = -std=c++17 -Wall -Ilibs/Bcrypt.cpp/include

SRCS = main.cpp userAuth.cpp bankSystem.cpp helper.cpp
BCRYPT_SRCS = $(wildcard libs/Bcrypt.cpp/src/*.cpp)

OUT = BankManagementSystem

all:
	$(CXX) $(CXXFLAGS) $(SRCS) $(BCRYPT_SRCS) -o $(OUT)

clean:
	del $(OUT).exe
