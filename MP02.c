// *github.com/AminSpek/ProjectMicroP //
// Copyright (c) 2019 AminSpek //
// CONTRIBUTION //
// Later //

#include <MKL25Z4.H>

void msdelay(unsigned int value){   // Delay function
 
unsigned int x,y;
for(x=0;x<value;x++)
for(y=0;y<3275;y++);
}

void segment () {
 		 GPIOC->PSOR = 0x01000; //6
		 GPIOC->PSOR = 0x02000; //7
		 GPIOC->PSOR = 0x10000; //9
		 GPIOC->PSOR = 0x20000; //10
		 
		 GPIOB->PSOR = 0x00100; //1
		 GPIOB->PSOR = 0x00200; //2
		 GPIOB->PSOR = 0x00400; //4
		 GPIOB->PSOR = 0x00800; //DP
}
void segment0 () {
 		 GPIOC->PSOR = 0x01000; //6
		 GPIOC->PSOR = 0x02000; //7
		 GPIOC->PSOR = 0x10000; //9
		 GPIOC->PCOR = 0x20000; //10
		 
		 GPIOB->PSOR = 0x00100; //1
		 GPIOB->PSOR = 0x00200; //2
		 GPIOB->PSOR = 0x00400; //4
		 GPIOB->PSOR = 0x00800; //DP
}
void segment1 () {
 		 GPIOC->PSOR = 0x01000; //6
		 GPIOC->PCOR = 0x02000; //7
		 GPIOC->PCOR = 0x10000; //9
		 GPIOC->PCOR = 0x20000; //10
		 
		 GPIOB->PCOR = 0x00100; //1
		 GPIOB->PCOR = 0x00200; //2
		 GPIOB->PSOR = 0x00400; //4
		 GPIOB->PCOR = 0x00800; //DP
}
void segment2 () {
 		 GPIOC->PSOR = 0x01000; //6
		 GPIOC->PSOR = 0x02000; //7
		 GPIOC->PCOR = 0x10000; //9
		 GPIOC->PSOR = 0x20000; //10
		 
		 GPIOB->PSOR = 0x00100; //1
		 GPIOB->PSOR = 0x00200; //2
		 GPIOB->PCOR = 0x00400; //4
		 GPIOB->PCOR = 0x00800; //DP
}
void segment3 () {
 		 GPIOC->PSOR = 0x01000; //6
		 GPIOC->PSOR = 0x02000; //7
		 GPIOC->PCOR = 0x10000; //9
		 GPIOC->PSOR = 0x20000; //10
		 
		 GPIOB->PCOR = 0x00100; //1
		 GPIOB->PSOR = 0x00200; //2
		 GPIOB->PSOR = 0x00400; //4
		 GPIOB->PCOR = 0x00800; //DP
}

