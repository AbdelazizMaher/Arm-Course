/*
 * stm32f407xx.h
 *
 *  Created on: Sep 26, 2021
 *      Author: Abdel
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include<stddef.h>
#include <stdint.h>

#define __VO volatile
#define __weak __attribute__((weak))


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
  * peripheral register definition structure for SPI
  */
typedef struct
{
	__VO uint32_t CR1;        /*!< TODO,     										Address offset: 0x00 */
	__VO uint32_t CR2;        /*!< TODO,     										Address offset: 0x04 */
	__VO uint32_t SR;         /*!< TODO,     										Address offset: 0x08 */
	__VO uint32_t DR;         /*!< TODO,     										Address offset: 0x0C */
	__VO uint32_t CRCPR;      /*!< TODO,     										Address offset: 0x10 */
	__VO uint32_t RXCRCR;     /*!< TODO,     										Address offset: 0x14 */
	__VO uint32_t TXCRCR;     /*!< TODO,     										Address offset: 0x18 */
	__VO uint32_t I2SCFGR;    /*!< TODO,     										Address offset: 0x1C */
	__VO uint32_t I2SPR;      /*!< TODO,     										Address offset: 0x20 */
} SPI_RegDef_t;

/**
  * peripheral register definition structure for I2C
  */
typedef struct
{
	__VO uint32_t CR1;        /*!< TODO,     										Address offset: 0x00 */
	__VO uint32_t CR2;        /*!< TODO,     										Address offset: 0x04 */
	__VO uint32_t OAR1;       /*!< TODO,     										Address offset: 0x08 */
	__VO uint32_t OAR2;       /*!< TODO,     										Address offset: 0x0C */
	__VO uint32_t DR;         /*!< TODO,     										Address offset: 0x10 */
	__VO uint32_t SR1;        /*!< TODO,     										Address offset: 0x14 */
	__VO uint32_t SR2;        /*!< TODO,     										Address offset: 0x18 */
	__VO uint32_t CCR;        /*!< TODO,     										Address offset: 0x1C */
	__VO uint32_t TRISE;      /*!< TODO,     										Address offset: 0x20 */
	__VO uint32_t FLTR;       /*!< TODO,     										Address offset: 0x24 */
}I2C_RegDef_t;


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
  * peripheral register definition structure for USART
  */
typedef struct
{
	__VO uint32_t SR;         /*!< TODO,     										Address offset: 0x00 */
	__VO uint32_t DR;         /*!< TODO,     										Address offset: 0x04 */
	__VO uint32_t BRR;        /*!< TODO,     										Address offset: 0x08 */
	__VO uint32_t CR1;        /*!< TODO,     										Address offset: 0x0C */
	__VO uint32_t CR2;        /*!< TODO,     										Address offset: 0x10 */
	__VO uint32_t CR3;        /*!< TODO,     										Address offset: 0x14 */
	__VO uint32_t GTPR;       /*!< TODO,     										Address offset: 0x18 */
}USART_RegDef_t;


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

#define SPI1                ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2  				((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3  				((SPI_RegDef_t*)SPI3_BASEADDR)

#define I2C1                ((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2  				((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3  				((I2C_RegDef_t*)I2C3_BASEADDR)

#define USART1              ((USART_RegDef_t*)USART1_BASEADDR)
#define USART2  			((USART_RegDef_t*)USART2_BASEADDR)
#define USART3  			((USART_RegDef_t*)USART3_BASEADDR)
#define UART4  				((USART_RegDef_t*)UART4_BASEADDR)
#define UART5  				((USART_RegDef_t*)UART5_BASEADDR)
#define USART6  			((USART_RegDef_t*)USART6_BASEADDR)


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
#define I2C2_PCLK_EN()     ( RCC -> APB1ENR |= ( 1 << 22 ) )
#define I2C3_PCLK_EN()     ( RCC -> APB1ENR |= ( 1 << 23 ) )

/**
  * Clock Enable Macros for SPIx peripherals
  */

#define SPI1_PCLK_EN()     ( RCC -> APB2ENR |= ( 1 << 12 ) )
#define SPI2_PCLK_EN()     ( RCC -> APB1ENR |= ( 1 << 14 ) )
#define SPI3_PCLK_EN()     ( RCC -> APB1ENR |= ( 1 << 15 ) )

/**
  * Clock Enable Macros for USARTx peripherals
  */
#define USART1_PCCK_EN()   ( RCC-> APB2ENR |= ( 1 << 4 ) )
#define USART2_PCCK_EN()   ( RCC-> APB1ENR |= ( 1 << 17 ) )
#define USART3_PCCK_EN()   ( RCC-> APB1ENR |= ( 1 << 18 ) )
#define UART4_PCCK_EN()    ( RCC-> APB1ENR |= ( 1 << 19 ) )
#define UART5_PCCK_EN()    ( RCC-> APB1ENR |= ( 1 << 20 ) )
#define USART6_PCCK_EN()   ( RCC-> APB2ENR |= ( 1 << 5 ) )

