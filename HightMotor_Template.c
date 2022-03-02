/**
 *
 * \file HightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1-25-2022 05:06 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HightMotor.h"


/**
 *
 * Runnable HightMotor_move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHightMotor_Move
 *
 */

void HightMotor_move (StepMotorStepType step)
{
	Std_ReturnType status;

	/* Server Call Points */
	if(step == MOTOR_STEP_PLUS)
		(void)Rte_Call_rpIOSetHeight_IOSetForward();
	else if(step = MOTOR_STEP_MINUS)
		(void)Rte_Call_rpIOSetHeight_IOSetReverse();
	
}

