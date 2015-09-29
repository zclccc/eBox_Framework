

#include "ebox.h"


GPIO PA0(GPIOA,GPIO_Pin_0);
GPIO PA1(GPIOA,GPIO_Pin_1);
GPIO PA2(GPIOA,GPIO_Pin_2);
GPIO PA3(GPIOA,GPIO_Pin_3);
GPIO PA4(GPIOA,GPIO_Pin_4);
GPIO PA5(GPIOA,GPIO_Pin_5);
GPIO PA6(GPIOA,GPIO_Pin_6);
GPIO PA7(GPIOA,GPIO_Pin_7);
GPIO PA8(GPIOA,GPIO_Pin_8);
GPIO PA9(GPIOA,GPIO_Pin_9);
GPIO PA10(GPIOA,GPIO_Pin_10);
GPIO PA11(GPIOA,GPIO_Pin_11);
GPIO PA12(GPIOA,GPIO_Pin_12);
GPIO PA13(GPIOA,GPIO_Pin_13);
GPIO PA14(GPIOA,GPIO_Pin_14);
GPIO PA15(GPIOA,GPIO_Pin_15);

GPIO PB0(GPIOB,GPIO_Pin_0);
GPIO PB1(GPIOB,GPIO_Pin_1);
GPIO PB2(GPIOB,GPIO_Pin_2);
GPIO PB3(GPIOB,GPIO_Pin_3);
GPIO PB4(GPIOB,GPIO_Pin_4);
GPIO PB5(GPIOB,GPIO_Pin_5);
GPIO PB6(GPIOB,GPIO_Pin_6);
GPIO PB7(GPIOB,GPIO_Pin_7);
GPIO PB8(GPIOB,GPIO_Pin_8);
GPIO PB9(GPIOB,GPIO_Pin_9);
GPIO PB10(GPIOB,GPIO_Pin_10);
GPIO PB11(GPIOB,GPIO_Pin_11);
GPIO PB12(GPIOB,GPIO_Pin_12);
GPIO PB13(GPIOB,GPIO_Pin_13);
GPIO PB14(GPIOB,GPIO_Pin_14);
GPIO PB15(GPIOB,GPIO_Pin_15);


GPIO PC0(GPIOC,GPIO_Pin_0);
GPIO PC1(GPIOC,GPIO_Pin_1);
GPIO PC2(GPIOC,GPIO_Pin_2);
GPIO PC3(GPIOC,GPIO_Pin_3);
GPIO PC4(GPIOC,GPIO_Pin_4);
GPIO PC5(GPIOC,GPIO_Pin_5);
GPIO PC6(GPIOC,GPIO_Pin_6);
GPIO PC7(GPIOC,GPIO_Pin_7);
GPIO PC8(GPIOC,GPIO_Pin_8);
GPIO PC9(GPIOC,GPIO_Pin_9);
GPIO PC10(GPIOC,GPIO_Pin_10);
GPIO PC11(GPIOC,GPIO_Pin_11);
GPIO PC12(GPIOC,GPIO_Pin_12);
GPIO PC13(GPIOC,GPIO_Pin_13);
GPIO PC14(GPIOC,GPIO_Pin_14);
GPIO PC15(GPIOC,GPIO_Pin_15);


GPIO PD0(GPIOD,GPIO_Pin_0);
GPIO PD1(GPIOD,GPIO_Pin_1);
GPIO PD2(GPIOD,GPIO_Pin_2);
GPIO PD3(GPIOD,GPIO_Pin_3);
GPIO PD4(GPIOD,GPIO_Pin_4);
GPIO PD5(GPIOD,GPIO_Pin_5);
GPIO PD6(GPIOD,GPIO_Pin_6);
GPIO PD7(GPIOD,GPIO_Pin_7);
GPIO PD8(GPIOD,GPIO_Pin_8);
GPIO PD9(GPIOD,GPIO_Pin_9);
GPIO PD10(GPIOD,GPIO_Pin_10);
GPIO PD11(GPIOD,GPIO_Pin_11);
GPIO PD12(GPIOD,GPIO_Pin_12);
GPIO PD13(GPIOD,GPIO_Pin_13);
GPIO PD14(GPIOD,GPIO_Pin_14);
GPIO PD15(GPIOD,GPIO_Pin_15);

