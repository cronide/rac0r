################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/track/Track.cpp \
../src/track/TrackDrawable.cpp \
../src/track/TrackFileManager.cpp \
../src/track/TrackLoader.cpp 

OBJS += \
./src/track/Track.o \
./src/track/TrackDrawable.o \
./src/track/TrackFileManager.o \
./src/track/TrackLoader.o 

CPP_DEPS += \
./src/track/Track.d \
./src/track/TrackDrawable.d \
./src/track/TrackFileManager.d \
./src/track/TrackLoader.d 


# Each subdirectory must supply rules for building sources it contributes
src/track/%.o: ../src/track/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -I/home/david/code/cpp/libs/SFML-2.0/include -I"/home/david/repos/rac0r/eclipse_linux" -O0 -g3 -pedantic -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


