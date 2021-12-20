#ifndef G4NIO_H
#define G4NIO_H

typedef struct {
	float ain1;           /* analog input 1 */
	float ain2;           /* analog input 2 */
	float ain3;           /* analog input 3 */
	int din1;             /* digital input 1, value 0 or 1 */
	int din2;             /* digital input 2, value 0 or 1 */
	int din3;             /* digital input 3, value 0 or 1 */
	float inputVoltage;   /* reads the input voltage the device is receiving*/
	int contact;          /* 0 - contact off, 1 - contact on */
	int relay;            /* 0 - relay off, 1 - replay on */
	int panicButton;      /* 0 - panic button off, 1 - panic button on */
	double temperature;   /* celsius grades	*/
} IOInfo;

/**
 * Reads device IO info
 * if Invalid command return NULL
 * QDIOINF
 */
IOInfo GetIOInfo(char* command);

#endif

