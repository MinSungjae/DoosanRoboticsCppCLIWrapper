/*    ========================================================================
	=               Doosan Robot API C++/CLI Class Wrapper                    =
	=                   Copyright (c) 2024 KAIST USRG.                        =
	=_______________________________________________________________________  =
	= Title             : Doosan Robot API C++/CLI Class Wrapper V1.0	      =
	= Author            : Min Sungjae<sungjae_min@kaist.ac.kr>				  =
	= Description       : -                                                   =
	======================================================================== */

	/*********************************************************************
	 * Software License Agreement (BSD License)
	 *
	 *  Copyright (c) 2024, KAIST USRG
	 *  All rights reserved.
	 *
	 *  Redistribution and use in source and binary forms, with or without
	 *  modification, are permitted provided that the following conditions
	 *  are met:
	 *
	 *   * Redistributions of source code must retain the above copyright
	 *     notice, this list of conditions and the following disclaimer.
	 *   * Redistributions in binary form must reproduce the above
	 *     copyright notice, this list of conditions and the following
	 *     disclaimer in the documentation and/or other materials provided
	 *     with the distribution.
	 *   * Neither the name of the Georgia Institute of Technology nor the names of
	 *     its contributors may be used to endorse or promote products derived
	 *     from this software without specific prior written permission.
	 *
	 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
	 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
	 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
	 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
	 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
	 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
	 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	 *  POSSIBILITY OF SUCH DAMAGE.
	 *********************************************************************/

#pragma once
#include "DRFL.h"
#include "DRFS.h"
#include "DRFC.h"
#include "DRFLEx.h"

#include <msclr/marshal_cppstd.h>

#include "DoosanRoboticsClassLibrary.h"
#include "DoosanRoboticsDataStructures.h"

using namespace DRAFramework;
using namespace DoosanRoboticsDataStructures;

public delegate void TOnMonitoringStateCBDelegate(ROBOT_STATE_WRAPPER);
public delegate void TOnMonitoringCtrlIOCBDelegate(MONITORING_CTRLIO_WRAPPER);
public delegate void TOnMonitoringCtrlIOExCBDelegate(MONITORING_CTRLIO_EX_WRAPPER);
public delegate void TOnMonitoringModbusCBDelegate(MONITORING_MODBUS_WRAPPER);
public delegate void TOnLogAlarmCBDelegate(LOG_ALARM_WRAPPER);
public delegate void TOnMonitoringAccessControlCBDelegate(MONITORING_ACCESS_CONTROL_WRAPPER);
public delegate void TOnHommingCompletedCBDelegate();
public delegate void TOnTpInitializingCompletedCBDelegate();
public delegate void TOnMasteringNeedCBDelegate();
public delegate void TOnProgramStoppedCBDelegate(PROGRAM_STOP_CAUSE_WRAPPER);
public delegate void TOnDisconnectedCBDelegate();
public delegate void TOnMonitoringRobotSystemCBDelegate();

