/**
 *
 * \file SeatMgr_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatMgr
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1-25-2022 11:32 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatMgr.h"

static boolean IsMotorAdjustNeeded(SensorPositionType Position, SensorWeightType Weight, StepMotorStepType *Step){
	boolean adjustMotor = FALSE;
	switch (Position)
	{
	case SENSOR_POSITION_STEP_0:
		if(Weight >= 60){
			Step = MOTOR_STEP_PLUS;
			adjustMotor = TRUE;
		}
		break;
	case SENSOR_POSITION_STEP_1:
		if(Weight < 60){
			Step = MOTOR_STEP_MINUS;
			adjustMotor = TRUE;
		}
		else if(Weight >= 80){
			Step = MOTOR_STEP_PLUS;
			adjustMotor = TRUE;
		}
		break;
	case SENSOR_POSITION_STEP_2:
		if(Weight < 80){
			Step = MOTOR_STEP_MINUS;
			adjustMotor = TRUE;
		}
		else if(Weight >= 100){
			Step = MOTOR_STEP_PLUS;
			adjustMotor = TRUE;
		}
		break;
	case SENSOR_POSITION_STEP_3:
		if(Weight < 100){
			Step = MOTOR_STEP_MINUS;
			adjustMotor = TRUE;
		}
		break;
	default:
		break;
	}
	return adjustMotor;
}
/**
 *
 * Runnable SeatMgr_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

void SeatMgr_SetHeight (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	
	/* Server Call Points */
	status = Rte_Call_rpHightMotor_Move(step);

	/*Runnable Logic*/
	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	else if(HeightBtnState == MULTI_STATE_BTN_PLUS)
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
	
}


/**
 *
 * Runnable SeatMgr_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatMgr_SetIncline (void)
{
	Std_ReturnType status;
	MultiStateBtnType InclineBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	
	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Move(step);

	/*Runnable Logic*/
	if(InclineBtnState == MULTI_STATE_BTN_MINUS)
		Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS);
	else if(InclineBtnState == MULTI_STATE_BTN_PLUS)
		Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);
	
}


/**
 *
 * Runnable SeatMgr_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */

void SeatMgr_SetSlide (void)
{
	Std_ReturnType status;
	MultiStateBtnType SlideBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	
	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Move(step);

	/*Runnable Logic*/
	if(SlideBtnState == MULTI_STATE_BTN_MINUS)
		Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
	else if(SlideBtnState == MULTI_STATE_BTN_PLUS)
		Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
	
}


/**
 *
 * Runnable SesaMgr_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SesaMgr_AutoHeight_200ms
 *
 */

void SeatMgr_AutoHeight (void)
{
	Std_ReturnType status;
	SensorPositionType position;
	SensorWeightType weight;
	StepMotorStepType step;
	boolean adjustMotor;

	/* Server Call Points */
	status = Rte_Call_rpHeightSensor_GetPosition(position);
	status = Rte_Call_rpWeightSensor_GetWeight(weight);
	adjustMotor = IsMotorAdjustNeeded(Position, Weight, &Step);
	if(adjustMotor)
		(void)Rte_Call_rpHightMotor_Move(step);
	
}


/**
 *
 * Runnable SeatMgr_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatMgr_AutoSlide_200ms
 *
 */

void SeatMgr_AutoSlide (void)
{
	Std_ReturnType status;
	SensorPositionType position;
	SensorWeightType weight;
	StepMotorStepType step;
	boolean adjustMotor;

	/* Server Call Points */
	status = Rte_Call_rpSlideSensor_GetPosition(position);
	status = Rte_Call_rpWeightSensor_GetWeight(weight);
	adjustMotor = IsMotorAdjustNeeded(Position, Weight, &Step);
	if(adjustMotor)
		(void)Rte_Call_rpHightMotor_Move(step);
	
}


/**
 *
 * Runnable SeatMgr_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatMgr_AutoIncline_200ms
 *
 */

void SeatMgr_AutoIncline (void)
{
	Std_ReturnType status;
	SensorPositionType position;
	SensorWeightType weight;
	StepMotorStepType step;
	boolean adjustMotor;

	/* Server Call Points */
	status = Rte_Call_rpInclineSensor_GetPosition(position);
	status = Rte_Call_rpWeightSensor_GetWeight(weight);
	adjustMotor = IsMotorAdjustNeeded(Position, Weight, &Step);
	if(adjustMotor)
		(void)Rte_Call_rpHightMotor_Move(step);
	
}