/**
  * Clock Disable Macros for SPIx peripherals
  */

#define SPI1_PCLK_DI()     ( RCC -> APB2ENR &= ~( 1 << 12 ) )
#define SPI2_PCLK_DI()     ( RCC -> APB1ENR &= ~( 1 << 14 ) )
#define SPI3_PCLK_DI()     ( RCC -> APB1ENR &= ~( 1 << 15 ) )


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
  * Clock Disable Macros for I2Cx peripherals
  */

#define I2C1_PCLK_DI()     ( RCC -> APB1ENR |= ( 1 << 21 ) )
#define I2C2_PCLK_DI()     ( RCC -> APB1ENR |= ( 1 << 22 ) )
#define I2C3_PCLK_DI()     ( RCC -> APB1ENR |= ( 1 << 23 ) )

/**
  * Clock Disable Macros for USARTx peripherals
  */
#define USART1_PCCK_DI()   ( RCC-> APB2ENR &= ~( 1 << 4 ) )
#define USART2_PCCK_DI()   ( RCC-> APB1ENR &= ~( 1 << 17 ) )
#define USART3_PCCK_DI()   ( RCC-> APB1ENR &= ~( 1 << 18 ) )
#define UART4_PCCK_DI()    ( RCC-> APB1ENR &= ~( 1 << 19 ) )
#define UART5_PCCK_DI()    ( RCC-> APB1ENR &= ~( 1 << 20 ) )
#define USART6_PCCK_DI()   ( RCC-> APB2ENR &= ~( 1 << 5 ) )


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
  *  Macros to reset SPIx peripherals
  */
#define SPI1_REG_RESET()               do{ (RCC->APB2RSTR |= (1 << 12)); (RCC->AHB1RSTR &= ~(1 << 12)); }while(0)
#define SPI2_REG_RESET()               do{ (RCC->APB1RSTR |= (1 << 14)); (RCC->AHB1RSTR &= ~(1 << 14)); }while(0)
#define SPI3_REG_RESET()               do{ (RCC->APB1RSTR |= (1 << 15)); (RCC->AHB1RSTR &= ~(1 << 15)); }while(0)

/**
  *  Macros to reset I2Cx peripherals
  */
#define I2C1_REG_RESET()               do{ (RCC->APB1RSTR |= (1 << 21)); (RCC->AHB1RSTR &= ~(1 << 21)); }while(0)
#define I2C2_REG_RESET()               do{ (RCC->APB1RSTR |= (1 << 22)); (RCC->AHB1RSTR &= ~(1 << 22)); }while(0)
#define I2C3_REG_RESET()               do{ (RCC->APB1RSTR |= (1 << 23)); (RCC->AHB1RSTR &= ~(1 << 23)); }while(0)

/**
  *  Macros to reset USARTx peripherals
  */
#define USART1_PCCK_RESET()            do{ (RCC->APB2RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define USART2_PCCK_RESET()            do{ (RCC->APB1RSTR |= (1 << 17 )); (RCC->AHB1RSTR &= ~(1 << 17 )); }while(0)
#define USART3_PCCK_RESET()            do{ (RCC->APB1RSTR |= (1 << 18)); (RCC->AHB1RSTR &= ~(1 << 18)); }while(0)
#define UART4_PCCK_RESET()             do{ (RCC->APB1RSTR |= (1 << 19)); (RCC->AHB1RSTR &= ~(1 << 19)); }while(0)
#define UART5_PCCK_RESET()             do{ (RCC->APB1RSTR |= (1 << 20)); (RCC->AHB1RSTR &= ~(1 << 20)); }while(0)
#define USART6_PCCK_RESET()            do{ (RCC->APB2RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)


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
#define FLAG_RESET         RESET
#define FLAG_SET 			SET


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
#define IRQ_NO_SPI1			35
#define IRQ_NO_SPI2         36
#define IRQ_NO_SPI3         51


/******************************************************************************************
 *Bit position definitions of SPI peripheral
 ******************************************************************************************/
/**
  * Bit position definitions SPI_CR1
  */
#define SPI_CR1_CPHA     				 0
#define SPI_CR1_CPOL      				 1
#define SPI_CR1_MSTR     				 2
#define SPI_CR1_BR   					 3
#define SPI_CR1_SPE     				 6
#define SPI_CR1_LSBFIRST   			 	 7
#define SPI_CR1_SSI     				 8
#define SPI_CR1_SSM      				 9
#define SPI_CR1_RXONLY      		 	10
#define SPI_CR1_DFF     			 	11
#define SPI_CR1_CRCNEXT   			 	12
#define SPI_CR1_CRCEN   			 	13
#define SPI_CR1_BIDIOE     			 	14
#define SPI_CR1_BIDIMODE      			15

/**
  * Bit position definitions SPI_CR2
  */
#define SPI_CR2_RXDMAEN		 			0
#define SPI_CR2_TXDMAEN				 	1
#define SPI_CR2_SSOE				 	2
#define SPI_CR2_FRF						4
#define SPI_CR2_ERRIE					5
#define SPI_CR2_RXNEIE				 	6
#define SPI_CR2_TXEIE					7