namespace DoosanRoboticsClassLibrary {
	public ref class DoosanManagedWrapper
	{
	private:
		CDRFLEx* robot;
		System::String^ robot_ip_address_;
		unsigned int robot_port_;

	private:
		bool has_robot_control_ = false;

		static TOnMonitoringStateCBDelegate^ onMonitoringStateCBDelegate;
		static TOnMonitoringCtrlIOCBDelegate^ onMonitoringCtrlIOCBDelegate;
		static TOnMonitoringCtrlIOExCBDelegate^ onMonitoringCtrlIOExCBDelegate;
		static TOnMonitoringModbusCBDelegate^ onMonitoringModbusCBDelegate;
		static TOnLogAlarmCBDelegate^ onLogAlarmCBDelegate;
		static TOnMonitoringAccessControlCBDelegate^ onMonitoringAccessControlCBDelegate;
		static TOnHommingCompletedCBDelegate^ onHommingCompletedCBDelegate;
		static TOnTpInitializingCompletedCBDelegate^ onTpInitializingCompletedCBDelegate;
		static TOnMasteringNeedCBDelegate^ onMasteringNeedCBDelegate;
		static TOnProgramStoppedCBDelegate^ onProgramStoppedCBDelegate;
		static TOnDisconnectedCBDelegate^ onDisconnectedCBDelegate;
		static TOnMonitoringRobotSystemCBDelegate^ onMonitoringRobotSystemCBDelegate;

	public:
		void set_on_monitoring_state(TOnMonitoringStateCBDelegate^ managedCallback);
		void set_on_monitoring_ctrl_io(TOnMonitoringCtrlIOCBDelegate^ managedCallback);
		void set_on_monitoring_ctrl_io_ex(TOnMonitoringCtrlIOExCBDelegate^ managedCallback);
		void set_on_monitoring_modbus(TOnMonitoringModbusCBDelegate^ managedCallback);
		void set_on_log_alarm(TOnLogAlarmCBDelegate^ managedCallback);
		void set_on_monitoring_access_control(TOnMonitoringAccessControlCBDelegate^ pCallbackFunc);
		void set_on_homming_completed(TOnHommingCompletedCBDelegate^ managedCallback);
		void set_on_tp_initializing_completed(TOnTpInitializingCompletedCBDelegate^ managedCallback);
		void set_on_mastering_need(TOnMasteringNeedCBDelegate^ managedCallback);
		void set_on_program_stopped(TOnProgramStoppedCBDelegate^ managedCallback);
		void set_on_disconnected(TOnDisconnectedCBDelegate^ managedCallback);
		void set_on_monitoring_robot_system(TOnMonitoringRobotSystemCBDelegate^ managedCallback);

	public:
		DoosanManagedWrapper();
		~DoosanManagedWrapper();

		bool open_connection(System::String^ ipAddress, unsigned int port);
		void close_connection();

		bool get_system_version(SYSTEM_VERSION_WRAPPER^ managedVersion);
		System::String^ get_library_version();
		ROBOT_MODE_WRAPPER get_robot_mode();
		bool set_robot_mode(ROBOT_MODE_WRAPPER eMode);

		bool set_robot_control(ROBOT_CONTROL_WRAPPER eControl);

		bool set_robot_system(ROBOT_SYSTEM_WRAPPER eRobotSystem);

		DRL_PROGRAM_STATE_WRAPPER get_program_state();

		ROBOT_FORCE_WRAPPER get_external_torque();
		ROBOT_FORCE_WRAPPER get_tool_force(/*COORDINATE_SYSTEM_WRAPPER eTargetRef*/);

		bool manage_access_control(MANAGE_ACCESS_CONTROL_WRAPPER eAccessControl);


		ROBOT_STATE_WRAPPER get_robot_state();
		

		bool jog(JOG_AXIS_WRAPPER eJointAxis, MOVE_REFERENCE_WRAPPER eMoveReference, float fVelocity);

		bool move_home();
		bool move_home(MOVE_HOME_WRAPPER eMode, unsigned char bRun);
		bool movej(float fTargetPos[6], float fTargetVel, float fTargetAcc, float fTargetTime, MOVE_MODE_WRAPPER eMoveMode, float fBlendingRadius, BLENDING_SPEED_TYPE_WRAPPER  eBlendingType);
		bool movel(float fTargetPos[6], float fTargetVel[2], float fTargetAcc[2], float fTargetTime, MOVE_MODE_WRAPPER eMoveMode, MOVE_REFERENCE_WRAPPER eMoveReference, float fBlendingRadius, BLENDING_SPEED_TYPE_WRAPPER eBlendingType);
		bool movec(float fTargetPos[2][6], float fTargetVel[2], float fTargetAcc[2], float fTargetTime, MOVE_MODE_WRAPPER eMoveMode, MOVE_REFERENCE_WRAPPER eMoveReference, float fTargetAngle1, float fTargetAngle2, float fBlendingRadius, BLENDING_SPEED_TYPE_WRAPPER eBlendingType);

		bool stop(STOP_TYPE_WRAPPER eStopType);
		bool move_pause();
		bool move_resume();

		bool mwait();
		ROBOT_POSE_WRAPPER trans(float fSourcePos[6], float fOffset[6], COORDINATE_SYSTEM_WRAPPER eSourceRef, COORDINATE_SYSTEM_WRAPPER eTargetRef);
		ROBOT_POSE_WRAPPER fkin(float fSourcePos[6], COORDINATE_SYSTEM_WRAPPER eTargetRef);
		ROBOT_POSE_WRAPPER ikin(float fSourcePos[6], unsigned char iSolutionSpace, COORDINATE_SYSTEM_WRAPPER eTargetRef);

		bool set_ref_coord(COORDINATE_SYSTEM_WRAPPER eTargetCoordSystem);
		int check_motion();

		bool set_singularity_handling(SINGULARITY_AVOIDANCE_WRAPPER eMode);

		bool servo_off(STOP_TYPE_WRAPPER eStopType);
		bool release_protective_stop(RELEASE_MODE_WRAPPER eReleaseMode);
		bool set_digital_output(GPIO_CTRLBOX_DIGITAL_INDEX_WRAPPER eGpioIdex, bool bOnOff);
		bool get_digital_input(GPIO_CTRLBOX_DIGITAL_INDEX_WRAPPER eGpioIdex);
		bool get_digital_output(GPIO_CTRLBOX_DIGITAL_INDEX_WRAPPER eGpioIdex);
		float get_analog_input(GPIO_CTRLBOX_ANALOG_INDEX_WRAPPER eGpioIdex);


		bool drl_start(ROBOT_SYSTEM_WRAPPER eRobotSystem, System::String^ strDrlProgram);
		bool drl_stop(unsigned char iStopType);
		bool drl_pause();
		bool drl_resume();

		ROBOT_POSE_WRAPPER coord_transform(float fTargetPos[6], COORDINATE_SYSTEM_WRAPPER eInCoordSystem, COORDINATE_SYSTEM_WRAPPER eOutCoordSystem);
	};
}