GPIO PE0(GPIOE,GPIO_Pin_0);
GPIO PE1(GPIOE,GPIO_Pin_1);
GPIO PE2(GPIOE,GPIO_Pin_2);
GPIO PE3(GPIOE,GPIO_Pin_3);
GPIO PE4(GPIOE,GPIO_Pin_4);
GPIO PE5(GPIOE,GPIO_Pin_5);
GPIO PE6(GPIOE,GPIO_Pin_6);
GPIO PE7(GPIOE,GPIO_Pin_7);
GPIO PE8(GPIOE,GPIO_Pin_8);
GPIO PE9(GPIOE,GPIO_Pin_9);
GPIO PE10(GPIOE,GPIO_Pin_10);
GPIO PE11(GPIOE,GPIO_Pin_11);
GPIO PE12(GPIOE,GPIO_Pin_12);
GPIO PE13(GPIOE,GPIO_Pin_13);
GPIO PE14(GPIOE,GPIO_Pin_14);
GPIO PE15(GPIOE,GPIO_Pin_15);

GPIO PF0(GPIOF,GPIO_Pin_0);
GPIO PF1(GPIOF,GPIO_Pin_1);
GPIO PF2(GPIOF,GPIO_Pin_2);
GPIO PF3(GPIOF,GPIO_Pin_3);
GPIO PF4(GPIOF,GPIO_Pin_4);
GPIO PF5(GPIOF,GPIO_Pin_5);
GPIO PF6(GPIOF,GPIO_Pin_6);
GPIO PF7(GPIOF,GPIO_Pin_7);
GPIO PF8(GPIOF,GPIO_Pin_8);
GPIO PF9(GPIOF,GPIO_Pin_9);
GPIO PF10(GPIOF,GPIO_Pin_10);
GPIO PF11(GPIOF,GPIO_Pin_11);
GPIO PF12(GPIOF,GPIO_Pin_12);
GPIO PF13(GPIOF,GPIO_Pin_13);
GPIO PF14(GPIOF,GPIO_Pin_14);
GPIO PF15(GPIOF,GPIO_Pin_15);

GPIO PG0(GPIOG,GPIO_Pin_0);
GPIO PG1(GPIOG,GPIO_Pin_1);
GPIO PG2(GPIOG,GPIO_Pin_2);
GPIO PG3(GPIOG,GPIO_Pin_3);
GPIO PG4(GPIOG,GPIO_Pin_4);
GPIO PG5(GPIOG,GPIO_Pin_5);
GPIO PG6(GPIOG,GPIO_Pin_6);
GPIO PG7(GPIOG,GPIO_Pin_7);
GPIO PG8(GPIOG,GPIO_Pin_8);
GPIO PG9(GPIOG,GPIO_Pin_9);
GPIO PG10(GPIOG,GPIO_Pin_10);
GPIO PG11(GPIOG,GPIO_Pin_11);
GPIO PG12(GPIOG,GPIO_Pin_12);
GPIO PG13(GPIOG,GPIO_Pin_13);
GPIO PG14(GPIOG,GPIO_Pin_14);
GPIO PG15(GPIOG,GPIO_Pin_15);

//����
USART uart1(USART1,&PA9,&PA10);
USART uart2(USART3,&PA2,&PA3);
USART uart3(USART3,&PB10,&PB11);

//spi
SPIClASS spi1(SPI1,&PA5,&PA6,&PA7);	
SPIClASS spi2(SPI2,&PB13,&PB14,&PB15);	
SOFTSPI  sspi(&PA5,&PA6,&PA7);

//i2c
I2C i2c1(I2C1,&PB6,&PB7);
I2C i2c2(I2C2,&PB10,&PB11);
SOFTI2C si2c(&PA4,&PA5);
SOFTI2C si2c1(&PB6,&PB7);
