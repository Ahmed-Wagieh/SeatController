/**
 *
 * \file HightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1-25-2022 05:17 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HightSensor.h"


/**
 *
 * Runnable HeightSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHightSensor_GetPosition
 *
 */

void HeightSensor_GetPosition (SensorPositionType* Position)
{
	Std_ReturnType status;
	IOPositionSensorReadingType position;

	/* Server Call Points */
	status = Rte_Call_rpIOGetHeight_IOGet(&position);
	
}

