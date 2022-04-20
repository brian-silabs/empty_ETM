/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include "em_gpio.h"
#include "em_cmu.h"

#if 1 //xG22

#define ETMCLK_PORT gpioPortA
#define ETMCLK_PIN  4

#define ETMD0_PORT  gpioPortA
#define ETMD0_PIN   3

#else // xG24

#define ETMCLK_PORT gpioPortA
#define ETMCLK_PIN  4

#define ETMD0_PORT  gpioPortA
#define ETMD0_PIN   3

#define ETMD1_PORT  gpioPortA
#define ETMD1_PIN   5

#define ETMD2_PORT  gpioPortA
#define ETMD2_PIN   6

#define ETMD3_PORT  gpioPortA
#define ETMD3_PIN   7

#endif

/**************************************************************************//**
 * @brief Configure EFM32 for ETM trace output.
*****************************************************************************/
void initTraceETM(void)
{
  /* Enable peripheral clocks */
  CMU_ClockEnable(cmuClock_GPIO, true);

  /* Configure trace output */
  /* Enable GPIO Pins for ETM Trace Data output and ETM Clock */

#if 1 //xG22
  GPIO_PinModeSet(ETMCLK_PORT, ETMCLK_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(ETMD0_PORT, ETMD0_PIN, gpioModePushPull, 0);

  GPIO->TRACEROUTEPEN = GPIO_TRACEROUTEPEN_TRACECLKPEN | GPIO_TRACEROUTEPEN_TRACEDATA0PEN;
#else
  GPIO_PinModeSet(ETMD1_PORT, ETMD1_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(ETMD2_PORT, ETMD2_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(ETMD3_PORT, ETMD3_PIN, gpioModePushPull, 0);

  GPIO->TRACEROUTEPEN = GPIO_TRACEROUTEPEN_TRACECLKPEN | \
                        GPIO_TRACEROUTEPEN_TRACEDATA0PEN \
                        GPIO_TRACEROUTEPEN_TRACEDATA1PEN \
                        GPIO_TRACEROUTEPEN_TRACEDATA2PEN \
                        GPIO_TRACEROUTEPEN_TRACEDATA3PEN;
#endif

}



/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
}




/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
}
