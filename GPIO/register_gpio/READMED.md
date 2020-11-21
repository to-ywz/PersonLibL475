# GPIO 寄存器基本输入输出模式测试

> 简单的寄存器控制 GPIO 模拟 ST 公司 的 gpio 配置，仿照 ST 的 GPIO 库, 写的 gpio 寄存器,目前只能实现 基本输入输出. rcc 结构体, gpio 结构体 与 标准库一致 只适用于 stm32l475系列

### 关于为什么写这个玩意
> 不用于开发, 仅仅是为了让自己更加深入的了解 这个系列的单片机框架,更加底层的去分析思考库的构建 以及 分层的思想, 高内聚,低耦合 

### 关于使用
> 使用方法,类型名,偏移地址方法都与 ST 的 GPIO 库 寄存器配置一致
> ### GPIO 数据类型定义
> ```c
> /*
>  * IO 表示寄存器可读可写 
>  */
> typedef struct
> {
>     __IO uint32_t MODER;   
>     __IO uint32_t OTYPER;  
>     __IO uint32_t OSPEEDR; 
>     __IO uint32_t PUPDR;   
>     __O  uint32_t IDR;     
>     __IO uint32_t ODR;     
>     __I  uint32_t BSRR;    
>     __IO uint32_t LCKR;    
>     __IO uint32_t AFR[2];  
>     __IO uint32_t BRR;     
>     __IO uint32_t ASCR;    
> } GPIO_TypeDef;   
> ```
> ### 模式配置(输出)
> ```c
>   /*
>    * 特别注意 L475 Moder 寄存器 复位值为 全 1
>    */  
>    GPIOE->MODER   &=  (uint32_t)((0x01 << (7 * 2)));
>    GPIOE->OTYPER  &= ~(uint32_t)((1 << 7));
>    GPIOE->OSPEEDR |=  (uint32_t)((0x03 << (7 * 2));
>    GPIOE->PUPDR   |=  (uint32_t)((0x01 << (7 * 2));
> ```

### 关于后续
> 库会继续完善的, 寄存器配置基本模仿 ST 公司, 上层建筑会模拟 标准库 和 HAL库 加入自己的习惯,上层建筑会尽可能的具有 良好的可移植性