void segmentoff () {
	GPIOC->PCOR = 0xFFFFF;  // All LED will turn OFF
	GPIOB->PCOR = 0xFFFFF;  // All LED will turn OFF
}
int main (void) {
	SIM_SCGC5 |= (SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTC_MASK |   SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTE_MASK ); //ENABLE ALL PORT AT ONCE!
  PORTD->PCR[0] = 0x0100;   // Set Pin D0 as (GPIO) LED 1 (Output)
  PORTD->PCR[2] = 0x0100;   // Set Pin D2 as (GPIO) LED 2 (Output)	    
  PORTD->PCR[3] = 0x0103;   // Set Pin D3 as (GPIO with PE & S) PB1   (Input)
  PORTE->PCR[0] = 0x0100;   // Set Pin E0 as (GPIO) LED 3 (Output)
	PORTE->PCR[1] = 0x0100;   // Set Pin E1 as (GPIO) LED 4 (Output)
	PORTE->PCR[2] = 0x0100;   // Set Pin E2 as (GPIO) LED 5 (Output)
	/// SEGMENT PORT ///
	PORTC->PCR[12] = 0x0100;   // Set Pin C12 as (GPIO) SEGMENT 6 (Output)
	PORTC->PCR[13] = 0x0100;   // Set Pin C13 as (GPIO) SEGMENT 7 (Output)
	PORTC->PCR[16] = 0x0100;   // Set Pin C16 as (GPIO) SEGMENT 9 (Output)
	PORTC->PCR[17] = 0x0100;   // Set Pin C17 as (GPIO) SEGMENT 10 (Output)
	
	PORTB->PCR[11] = 0x0100;   // Set Pin B11 as (GPIO) LED 5 (Output)
	PORTB->PCR[10] = 0x0100;   // Set Pin B10 as (GPIO) LED 4 (Output)
	PORTB->PCR[9] = 0x0100;   // Set Pin B9 as (GPIO) LED 2 (Output)
	PORTB->PCR[8] = 0x0100;   // Set Pin B8 as (GPIO) LED 1 (Output)
	

 FPTD->PDOR = 0x00005; 		  // Set the output for Port D (Port Data Output Register)	
 FPTD->PDDR = 0x00005;      // (Port Data Direction Register)
 FPTE->PDOR = 0x00007; 		  // Set the output for Port E (Port Data Output Register)
 FPTE->PDDR = 0x00007;      // (Port Data Direction Register)
 // SEGMENT //
 FPTC->PDOR = 0xFFFFF; 		  // Set the output for Port C (Port Data Output Register)
 FPTC->PDDR = 0xFFFFF;      // (Port Data Direction Register)
 FPTB->PDOR = 0xFFFFF; 		  // Set the output for Port B (Port Data Output Register)
 FPTB->PDDR = 0xFFFFF;      // (Port Data Direction Register)

	
 while(1) {
	int PB;                   //Initialization for PB1
	 PB = GPIOD->PDIR;        //(Port Data Input Register)
	 PB &= 0x00008;

	 /*
	 PORTD D0 LED1 = Green1
	 PORTD D2 LED2 = Red1
	 PORTE E0 LED3 = Green2
	 PORTE E1 LED4 = Yellow2
	 PORTE E2 LED5 = Red5
	 */
	 
	 if (PB==0x00){             // When PB1 is pressed
		 
		 GPIOE->PCOR = 0x00001;   //LED 3 will turn OFF HIJAU2
		 msdelay(1000);
		 GPIOE->PSOR = 0x00001;   //LED 3 will turn ON
		 msdelay(1000);
		 GPIOE->PCOR = 0x00001;   //LED 3 will turn OFF
		 msdelay(1000);
		 GPIOE->PSOR = 0x00001;   //LED 3 will turn ON
		 msdelay(1000);
		 GPIOE->PCOR = 0x00001;   //LED 3 will turn OFF
		 msdelay(1000);
		 GPIOE->PSOR = 0x00001;   //LED 3 will turn ON
		 msdelay(1000);
		 GPIOE->PCOR = 0x00001;   //LED 3 will turn OFF
		 msdelay(1000);
		 
		 GPIOE->PSOR = 0x00002;   //LED 4 will turn ON KUNING2
		 msdelay(3000);
		 GPIOE->PCOR = 0x00002;   //LED 4 will turn OFF
		 
		 GPIOE->PSOR = 0x00004;   //LED 5 will turn ON MERAH2
		 msdelay(1000);
		 GPIOD->PCOR = 0x00004;   //LED 5 will turn OFF

		 GPIOD->PSOR = 0x00001;   //LED 1 will turn ON HIJAU1
		 msdelay(5000);
		 GPIOD->PCOR = 0x00001;   //LED 1 will turn OFF
		 segment3();
		 msdelay(1000);
		 GPIOD->PSOR = 0x00001;   //LED 1 will turn ON
		 msdelay(1000);
		 GPIOD->PCOR = 0x00001;   //LED 1 will turn OFF
		 segment2();
		 msdelay(1000);
		 GPIOD->PSOR = 0x00001;   //LED 1 will turn ON
		 msdelay(1000);
		 GPIOD->PCOR = 0x00001;   //LED 1 will turn OFF
		 segment1();
		 msdelay(1000);
		 GPIOD->PSOR = 0x00001;   //LED 1 will turn ON
		 msdelay(1000);
		 GPIOD->PCOR = 0x00001;   //LED 1 will turn OFF
		 msdelay(1000);
		 
		 segment0();
		 msdelay(1000);
		 GPIOD->PSOR = 0x00004;   //LED 2 will turn ON MERAH1
		 msdelay(500);
		 GPIOE->PCOR = 0x00004;   //LED 3 will turn OFF MERAH2
		 GPIOE->PSOR = 0x00001;   //LED 3 will turn ON HIJAU2
		 segmentoff();
		 msdelay(1000);
		 
	 }		
	 else{                     // When there is no pushbutton pressed
		 GPIOD->PCOR = 0x00005;  // All LED will turn OFF
		 GPIOE->PCOR = 0x0000F;  // All LED will turn OFF
		 GPIOE->PSOR = 0x00001;  // LED 2 ON MERAH1
		 GPIOD->PSOR = 0x00004;  // LED 3 ON HIJAU2
		 // SEGMENT //
		segmentoff();
		 
		} 
	}
 }
