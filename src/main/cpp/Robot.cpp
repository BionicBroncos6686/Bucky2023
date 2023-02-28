// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>
#include <iostream>

void Robot::RobotInit()
{
  rightMotor1.SetInverted(true);
  rightMotor2.SetInverted(true);

  timer.Start();
  killed = false;
}

void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit()
{
}

void Robot::AutonomousPeriodic()
{
}

void Robot::TeleopInit()
{
}

void Robot::TeleopPeriodic()
{
  if (!controller.IsConnected() && controllerConnected == true)
  {
    controllerConnected = false;
    std::cout << "Controller is disconnected, " << std::endl;
  }

  if (controller.GetYButton()) //killswitch, toggled with y
  {
    if (!killed)
    {
      killed = true;
      speed = 0;
      rspeed = 0;
      return;
    }
    else
    {
      killed = false;
    }
  }

  if (!controllerConnected || killed)
  {
    return;
  }

  if (controller.GetLeftY() <= -0.5)
  { // if analog stick is up, with a 0.5 deadzone
    speed = 1;
  }
  else if (controller.GetLeftY() >= 0.5)
  { // if analog stick is down, with a 0.5 deadzone
    speed = -1;
  }
  else
  {
    speed = 0;
  }

  if (controller.GetLeftX() >= 0.5)
  {
    rspeed = 0.8;
  }
  else if (controller.GetLeftX() <= -0.5)
  {
    rspeed = -0.8;
  }
  else
  {
    rspeed = 0;
  }

  motorPair1.ArcadeDrive(speed, rspeed);
  motorPair2.ArcadeDrive(speed, rspeed);
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif
