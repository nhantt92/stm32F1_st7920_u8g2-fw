/* LCD OLED */

// #include <libopencm3/stm32/rcc.h>
// #include <libopencm3/stm32/gpio.h>
// #include <libopencm3/stm32/i2c.h>
// #include "u8x8.h"
// #include "u8g2.h"

// /* Wait a bit - the lazy version */
// static void delay(int n) {
//   for(int i = 0; i < n; i++)
//     __asm__("nop");
// }

// /* Initialize I2C1 interface */
// static void i2c_setup(void) {
//   /* Enable GPIOB and I2C1 clocks */
//   rcc_periph_clock_enable(RCC_GPIOB);
//   rcc_periph_clock_enable(RCC_AFIO);
//   rcc_periph_clock_enable(RCC_I2C1);

//   /* Set alternate functions for SCL and SDA pins of I2C1 */
//   gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
//           GPIO_CNF_OUTPUT_ALTFN_OPENDRAIN,
//           GPIO_I2C1_SCL | GPIO_I2C1_SDA);

//   /* Disable the I2C peripheral before configuration */
//   i2c_peripheral_disable(I2C1);

//   /* APB1 running at 36MHz */
//   i2c_set_clock_frequency(I2C1, I2C_CR2_FREQ_36MHZ);

//   /* 400kHz - I2C fast mode */
//   i2c_set_fast_mode(I2C2);
//   i2c_set_ccr(I2C1, 0x1e);
//   i2c_set_trise(I2C1, 0x0b);

//   /* And go */
//   i2c_peripheral_enable(I2C1);
// }

// static uint8_t u8x8_gpio_and_delay_cm3(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
//   switch(msg) {
//   case U8X8_MSG_GPIO_AND_DELAY_INIT:
//     i2c_setup();  /* Init I2C communication */
//     break;

//   default:
//     u8x8_SetGPIOResult(u8x8, 1);
//     break;
//   }

//   return 1;
// }

// /* I2C hardware transfer based on u8x8_byte.c implementation */
// static uint8_t u8x8_byte_hw_i2c_cm3(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
//   static uint8_t buffer[32];   /* u8g2/u8x8 will never send more than 32 bytes */
//   static uint8_t buf_idx;
//   uint8_t *data;

//   switch(msg) {
//   case U8X8_MSG_BYTE_SEND:
//     data = (uint8_t *)arg_ptr;
//     while(arg_int > 0) {
//       buffer[buf_idx++] = *data;
//       data++;
//       arg_int--;
//     }
//     break;
//   case U8X8_MSG_BYTE_INIT:
//     break;
//   case U8X8_MSG_BYTE_SET_DC:
//     break;
//   case U8X8_MSG_BYTE_START_TRANSFER:
//     buf_idx = 0;
//     break;
//   case U8X8_MSG_BYTE_END_TRANSFER:
//     i2c_transfer7(I2C1, 0x3C, buffer, buf_idx, NULL, 0);
//     break;
//   default:
//     return 0;
//   }
//   return 1;
// }


// #define I2C_ADDRESS 0x3C
// u8x8_t u8x8;                    // u8x8 object
// u8g2_t u8g2;

// int main(void) {
//   //u8x8_t u8x8_i, *u8x8 = &u8x8_i;

//   rcc_periph_clock_enable(RCC_GPIOC);
//   rcc_clock_setup_in_hse_8mhz_out_72mhz();

//   gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

//   // u8x8_Setup(u8x8, u8x8_d_ssd1306_128x64_noname, u8x8_cad_ssd13xx_i2c, u8x8_byte_hw_i2c_cm3, u8x8_gpio_and_delay_cm3);

//   // u8x8_InitDisplay(u8x8);
//   // u8x8_SetPowerSave(u8x8,0);
//   // u8x8_ClearDisplay(&u8x8);
//   // u8x8_SetFont(u8x8, u8x8_font_amstrad_cpc_extended_r);
      
//   // u8x8_ClearDisplay(u8x8);
//   // u8x8_DrawString(u8x8, 0, 0, "Hello World");

