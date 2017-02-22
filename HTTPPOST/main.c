/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2015, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/ 
/* <DESC>
 * An example source code that issues a HTTP POST and we provide the actual
 * data through a read callback.
 * </DESC>
 */ 
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int main(void)
{
 int validation=0;
    BYTE key;
    BYTE sBuf[128];
    int amount;
    {
        CURL *curl;
        CURLcode res;
       

        curl = curl_easy_init();
        if (curl) {
             char* jsonObj = "{ \"pin\" : \"4444\" , \"amount\" : \amount, \"card_number\" : \"72828276766262\" }"; 
            curl_easy_setopt(curl, CURLOPT_URL, "http://196.216.73.150:9990/posdemo/request/card");
            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, "Accept: application/json");
            headers = curl_slist_append(headers, "Content-Type: application/json");
            headers = curl_slist_append(headers, "charsets: utf-8");
            /* example.com is redirected, so we tell libcurl to follow redirection */
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

            /* Perform the request, res will get the return code */
             curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonObj);
            res = curl_easy_perform(curl);
            //CTOS_LCDTPrintXY(4, 4, " Response is");
            /* Check for errors */
            if (res == CURLE_OK)
            {
//                ClearScreen(4, 14);
//                CTOS_LCDTPrintXY(4, 6, " Successful");
//                CTOS_KBDGet(&key);
                validation=1;
                return 1;
            }
            else
            {
//                ClearScreen(4, 14);
//                CTOS_LCDTPrintXY(4, 6, " Failed");
//                CTOS_KBDGet(&key);
                 validation=0;
                return 0;
            }
               
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
            sprintf(sBuf, "%s     ", "ROAM");

            /* always cleanup */
            curl_easy_cleanup(curl);
        }
        
        curl_global_cleanup();

        
        return;
    }
}