/*
 * stm32f407xx.h
 *
 *  Created on: Sep 26, 2021
 *      Author: Abdel
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#define __VO volatile


/**********************************START:Processor Specific Details **********************************/

/**
  * ARM Cortex Mx Processor NVIC ISERx register Addresses
  */

#define NVIC_ISER0          ( (__VO uint32_t*)0xE000E100 )
#define NVIC_ISER1          ( (__VO uint32_t*)0xE000E104 )
#define NVIC_ISER2          ( (__VO uint32_t*)0xE000E108 )
#define NVIC_ISER3          ( (__VO uint32_t*)0xE000E10C )


/**
  * ARM Cortex Mx Processor NVIC ICERx register Addresses
  */

#define NVIC_ICER0 			((__VO uint32_t*)0XE000E180)
#define NVIC_ICER1			((__VO uint32_t*)0XE000E184)
#define NVIC_ICER2  		((__VO uint32_t*)0XE000E188)
#define NVIC_ICER3			((__VO uint32_t*)0XE000E18C)

/**
  * ARM Cortex Mx Processor Priority Register Address Calculation
  */

#define NVIC_PR_BASE_ADDR 	((__VO uint32_t*)0xE000E400)


/**
  * ARM Cortex Mx Processor number of priority bits implemented in Priority Register
  */

#define NO_PR_BITS_IMPLEMENTED  4




/**
  *  base address of flash and sram memories
  */

#define FLASH_BASEADDR                 0x08000000U              /*!< FLASH(up to 1 MB) base address                */
#define SRAM1_BASEADDR                 0x20000000U              /*!< SRAM1(112 KB) base address                          */
#define SRAM2_BASEADDR                 0x2001C000U              /*!< SRAM2(16 KB) base address                        */
#define ROM_BASEADDRR                  0x1FFF0000U              /*!< SYSTEM MEMORY                        */
#define SRAM                           SRAM1_BASEADDR           /*!< MAIN RAM                        */

/**
  *  AHBx and APBx bus peripheral base address
  */

#define PERIPH_BASE                   0x40000000U
#define APB1PERIPH_BASEADDR           PERIPH_BASE
#define APB2PERIPH_BASEADDR           0x40010000U                /*!<  (PERIPH_BASE + 0x00010000U)               */
#define AHB1PERIPH_BASEADDR           0x40020000U                /*!<  (PERIPH_BASE + 0x00020000U)              */
#define AHB2PERIPH_BASEADDR           0x50000000U                /*!<  (PERIPH_BASE + 0x10000000U)              */



/**
  *  base addresses of peripherals which are hanging on AHB1 bus
  */

#define GPIOA_BASEADDR                (AHB1PERIPH_BASEADDR+ 0x0000U)
#define GPIOB_BASEADDR                (AHB1PERIPH_BASEADDR+ 0x0400U)
#define GPIOC_BASEADDR                (AHB1PERIPH_BASEADDR+ 0x0800U)
#define GPIOD_BASEADDR                (AHB1PERIPH_BASEADDR+ 0x0C00U)
#define GPIOE_BASEADDR                (AHB1PERIPH_BASEADDR+ 0x1000U)
#define GPIOF_BASEADDR                (AHB1PERIPH_BASEADDR+ 0x1400U)
#define GPIOG_BASEADDR                (AHB1PERIPH_BASEADDR+ 0x1800U)
#define GPIOH_BASEADDR                (AHB1PERIPH_BASEADDR+ 0x1C00U)
#define GPIOI_BASEADDR                (AHB1PERIPH_BASEADDR+ 0x2000U)
#define RCC_BASEADDR                  (AHB1PERIPH_BASEADDR+ 0x3800U)


/**
  *  base addresses of peripherals which are hanging on APB1 bus
  */

#define I2C1_BASEADDR                (APB1PERIPH_BASEADDR + 0x5400U)
#define I2C2_BASEADDR                (APB1PERIPH_BASEADDR + 0x5800U)
#define I2C3_BASEADDR                (APB1PERIPH_BASEADDR + 0x5C00U)

#define SPI2_BASEADDR                (APB1PERIPH_BASEADDR + 0x3800U)
#define SPI3_BASEADDR                (APB1PERIPH_BASEADDR + 0x3C00U)

#define USART2_BASEADDR              (APB1PERIPH_BASEADDR + 0x4400U)
#define USART3_BASEADDR              (APB1PERIPH_BASEADDR + 0x4800U)
#define UART4_BASEADDR               (APB1PERIPH_BASEADDR + 0x4C00U)
#define UART5_BASEADDR               (APB1PERIPH_BASEADDR + 0x5000U)



/**
  *  base addresses of peripherals which are hanging on APB2 bus
  */

