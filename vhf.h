#ifndef SKYWARD_COMMS_VHF_H
#define SKYWARD_COMMS_VHF_H


#define NUM_VHF_RADIOS  3


typedef struct {
    int active;
    int standby;
    int volume;
    int squelch;
} vhf_radio_t;


int          vhf_init(void);
int          vhf_set_active(int idx, int khz);
int          vhf_set_standby(int idx, int khz);
int          vhf_swap(int idx);
vhf_radio_t  vhf_get(int idx);


#endif
