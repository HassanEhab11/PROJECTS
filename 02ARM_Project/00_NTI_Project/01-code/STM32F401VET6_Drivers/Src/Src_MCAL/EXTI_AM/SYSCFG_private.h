/*
   Author : Mohamed Helmi
   Date   : 17-5-2022
   Version: V1
*/

#ifndef SYSCFG_PRIVATE_H
#define SYSCFG_PRIVATE_H 


typedef struct
{
	volatile u32 MEMRMP;
	volatile u32 PMC;
	volatile u32 EXTICR[4];
	volatile u32 CMPCR;	
}SYSCFG_t;

#define SYSCFG ((volatile SYSCFG_t*)(0x40013800))



#endif
