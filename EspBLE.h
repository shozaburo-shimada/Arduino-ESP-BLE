#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-fpermissive"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "bt.h"
#include "bta_api.h"

#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "esp_bt_main.h"

#include "sdkconfig.h"
#include "Arduino.h"

#pragma GCC diagnostic pop

#define LED 4
#define GATTS_TAG "GATTS_DEMO"

#define GATTS_SERVICE_UUID_TEST_ON   0x00FF
#define GATTS_CHAR_UUID_TEST_ON      0xAA01
#define GATTS_CHAR_UUID_TEST_OFF     0xBB01
#define GATTS_NUM_HANDLE_TEST_ON     8

#define TEST_DEVICE_NAME            "ESP_GATTS_ON_OFF"
/* maximum value of a characteristic */
#define GATTS_DEMO_CHAR_VAL_LEN_MAX 0xFF

#define PROFILE_ON_APP_ID 0
/* characteristic ids 0 and 1 */
#define CHAR_NUM 2
#define CHARACTERISTIC_ON_ID    0
#define CHARACTERISTIC_OFF_ID   1


typedef struct {
    uint8_t                 *prepare_buf;
    int                     prepare_len;
} prepare_type_env_t;

static prepare_type_env_t on_prepare_write_env;
static prepare_type_env_t off_prepare_write_env;


class EspGatt{
public:
    EspGatt();
    void init();
private:

};

void gatts_profile_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
void gap_event_handler(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param);
void example_write_event_env(esp_gatt_if_t gatts_if, prepare_type_env_t *prepare_write_env, esp_ble_gatts_cb_param_t *param);
void gatts_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
