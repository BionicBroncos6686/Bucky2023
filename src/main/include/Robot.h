// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Timer.h>
#include <frc/motorcontrol/PWMVictorSPX.h>
#include <frc/XboxController.h>;

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
 // Why so many motors? Good question.
  frc::PWMVictorSPX leftMotor1{0};
  frc::PWMVictorSPX leftMotor2{1};
  frc::PWMVictorSPX rightMotor1{2};
  frc::PWMVictorSPX rightMotor2{3};

  // Both motor pairs
  frc::DifferentialDrive motorPair1{m_leftMotor1, m_rightMotor1};
  frc::DifferentialDrive motorPair2{m_leftMotor2, m_rightMotor2};

  frc::Timer timer{};
  frc::XboxController controller{0};

  bool controllerConnected{};
  bool killed{};
  double speed{}; //directional speed
  double rspeed{}; //rotational speed
};