//   u8g2_Setup_ssd1306_i2c_128x64_noname_f(&u8g2,
//       U8G2_R0,
//       u8x8_byte_hw_i2c_cm3,
//       u8x8_gpio_and_delay_cm3);
//   u8g2_SetI2CAddress(&u8g2, I2C_ADDRESS*2);
//   u8g2_InitDisplay(&u8g2);
//   u8g2_SetPowerSave(&u8g2, 0);
//   u8g2_ClearDisplay(&u8g2);

//   u8g2_SetDrawColor(&u8g2, 1);
//   u8g2_SetFontDirection(&u8g2, 0);

//   u8g2_ClearBuffer(&u8g2);

//     u8g2_SetFontMode(&u8g2, 1); // Transparent
//     u8g2_SetFontDirection(&u8g2, 0);
//     u8g2_SetFont(&u8g2, u8g2_font_inb24_mf);
//     u8g2_DrawStr(&u8g2, 0, 30, "NHANTT");

//     // u8g2_SetFontDirection(&u8g2, 1);
//     // u8g2_SetFont(&u8g2, u8g2_font_inb30_mn);
//     // u8g2_DrawStr(&u8g2, 21,8,"8");

//     // u8g2_SetFontDirection(&u8g2, 0);
//     // u8g2_SetFont(&u8g2, u8g2_font_inb24_mf);
//     // u8g2_DrawStr(&u8g2, 51,30,"g");
//     // u8g2_DrawStr(&u8g2, 67,30,"\xb2");

//     u8g2_DrawHLine(&u8g2, 2, 35, 128);
//     u8g2_DrawHLine(&u8g2, 3, 36, 128);

//     u8g2_SetFont(&u8g2, u8g2_font_4x6_tr);

//     u8g2_DrawStr(&u8g2, 2,54,"github.com/nhantt92");

//     u8g2_SendBuffer(&u8g2);

//   while(true) {

//   }
//   return 0;
// }

/* LCD ST7920 */
#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/iwdg.h>
#include <libopencm3/stm32/timer.h>
#include "cdcacm.h"
#include "tick.h"
#include "timerTick.h"
#include "debug.h"
#include "u8x8.h"
#include "u8g2.h"

#define LCD_RST_1 gpio_set(GPIOA, GPIO3);
#define LCD_RST_0 gpio_clear(GPIOA, GPIO3);

#define LCD_RS_1 gpio_set(GPIOA, GPIO4);
#define LCD_RS_0 gpio_clear(GPIOA, GPIO4);

#define LCD_SCLK_1 gpio_set(GPIOA, GPIO5);
#define LCD_SCLK_0 gpio_clear(GPIOA, GPIO5);

#define LCD_SID_1 gpio_set(GPIOA, GPIO7);
#define LCD_SID_0 gpio_clear(GPIOA, GPIO7);

static u8g2_t u8g2;

static void clock_init(void);
static void iwd_init(void);

/* Output for printf */
int _write(int file, char *ptr, int len);
int _write(int file, char *ptr, int len)
{
  int i;
  if(file == STDOUT_FILENO || file == STDERR_FILENO)
  {
    for(i = 0; i < len; i++)
    {
      if(ptr[i] == '\n')
      {
        cdcacm_input('\r');
      }
      cdcacm_input(ptr[i]);
    }
    return i;
  }
  errno = EIO;
  return -1;
}

