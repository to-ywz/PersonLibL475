/**
 * @file main.c
 * @author  秦殇 (ywz_123xxx@163.com)
 * @brief gpio 库建立工程
 * @version 0.1
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../BSP/bsp_gpio.h"

#define LEDB_PIN (0x1 << 9)
#define LEDG_PIN (0x1 << 8)
#define LEDR_PIN (0x1 << 7)

#define KEY0_PIN (0x1 << 10)
#define KEY1_PIN (0x1 << 9)
#define KEY2_PIN (0x1 << 8)

void Delay(uint32_t ticks);

int main(void)
{
    /* 使能 GPIOE GPIOD*/
    RCC->AHB2ENR |= (0x01 << 3) | (0x01 << 4);
    /* 配置 GPIOE9 工作模式 */
    GPIOE->MODER &= (uint32_t)((0x01 << (7 * 2)) | (0x01 << (8 * 2)) | (0x01 << (9 * 2)));
    GPIOE->OTYPER &= ~(uint32_t)((1 << 7) | (1 << 8) | (1 << 9));
    GPIOE->OSPEEDR |= (uint32_t)((0x03 << (7 * 2)) | (0x03 << (8 * 2)) | (0x03 << (9 * 2)));
    GPIOE->PUPDR |= (uint32_t)((0x01 << (7 * 2)) | (0x01 << (8 * 2)) | (0x01 << (9 * 2)));
    GPIOE->BSRR |= (uint32_t)((1 << 7) | (1 << 8) | (1 << 9));
    /* 配置 GPIOD 工作模式 */
    GPIOD->MODER &= (uint32_t)((0x00 << (8 * 2)) | (0x00 << (9 * 2)) | (0x00 << (10 * 2)));
    GPIOE->OTYPER &= ~(uint32_t)((1 << 8) | (1 << 9) | (1 << 10));
    GPIOE->PUPDR |= (uint32_t)((0x01 << (8 * 2)) | (0x01 << (9 * 2)) | (0x01 << (10 * 2)));

    while (1)
    {
        if (0 == (GPIOD->IDR & KEY0_PIN))
        {
            Delay(100);
            if (0 == (GPIOD->IDR & KEY0_PIN))
            {
                while (0 == (GPIOD->IDR & KEY0_PIN))
                    ;
            }
            GPIOE->ODR ^= LEDB_PIN;
            GPIOE->BSRR |= LEDG_PIN | LEDR_PIN;
        }
        if (0 == (GPIOD->IDR & KEY1_PIN))
        {
            Delay(100);
            if (0 == (GPIOD->IDR & KEY1_PIN))
            {
                while (0 == (GPIOD->IDR & KEY1_PIN))
                    ;
            }
            GPIOE->ODR ^= LEDG_PIN;
            GPIOE->BSRR |= LEDB_PIN | LEDR_PIN;
        }
        if (0 == (GPIOD->IDR & KEY2_PIN))
        {
            Delay(100);
            if (0 == (GPIOD->IDR & KEY2_PIN))
            {
                while (0 == (GPIOD->IDR & KEY2_PIN))
                    ;
            }
            GPIOE->ODR ^= LEDR_PIN;
            GPIOE->BSRR |= LEDB_PIN | LEDG_PIN;
        }
    }

    return 0;
}

void Delay(uint32_t ticks)
{
    while (ticks--)
        ;
}
