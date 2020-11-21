#ifndef __STM32L475_H
#define __STM32L475_H

#include "stm32l4xx_con.h"

/**
 * @addtogroup RCC_TypeDef 
 * @brief Reset and Clock Control
 * @note :
 *      RESERVEDx 存在的原因: 保证结构体偏移地址与功能寄存器对齐
 * @{
 */
typedef struct RCC_TypeDef
{
    __IO uint32_t CR;          /* RCC clock control register,                                              Address offset: 0x00 */
    __IO uint32_t ICSCR;       /* RCC internal clock sources calibration register,                         Address offset: 0x04 */
    __IO uint32_t CFGR;        /* RCC clock configuration register,                                        Address offset: 0x08 */
    __IO uint32_t PLLCFGR;     /* RCC system PLL configuration register,                                   Address offset: 0x0C */
    __IO uint32_t PLLSAI1CFGR; /* RCC PLL SAI1 configuration register,                                     Address offset: 0x10 */
    __IO uint32_t PLLSAI2CFGR; /* RCC PLL SAI2 configuration register,                                     Address offset: 0x14 */
    __IO uint32_t CIER;        /* RCC clock interrupt enable register,                                     Address offset: 0x18 */
    __IO uint32_t CIFR;        /* RCC clock interrupt flag register,                                       Address offset: 0x1C */
    __IO uint32_t CICR;        /* RCC clock interrupt clear register,                                      Address offset: 0x20 */
    uint32_t RESERVED0;        /* Reserved, Align register address                                         Address offset: 0x24 */
    __IO uint32_t AHB1RSTR;    /* RCC AHB1 peripheral reset register,                                      Address offset: 0x28 */
    __IO uint32_t AHB2RSTR;    /* RCC AHB2 peripheral reset register,                                      Address offset: 0x2C */
    __IO uint32_t AHB3RSTR;    /* RCC AHB3 peripheral reset register,                                      Address offset: 0x30 */
    uint32_t RESERVED1;        /* Reserved, Align register address                                         Address offset: 0x34 */
    __IO uint32_t APB1RSTR1;   /* RCC APB1 peripheral reset register 1,                                    Address offset: 0x38 */
    __IO uint32_t APB1RSTR2;   /* RCC APB1 peripheral reset register 2,                                    Address offset: 0x3C */
    __IO uint32_t APB2RSTR;    /* RCC APB2 peripheral reset register,                                      Address offset: 0x40 */
    uint32_t RESERVED2;        /* Reserved, Align register address                                         Address offset: 0x44 */
    __IO uint32_t AHB1ENR;     /* RCC AHB1 peripheral clocks enable register,                              Address offset: 0x48 */
    __IO uint32_t AHB2ENR;     /* RCC AHB2 peripheral clocks enable register,                              Address offset: 0x4C */
    __IO uint32_t AHB3ENR;     /* RCC AHB3 peripheral clocks enable register,                              Address offset: 0x50 */
    uint32_t RESERVED3;        /* Reserved, Align register address                                         Address offset: 0x54 */
    __IO uint32_t APB1ENR1;    /* RCC APB1 peripheral clocks enable register 1,                            Address offset: 0x58 */
    __IO uint32_t APB1ENR2;    /* RCC APB1 peripheral clocks enable register 2,                            Address offset: 0x5C */
    __IO uint32_t APB2ENR;     /* RCC APB2 peripheral clocks enable register,                              Address offset: 0x60 */
    uint32_t RESERVED4;        /* Reserved, Align register address                                         Address offset: 0x64 */
    __IO uint32_t AHB1SMENR;   /* RCC AHB1 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x68 */
    __IO uint32_t AHB2SMENR;   /* RCC AHB2 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x6C */
    __IO uint32_t AHB3SMENR;   /* RCC AHB3 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x70 */
    uint32_t RESERVED5;        /* Reserved, Align register address                                         Address offset: 0x74 */
    __IO uint32_t APB1SMENR1;  /* RCC APB1 peripheral clocks enable in sleep mode and stop modes register 1, Address offset: 0x78 */
    __IO uint32_t APB1SMENR2;  /* RCC APB1 peripheral clocks enable in sleep mode and stop modes register 2, Address offset: 0x7C */
    __IO uint32_t APB2SMENR;   /* RCC APB2 peripheral clocks enable in sleep mode and stop modes register, Address offset: 0x80 */
    uint32_t RESERVED6;        /* Reserved, Align register address                                         Address offset: 0x84 */
    __IO uint32_t CCIPR;       /* RCC peripherals independent clock configuration register,                Address offset: 0x88 */
    uint32_t RESERVED7;        /* Reserved, Align register address                                         Address offset: 0x8C */
    __IO uint32_t BDCR;        /* RCC backup domain control register,                                      Address offset: 0x90 */
    __IO uint32_t CSR;         /* RCC clock control & status register,                                     Address offset: 0x94 */
} RCC_TypeDef;
/**
 * @}
 */

/** 
 * @addtogroup GPIO_TypeDef 
 * @brief General Purpose I/O Type Definition 
 * @{
*/
typedef struct
{
    __IO uint32_t MODER;   /* GPIO port mode register,               Address offset: 0x00      */
    __IO uint32_t OTYPER;  /* GPIO port output type register,        Address offset: 0x04      */
    __IO uint32_t OSPEEDR; /* GPIO port output speed register,       Address offset: 0x08      */
    __IO uint32_t PUPDR;   /* GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
    __O  uint32_t IDR;     /* GPIO port input data register,         Address offset: 0x10      */
    __IO uint32_t ODR;     /* GPIO port output data register,        Address offset: 0x14      */
    __I  uint32_t BSRR;    /* GPIO port bit set/reset  register,     Address offset: 0x18      */
    __IO uint32_t LCKR;    /* GPIO port configuration lock register, Address offset: 0x1C      */
    __IO uint32_t AFR[2];  /* GPIO alternate function registers,     Address offset: 0x20-0x24 */
    __I  uint32_t BRR;     /* GPIO Bit Reset register,               Address offset: 0x28      */
    __IO uint32_t ASCR;    /* GPIO analog switch control register,   Address offset: 0x2C      */
} GPIO_TypeDef;
/**
 * @}
 */

/**
 * @addtogroup Peripherals_memory_map
 * @brief Peripherals memory map
 * 
 */
#define PERIPH_BASE             (0x40000000UL)                    /* Peripheral base address */


/* Peripheral memory map */
#define APB1PERIPH_BASE         PERIPH_BASE
#define APB2PERIPH_BASE         (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE         (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE         (PERIPH_BASE + 0x08000000UL)

/*!< AHB1 peripherals */
#define RCC_BASE                (AHB1PERIPH_BASE + 0x1000UL)


/* AHB2 peripherals */ 
// GPIOx_BASE
#define GPIOA_BASE              (AHB2PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE              (AHB2PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE              (AHB2PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE              (AHB2PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE              (AHB2PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE              (AHB2PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE              (AHB2PERIPH_BASE + 0x1800UL)
#define GPIOH_BASE              (AHB2PERIPH_BASE + 0x1C00UL)

/** 
 * @addtogroup Peripheral_declaration
 * @brief Peripheral variable declarations
 * @{
 */
#define GPIOA                   ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB                   ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC                   ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD                   ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE                   ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF                   ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG                   ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH                   ((GPIO_TypeDef *) GPIOH_BASE)

#define RCC                     ((RCC_TypeDef *) RCC_BASE)

/**
 * @}
 */
#endif // !__STM32L475_H
