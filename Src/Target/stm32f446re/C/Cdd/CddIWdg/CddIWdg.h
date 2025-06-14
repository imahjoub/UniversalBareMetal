#ifndef CDD_IWDG_2025_06_10_H
  #define CDD_IWDG_2025_06_10_H

  #include <Mcal/Mcu.h>

  // Bit fields and values
  #define IWDG_START           0x0000CCCC
  #define IWDG_WRITE_ACCESS    0x00005555
  #define IWDG_REFRESH         0x0000AAAA

  void CddIWdg_Init       (void);
  void CddIWdg_HandleReset(void);


#endif /* CDD_IWDG_2025_06_10_H */