/**
  * Bit position definitions SPI_SR
  */
#define SPI_SR_RXNE						0
#define SPI_SR_TXE				 		1
#define SPI_SR_CHSIDE				 	2
#define SPI_SR_UDR					 	3
#define SPI_SR_CRCERR				 	4
#define SPI_SR_MODF					 	5
#define SPI_SR_OVR					 	6
#define SPI_SR_BSY					 	7
#define SPI_SR_FRE					 	8


/******************************************************************************************
 *Bit position definitions of I2C peripheral
 ******************************************************************************************/
/**
  * Bit position definitions I2C_CR1
  */
#define I2C_CR1_PE						0
#define I2C_CR1_NOSTRETCH  				7
#define I2C_CR1_START 					8
#define I2C_CR1_STOP  				 	9
#define I2C_CR1_ACK 				 	10
#define I2C_CR1_SWRST  				 	15

/**
  * Bit position definitions I2C_CR2
  */
#define I2C_CR2_FREQ				 	0
#define I2C_CR2_ITERREN				 	8
#define I2C_CR2_ITEVTEN				 	9
#define I2C_CR2_ITBUFEN 			    10

/**
  * Bit position definitions I2C_OAR1
  */
#define I2C_OAR1_ADD0    				 0
#define I2C_OAR1_ADD71 				 	 1
#define I2C_OAR1_ADD98  			 	 8
#define I2C_OAR1_ADDMODE   			 	15

/**
  * Bit position definitions I2C_SR1
  */

#define I2C_SR1_SB 					 	0
#define I2C_SR1_ADDR 				 	1
#define I2C_SR1_BTF 					2
#define I2C_SR1_ADD10 					3
#define I2C_SR1_STOPF 					4
#define I2C_SR1_RXNE 					6
#define I2C_SR1_TXE 					7
#define I2C_SR1_BERR 					8
#define I2C_SR1_ARLO 					9
#define I2C_SR1_AF 					 	10
#define I2C_SR1_OVR 					11
#define I2C_SR1_TIMEOUT 				14

/**
  * Bit position definitions I2C_SR2
  */
#define I2C_SR2_MSL						0
#define I2C_SR2_BUSY 					1
#define I2C_SR2_TRA 					2
#define I2C_SR2_GENCALL 				4
#define I2C_SR2_DUALF 					7

/**
  * Bit position definitions I2C_CCR
  */
#define I2C_CCR_CCR 					 0
#define I2C_CCR_DUTY 					14
#define I2C_CCR_FS  				 	15

/******************************************************************************************
 *Bit position definitions of USART peripheral
 ******************************************************************************************/

/**
  * Bit position definitions USART_CR1
  */
#define USART_CR1_SBK					0
#define USART_CR1_RWU 					1
#define USART_CR1_RE  					2
#define USART_CR1_TE 					3
#define USART_CR1_IDLEIE 				4
#define USART_CR1_RXNEIE  				5
#define USART_CR1_TCIE					6
#define USART_CR1_TXEIE					7
#define USART_CR1_PEIE 					8
#define USART_CR1_PS 					9
#define USART_CR1_PCE 					10
#define USART_CR1_WAKE  				11
#define USART_CR1_M 					12
#define USART_CR1_UE 					13
#define USART_CR1_OVER8  				15



/**
  * Bit position definitions USART_CR2
  */
#define USART_CR2_ADD   				0
#define USART_CR2_LBDL   				5
#define USART_CR2_LBDIE  				6
#define USART_CR2_LBCL   				8
#define USART_CR2_CPHA   				9
#define USART_CR2_CPOL   				10
#define USART_CR2_STOP   				12
#define USART_CR2_LINEN   				14


/**
  * Bit position definitions USART_CR3
  */
#define USART_CR3_EIE   				0
#define USART_CR3_IREN   				1
#define USART_CR3_IRLP  				2
#define USART_CR3_HDSEL   				3
#define USART_CR3_NACK   				4
#define USART_CR3_SCEN   				5
#define USART_CR3_DMAR  				6
#define USART_CR3_DMAT   				7
#define USART_CR3_RTSE   				8
#define USART_CR3_CTSE   				9
#define USART_CR3_CTSIE   				10
#define USART_CR3_ONEBIT   				11

/**
  * Bit position definitions USART_SR
  */

#define USART_SR_PE        				0
#define USART_SR_FE        				1
#define USART_SR_NE        				2
#define USART_SR_ORE       				3
#define USART_SR_IDLE       			4
#define USART_SR_RXNE        			5
#define USART_SR_TC        				6
#define USART_SR_TXE        			7
#define USART_SR_LBD        			8
#define USART_SR_CTS        			9





#include "stm32f407xx_GPIO_driver.h"
#include "stm32f407xx_SPI_driver.h"
#include "stm32f407xx_I2C_driver.h"
#include "stm32f407xx_USART_driver.h"
#endif /* INC_STM32F407XX_H_ */