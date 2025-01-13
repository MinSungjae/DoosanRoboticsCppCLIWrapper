#include "pch.h"

#include "DoosanRoboticsClassLibrary.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace DoosanRoboticsClassLibrary;

DoosanManagedWrapper::DoosanManagedWrapper()
{
	robot = new CDRFLEx();
}

DoosanManagedWrapper::~DoosanManagedWrapper()
{

}

bool DoosanManagedWrapper::open_connection(String^ ipAddress, unsigned int port)
{
    std::string nativeIpAddress = msclr::interop::marshal_as<std::string>(ipAddress);
    bool result = robot->open_connection(nativeIpAddress, port);
    if (result)
    {
        robot_ip_address_ = ipAddress;
        robot_port_ = port;
        return true;
    }
    else
        return false;
}

void DoosanManagedWrapper::close_connection()
{
	robot->close_connection();
}

bool DoosanManagedWrapper::get_system_version(SYSTEM_VERSION_WRAPPER^ managedVersion)
{
    SYSTEM_VERSION nativeVersion;
    if (robot->get_system_version(&nativeVersion))
    {
        managedVersion->fromNative(nativeVersion);
        return true;
    }
    else
        return false;
}

String^ DoosanManagedWrapper::get_library_version()
{
    const char* nativeVersion = robot->get_library_version();

    return gcnew String(nativeVersion);
}

bool DoosanManagedWrapper::manage_access_control(MANAGE_ACCESS_CONTROL_WRAPPER eAccessControl)
{
    MANAGE_ACCESS_CONTROL nativeAccessControl = static_cast<MANAGE_ACCESS_CONTROL>(eAccessControl);

    return robot->manage_access_control(nativeAccessControl);
}

ROBOT_MODE_WRAPPER DoosanManagedWrapper::get_robot_mode()
{
    ROBOT_MODE nativeRobotMode = robot->get_robot_mode();

    return static_cast<ROBOT_MODE_WRAPPER>(nativeRobotMode);
}

bool DoosanManagedWrapper::set_robot_mode(ROBOT_MODE_WRAPPER eMode)
{
    ROBOT_MODE nativeRobotMode = static_cast<ROBOT_MODE>(eMode);

    return robot->set_robot_mode(nativeRobotMode);
}

ROBOT_STATE_WRAPPER DoosanManagedWrapper::get_robot_state()
{
    ROBOT_STATE nativeState = robot->get_robot_state();

    return static_cast<ROBOT_STATE_WRAPPER>(nativeState);
}

bool DoosanManagedWrapper::set_robot_control(ROBOT_CONTROL_WRAPPER eControl)
{
    ROBOT_CONTROL nativeControl = static_cast<ROBOT_CONTROL>(eControl);

    return robot->set_robot_control(nativeControl);
}

bool DoosanManagedWrapper::set_robot_system(ROBOT_SYSTEM_WRAPPER eRobotSystem)
{
    ROBOT_SYSTEM nativeRobotSystem = static_cast<ROBOT_SYSTEM>(eRobotSystem);

    return robot->set_robot_system(nativeRobotSystem);
}

DRL_PROGRAM_STATE_WRAPPER DoosanManagedWrapper::get_program_state()
{
    DRL_PROGRAM_STATE nativeProgramState = robot->get_program_state();

    return static_cast<DRL_PROGRAM_STATE_WRAPPER>(nativeProgramState);
}

ROBOT_FORCE_WRAPPER DoosanManagedWrapper::get_external_torque()
{
    LPROBOT_FORCE nativeForce = robot->get_external_torque();

    ROBOT_FORCE_WRAPPER managedForce;
    managedForce.fromNativePtr(nativeForce);

    return managedForce;
}


//? Header definition does not identical from API Manual
ROBOT_FORCE_WRAPPER DoosanManagedWrapper::get_tool_force(/*COORDINATE_SYSTEM_WRAPPER eTargetRef*/)
{
    /*COORDINATE_SYSTEM nativeCoordinateSystem = static_cast<COORDINATE_SYSTEM>(eTargetRef);*/
    LPROBOT_FORCE nativeForce = robot->get_tool_force();

    ROBOT_FORCE_WRAPPER managedForce;
    managedForce.fromNativePtr(nativeForce);

    return managedForce;
}

bool DoosanManagedWrapper::jog(JOG_AXIS_WRAPPER eJointAxis, MOVE_REFERENCE_WRAPPER eMoveReference, float fVelocity)
{
    JOG_AXIS nativeJointAxis = static_cast<JOG_AXIS>(eJointAxis);
    MOVE_REFERENCE nativeMoveReference = static_cast<MOVE_REFERENCE>(eMoveReference);

    return robot->jog(nativeJointAxis, nativeMoveReference, fVelocity);
}

bool DoosanManagedWrapper::move_home()
{
    return robot->move_home();
}
bool DoosanManagedWrapper::move_home(MOVE_HOME_WRAPPER eMode, unsigned char bRun)
{
    MOVE_HOME nativeMode = static_cast<MOVE_HOME>(eMode);

    return robot->move_home(nativeMode, bRun);
}

