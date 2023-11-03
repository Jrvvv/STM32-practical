#include <stdint.h>

#define STACK_INIT (0x20020000U)  // end of DTCM

int  main(void);
void Default_handler(void);

void Reset_handler(void);

__attribute__((weak, alias("Default_handler"))) void NMI_handler(void);
__attribute__((weak, alias("Default_handler"))) void HardFault_handler(void);
__attribute__((weak, alias("Default_handler"))) void MemManage_handler(void);
__attribute__((weak, alias("Default_handler"))) void BusFault_handler(void);
__attribute__((weak, alias("Default_handler"))) void UsageFault_handler(void);
__attribute__((weak, alias("Default_handler"))) void SVCall_handler(void);
__attribute__((weak, alias("Default_handler"))) void PendSV_handler(void);
__attribute__((weak, alias("Default_handler"))) void SysTick_handler(void);

__attribute__((section(".isr_vectors"))) uint32_t isr_vectors[] = {
                            STACK_INIT,
                            (uint32_t)&Reset_handler,
                            (uint32_t)&NMI_handler,
                            (uint32_t)&HardFault_handler,
                            (uint32_t)&MemManage_handler,
                            (uint32_t)&BusFault_handler,
                            (uint32_t)&UsageFault_handler,
                            0,
                            0,
                            0,
                            0,
                            (uint32_t)&SVCall_handler,
                            0,
                            0,
                            (uint32_t)&PendSV_handler,
                            (uint32_t)&SysTick_handler
                          };

void Default_handler(void) {
  while(1);
}

void Reset_handler(void){
  main();
  while(1);
}
