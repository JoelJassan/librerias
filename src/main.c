#include "stm32f1xx.h"
#include "SystemClock_Config.h"
#include "Gpio_config_dig.h"

int main(void)

{
    // Configurar el reloj del sistema

    SystemClock_Confi();
    Gpio_Config();

    while (1)
    {
        // Cambiar el estado del LED
        GPIOC->ODR ^= GPIO_ODR_ODR13;
        for (int bucle = 0; bucle < 5000000; bucle++)
        {
            asm("nop");
        }
    }
}
