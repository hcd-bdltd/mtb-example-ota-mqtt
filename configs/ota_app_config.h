/******************************************************************************
* File Name:   ota_app_config.h
*
* Description: This file contains the OTA application level configuration macros.
*
* Related Document: See README.md
*
*
*******************************************************************************
* Copyright 2020-2024, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

#ifndef SOURCE_OTA_APP_CONFIG_H_
#define SOURCE_OTA_APP_CONFIG_H_

#include "cy_ota_config.h"
#include "cy_ota_api.h"

/***********************************************
 * Connection configuration
 **********************************************/
/* Name of the Wi-Fi network */
#define WIFI_SSID           "WIFI_SSID"

/* Password for the Wi-Fi network */
#define WIFI_PASSWORD       "WIFI_PASSWORD"

/* Security type of the Wi-Fi access point. See 'cy_wcm_security_t' structure
 * in "cy_wcm.h" for more details.
 */
#define WIFI_SECURITY       (CY_WCM_SECURITY_WPA2_AES_PSK)

/* MQTT Broker endpoint */
#define MQTT_BROKER_URL     "192.168.1.56"

/* Macro to enable/disable TLS */
#define ENABLE_TLS          (true)

#if (ENABLE_TLS == true)
/* MQTT Server Port */
#define MQTT_SERVER_PORT    (8884)
#else
/* MQTT Server Port */
#define MQTT_SERVER_PORT    (1883)
#endif

/* MQTT identifier - less than 17 characters*/
#define OTA_MQTT_ID         "CY_IOT_DEVICE"

/* Number of MQTT topic filters */
#define MQTT_TOPIC_FILTER_NUM   (1)

/* MQTT topics */
const char * my_topics[ MQTT_TOPIC_FILTER_NUM ] =
{
        COMPANY_TOPIC_PREPEND "/" CY_TARGET_BOARD_STRING "/" PUBLISHER_DIRECT_TOPIC
};

/*
 * AWS IoT MQTT Mode - This parameter must be 1 when using the AWS IoT MQTT
 *                     server, 0 otherwise.
 */
#define AWS_IOT_MQTT_MODE   (0)

/**********************************************
 * Certificates and Keys - TLS Mode only
 *********************************************/
/* Root CA Certificate -
   Must include the PEM header and footer:

        "-----BEGIN CERTIFICATE-----\n" \
        ".........base64 data.......\n" \
        "-----END CERTIFICATE-------\n"
*/
#define ROOT_CA_CERTIFICATE "-----BEGIN CERTIFICATE-----\n"\
"MIIDrzCCApegAwIBAgIUcVg9stKZvLrC+BLIpXccoC6doxwwDQYJKoZIhvcNAQEL\n"\
"BQAwZzELMAkGA1UEBhMCSU4xEjAQBgNVBAgMCUthcm5hdGFrYTESMBAGA1UEBwwJ\n"\
"QmVuZ2FsdXJ1MQswCQYDVQQKDAJDWTEUMBIGA1UECwwLRW5naW5lZXJpbmcxDTAL\n"\
"BgNVBAMMBG15Q0EwHhcNMjQwOTMwMDMyMjQyWhcNMzQwOTI4MDMyMjQyWjBnMQsw\n"\
"CQYDVQQGEwJJTjESMBAGA1UECAwJS2FybmF0YWthMRIwEAYDVQQHDAlCZW5nYWx1\n"\
"cnUxCzAJBgNVBAoMAkNZMRQwEgYDVQQLDAtFbmdpbmVlcmluZzENMAsGA1UEAwwE\n"\
"bXlDQTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBANBwG+CDMA7VapPv\n"\
"7miLbJ2E2GcCn402e3kPRc82MiFQtd6jtCWDYDx2rPgK6gJ0FVcLQ+PwFoIJUGUA\n"\
"8PTvvVxj4oCcbX17ukXbCvwSwa04zY52pb3uvqBzIoGVt7R/0Vq0kr7pz0DdDDDt\n"\
"9bhMNKpi6hiqzTa7Vp0fXB6yUYpivNcjyEPi8mrkxc/GLEX1ZnSGTw+/CiQBIVQD\n"\
"3mMX6Ze4o8Otxa0jFdpyruU41tWDB9sMhHkhi0xS+D5Cpb5Dok13TeOEXLYjRxwt\n"\
"JYvRtrUTtEbYpsc07SAHcXa2hPycIhovbNRzLvi6mLruVjrAObNaj6/HknF0y+DF\n"\
"QemxEQsCAwEAAaNTMFEwHQYDVR0OBBYEFDjxkivosG+i7uQgtivmkbxwjhoNMB8G\n"\
"A1UdIwQYMBaAFDjxkivosG+i7uQgtivmkbxwjhoNMA8GA1UdEwEB/wQFMAMBAf8w\n"\
"DQYJKoZIhvcNAQELBQADggEBAF2DuIKn+sE7gdUkf/P+Yf4OImOFpkcGHMzjqxK8\n"\
"t0qIabwwSs2JZk6PyVlew1iazFACH/YP1Sz+xgMregFignCbl7driGUXV9QQb3Lq\n"\
"IkvrGU9A+GeI+NrJlUOES1jQVP6H5DQyIjwN7jv8lDfYQvgpqFvsJB2cr2XEaUFv\n"\
"KjM0vZhU/youOAMc8v+/X5m0rSTaZZFskCsXvNHmpvrkc2CtJfGkjJdVTxRcIoku\n"\
"B1rcx71Fdg8GwhTNCDkyZtNsL7iBuP2Cp9B5q8qgQkvSZjh8q3yqofWzgcfGMExv\n"\
"mF2Jol14k4VoOceNxwayU/wY0ccu4s4nskbgYu31aTaDgos=\n"\
"-----END CERTIFICATE-----\n"

