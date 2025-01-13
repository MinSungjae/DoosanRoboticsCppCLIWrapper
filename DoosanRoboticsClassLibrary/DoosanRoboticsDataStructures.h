/*    ========================================================================
    =               Doosan Robot API C++/CLI Class Wrapper                    =
    =                   Copyright (c) 2024 KAIST USRG.                        =
    =_______________________________________________________________________  =
    = Title             : Doosan Robot API C++/CLI Class Wrapper V1.0         =
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
#include "DRFS.h"

#include <msclr/marshal_cppstd.h>

namespace DoosanRoboticsDataStructures {
    public ref class SYSTEM_VERSION_WRAPPER {
    public:
        System::String^ SmartTp;
        System::String^ Controller;
        System::String^ Interpreter;
        System::String^ Inverter;
        System::String^ SafetyBoard;
        System::String^ RobotSerial;
        System::String^ RobotModel;
        System::String^ JTSBoard;
        System::String^ FlangeBoard;

        void fromNative(const SYSTEM_VERSION& nativeVersion)
        {
            SmartTp = gcnew System::String(nativeVersion._szSmartTp);
            Controller = gcnew System::String(nativeVersion._szController);
            Interpreter = gcnew System::String(nativeVersion._szInterpreter);
            Inverter = gcnew System::String(nativeVersion._szInverter);
            SafetyBoard = gcnew System::String(nativeVersion._szSafetyBoard);
            RobotSerial = gcnew System::String(nativeVersion._szRobotSerial);
            RobotModel = gcnew System::String(nativeVersion._szRobotModel);
            JTSBoard = gcnew System::String(nativeVersion._szJTSBoard);
            FlangeBoard = gcnew System::String(nativeVersion._szFlangeBoard);
        }
    };

    public ref class ROBOT_FORCE_WRAPPER {
    private:
        LPROBOT_FORCE nativeForcePtr;

    public:
        array<float>^ _fForce;

        ROBOT_FORCE_WRAPPER()
        {
            _fForce = gcnew array<float>(NUM_JOINT);
            nativeForcePtr = new ROBOT_FORCE();
        }
        ROBOT_FORCE_WRAPPER(const ROBOT_FORCE_WRAPPER% other)
        {
            _fForce = gcnew array<float>(NUM_JOINT);
            for (int i = 0; i < NUM_JOINT; ++i)
                _fForce[i] = other._fForce[i];
        }
        ~ROBOT_FORCE_WRAPPER()
        {
            this->!ROBOT_FORCE_WRAPPER();
        }
        !ROBOT_FORCE_WRAPPER()
        {
            if (nativeForcePtr != nullptr)
            {
                delete nativeForcePtr;
                nativeForcePtr = nullptr;
            }
        }

        void fromNative(const ROBOT_FORCE& nativeForce)
        {
            for (int i = 0; i < NUM_JOINT; ++i)
                _fForce[i] = nativeForce._fForce[i];
        }

        void fromNativePtr(LPROBOT_FORCE nativeForcePtr)
        {
            if (nativeForcePtr != nullptr)
                for (int i = 0; i < NUM_JOINT; ++i)
                    _fForce[i] = nativeForcePtr->_fForce[i];
        }

        ROBOT_FORCE toNative()
        {
            ROBOT_FORCE nativeForce;
            for (int i = 0; i < NUM_JOINT; ++i)
                nativeForce._fForce[i] = _fForce[i];
            return nativeForce;
        }

        LPROBOT_FORCE toNativePtr()
        {
            for (int i = 0; i < NUM_JOINT; ++i)
                nativeForcePtr->_fForce[i] = _fForce[i];
            return nativeForcePtr;
        }
    };

    public ref class MONITORING_CTRLIO_WRAPPER {

    };

    public ref class MONITORING_CTRLIO_EX_WRAPPER {

    };

    public ref class MONITORING_MODBUS_WRAPPER {

    };

    public ref class LOG_ALARM_WRAPPER {
    public:
        unsigned char LogLevel;
        unsigned char CategoryNumber;
        unsigned int LogNumber;
        System::String^ Parameter1;
        System::String^ Parameter2;
        System::String^ Parameter3;

        LOG_ALARM_WRAPPER(){}

        LOG_ALARM_WRAPPER(const LOG_ALARM_WRAPPER% other)
        {
            LogLevel = other.LogLevel;
            CategoryNumber = other.CategoryNumber;
            LogNumber = other.LogNumber;
            Parameter1 = other.Parameter1;
            Parameter2 = other.Parameter2;
            Parameter3 = other.Parameter3;
        }

        void fromNative(const LOG_ALARM& nativeAlarm)
        {
            LogLevel = nativeAlarm._iLevel;
            CategoryNumber = nativeAlarm._iGroup;
            LogNumber = nativeAlarm._iIndex;
            Parameter1 = gcnew System::String(nativeAlarm._szParam[0]);
            Parameter2 = gcnew System::String(nativeAlarm._szParam[1]);
            Parameter3 = gcnew System::String(nativeAlarm._szParam[2]);
        }

        LOG_ALARM toNative()
        {
            LOG_ALARM nativeAlarm;
            nativeAlarm._iLevel = LogLevel;
            nativeAlarm._iGroup = CategoryNumber;
            nativeAlarm._iIndex = LogNumber;

            pin_ptr<const wchar_t> p1 = PtrToStringChars(Parameter1);
            wcstombs(nativeAlarm._szParam[0], p1, 256);

            pin_ptr<const wchar_t> p2 = PtrToStringChars(Parameter2);
            wcstombs(nativeAlarm._szParam[1], p2, 256);

            pin_ptr<const wchar_t> p3 = PtrToStringChars(Parameter3);
            wcstombs(nativeAlarm._szParam[2], p3, 256);

            return nativeAlarm;
        }
    };

    public ref class ROBOT_POSE_WRAPPER {
    private:
        LPROBOT_POSE nativePosePtr;

    public:
        array<float>^ _fPosition;

        ROBOT_POSE_WRAPPER()
        {
            _fPosition = gcnew array<float>(NUM_JOINT);
            nativePosePtr = new ROBOT_POSE();
        }
        ROBOT_POSE_WRAPPER(const ROBOT_POSE_WRAPPER% other)
        {
            _fPosition = gcnew array<float>(NUM_JOINT);
            for (int i = 0; i < NUM_JOINT; ++i)
                _fPosition[i] = other._fPosition[i];
        }
        ~ROBOT_POSE_WRAPPER()
        {
            this->!ROBOT_POSE_WRAPPER();
        }
        !ROBOT_POSE_WRAPPER()
        {
            if (nativePosePtr != nullptr)
            {
                delete nativePosePtr;
                nativePosePtr = nullptr;
            }
        }

        void fromNative(const ROBOT_POSE& nativeForce)
        {
            for (int i = 0; i < NUM_JOINT; ++i)
                _fPosition[i] = nativeForce._fPosition[i];
        }

        void fromNativePtr(LPROBOT_POSE nativePosePtr)
        {
            if (nativePosePtr != nullptr)
                for (int i = 0; i < NUM_JOINT; ++i)
                    _fPosition[i] = nativePosePtr->_fPosition[i];
        }

        ROBOT_POSE toNative()
        {
            ROBOT_POSE nativeForce;
            for (int i = 0; i < NUM_JOINT; ++i)
                nativeForce._fPosition[i] = _fPosition[i];
            return nativeForce;
        }

        LPROBOT_POSE toNativePtr()
        {
            for (int i = 0; i < NUM_JOINT; ++i)
                nativePosePtr->_fPosition[i] = _fPosition[i];
            return nativePosePtr;
        }
    };

    public enum class ROBOT_STATE_WRAPPER {
        STATE_INITIALIZING                  = ROBOT_STATE::STATE_INITIALIZING,
        STATE_STANDBY                       = ROBOT_STATE::STATE_STANDBY,
        STATE_MOVING                        = ROBOT_STATE::STATE_MOVING,
        STATE_SAFE_OFF                      = ROBOT_STATE::STATE_SAFE_OFF,
        STATE_TEACHING                      = ROBOT_STATE::STATE_TEACHING,
        STATE_SAFE_STOP                     = ROBOT_STATE::STATE_SAFE_STOP,
        STATE_EMERGENCY_STOP                = ROBOT_STATE::STATE_EMERGENCY_STOP,
        STATE_HOMMING                       = ROBOT_STATE::STATE_HOMMING,
        STATE_RECOVERY                      = ROBOT_STATE::STATE_RECOVERY,
        STATE_SAFE_STOP2                    = ROBOT_STATE::STATE_SAFE_STOP2,
        STATE_SAFE_OFF2                     = ROBOT_STATE::STATE_SAFE_OFF2,
        STATE_RESERVED1                     = ROBOT_STATE::STATE_RESERVED1,
        STATE_RESERVED2                     = ROBOT_STATE::STATE_RESERVED2,
        STATE_RESERVED3                     = ROBOT_STATE::STATE_RESERVED3,
        STATE_RESERVED4                     = ROBOT_STATE::STATE_RESERVED4,
        STATE_NOT_READY                     = ROBOT_STATE::STATE_NOT_READY
    };

    public enum class ROBOT_CONTROL_WRAPPER {
        CONTROL_INIT_CONFIG                 = ROBOT_CONTROL::CONTROL_INIT_CONFIG,
        CONTROL_ENABLE_OPERATION            = ROBOT_CONTROL::CONTROL_ENABLE_OPERATION,
        CONTROL_RESET_SAFET_STOP            = ROBOT_CONTROL::CONTROL_RESET_SAFET_STOP,
        CONTROL_RESET_SAFET_OFF             = ROBOT_CONTROL::CONTROL_RESET_SAFET_OFF,
        CONTROL_RECOVERY_SAFE_STOP          = ROBOT_CONTROL::CONTROL_RECOVERY_SAFE_STOP,
        CONTROL_RECOVERY_SAFE_OFF           = ROBOT_CONTROL::CONTROL_RECOVERY_SAFE_OFF,
        CONTROL_RECOVERY_BACKDRIVE          = ROBOT_CONTROL::CONTROL_RECOVERY_BACKDRIVE,
        CONTROL_RESET_RECOVERY              = ROBOT_CONTROL::CONTROL_RESET_RECOVERY
    };

    public enum class MONITORING_SPEED_WRAPPER {
        SPEED_NORMAL_MODE                   = MONITORING_SPEED::SPEED_NORMAL_MODE,
        SPEED_REDUCED_MODE                  = MONITORING_SPEED::SPEED_REDUCED_MODE
    };

    public enum class SPEED_MODE_WRAPPER {
        SPEED_NORMAL_MODE                   = SPEED_MODE::SPEED_NORMAL_MODE,
        SPEED_REDUCED_MODE                  = SPEED_MODE::SPEED_REDUCED_MODE
    };

    public enum class ROBOT_SYSTEM_WRAPPER {
        ROBOT_SYSTEM_REAL                   = ROBOT_SYSTEM::ROBOT_SYSTEM_REAL,
        ROBOT_SYSTEM_VIRTUAL                = ROBOT_SYSTEM::ROBOT_SYSTEM_VIRTUAL
    };

    public enum class ROBOT_MODE_WRAPPER {
        ROBOT_MODE_MANUAL                   = ROBOT_MODE::ROBOT_MODE_MANUAL,
        ROBOT_MODE_AUTONOMOUS               = ROBOT_MODE::ROBOT_MODE_AUTONOMOUS,
        ROBOT_MODE_RECOVERY                 = ROBOT_MODE::ROBOT_MODE_RECOVERY,
        ROBOT_MODE_MEASURE                  = ROBOT_MODE::ROBOT_MODE_MEASURE,
        ROBOT_MODE_INITIALIZE               = ROBOT_MODE::ROBOT_MODE_INITIALIZE
    };

    public enum class ROBOT_SPACE_WRAPPER {
        ROBOT_SPACE_JOINT                   = ROBOT_SPACE::ROBOT_SPACE_JOINT,
        ROBOT_SPACE_TASK                    = ROBOT_SPACE::ROBOT_SPACE_TASK
    };

    public enum class SAFE_STOP_RESET_TYPE_WRAPPER {
        SAFE_STOP_RESET_TYPE_DEFAULT        = SAFE_STOP_RESET_TYPE::SAFE_STOP_RESET_TYPE_DEFAULT,
        SAFE_STOP_RESET_TYPE_PROGRAM_STOP   = SAFE_STOP_RESET_TYPE::SAFE_STOP_RESET_TYPE_PROGRAM_STOP,
        SAFE_STOP_RESET_TYPE_PROGRAM_RESUME = SAFE_STOP_RESET_TYPE::SAFE_STOP_RESET_TYPE_PROGRAM_RESUME
    };

    public enum class MANAGE_ACCESS_CONTROL_WRAPPER {
        MANAGE_ACCESS_CONTROL_FORCE_REQUEST = MANAGE_ACCESS_CONTROL::MANAGE_ACCESS_CONTROL_FORCE_REQUEST,
        MANAGE_ACCESS_CONTROL_REQUEST       = MANAGE_ACCESS_CONTROL::MANAGE_ACCESS_CONTROL_REQUEST,
        MANAGE_ACCESS_CONTROL_RESPONSE_YES  = MANAGE_ACCESS_CONTROL::MANAGE_ACCESS_CONTROL_RESPONSE_YES,
        MANAGE_ACCESS_CONTROL_RESPONSE_NO   = MANAGE_ACCESS_CONTROL::MANAGE_ACCESS_CONTROL_RESPONSE_NO
    };

    public enum class MONITORING_ACCESS_CONTROL_WRAPPER {
        MONITORING_ACCESS_CONTROL_REQUEST   = MONITORING_ACCESS_CONTROL::MONITORING_ACCESS_CONTROL_REQUEST,
        MONITORING_ACCESS_CONTROL_DENY      = MONITORING_ACCESS_CONTROL::MONITORING_ACCESS_CONTROL_DENY,
        MONITORING_ACCESS_CONTROL_GRANT     = MONITORING_ACCESS_CONTROL::MONITORING_ACCESS_CONTROL_GRANT,
        MONITORING_ACCESS_CONTROL_LOSS      = MONITORING_ACCESS_CONTROL::MONITORING_ACCESS_CONTROL_LOSS
    };

    public enum class COORDINATE_SYSTEM_WRAPPER {
        COORDINATE_SYSTEM_BASE              = COORDINATE_SYSTEM::COORDINATE_SYSTEM_BASE,
        COORDINATE_SYSTEM_TOOL              = COORDINATE_SYSTEM::COORDINATE_SYSTEM_TOOL,
        COORDINATE_SYSTEM_WORLD             = COORDINATE_SYSTEM::COORDINATE_SYSTEM_WORLD,
        COORDINATE_SYSTEM_USER_MIN          = COORDINATE_SYSTEM::COORDINATE_SYSTEM_USER_MIN,
        COORDINATE_SYSTEM_USER_MAX          = COORDINATE_SYSTEM::COORDINATE_SYSTEM_USER_MAX
    };

    public enum class JOG_AXIS_WRAPPER {
        JOG_AXIS_JOINT_1                    = JOG_AXIS::JOG_AXIS_JOINT_1,
        JOG_AXIS_JOINT_2                    = JOG_AXIS::JOG_AXIS_JOINT_2,
        JOG_AXIS_JOINT_3                    = JOG_AXIS::JOG_AXIS_JOINT_3,
        JOG_AXIS_JOINT_4                    = JOG_AXIS::JOG_AXIS_JOINT_4,
        JOG_AXIS_JOINT_5                    = JOG_AXIS::JOG_AXIS_JOINT_5,
        JOG_AXIS_JOINT_6                    = JOG_AXIS::JOG_AXIS_JOINT_6,

        JOG_AXIS_TASK_X                     = JOG_AXIS::JOG_AXIS_TASK_X,
        JOG_AXIS_TASK_Y                     = JOG_AXIS::JOG_AXIS_TASK_Y,
        JOG_AXIS_TASK_Z                     = JOG_AXIS::JOG_AXIS_TASK_Z,
        JOG_AXIS_TASK_RX                    = JOG_AXIS::JOG_AXIS_TASK_RX,
        JOG_AXIS_TASK_RY                    = JOG_AXIS::JOG_AXIS_TASK_RY,
        JOG_AXIS_TASK_RZ                    = JOG_AXIS::JOG_AXIS_TASK_RZ
    };
    
    public enum class JOINT_AXIS_WRAPPER {
        JOINT_AXIS_1                        = JOINT_AXIS::JOINT_AXIS_1,
        JOINT_AXIS_2                        = JOINT_AXIS::JOINT_AXIS_2,
        JOINT_AXIS_3                        = JOINT_AXIS::JOINT_AXIS_3,
        JOINT_AXIS_4                        = JOINT_AXIS::JOINT_AXIS_4,
        JOINT_AXIS_5                        = JOINT_AXIS::JOINT_AXIS_5,
        JOINT_AXIS_6                        = JOINT_AXIS::JOINT_AXIS_6
    };

    public enum class TASK_AXIS_WRAPPER {
        TASK_AXIS_X                         = TASK_AXIS::TASK_AXIS_X,
        TASK_AXIS_Y                         = TASK_AXIS::TASK_AXIS_Y,
        TASK_AXIS_Z                         = TASK_AXIS::TASK_AXIS_Z
    };

    public enum class FORCE_AXIS_WRAPPER {
        FORCE_AXIS_X                        = FORCE_AXIS::FORCE_AXIS_X,
        FORCE_AXIS_Y                        = FORCE_AXIS::FORCE_AXIS_Y,
        FORCE_AXIS_Z                        = FORCE_AXIS::FORCE_AXIS_Z,
        FORCE_AXIS_A                        = FORCE_AXIS::FORCE_AXIS_A,
        FORCE_AXIS_B                        = FORCE_AXIS::FORCE_AXIS_B,
        FORCE_AXIS_C                        = FORCE_AXIS::FORCE_AXIS_C
    };

    public enum class MOVE_REFERENCE_WRAPPER {
        MOVE_REFERENCE_BASE                 = MOVE_REFERENCE::MOVE_REFERENCE_BASE,
        MOVE_REFERENCE_TOOL                 = MOVE_REFERENCE::MOVE_REFERENCE_TOOL,
        MOVE_REFERENCE_WORLD                = MOVE_REFERENCE::MOVE_REFERENCE_WORLD,
        MOVE_REFERENCE_USER_MIN             = MOVE_REFERENCE::MOVE_REFERENCE_USER_MIN,
        MOVE_REFERENCE_USER_MAX             = MOVE_REFERENCE::MOVE_REFERENCE_USER_MAX
    };

    public enum class MOVE_MODE_WRAPPER {
        MOVE_MODE_ABSOLUTE                  = MOVE_MODE::MOVE_MODE_ABSOLUTE,
        MOVE_MODE_RELATIVE                  = MOVE_MODE::MOVE_MODE_RELATIVE
    };

    public enum class FORCE_MODE_WRAPPER {
        FORCE_MODE_ABSOLUTE                 = FORCE_MODE::FORCE_MODE_ABSOLUTE,
        FORCE_MODE_RELATIVE                 = FORCE_MODE::FORCE_MODE_RELATIVE
    };

    public enum class BLENDING_SPEED_TYPE_WRAPPER {
        BLENDING_SPEED_TYPE_DUPLICATE       = BLENDING_SPEED_TYPE::BLENDING_SPEED_TYPE_DUPLICATE,
        BLENDING_SPEED_TYPE_OVERRIDE        = BLENDING_SPEED_TYPE::BLENDING_SPEED_TYPE_OVERRIDE
    };

    public enum class STOP_TYPE_WRAPPER {
        STOP_TYPE_QUICK_STO                 = STOP_TYPE::STOP_TYPE_QUICK_STO,
        STOP_TYPE_QUICK                     = STOP_TYPE::STOP_TYPE_QUICK,
        STOP_TYPE_SLOW                      = STOP_TYPE::STOP_TYPE_SLOW,
        STOP_TYPE_HOLD                      = STOP_TYPE::STOP_TYPE_HOLD,
        STOP_TYPE_EMERGENCY                 = STOP_TYPE::STOP_TYPE_EMERGENCY
    };

    public enum class MOVEB_BLENDING_TYPE_WRAPPER {
        MOVEB_BLENDING_TYPE_LINE            = MOVEB_BLENDING_TYPE::MOVEB_BLENDING_TYPE_LINE,
        MOVEB_BLENDING_TYPE_CIRLCE          = MOVEB_BLENDING_TYPE::MOVEB_BLENDING_TYPE_CIRLCE
    };

    public enum class SPLINE_VELOCITY_OPTION_WRAPPER {
        SPLINE_VELOCITY_OPTION_DEFAULT      = SPLINE_VELOCITY_OPTION::SPLINE_VELOCITY_OPTION_DEFAULT,
        SPLINE_VELOCITY_OPTION_CONST        = SPLINE_VELOCITY_OPTION::SPLINE_VELOCITY_OPTION_CONST
    };

    public enum class GPIO_CTRLBOX_DIGITAL_INDEX_WRAPPER {
        GPIO_CTRLBOX_DIGITAL_INDEX_1        = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_1,
        GPIO_CTRLBOX_DIGITAL_INDEX_2        = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_2,
        GPIO_CTRLBOX_DIGITAL_INDEX_3        = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_3,
        GPIO_CTRLBOX_DIGITAL_INDEX_4        = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_4,
        GPIO_CTRLBOX_DIGITAL_INDEX_5        = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_5,
        GPIO_CTRLBOX_DIGITAL_INDEX_6        = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_6,
        GPIO_CTRLBOX_DIGITAL_INDEX_7        = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_7,
        GPIO_CTRLBOX_DIGITAL_INDEX_8        = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_8,
        GPIO_CTRLBOX_DIGITAL_INDEX_9        = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_9,
        GPIO_CTRLBOX_DIGITAL_INDEX_10       = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_10,
        GPIO_CTRLBOX_DIGITAL_INDEX_11       = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_11,
        GPIO_CTRLBOX_DIGITAL_INDEX_12       = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_12,
        GPIO_CTRLBOX_DIGITAL_INDEX_13       = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_13,
        GPIO_CTRLBOX_DIGITAL_INDEX_14       = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_14,
        GPIO_CTRLBOX_DIGITAL_INDEX_15       = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_15,
        GPIO_CTRLBOX_DIGITAL_INDEX_16       = GPIO_CTRLBOX_DIGITAL_INDEX::GPIO_CTRLBOX_DIGITAL_INDEX_16,
    };

    public enum class GPIO_CTRLBOX_ANALOG_INDEX_WRAPPER {
        GPIO_CTRLBOX_ANALOG_INDEX_1         = GPIO_CTRLBOX_ANALOG_INDEX::GPIO_CTRLBOX_ANALOG_INDEX_1,
        GPIO_CTRLBOX_ANALOG_INDEX_2         = GPIO_CTRLBOX_ANALOG_INDEX::GPIO_CTRLBOX_ANALOG_INDEX_2
    };

    public enum class DRL_PROGRAM_STATE_WRAPPER {
        DRL_PROGRAM_STATE_PLAY              = DRL_PROGRAM_STATE::DRL_PROGRAM_STATE_PLAY,
        DRL_PROGRAM_STATE_STOP              = DRL_PROGRAM_STATE::DRL_PROGRAM_STATE_STOP,
        DRL_PROGRAM_STATE_HOLD              = DRL_PROGRAM_STATE::DRL_PROGRAM_STATE_HOLD
    };

    public enum class PROGRAM_STOP_CAUSE_WRAPPER {
        PROGRAM_STOP_CAUSE_NORMAL           = PROGRAM_STOP_CAUSE::PROGRAM_STOP_CAUSE_NORMAL,
        PROGRAM_STOP_CAUSE_FORCE            = PROGRAM_STOP_CAUSE::PROGRAM_STOP_CAUSE_FORCE,
        PROGRAM_STOP_CAUSE_ERROR            = PROGRAM_STOP_CAUSE::PROGRAM_STOP_CAUSE_ERROR
    };

    public enum class SINGULARITY_AVOIDANCE_WRAPPER {
        SINGULARITY_AVOIDANCE_AVOID         = SINGULARITY_AVOIDANCE::SINGULARITY_AVOIDANCE_AVOID,
        SINGULARITY_AVOIDANCE_STOP          = SINGULARITY_AVOIDANCE::SINGULARITY_AVOIDANCE_STOP,
        SINGULARITY_AVOIDANCE_VEL           = SINGULARITY_AVOIDANCE::SINGULARITY_AVOIDANCE_VEL
    };

    public enum class MESSAGE_LEVEL_CLASS {
        MESSAGE_LEVEL_INFO                  = MESSAGE_LEVEL::MESSAGE_LEVEL_INFO,
        MESSAGE_LEVEL_WARN                  = MESSAGE_LEVEL::MESSAGE_LEVEL_WARN,
        MESSAGE_LEVEL_ALARM                 = MESSAGE_LEVEL::MESSAGE_LEVEL_ALARM,
    };

    public enum class MOVE_HOME_WRAPPER {
        MOVE_HOME_MECHANIC                  = MOVE_HOME::MOVE_HOME_MECHANIC,
        MOVE_HOME_USER                      = MOVE_HOME::MOVE_HOME_USER
    };

    public enum class RELEASE_MODE_WRAPPER {
        RELEASE_MODE_STOP                   = RELEASE_MODE::RELEASE_MODE_STOP,
        RELEASE_MODE_RESUME                 = RELEASE_MODE::RELEASE_MODE_RESUME,
        RELEASE_MODE_RELEASE                = RELEASE_MODE::RELEASE_MODE_RELEASE,
        RELEASE_MODE_RESET                  = RELEASE_MODE::RELEASE_MODE_RESET
    };
}