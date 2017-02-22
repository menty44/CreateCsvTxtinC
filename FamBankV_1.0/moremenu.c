
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/** These two files are necessary for calling CTOS API **/
#include <ctosapi.h>

#include "gsm.h"
#include "Transaction.h"

void moremenu(void) {

    BYTE key;
    while (1) {
        ClearScreen(4, 14);
        ShowTitle("   MAIN MENU  ");
        CTOS_LCDTPrintXY(1, 15, "       X. PREVIOUS MENU");
        CTOS_LCDTPrintXY(3, 4, "1. NETWORK");
        CTOS_LCDTPrintXY(3, 5, "2. SHUTDOWN");
        CTOS_LCDTPrintXY(3, 6, "3. RESTART");


        CTOS_KBDGet(&key);

        switch (key) {
            case '1':
                gsmmain();
                break;

            case '2':
                CTOS_PowerOff();
                break;

            case '3':
                CTOS_SystemReset();
                break;
            case d_KBD_CANCEL:
                return;
                break;


        }


    }


}