/* Client Certificate
   Must include the PEM header and footer:

        "-----BEGIN CERTIFICATE-----\n" \
        ".........base64 data.......\n" \
        "-----END CERTIFICATE-------\n"
*/
#define CLIENT_CERTIFICATE "-----BEGIN CERTIFICATE-----\n"\
"MIIDqjCCApKgAwIBAgIUC975JNGflZQvirR/AcWYp4lGm2EwDQYJKoZIhvcNAQEL\n"\
"BQAwZzELMAkGA1UEBhMCSU4xEjAQBgNVBAgMCUthcm5hdGFrYTESMBAGA1UEBwwJ\n"\
"QmVuZ2FsdXJ1MQswCQYDVQQKDAJDWTEUMBIGA1UECwwLRW5naW5lZXJpbmcxDTAL\n"\
"BgNVBAMMBG15Q0EwHhcNMjQwOTMwMDMyMjQyWhcNMzQwOTI4MDMyMjQyWjBzMQsw\n"\
"CQYDVQQGEwJJTjESMBAGA1UECAwJS2FybmF0YWthMRIwEAYDVQQHDAlCZW5nYWx1\n"\
"cnUxCzAJBgNVBAoMAkNZMRQwEgYDVQQLDAtFbmdpbmVlcmluZzEZMBcGA1UEAwwQ\n"\
"bW9zcXVpdHRvX2NsaWVudDCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEB\n"\
"ANdS0bcvxfczbaD5S9zefAAMtD/OaWaEqHPkxegvA4eYblvFHlmV+mrjRoS1Dl4J\n"\
"fsmf5h+JkRucg1dmdJonfXuSE73p5eVLKd9yB0XF5LGM+5Z4asud1x4q79id6LyQ\n"\
"TtMb7LjYI21OJ7mtwxsbdeOOJJ6enE3vr85Wm6rn+qgWd/M7N7wX/RJYEnpY8xnQ\n"\
"2B3ZJKnBlPHrjrQ8mDLdVzlIf+bi1XjVuux8DPh1pc3dRCpwDY1n8WpdRCABvAip\n"\
"VzuGNxzTxXwArDyiWvq2KZ7h1NylunRQVJ3WtQ7bP5cBUYaQv92prFdSGPAtobBW\n"\
"dwqezTxm/6106NWEH1UI3HMCAwEAAaNCMEAwHQYDVR0OBBYEFMbQQmDVGTHGm5ys\n"\
"iLqUa3qWt0YjMB8GA1UdIwQYMBaAFDjxkivosG+i7uQgtivmkbxwjhoNMA0GCSqG\n"\
"SIb3DQEBCwUAA4IBAQCkQYDTlg4dx6ooMAnUjYrLlJfYsM4YX8aUtc9KHZcR/h1G\n"\
"5KXdaQvQmfDA/5cvQ4smIvsivfz6FPfnagZoMNvV/M2Aj/FIRpFxoBm0jY19Qd8W\n"\
"nn/nQiOyfeZ0bLeSDDIAN8S4R8U4OgAHrzbGUUBohVLWyagGTp4ZGpFJT1J0TBex\n"\
"1z37fhCqsHS3qjLD7c7NAD443xfrkO2ne4VinXAjkkWcTa/uMiq1TxI9LwGZlgyC\n"\
"xs3niyGl2aXGNqHwsQzg0CwFcB2APLBi3pVOz6mABexTnZscAx8SpAn7gTTCibPm\n"\
"5iRXgklRUjb+RAK2+/Cnwi5siLge1ezPx+/xBfYw\n"\
"-----END CERTIFICATE-----\n"

