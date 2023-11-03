ENTRY(Reset_handler)

MEMORY
{
  ROM (rx) : ORIGIN = 0x08000000, LENGTH = 1M
  RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS
{
  .isr_vectors :
  {
    KEEP(*.o (.isr_vectors));
  } > ROM

  .text :
  {
    *.o (.text)
    *.o (.rodata)
  } > ROM

  .data :
  {
    *.o (.data)
  } > RAM AT > ROM

  .bss :
  {
    *.o (.bss)
  } > RAM
}

