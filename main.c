#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "navigation/gps.h"
#include "navigation/ins.h"
#include "navigation/waypoint.h"
#include "autopilot/director.h"
#include "autopilot/autothrottle.h"
#include "radar/transponder.h"
#include "radar/primary.h"
#include "comms/vhf.h"
#include "comms/acars.h"
#include "engine/fadec.h"
#include "engine/eicas.h"
#include "cockpit/pfd.h"
#include "cockpit/nd.h"
#include "weather/wx_radar.h"
#include "safety/tcas.h"
#include "safety/gpws.h"
#include "safety/stall.h"
#include "utils/log.h"


static int boot(void) {
    LOGI("boot", "skyward starting");

    gps_init();
    ins_init();
    wp_clear();

    ap_disengage();
    at_disengage();

    xpdr_init();
    radar_init();

    vhf_init();
    acars_init();

    fadec_init();
    eicas_init();

    pfd_init();
    nd_init();
    wx_init();

    tcas_init();
    gpws_init();
    stall_init();

    LOGI("boot", "all subsystems initialized");
    return 0;
}


static int tick(double dt) {
    fadec_step(dt);
    eicas_scan();
    return 0;
}


int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    if (boot() != 0) {
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 10; i++) {
        tick(0.1);
        usleep(100000);
    }

    LOGI("main", "shutdown");
    return EXIT_SUCCESS;
}
