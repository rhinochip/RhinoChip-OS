#ifndef QEI_H
#define QEI_H

#include <p30fxxxx.h>

#include "../types.h"
#include "clock.h"

#define QEA_MA    PORTBbits.RB0
#define QEB_MA    PORTBbits.RB1
#define QEA_MB    PORTBbits.RB2
#define QEB_MB    PORTBbits.RB3
#define QEA_MC    PORTBbits.RB4
#define QEB_MC    PORTBbits.RB5
#define QEA_MD    PORTDbits.RD2
#define QEB_MD    PORTDbits.RD3
#define QEA_ME    PORTFbits.RF0
#define QEB_ME    PORTFbits.RF1
#define QEA_MF    PORTFbits.RF4
#define QEB_MF    PORTFbits.RF5

#define NUM_MOTORS    6

#define MOTOR_A    0
#define MOTOR_B    1
#define MOTOR_C    2
#define MOTOR_D    3
#define MOTOR_E    4
#define MOTOR_F    5

#define MOTOR_A_MAX_RANGE     300
#define MOTOR_A_MIN_RANGE    -300
#define MOTOR_B_MAX_RANGE     300
#define MOTOR_B_MIN_RANGE    -300
#define MOTOR_C_MAX_RANGE     300
#define MOTOR_C_MIN_RANGE    -300
#define MOTOR_D_MAX_RANGE     300
#define MOTOR_D_MIN_RANGE    -300
#define MOTOR_E_MAX_RANGE     300
#define MOTOR_E_MIN_RANGE    -300
#define MOTOR_F_MAX_RANGE     300
#define MOTOR_F_MIN_RANGE    -300

#define T2FREQ         100000                         /* Timer 2 frequency: 100 kHz */
#define T2PRESCALER    1                              /* Timer 2 prescale value of 1:1 */
#define PR2VAL         (FCY / (T2FREQ * T2PRESCALER)) /* Value for the PR1 register of Timer 2 */

/**
 * 16-bit count registers to count motor steps. Being 16-bit wide, they can
 * store a value between -32768 an 32767.
 */
static int motor_steps[NUM_MOTORS] = {0, 0, 0, 0, 0, 0};

/**
 * Flag that indicates whether a motor is stalled.
 */
static bool_t motor_stalled[NUM_MOTORS] = {false, false, false, false, false, false};

/**
 * Set up the Quadrature Encoder Interface.
 */
void qei_setup(void);

/**
 * Timer 1 ISR to sample the QEA and QEB lines for each motor and count motor
 * steps.
 */
void __attribute__((__interrupt__)) _T2Interrupt(void);

#endif