bool DoosanManagedWrapper::movej(float fTargetPos[6], float fTargetVel, float fTargetAcc, float fTargetTime, MOVE_MODE_WRAPPER eMoveMode, float fBlendingRadius, BLENDING_SPEED_TYPE_WRAPPER eBlendingType)
{
    MOVE_MODE nativeMoveMode = static_cast<MOVE_MODE>(eMoveMode);
    BLENDING_SPEED_TYPE nativeBlendingSpeedType = static_cast<BLENDING_SPEED_TYPE>(eBlendingType);

    return robot->movej(fTargetPos, fTargetVel, fTargetAcc, fTargetTime, nativeMoveMode, fBlendingRadius, nativeBlendingSpeedType);
}
bool DoosanManagedWrapper::movel(float fTargetPos[6], float fTargetVel[2], float fTargetAcc[2], float fTargetTime, MOVE_MODE_WRAPPER eMoveMode, MOVE_REFERENCE_WRAPPER eMoveReference, float fBlendingRadius, BLENDING_SPEED_TYPE_WRAPPER eBlendingType)
{
    MOVE_MODE nativeMoveMode = static_cast<MOVE_MODE>(eMoveMode);
    MOVE_REFERENCE nativeMoveReference = static_cast<MOVE_REFERENCE>(eMoveReference);
    BLENDING_SPEED_TYPE nativeBlendingSpeedType = static_cast<BLENDING_SPEED_TYPE>(eBlendingType);

    return robot->movel(fTargetPos, fTargetVel, fTargetAcc, fTargetTime, nativeMoveMode, nativeMoveReference, fBlendingRadius, nativeBlendingSpeedType);
}
bool DoosanManagedWrapper::movec(float fTargetPos[2][6], float fTargetVel[2], float fTargetAcc[2], float fTargetTime, MOVE_MODE_WRAPPER eMoveMode, MOVE_REFERENCE_WRAPPER eMoveReference, float fTargetAngle1, float fTargetAngle2, float fBlendingRadius, BLENDING_SPEED_TYPE_WRAPPER eBlendingType)
{
    MOVE_MODE nativeMoveMode = static_cast<MOVE_MODE>(eMoveMode);
    MOVE_REFERENCE nativeMoveReference = static_cast<MOVE_REFERENCE>(eMoveReference);
    BLENDING_SPEED_TYPE nativeBlendingSpeedType = static_cast<BLENDING_SPEED_TYPE>(eBlendingType);

    return robot->movec(fTargetPos, fTargetVel, fTargetAcc, fTargetTime, nativeMoveMode, nativeMoveReference, fTargetAngle1, fTargetAngle2, fBlendingRadius, nativeBlendingSpeedType);
}

bool DoosanManagedWrapper::stop(STOP_TYPE_WRAPPER eStopType)
{
    STOP_TYPE nativeStopType = static_cast<STOP_TYPE>(eStopType);
    
    return robot->stop(nativeStopType);
}

bool DoosanManagedWrapper::move_pause()
{
    return robot->move_pause();
}

bool DoosanManagedWrapper::move_resume()
{
    return robot->move_resume();
}

bool DoosanManagedWrapper::mwait()
{
    return robot->mwait();
}

ROBOT_POSE_WRAPPER DoosanManagedWrapper::trans(float fSourcePos[6], float fOffset[6], COORDINATE_SYSTEM_WRAPPER eSourceRef, COORDINATE_SYSTEM_WRAPPER eTargetRef)
{
    COORDINATE_SYSTEM nativeSourceRef = static_cast<COORDINATE_SYSTEM>(eSourceRef);
    COORDINATE_SYSTEM nativeTargetRef = static_cast<COORDINATE_SYSTEM>(eTargetRef);

    LPROBOT_POSE nativeResPtr = robot->trans(fSourcePos, fOffset, nativeSourceRef, nativeTargetRef);

    ROBOT_POSE_WRAPPER managedRes;
    managedRes.fromNativePtr(nativeResPtr);

    return managedRes;
}
ROBOT_POSE_WRAPPER DoosanManagedWrapper::fkin(float fSourcePos[6], COORDINATE_SYSTEM_WRAPPER eTargetRef)
{
    COORDINATE_SYSTEM nativeTargetRef = static_cast<COORDINATE_SYSTEM>(eTargetRef);

    LPROBOT_POSE nativeResPtr = robot->fkin(fSourcePos, nativeTargetRef);

    ROBOT_POSE_WRAPPER managedRes;
    managedRes.fromNativePtr(nativeResPtr);

    return managedRes;

}
ROBOT_POSE_WRAPPER DoosanManagedWrapper::ikin(float fSourcePos[6], unsigned char iSolutionSpace, COORDINATE_SYSTEM_WRAPPER eTargetRef)
{
    COORDINATE_SYSTEM nativeTargetRef = static_cast<COORDINATE_SYSTEM>(eTargetRef);

    LPROBOT_POSE nativeResPtr = robot->ikin(fSourcePos, iSolutionSpace, nativeTargetRef);

    ROBOT_POSE_WRAPPER managedRes;
    managedRes.fromNativePtr(nativeResPtr);

    return managedRes;

}
bool DoosanManagedWrapper::set_ref_coord(COORDINATE_SYSTEM_WRAPPER eTargetCoordSystem)
{
    COORDINATE_SYSTEM nativeTargetCoordSystem = static_cast<COORDINATE_SYSTEM>(eTargetCoordSystem);

    return robot->set_ref_coord(nativeTargetCoordSystem);
}
int DoosanManagedWrapper::check_motion()
{
    return robot->check_motion();
}

