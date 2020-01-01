#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../SRC/Rover.hpp"
#include "../SRC/RoverData.hpp"
#include "../SRC/MovingRover.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>
using namespace std;
using namespace testing;

TEST(SettingRoverTest, start){
		Rover rover;
		EXPECT_THAT(rover.get_orientation(), Eq('N'));
		EXPECT_THAT(rover.get_x(), Eq(0));
		EXPECT_THAT(rover.get_y(), Eq(0));
}

TEST(SettingRoverVariabls, settingVariables){
		Rover rover;
		rover.set_orientation('S');
		rover.set_x(5);
		rover.set_y(15);
		EXPECT_THAT(rover.get_orientation(), Eq('S'));
		EXPECT_THAT(rover.get_x(), Eq(5));
		EXPECT_THAT(rover.get_y(), Eq(15));
}


TEST(RoverDrivingTest, MovingForwardN){
		std::unique_ptr<Rover> rover = std::make_unique<MovingRover>(1,2,'N'); 
		rover->move_forward();
		EXPECT_THAT(rover->get_y(), Eq(3));
}

TEST(RoverDrivingTest, MovingForwardS){
		std::unique_ptr<Rover> rover = std::make_unique<MovingRover>(1,2,'S'); 
		rover->move_forward();
		EXPECT_THAT(rover->get_y(), Eq(1));
}

TEST(RoverDrivingTest, MovingLeft){
		std::unique_ptr<Rover> rover = std::make_unique<MovingRover>(1,2,'S'); 
		rover->move_left();
		EXPECT_THAT(rover->get_orientation(), Eq('E'));
}

TEST(RoverDrivingTest, MovingRight){
		std::unique_ptr<Rover> rover = std::make_unique<MovingRover>(1,2,'S'); 
		rover->move_right();
		EXPECT_THAT(rover->get_orientation(), Eq('W'));
}

int main(int argc, char **argv){
	testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

