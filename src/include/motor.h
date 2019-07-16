#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

#define X_Axis_Start_Pin GPIO5
#define X_Axis_Start_Port GPIOA
#define X_Axis_Step_Pin GPIO8
#define X_Axis_Step_Port GPIOA
#define X_Axis_Dir_Pin GPIO13
#define X_Axis_Dir_Port GPIOB

#define Y_Axis_Start_Pin GPIO0
#define Y_Axis_Start_Port GPIOB
#define Y_Axis_Step_Pin GPIO9
#define Y_Axis_Step_Port GPIOA
#define Y_Axis_Dir_Pin GPIO14
#define Y_Axis_Dir_Port GPIOB

#define Z_Axis_Start_Pin GPIO1
#define Z_Axis_Start_Port GPIOB
#define Z_Axis_Step_Pin GPIO10
#define Z_Axis_Step_Port GPIOA
#define Z_Axis_Dir_Pin GPIO15
#define Z_Axis_Dir_Port GPIOB

#define P_Axis_Start_Pin GPIO7
#define P_Axis_Start_Port GPIOA
#define P_Axis_Step_Pin GPIO6
#define P_Axis_Step_Port GPIOA
#define P_Axis_Dir_Pin GPIO12
#define P_Axis_Dir_Port GPIOB

#define X_Axis 0
#define Y_Axis 1
#define Z_Axis 2
#define P_Axis 3

#define STEPPER_COUNT 4

void motor_stop(int  motor_enum);
void motor_enable(int motor_enum);
void motor_start(int motor_enum, int steps, int8_t dir, uint32_t freq);
void motor_power_off(void);
void motor_power_on(void);
bool motor_is_power_on(void);
void motor_init(void);

void motor_interrupt(uint32_t tim);

#endif