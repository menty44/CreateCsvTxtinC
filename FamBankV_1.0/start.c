/** 
 **	A Template for developing new terminal application
 **/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctosapi.h>
#include <emv_cl.h>
#include "debug2.h"
#include "wub_lib.h"
#include "Transaction.h"
#include "Setting.h"
#include "mainmenu.h"


/** 
 ** The main entry of the terminal application 
 **/


BYTE key;

BOOL CancelTransactionEvent(void) {
    BYTE k;

    CTOS_KBDHit(&k);

    if (k == '1') {
        return TRUE;
    }

    return FALSE;
}

void ShowMessageEvent(BYTE bKernel, EMVCL_USER_INTERFACE_REQ_DATA *stUserInterfaceRequestData) {
    DebugAddSTR("Enter Show Message Event");

    DebugAddINT("Current Kernel", bKernel);
    DebugAddHEX("Usr Req Data", (BYTE*) stUserInterfaceRequestData, sizeof (EMVCL_USER_INTERFACE_REQ_DATA));
}

EMVCL_INIT_DATA emvcl_initdat;

int main(int argc, char *argv[]) {

    BYTE bKey;
    ULONG ulRtn;

    CTOS_LCDTClearDisplay();
    CTOS_LCDSelectMode(0x04);
    CTOS_LCDTSelectFontSize(d_FONT_16x30);

    DebugInit();

    emvcl_initdat.stOnEvent.OnCancelTransaction = NULL;
    //emvcl_event.OnCancelTransaction = CancelTransactionEvent;
    //emvcl_initdat.stOnEvent.OnShowMessage = NULL;
    emvcl_initdat.stOnEvent.OnShowMessage = ShowMessageEvent;
    emvcl_initdat.bConfigFilenameLen = strlen("V3CLVpTP_config.xml");
    emvcl_initdat.pConfigFilename = "V3CLVpTP_config.xml";
    ulRtn = EMVCL_Initialize(&emvcl_initdat);
    if (ulRtn != 0) {
        ShowRtn(3, "EMVCL Init Fail ", ulRtn);
        CTOS_KBDGet(&bKey);

    }

    EMVCL_ShowVirtualLED(NULL);
    EMVCL_SetLED(0x0F, 0x08);
    {


        while (1) {
            CTOS_LCDTClearDisplay();
            CTOS_LCDTPrintXY(6, 6, "1. LOGIN");
            CTOS_LCDTPrintXY(1, 15, "              X-Exit");

            CTOS_KBDGet(&key);

            switch (key) {
                case d_KBD_ENTER:
                    mainmenu();
                    break;

                case d_KBD_CANCEL:
                    exit(0);
                    break;
            }


        }
    }
}