uint8_t u8g2_gpio_and_delay_stm32(U8X8_UNUSED u8x8_t *u8x8, U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int, U8X8_UNUSED void *arg_ptr)
{
  switch(msg)
  {
    case U8X8_MSG_GPIO_AND_DELAY_INIT:
      rcc_periph_clock_enable(RCC_GPIOB);
      gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO3|GPIO4|GPIO5|GPIO7);
      gpio_set(GPIOA, GPIO3|GPIO4|GPIO5|GPIO7);
      break;
    case U8X8_MSG_DELAY_MILLI:
      tick_wait_ms(arg_int);
      break;
    case U8X8_MSG_DELAY_10MICRO:
      tick_wait_us(10);
      break;
    case U8X8_MSG_DELAY_100NANO:
      __asm__("nop");
      break;
    case U8X8_MSG_GPIO_SPI_CLOCK:
      if(arg_int)
      {
        LCD_SCLK_1;
      }
      else
      {
        LCD_SCLK_0;
      }
      break;
    case U8X8_MSG_GPIO_SPI_DATA:
      if(arg_int)
      {
        LCD_SID_1;
      }
      else 
      {
        LCD_SID_0;
      }
      break;
    case U8X8_MSG_GPIO_CS1:
      if(arg_int)
      {
        LCD_RS_1;
      }
      else
      {
        LCD_RS_0;
      }
      break;
    case U8X8_MSG_GPIO_DC:
      break;
    case U8X8_MSG_GPIO_RESET:
      if(arg_int)
      {
        LCD_RST_1;
      }
      else
      {
        LCD_RST_0;
      }
      break;
    default:
      return 0;
  }
  return 1;
}

int main(void)
{
  TIME tick;
  clock_init();
  tick_init();
  timer_tick_init();
  cdcacm_init();
  iwd_init();
  tick_initTime(&tick);
  //gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
  u8g2_Setup_st7920_s_128x64_f(&u8g2, U8G2_R0, u8x8_byte_4wire_sw_spi, u8g2_gpio_and_delay_stm32); // init u8g2 structure
  u8g2_InitDisplay(&u8g2);
  // u8g2_SetPowerSave(&u8g2, 0); // wake up display
  u8g2_ClearBuffer(&u8g2);
  u8g2_SetFontMode(&u8g2, 1);
  u8g2_SetFontDirection(&u8g2, 0);
  u8g2_SetFont(&u8g2, u8g2_font_unifont_t_vietnamese2);
  //u8g2_DrawStr(&u8g2,  0, 24, "tiếng việt");
  u8g2_DrawUTF8(&u8g2, 58, 18, "Trời mưa");
  u8g2_DrawFrame(&u8g2, 56, 0, 70, 25);
  u8g2_DrawFrame(&u8g2, 56, 28, 70, 25);
  // u8g2_DrawStr(&u8g2,  0, 50, "i'm nhantt");
  // u8g2_SetFont(&u8g2, u8g2_font_u8glib_4_tf);
  // u8g2_DrawStr(&u8g2,  0, 60, "2019-05-20");
  //u8g2_DrawCircle(&u8g2, 64, 40, 10, U8G2_DRAW_ALL);
  u8g2_SetFont(&u8g2, u8g2_font_open_iconic_weather_6x_t);
  u8g2_DrawGlyph(&u8g2, 2, 50, 67);
  u8g2_DrawFrame(&u8g2, 0, 0, 55, 63);
  u8g2_SendBuffer(&u8g2);
  while(1)
  {
    if(!tick_checkMS(&tick, 500))
    {
      u8g2_SendBuffer(&u8g2);
      INFO("LCD Refresh \n");
      gpio_toggle(GPIOC, GPIO13);
    }
    cdcacm_manage();
    iwdg_reset();
  }
}
static void iwd_init(void)
{
  iwdg_reset();
  iwdg_set_period_ms(5000);
  iwdg_start();
}

static void clock_init(void)
{
  rcc_clock_setup_in_hse_8mhz_out_72mhz();
  rcc_periph_clock_enable(RCC_GPIOA);
  rcc_periph_clock_enable(RCC_GPIOB);
  rcc_periph_clock_enable(RCC_GPIOC);
  rcc_periph_clock_enable(RCC_GPIOD);
  rcc_periph_clock_enable(RCC_AFIO);
  rcc_periph_clock_enable(RCC_TIM1);
  rcc_periph_clock_enable(RCC_TIM3);
  gpio_primary_remap(AFIO_MAPR_SWJ_CFG_JTAG_OFF_SW_ON, 0);
}

