/*
 * Bit_Math.h
 *
 * Created: 2022-12-03 2:17:33 AM
 *  Author: Sherif
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_



/* Set a certain bit in any register */
#define SET_BIT(REG,BIT)   REG|=(1<<BIT)

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) REG&=(~(1<<BIT))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT)  REG^=(1<<BIT)

/* Read a certain bit in any register */
#define READ_BIT(REG,BIT)   REG&(1<<BIT)

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num)    REG= (REG>>num) | (REG<<(8-num)) 

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

/*Get any bit*/
#define GET_BIT(REG,BIT_NUM)    ((REG>>BIT_NUM)&1)






#endif /* BIT_MATH_H_ */