/* Private Key
   Must include the PEM header and footer:

        "-----BEGIN RSA PRIVATE KEY-----\n" \
        "...........base64 data.........\n" \
        "-----END RSA PRIVATE KEY-------\n"
*/
#define CLIENT_KEY "-----BEGIN PRIVATE KEY-----\n"\
"MIIEvAIBADANBgkqhkiG9w0BAQEFAASCBKYwggSiAgEAAoIBAQDXUtG3L8X3M22g\n"\
"+Uvc3nwADLQ/zmlmhKhz5MXoLwOHmG5bxR5Zlfpq40aEtQ5eCX7Jn+YfiZEbnINX\n"\
"ZnSaJ317khO96eXlSynfcgdFxeSxjPuWeGrLndceKu/Ynei8kE7TG+y42CNtTie5\n"\
"rcMbG3XjjiSenpxN76/OVpuq5/qoFnfzOze8F/0SWBJ6WPMZ0Ngd2SSpwZTx6460\n"\
"PJgy3Vc5SH/m4tV41brsfAz4daXN3UQqcA2NZ/FqXUQgAbwIqVc7hjcc08V8AKw8\n"\
"olr6time4dTcpbp0UFSd1rUO2z+XAVGGkL/dqaxXUhjwLaGwVncKns08Zv+tdOjV\n"\
"hB9VCNxzAgMBAAECggEAQO9k902c8fO8d/M2gaFG2+z43tUszBHtiyXO2Tp0YgwC\n"\
"HALSKEomft2Tgqnnb0yFw+BI0fH2pNEKeu0W9PY7zWw8L+W9wuxr8Eq/DrejRDg0\n"\
"FyixbD5phVuFgVn9uf/7BYdCWGw2ItyS9lgEosQhRUK0oHFMyeQirKNJxry2xsGR\n"\
"wyygiEzHIPndKF9tBQC/wBaJ3nfoQfhUi8044b3BjS2PkKbK8IOA+2bh4cGs4BMN\n"\
"ubuEhoy8RWfIgLxXhtYZPio5v9+9G1DdiIFKKi2Yw+rApIOT4sr8KbWZNBjy1w0k\n"\
"m/+gGKyAa7tO7kH2gpaS/15086cIIIHmDB4SlUTIYQKBgQD/rsGEkdKhB+snsxVO\n"\
"4KB2UqCOaeQAComsJwEHp8BQEb6xup4R9qJU0m20lgMppuIMh4htjTYtvnBuLrGF\n"\
"4hk+vpDbQ7gS3S5XZjnJQYNtMX9c5jee0PHvL9ByNWzdBlkL8Qs6v+LWhkN+eGdA\n"\
"Cd/NrsTnEegFMxrRYMtnbFKLpwKBgQDXlz0wH0UbndDiqrVmt73D9y3jb3UK9SgV\n"\
"K3ETsQFRafjT1/Di6k9bi+MrdLDHq6vRqVAz8n/2hcqQTSn4qUMNFhFjzMH/4iae\n"\
"FMC3tUN8HBlNvu/xLIcvbu8q1rWJKh9xPwubSac3UpbH8B8FULOffU1vLgT3KwCh\n"\
"0WkZ5JNSVQKBgDCdXMRFKcReihLRVTLbOQdmbIrHjYeIeWbXP7Xh6ooO5bBLaHTH\n"\
"7VOtcxiMEWvhBEgXmRQjbnLCLAR3Ml/ffqdUepyGQsCrd308va4Lm96uM6ZJS7gR\n"\
"yH6PG9YrXFimNVY07cqs44egncK1SASAHCKyoVPCLtiWP/ohqmsuyH8vAoGAYgYL\n"\
"9iNhoqrg3Q7NKAUHLWDn5m85AmBxdx6nbVKfzMqoLnoStrnelztFcO6/qimuF8gq\n"\
"BVSPRiGS9oV/PeaH7B1Kjtv8oUHMWTgKX/z00CteffEA2+FpHfIMoKe7JsCWR0Fp\n"\
"H5QfiZHtqL7O+/WzliK84H5GF7Pft7OlW/aH3XkCgYB+rV1nHtoIFFdqwhEwbzew\n"\
"2K/NBzqGsoX4b3yO8dfDoyTRFi33CVD/zP+E8HaOWcQcmn4SibRVPDR04KnXwWTv\n"\
"7KbGsotfP+8GN0J85Lh8IWNO6Wh3fgdklzKFrgEYTSJb7F8/Pswr4xK7jEtjuizP\n"\
"iEGaynUn21L8KpftAuqKfw==\n"\
"-----END PRIVATE KEY-----\n"

#endif /* SOURCE_OTA_APP_CONFIG_H_ */