#define USART1_BASEADDR             (APB2PERIPH_BASEADDR + 0x1000U)
#define USART6_BASEADDR             (APB2PERIPH_BASEADDR + 0x1400U)

#define EXTI_BASEADDR               (APB2PERIPH_BASEADDR + 0x3C00U)
#define SYSCFG_BASEADDR        		(APB2PERIPH_BASEADDR + 0x3800U)
#define SPI1_BASEADDR               (APB2PERIPH_BASEADDR + 0x3000U)




/****************************************Peripheral register definition structure**************************************/


/**
  * General Purpose I/O
  */

typedef struct
{
	__VO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
	__VO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
	__VO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
    __VO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
	__VO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
	__VO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
	__VO uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
    __VO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
	__VO uint32_t AFR[2];   /*!< AFR[0]: GPIO alternate function low register,AFR[1]:GPIO alternate function high register,     Address offset: 0x20-0x24 */
}GPIO_RegDef_t;


/**
  * Peripheral structure for RCC registers
  */
typedef struct
{
	  __VO uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
	  __VO uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
	  __VO uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
	  __VO uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
	  __VO uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
	  __VO uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
	  __VO uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
	  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
	  __VO uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
	  __VO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
	  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
	  __VO uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
	  __VO uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
	  __VO uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
	  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
	  __VO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
	  __VO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
	  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
	  __VO uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
	  __VO uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
	  __VO uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
	  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
	  __VO uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
	  __VO uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
	  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
	  __VO uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
	  __VO uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
	  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
	  __VO uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
	  __VO uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
}RCC_RegDef_t;


/**
  * Peripheral structure for EXTI registers
  */

typedef struct
{
	__VO uint32_t IMR;    /*!< Give a short description,          	  	    Address offset: 0x00 */
	__VO uint32_t EMR;    /*!< TODO,                						Address offset: 0x04 */
	__VO uint32_t RTSR;   /*!< TODO,  									     Address offset: 0x08 */
	__VO uint32_t FTSR;   /*!< TODO, 										Address offset: 0x0C */
	__VO uint32_t SWIER;  /*!< TODO,  									   Address offset: 0x10 */
	__VO uint32_t PR;     /*!< TODO,                   					   Address offset: 0x14 */
}EXTI_RegDef_t;

/**
  * peripheral register definition structure for SYSCFG
  */
typedef struct
{
	__VO uint32_t MEMRMP;       /*!< Give a short description,                    Address offset: 0x00      */
	__VO uint32_t PMC;          /*!< TODO,     									  Address offset: 0x04      */
	__VO uint32_t EXTICR[4];    /*!< TODO , 									  Address offset: 0x08-0x14 */
	uint32_t      RESERVED1[2];  /*!< TODO          							  Reserved, 0x18-0x1C    	*/
	__VO uint32_t CMPCR;        /*!< TODO         								  Address offset: 0x20      */
	uint32_t      RESERVED2[2];  /*!<                                             Reserved, 0x24-0x28 	    */
	__VO uint32_t CFGR;         /*!< TODO                                         Address offset: 0x2C   	*/
} SYSCFG_RegDef_t;


/**
  * Peripheral definitions ( Peripheral base addresses typecasted  to xxx_RegDef_t )
  */

#define GPIOA               ((GPIO_RegDef_t *) GPIOA_BASEADDR)
#define GPIOB               ((GPIO_RegDef_t *) GPIOB_BASEADDR)
#define GPIOC               ((GPIO_RegDef_t *) GPIOC_BASEADDR)
#define GPIOD               ((GPIO_RegDef_t *) GPIOD_BASEADDR)
#define GPIOE               ((GPIO_RegDef_t *) GPIOE_BASEADDR)
#define GPIOF               ((GPIO_RegDef_t *) GPIOF_BASEADDR)
#define GPIOG               ((GPIO_RegDef_t *) GPIOG_BASEADDR)
#define GPIOH               ((GPIO_RegDef_t *) GPIOH_BASEADDR)
#define GPIOI               ((GPIO_RegDef_t *) GPIOI_BASEADDR)

#define RCC                 ((RCC_RegDef_t *) RCC_BASEADDR)

#define EXTI                ((EXTI_RegDef_t *) EXTI_BASEADDR)

#define SYSCFG				((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)



/**
  * Clock Enable Macros for GPIOx peripherals
  */

