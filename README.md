为了方便拿快递，打算把家里的小推车升级个助力功能。主控用的是自己做的F28335核心板，驱动芯片用的DRV8412，这款芯片原本是步进电机驱动芯片，内置了两个全桥。拿过来驱动直流电机的话正好控制两个轮子，不需要太多外部器件。
电机是自带编码器，用编码器获取当前电机状态，个人感觉用电流采样可能更好，不过这些都是后话，后续再做升级吧
