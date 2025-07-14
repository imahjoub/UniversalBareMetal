#ifndef CDD_STAND_BY_MODE_MANAGER_2025_07_10_H
  #define CDD_STAND_BY_MODE_MANAGER_2025_07_10_H

  #include "stdint.h"
  #include "Mcal/Mcu.h"


  void     CddSBM_HandleReset(void);
  void     CddSBM_StandbyWakeupPinSetup(void);
  uint32_t CddSBM_GetWakeUpStatePin(void);

#endif /* CDD_STAND_BY_MODE_MANAGER_2025_07_10_H */




