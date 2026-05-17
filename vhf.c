#include "vhf.h"

#include <string.h>


static vhf_radio_t radios[NUM_VHF_RADIOS];


int vhf_init(void) {
    memset(radios, 0, sizeof(radios));

    for (int i = 0; i < NUM_VHF_RADIOS; i++) {
        radios[i].active   = 121500;
        radios[i].standby  = 121500;
        radios[i].volume   = 50;
        radios[i].squelch  = 1;
    }

    return 0;
}


int vhf_set_active(int idx, int khz) {
    if (idx < 0 || idx >= NUM_VHF_RADIOS) return -1;
    if (khz < 118000 || khz > 136975) return -1;
    radios[idx].active = khz;
    return 0;
}


int vhf_set_standby(int idx, int khz) {
    if (idx < 0 || idx >= NUM_VHF_RADIOS) return -1;
    if (khz < 118000 || khz > 136975) return -1;
    radios[idx].standby = khz;
    return 0;
}


int vhf_swap(int idx) {
    if (idx < 0 || idx >= NUM_VHF_RADIOS) return -1;

    int tmp = radios[idx].active;
    radios[idx].active = radios[idx].standby;
    radios[idx].standby = tmp;

    return 0;
}


vhf_radio_t vhf_get(int idx) {
    vhf_radio_t empty = {0};
    if (idx < 0 || idx >= NUM_VHF_RADIOS) return empty;
    return radios[idx];
}
