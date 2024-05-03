#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <curl/curl.h>
#include "appdev.h"

int main(void)
{
    CURL* curl;
    CURLcode res;
    char poststring[200];
   
    combo c = minmax();

    sprintf(poststring, "min=%d&max=%d", c.min, c.max);

    curl = curl_easy_init();
    if (curl) {

        curl_easy_setopt(curl, CURLOPT_URL, "http://www.cc.puv.fi/~e2301477/echo.php");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, poststring);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}