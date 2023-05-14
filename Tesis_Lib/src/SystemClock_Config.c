#include "SystemClock_Config.h"

void SystemClock_Confi(void)
{
    RCC->CR |= RCC_CR_HSEON; // Habilitar el oscilador externo (HSE)
    while (!(RCC->CR & RCC_CR_HSERDY))
    {
    } // Esperar hasta que el oscilador externo esté listo

    RCC->CFGR |= RCC_CFGR_PLLSRC;   // Configurar la fuente de reloj para el PLL (HSE en este ejemplo)
    RCC->CFGR |= RCC_CFGR_PLLMULL9; // Configurar el factor de multiplicación del PLL a x9

    RCC->CR |= RCC_CR_PLLON; // Habilitar el PLL
    while (!(RCC->CR & RCC_CR_PLLRDY))
    {
    } // Esperar hasta que el PLL esté listo

    RCC->CFGR &= ~(RCC_CFGR_SW);  // Limpiar los bits de selección de fuente de reloj del sistema
    RCC->CFGR |= RCC_CFGR_SW_PLL; // Seleccionar el PLL como fuente de reloj del sistema

    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL)
    {
    } // Esperar hasta que el PLL sea la fuente de reloj del sistema
}