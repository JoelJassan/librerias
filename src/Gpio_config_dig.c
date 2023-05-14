#include "Gpio_config_dig.h"

void Gpio_Config(void)
{
    //* Habilitar el reloj del periférico GPIOC
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

    // Configurar el pin PC13 como salida
    GPIOC->CRH &= ~(GPIO_CRH_CNF13);
    GPIOC->CRH |= GPIO_CRH_MODE13_0;
}