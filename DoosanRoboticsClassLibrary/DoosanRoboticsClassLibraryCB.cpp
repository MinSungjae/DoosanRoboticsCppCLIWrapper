#include "pch.h"

#include "DoosanRoboticsClassLibrary.h"

using namespace System::Runtime::InteropServices;
using namespace DoosanRoboticsClassLibrary;

void DoosanManagedWrapper::set_on_monitoring_state(TOnMonitoringStateCBDelegate^ managedCallback)
{
	TOnMonitoringStateCB nativeCallback = (TOnMonitoringStateCB)Marshal::GetFunctionPointerForDelegate(managedCallback).ToPointer();

	robot->set_on_monitoring_state(nativeCallback);
}

void DoosanManagedWrapper::set_on_monitoring_ctrl_io(TOnMonitoringCtrlIOCBDelegate^ managedCallback)
{
	TOnMonitoringCtrlIOCB nativeCallback = static_cast<TOnMonitoringCtrlIOCB>(Marshal::GetFunctionPointerForDelegate(managedCallback).ToPointer());
	onMonitoringCtrlIOCBDelegate = managedCallback;

	robot->set_on_monitoring_ctrl_io(nativeCallback);
}

void DoosanManagedWrapper::set_on_monitoring_ctrl_io_ex(TOnMonitoringCtrlIOExCBDelegate^ managedCallback)
{
	TOnMonitoringCtrlIOExCB nativeCallback = static_cast<TOnMonitoringCtrlIOExCB>(Marshal::GetFunctionPointerForDelegate(managedCallback).ToPointer());
	onMonitoringCtrlIOExCBDelegate = managedCallback;

	robot->set_on_monitoring_ctrl_io_ex(nativeCallback);
}

void DoosanManagedWrapper::set_on_monitoring_modbus(TOnMonitoringModbusCBDelegate^ managedCallback)
{
	TOnMonitoringModbusCB nativeCallback = static_cast<TOnMonitoringModbusCB>(Marshal::GetFunctionPointerForDelegate(managedCallback).ToPointer());
	onMonitoringModbusCBDelegate = managedCallback;

	robot->set_on_monitoring_modbus(nativeCallback);
}

void DoosanManagedWrapper::set_on_log_alarm(TOnLogAlarmCBDelegate^ managedCallback)
{
	TOnLogAlarmCB nativeCallback = static_cast<TOnLogAlarmCB>(Marshal::GetFunctionPointerForDelegate(managedCallback).ToPointer());
	onLogAlarmCBDelegate = managedCallback;

	robot->set_on_log_alarm(nativeCallback);
}

void DoosanManagedWrapper::set_on_monitoring_access_control(TOnMonitoringAccessControlCBDelegate^ managedCallback)
{
	TOnMonitoringAccessControlCB nativeCallback = static_cast<TOnMonitoringAccessControlCB>(Marshal::GetFunctionPointerForDelegate(managedCallback).ToPointer());
	onMonitoringAccessControlCBDelegate = managedCallback;

	robot->set_on_monitoring_access_control(nativeCallback);
}

void DoosanManagedWrapper::set_on_homming_completed(TOnHommingCompletedCBDelegate^ managedCallback)
{
	TOnHommingCompletedCB nativeCallback = static_cast<TOnHommingCompletedCB>(Marshal::GetFunctionPointerForDelegate(managedCallback).ToPointer());
	
	robot->set_on_homming_completed(nativeCallback);
}

void DoosanManagedWrapper::set_on_tp_initializing_completed(TOnTpInitializingCompletedCBDelegate^ managedCallback)
{
	TOnTpInitializingCompletedCB nativeCallback = static_cast<TOnTpInitializingCompletedCB>(Marshal::GetFunctionPointerForDelegate(managedCallback).ToPointer());

	robot->set_on_tp_initializing_completed(nativeCallback);
}

void DoosanManagedWrapper::set_on_mastering_need(TOnMasteringNeedCBDelegate^ managedCallback)
{
	TOnMasteringNeedCB nativeCallback = static_cast<TOnMasteringNeedCB>(Marshal::GetFunctionPointerForDelegate(managedCallback).ToPointer());

	robot->set_on_mastering_need(nativeCallback);
}

void DoosanManagedWrapper::set_on_program_stopped(TOnProgramStoppedCBDelegate^ managedCallback)
{
	TOnProgramStoppedCB nativeCallback = static_cast<TOnProgramStoppedCB>(Marshal::GetFunctionPointerForDelegate(managedCallback).ToPointer());

	robot->set_on_program_stopped(nativeCallback);
}

void DoosanManagedWrapper::set_on_disconnected(TOnDisconnectedCBDelegate^ managedCallback)
{
	TOnDisconnectedCB nativeCallback = static_cast<TOnDisconnectedCB>(Marshal::GetFunctionPointerForDelegate(managedCallback).ToPointer());

	robot->set_on_disconnected(nativeCallback);
}

void DoosanManagedWrapper::set_on_monitoring_robot_system(TOnMonitoringRobotSystemCBDelegate^ managedCallback)
{
	TOnMonitoringRobotSystemCB nativeCallback = static_cast<TOnMonitoringRobotSystemCB>(Marshal::GetFunctionPointerForDelegate(managedCallback).ToPointer());

	robot->set_on_monitoring_robot_system(nativeCallback);
}