/**
 *
 * \file WeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: WeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1-25-2022 05:06 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_WeightSensor.h"


/**
 *
 * Runnable WeightSensor_GetWieght
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppWeightSensor_GetWeight
 *
 */

void WeightSensor_GetWieght (SensorWeightType* weight)
{
	Std_ReturnType status;
	IoWeightSensorReadingType Weight;

	/* Server Call Points */
	Weight = Rte_Call_rpIOGetWeight_IOGet(&Weight)/1000;
	
}