#define GPIOA_PCLK_EN()     ( RCC -> AHB1ENR |= ( 1 << 0 ) )
#define GPIOB_PCLK_EN()     ( RCC -> AHB1ENR |= ( 1 << 1 ) )
#define GPIOC_PCLK_EN()     ( RCC -> AHB1ENR |= ( 1 << 2 ) )
#define GPIOD_PCLK_EN()     ( RCC -> AHB1ENR |= ( 1 << 3 ) )
#define GPIOE_PCLK_EN()     ( RCC -> AHB1ENR |= ( 1 << 4 ) )
#define GPIOF_PCLK_EN()     ( RCC -> AHB1ENR |= ( 1 << 5 ) )
#define GPIOG_PCLK_EN()     ( RCC -> AHB1ENR |= ( 1 << 6 ) )
#define GPIOH_PCLK_EN()     ( RCC -> AHB1ENR |= ( 1 << 7 ) )
#define GPIOI_PCLK_EN()     ( RCC -> AHB1ENR |= ( 1 << 8 ) )

/**
  * Clock Enable Macros for SYSCFG peripheral
  */

#define SYSCFG_PCLK_EN()    (RCC->APB2ENR |= (1 << 14))



/**
  * Clock Enable Macros for I2Cx peripherals
  */

#define I2C1_PCLK_EN()     ( RCC -> APB1ENR |= ( 1 << 21 ) )
#define I22C_PCLK_EN()     ( RCC -> APB1ENR |= ( 1 << 22 ) )
#define I23C_PCLK_EN()     ( RCC -> APB1ENR |= ( 1 << 23 ) )


/**
  * Clock Enable Macros for SPIx peripherals
  */

#define SPI1_PCLK_EN()     ( RCC -> APB2ENR |= ( 1 << 12 ) )
#define SPI2_PCLK_EN()     ( RCC -> APB1ENR |= ( 1 << 14 ) )
#define SPI3_PCLK_EN()     ( RCC -> APB1ENR |= ( 1 << 15 ) )


/**
  * Clock Disable Macros for GPIOx peripherals
  */

#define GPIOA_PCLK_DI()     ( RCC -> AHB1ENR &= ~( 1 << 0 ) )
#define GPIOB_PCLK_DI()     ( RCC -> AHB1ENR &= ~( 1 << 1 ) )
#define GPIOC_PCLK_DI()     ( RCC -> AHB1ENR &= ~( 1 << 2 ) )
#define GPIOD_PCLK_DI()     ( RCC -> AHB1ENR &= ~( 1 << 3 ) )
#define GPIOE_PCLK_DI()     ( RCC -> AHB1ENR &= ~( 1 << 4 ) )
#define GPIOF_PCLK_DI()     ( RCC -> AHB1ENR &= ~( 1 << 5 ) )
#define GPIOG_PCLK_DI()     ( RCC -> AHB1ENR &= ~( 1 << 6 ) )
#define GPIOH_PCLK_DI()     ( RCC -> AHB1ENR &= ~( 1 << 7 ) )
#define GPIOI_PCLK_DI()     ( RCC -> AHB1ENR &= ~( 1 << 8 ) )


/**
  *  Macros to reset GPIOx peripherals
  */
#define GPIOA_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)
#define GPIOI_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8)); }while(0)


/**
  *  returns port code for given GPIOx base address
  */
#define GPIO_BASEADDR_TO_CODE(x)       ((x==GPIOA)?  0:\
                                       (x==GPIOB)?  1:\
                                       (x==GPIOC)?  2:\
                                       (x==GPIOD)?  3:\
                                       (x==GPIOE)?  4:\
                                       (x==GPIOF)?  5:\
                                       (x==GPIOG)?  6:\
                                       (x==GPIOH)?  7:\
                                       (x==GPIOI)?  8:0)



/**
  * macros for all the possible priority levels
  */

#define NVIC_IRQ_PRI0     0
#define NVIC_IRQ_PRI1     1
#define NVIC_IRQ_PRI2     2
#define NVIC_IRQ_PRI3     3
#define NVIC_IRQ_PRI4     4
#define NVIC_IRQ_PRI15    15



/**
  * Some generic macros
  */

#define  ENABLE            1
#define  DISABLE           0
#define  SET               ENABLE
#define  RESET             DISABLE
#define  GPIO_PIN_SET      SET
#define  GPIO_PIN_RESET    RESET

/**
  * IRQ(Interrupt Request) Numbers of STM32F407x MCU
  * NOTE: update these macros with valid values according to your MCU
  */

#define IRQ_NO_EXTI0 		6
#define IRQ_NO_EXTI1 		7
#define IRQ_NO_EXTI2 		8
#define IRQ_NO_EXTI3 		9
#define IRQ_NO_EXTI4 		10
#define IRQ_NO_EXTI9_5 		23
#define IRQ_NO_EXTI15_10 	40

#include "stm32f407xx_GPIO_driver.h"


#endif /* INC_STM32F407XX_H_ */
