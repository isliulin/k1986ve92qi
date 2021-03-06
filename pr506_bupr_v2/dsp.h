#ifndef _DSP_H
#define _DSP_H

extern void dq_to_abc(int32_t *abc, int32_t *dq, int32_t angle);
extern void abc_to_dq(int32_t *abc, int32_t *dq, int32_t angle);
extern void reg_init(struct pi_reg_state *s, int32_t ki, int32_t kp);
extern void reg_update(struct pi_reg_state *s, int32_t e, int32_t fs);
extern int32_t svpwm(int32_t *abc, int32_t *dq, int32_t phase);
extern int32_t sinpwm(int32_t *abc, int32_t *dq, int32_t phase);
extern int32_t get_speed(int32_t enc, int32_t *pos);
//extern int32_t mfilter(int32_t x, int32_t a);
extern int32_t lpos_filter(int32_t x, int32_t a);
extern int32_t lref_filter(int32_t x, int32_t a);
extern int32_t rfilter1(int32_t x);
extern int32_t rfilter2(int32_t x);

extern int32_t mag_current;

#define ALPHA 10
static inline int32_t mfilter(int32_t x, int32_t y)
{
	return (x*ALPHA + (1024-ALPHA)*y)>>10;	
}

#endif