bool DoosanManagedWrapper::set_singularity_handling(SINGULARITY_AVOIDANCE_WRAPPER eMode)
{
    SINGULARITY_AVOIDANCE nativeSingularityAvoidance = static_cast<SINGULARITY_AVOIDANCE>(eMode);

    return robot->set_singularity_handling(nativeSingularityAvoidance);
}

bool DoosanManagedWrapper::servo_off(STOP_TYPE_WRAPPER eStopType)
{
    STOP_TYPE nativeStopType = static_cast<STOP_TYPE>(eStopType);

    return robot->servo_off(nativeStopType);
}

bool DoosanManagedWrapper::release_protective_stop(RELEASE_MODE_WRAPPER eReleaseMode)
{
    RELEASE_MODE nativeReleaseMode = static_cast<RELEASE_MODE>(eReleaseMode);

    return robot->release_protective_stop(nativeReleaseMode);
}

bool DoosanManagedWrapper::set_digital_output(GPIO_CTRLBOX_DIGITAL_INDEX_WRAPPER eGpioIdex, bool bOnOff)
{
    GPIO_CTRLBOX_DIGITAL_INDEX nativeGpioIdex = static_cast<GPIO_CTRLBOX_DIGITAL_INDEX>(eGpioIdex);

    return robot->set_digital_output(nativeGpioIdex, bOnOff);
}

bool DoosanManagedWrapper::get_digital_input(GPIO_CTRLBOX_DIGITAL_INDEX_WRAPPER eGpioIdex)
{
    GPIO_CTRLBOX_DIGITAL_INDEX nativeGpioIdex = static_cast<GPIO_CTRLBOX_DIGITAL_INDEX>(eGpioIdex);

    return robot->get_digital_input(nativeGpioIdex);
}

bool DoosanManagedWrapper::get_digital_output(GPIO_CTRLBOX_DIGITAL_INDEX_WRAPPER eGpioIdex)
{
    GPIO_CTRLBOX_DIGITAL_INDEX nativeGpioIdex = static_cast<GPIO_CTRLBOX_DIGITAL_INDEX>(eGpioIdex);

    return robot->get_digital_output(nativeGpioIdex);
}

float DoosanManagedWrapper::get_analog_input(GPIO_CTRLBOX_ANALOG_INDEX_WRAPPER eGpioIdex)
{

    GPIO_CTRLBOX_ANALOG_INDEX nativeGpioIdex = static_cast<GPIO_CTRLBOX_ANALOG_INDEX>(eGpioIdex);

    return robot->get_analog_input(nativeGpioIdex);
}

bool DoosanManagedWrapper::drl_start(ROBOT_SYSTEM_WRAPPER eRobotSystem, String^ strDrlProgram)
{
    ROBOT_SYSTEM nativeRobotSystem = static_cast<ROBOT_SYSTEM>(eRobotSystem);
    std::string nativeDrlProgram = msclr::interop::marshal_as<std::string>(strDrlProgram);

    return robot->drl_start(nativeRobotSystem, nativeDrlProgram);
}

bool DoosanManagedWrapper::drl_stop(unsigned char iStopType)
{
    return robot->drl_stop(iStopType);
}

bool DoosanManagedWrapper::drl_pause()
{
    return robot->drl_pause();
}

bool DoosanManagedWrapper::drl_resume()
{
    return robot->drl_resume();
}

ROBOT_POSE_WRAPPER DoosanManagedWrapper::coord_transform(float fTargetPos[6], COORDINATE_SYSTEM_WRAPPER eInCoordSystem, COORDINATE_SYSTEM_WRAPPER eOutCoordSystem)
{
    COORDINATE_SYSTEM nativeInCoordSystem = static_cast<COORDINATE_SYSTEM>(eInCoordSystem);
    COORDINATE_SYSTEM nativeOutCoordSystem = static_cast<COORDINATE_SYSTEM>(eOutCoordSystem);

    LPROBOT_POSE nativeRes = robot->coord_transform(fTargetPos, nativeInCoordSystem, nativeOutCoordSystem);

    ROBOT_POSE_WRAPPER managedRes;
    managedRes.fromNativePtr(nativeRes);

    return managedRes;
}