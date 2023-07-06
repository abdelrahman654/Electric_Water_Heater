/*
 * Timer0Cfg.h
 *
 * Created: 04/06/2022 08:05:02 م
 *  Author: dell
 */ 


#ifndef TIMER0CFG_H_
#define TIMER0CFG_H_
/******************************************_SELECT_TIMER0_MODE_********************************************/
// option 1 -> [ NORMAL_MODE ]
// option 2 -> [ CTC_MODE    ]
#define TIMER0_MODE                  NORMAL_MODE
/*******************************************_SELECT_PWM_MODE_********************************************/
// option 1 -> [ FST_PWM0           ]
// option 2 -> [ PHASE_CORRECT_PWM0 ]
//#define PWM0_MODE                       PHASE_CORRECT_PWM0
/*****************************************_SELECT_FAST_PWM_MODE_********************************************/
// option 1 -> [ NON_INVERTED ]
// option 2 -> [ INVERTED     ]
//#define FAST_PWM_MODE                  NON_INVERTED
/************************************_SELECT_PHASE_CORRECT_PWM_MODE_********************************************/
// option 1 -> [ NON_INVERTED ]
// option 2 -> [ INVERTED     ]
//#define PHASE_CORRECT_PWM_MODE         NON_INVERTED
/*********************************************_SELECT_F_OSC_********************************************/
#define F_OSC                   16
/***************************************_SELECT_TIMER0_PRESCALER_********************************************/
// option 1 -> [ 1024 ]
// option 2 -> [ 256  ]
#define TIMER0_PRESCALER       1024
#endif /* TIMER0CFG_H_ */