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

typedef struct {
    uint8_t                 *prepare_buf;
    int                     prepare_len;
} prepare_type_env_t;

static prepare_type_env_t on_prepare_write_env;
static prepare_type_env_t off_prepare_write_env;

typedef enum {
    ARDUINO_ESP_FAILURE = 0,
    ARDUINO_ESP_SUCCESS = 1,
} esp_ble_error_t;

class EspBLE{
public:
    EspBLE();
    void init();
    //esp_ble_error_t setServiceUUID(uint8_t *, uint8_t);
    esp_ble_error_t setServiceUUID(uint16_t);
    esp_ble_error_t setServiceUUID(uint8_t *, uint8_t);
    esp_ble_error_t setCharUUID(uint16_t);
    esp_ble_error_t setCharUUID(uint8_t *, uint8_t);
    uint8_t read();
    uint16_t write(uint8_t);
    uint16_t write(uint8_t *, uint8_t);
    uint16_t available();
private:

};

void gatts_profile_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
void gap_event_handler(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param);
void example_write_event_env(esp_gatt_if_t gatts_if, prepare_type_env_t *prepare_write_env, esp_ble_gatts_cb_param_t *param);
void gatts_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
