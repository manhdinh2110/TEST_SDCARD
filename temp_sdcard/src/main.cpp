/*Get data from Textarea */
/*    const char *new_option = lv_textarea_get_text(objects.edit_name);        //Get the text entered by user
          //  String option = String(new_option);  
         lv_label_set_text_fmt(objects.user1_label, "%s", new_option); //Update label0 */

/*
 if(n==1)
        {
        lv_obj_set_pos(objects.button_img2, 285, 148);
            const char *new_option = lv_textarea_get_text(objects.edit_name);        //Get the text entered by user
          //  String option = String(new_option);  
         lv_label_set_text_fmt(objects.user1_label, "%s", new_option); //Update label0 */
        
//         }
//         else if(n==2)
//         {
//             lv_obj_clear_flag(objects.button_img3, LV_OBJ_FLAG_HIDDEN);
//              const char *new_option = lv_textarea_get_text(objects.edit_name);        //Get the text entered by user
//                    lv_obj_set_pos(objects.user2_label, 314, 263);
//              lv_label_set_text_fmt(objects.user2_label, "%s", new_option); //Update label0 
//              */

//         }



// */
//  */


/*Thay doi gia tri cho thanh slider */

/*Slider for time
 */
/*


void set_slider_value(void *slider, int32_t value) {
    lv_slider_set_value((lv_obj_t *)slider, value, LV_ANIM_ON);  // Cập nhật giá trị slider
}
       lv_anim_t a; 
        lv_anim_init(&a); 
        lv_anim_set_var(&a, objects.slider_temp);
        lv_anim_set_values(&a, 0, 100);
        a.time = 5000;
        //lv_anim_set_duration(&a, 5000);
    lv_anim_set_exec_cb(&a, set_slider_value);

        lv_anim_set_path_cb(&a, lv_anim_path_linear);
            lv_anim_set_ready_cb(&a, anim_ready_cb);

        lv_anim_start(&a);
       lv_anim_t a_time; 
        lv_anim_init(&a_time); 
        lv_anim_set_var(&a_time, objects.time_slider);
        lv_anim_set_values(&a_time, 0, 100);
        a_time.time = 5000;
        //lv_anim_set_duration(&a, 5000);
    lv_anim_set_exec_cb(&a_time, set_slider_value);

        lv_anim_set_path_cb(&a_time, lv_anim_path_linear);
        lv_anim_start(&a_time);
        */
/**
// Hàm callback khi animation kết thúc
void anim_ready_cb(lv_anim_t *a) {
    //lv_obj_t *slider = (lv_obj_t *)lv_anim_get_var(a);  // Lấy đối tượng được gắn vào animation
 //   lv_label_set_text(objects.temp_label_user1, "DONE\n");
    lv_anim_t anim;
    lv_anim_init(&anim);
    lv_anim_set_var(&anim, objects.message_box_ack);  // Gắn Message Box vào animation
    lv_anim_set_exec_cb(&anim, (lv_anim_exec_xcb_t)lv_obj_set_y);  // Thay đổi vị trí Y
    lv_anim_set_values(&anim, -234, 100);  // Từ Y = -150 đến Y = 200
    anim.time=2000;
   // lv_anim_set_duration(&anim, 2000);    // Thời gian animation: 2 giây
    lv_anim_set_path_cb(&anim, lv_anim_path_ease_in_out);  // Hiệu ứng mượt
    
    lv_anim_start(&anim);  // Bắt đầu animation

}

 */

/**
   lv_obj_set_pos(objects.message_box_ack, 127, -234);

 */




/*******************************************************************************
 * LVGL Widgets
 * This is a widgets demo for LVGL - Light and Versatile Graphics Library
 * import from: https://github.com/lvgl/lv_demos.git
 *
 * Dependent libraries:
 * LVGL: https://github.com/lvgl/lvgl.git

 * Touch libraries:
 * FT6X36: https://github.com/strange-v/FT6X36.git
 * GT911: https://github.com/TAMCTec/gt911-arduino.git
 * XPT2046: https://github.com/PaulStoffregen/XPT2046_Touchscreen.git
 *
 * LVGL Configuration file:
 * Copy your_arduino_path/libraries/lvgl/lv_conf_template.h
 * to your_arduino_path/libraries/lv_conf.h
 * Then find and set:
 * #define LV_COLOR_DEPTH     16
 * #define LV_TICK_CUSTOM     1
 *
 * For SPI display set color swap can be faster, parallel screen don't set!
 * #define LV_COLOR_16_SWAP   1
 *
 * Optional: Show CPU usage and FPS count
 * #define LV_USE_PERF_MONITOR 1
 ******************************************************************************/
//#include "lv_demo_widgets.h"
#include <lvgl.h>
#include <demos/lv_demos.h>
#include "ui.h"
#include "actions.h"
 #include "screens.h"
 #include "stdio.h"
#include "SD.h"
#include "SPI.h"
//#include "dscardd.h"
#include <WiFi.h>
#include "Arduino.h"
#include <Arduino_GFX_Library.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include <SD_MMC.h>

#define TFT_BL 2
//#define GFX_BL DF_GFX_BL // default backlight pin, you may replace DF_GFX_BL to actual backlight pin

/* More dev device declaration: https://github.com/moononournation/Arduino_GFX/wiki/Dev-Device-Declaration */
#if defined(DISPLAY_DEV_KIT)
Arduino_GFX *gfx = create_default_Arduino_GFX();
#else /* !defined(DISPLAY_DEV_KIT) */

/* More data bus class: https://github.com/moononournation/Arduino_GFX/wiki/Data-Bus-Class */
//Arduino_DataBus *bus = create_default_Arduino_DataBus();

/* More display class: https://github.com/moononournation/Arduino_GFX/wiki/Display-Class */
//Arduino_GFX *gfx = new Arduino_ILI9341(bus, DF_GFX_RST, 0 /* rotation */, false /* IPS */);



Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
    41 /* DE */, 40 /* VSYNC */, 39 /* HSYNC */, 42 /* PCLK */,
    14 /* R0 */, 21 /* R1 */, 47 /* R2 */, 48 /* R3 */, 45 /* R4 */,
    9 /* G0 */, 46 /* G1 */, 3 /* G2 */, 8 /* G3 */, 16 /* G4 */, 1 /* G5 */,
    15 /* B0 */, 7 /* B1 */, 6 /* B2 */, 5 /* B3 */, 4 /* B4 */,
    0 /* hsync_polarity */, 180 /* hsync_front_porch */, 30 /* hsync_pulse_width */, 16 /* hsync_back_porch */,
    0 /* vsync_polarity */, 12 /* vsync_front_porch */, 13 /* vsync_pulse_width */, 10 /* vsync_back_porch */);
Arduino_RGB_Display *gfx = new Arduino_RGB_Display(
    800 /* width */, 480 /* height */, rgbpanel, 0 /* rotation */, true /* auto_flush */);

#endif /* !defined(DISPLAY_DEV_KIT) */
/*******************************************************************************
 * End of Arduino_GFX setting
 ******************************************************************************/

/*******************************************************************************
 * Please config the touch panel in touch.h
 ******************************************************************************/
#include "touch.h"
#include "screens.h"
#include <driver/i2s.h>
#include <vector>
#include "time.h"
/* Change to your screen resolution */
static uint32_t screenWidth;
static uint32_t screenHeight;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t *disp_draw_buf;
static lv_disp_drv_t disp_drv;
lv_obj_t * label_time;

TaskHandle_t ntScanTaskHandler, ntConnectTaskHandler;

std::vector<String> foundWifiList;
const long gmtOffset_sec = 7 * 60 * 60;  // Set your timezone here
const int daylightOffset_sec = 0;
const char *ntpServer = "pool.ntp.org";

//File myFile;
// void Read_Data_User(String filename);
//void Write_Data_User(String filename,String data,bool isHeader = false,bool overwrite = 0);
/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

#if (LV_COLOR_16_SWAP != 0)
  gfx->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#else
  gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#endif

  lv_disp_flush_ready(disp);
}

void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  if (touch_has_signal())
  {
    if (touch_touched())
    {
      data->state = LV_INDEV_STATE_PR;

      /*Set the coordinates*/
      data->point.x = touch_last_x;
      data->point.y = touch_last_y;
      Serial.print( "Data x " );
      Serial.println( data->point.x );
      Serial.print( "Data y " );
      Serial.println( data->point.y );
    }
    else if (touch_released())
    {
      data->state = LV_INDEV_STATE_REL;
    }
  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
}





// extern void Write_Data_User(String filename,String data,bool isHeader = false,bool overwrite = false)
// {
//       if (overwrite) {
//     // Ghi đè toàn bộ nội dung file
//     myFile = SD.open(filename, FILE_WRITE);
//   } else {
//     // Thêm dữ liệu vào cuối file
//     myFile = SD.open(filename, FILE_APPEND);
//   }
// if (myFile) {
//     if(isHeader)
//     {
//    // myFile = SD.open(filename, FILE_WRITE);  // Mở file ở chế độ ghi
//      myFile.println(data);  // Ghi tiêu đề và xuống dòng sau khi ghi
//     }
//     else
//     {
//     //myFile = SD.open(filename, FILE_APPEND);  // Mở file ở chế độ ghi
//     myFile.print(data);  // Ghi dữ liệu vào file
//     myFile.print(",");  // Dấu phân cách giữa các cột, nếu cần thêm khoảng trắng
//     }
//         LV_LOG_USER("Writed data: %s", data.c_str());
//         myFile.close();  // Đóng file sau khi ghi
//   } else {
//     LV_LOG_USER("Don't open file to write.");
//   }

// }

lv_obj_t *ssid_list;          // Danh sách SSID
lv_obj_t *pass_textarea;      // Textarea nhập mật khẩu
lv_obj_t *label;              // Nhãn hiển thị trạng thái
lv_obj_t *selected_btn = NULL; // Nút được chọn trong danh sách
// Hàm để quét các mạng Wi-Fi
String ssid;
String password;
int network_count = 0;
String networks[20];

static lv_style_t border_style;
static lv_style_t popupBox_style;
static lv_obj_t *timeLabel;
static lv_obj_t *settings;
static lv_obj_t *settingBtn;
static lv_obj_t *settingCloseBtn;
static lv_obj_t *settingWiFiSwitch;
static lv_obj_t *wfList;
static lv_obj_t *settinglabel;
static lv_obj_t *mboxConnect;
static lv_obj_t *mboxTitle;
static lv_obj_t *mboxPassword;
static lv_obj_t *mboxConnectBtn;
static lv_obj_t *mboxCloseBtn;
static lv_obj_t *keyboard;
static lv_obj_t *popupBox;
static lv_obj_t *popupBoxCloseBtn;
static lv_timer_t *timer;



static int foundNetworks = 0;
unsigned long networkTimeout = 10 * 1000;
String ssidName, ssidPW;

typedef enum {
  NONE,
  NETWORK_SEARCHING,
  NETWORK_CONNECTED_POPUP,
  NETWORK_CONNECTED,
  NETWORK_CONNECT_FAILED
} Network_Status_t;
Network_Status_t networkStatus = NONE;



#include <EEPROM.h>
#define EEPROM_SIZE 128
#define EEPROM_ADDR_WIFI_FLAG 0
#define EEPROM_ADDR_WIFI_CREDENTIAL 4

static void showingFoundWiFiList();
static void popupMsgBox(String title, String msg);
void updateLocalTime();
static void networkScanner();
static void scanWIFITask(void *pvParameters);
static void buildPWMsgBox();
// Hàm xử lý sự kiện danh sách
void list_event_handler(lv_event_t *e) {
    selected_btn = lv_event_get_target(e); // Lưu nút được nhấn
    const char *btn_text = lv_list_get_btn_text(ssid_list, selected_btn);
    //LV_LOG_USER("Selected SSID: %s\n", selected_btn.c_tr());

    buildPWMsgBox();
}
// Hàm xử lý kết nối Wi-Fi
void connect_wifi() {
    if (selected_btn == NULL) {
        Serial.println("No SSID selected.");
        lv_label_set_text(label, "No SSID selected.");
        return;
    }

    const char *ssid_text = lv_list_get_btn_text(ssid_list, selected_btn);
    const char *password_text = lv_textarea_get_text(pass_textarea);

    WiFi.begin(ssid_text, password_text);

    LV_LOG_USER("Connecting to WiFi...");
    lv_label_set_text(label, "Connecting...");

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    LV_LOG_USER("\n");
   LV_LOG_USER("Connected! IP address: ");
    LV_LOG_USER("%s",WiFi.localIP());
    lv_label_set_text(label, "WiFi Connected!");
}
void scan_wifi() {
    WiFi.disconnect();
    delay(1000);
    network_count = WiFi.scanNetworks();
    for (int i = 0; i < network_count; i++) {
        networks[i] = WiFi.SSID(i);  // Lưu tên mạng Wi-Fi
      //  lv_obj_t *btn = lv_list_add_btn(list, NULL, networks[i].c_str());
        lv_list_add_btn(ssid_list, NULL, networks[i].c_str()); // Hiển thị mạng trong danh sách
      //  lv_obj_add_event_cb(btn, wifiItemEventHandler, LV_EVENT_CLICKED, (void *)i);
    }
}
static void setStyle() {
  lv_style_init(&border_style);
  lv_style_set_border_width(&border_style, 2);
  lv_style_set_border_color(&border_style, lv_color_black());

  lv_style_init(&popupBox_style);
  lv_style_set_radius(&popupBox_style, 10);
  lv_style_set_bg_opa(&popupBox_style, LV_OPA_COVER);
  lv_style_set_border_color(&popupBox_style, lv_palette_main(LV_PALETTE_BLUE));
  lv_style_set_border_width(&popupBox_style, 5);
}



static void makeKeyboard() {
  keyboard = lv_keyboard_create(lv_scr_act());
  lv_obj_add_flag(keyboard, LV_OBJ_FLAG_HIDDEN);
}

void saveWIFICredentialEEPROM(int flag, String ssidpw) {
  EEPROM.writeInt(EEPROM_ADDR_WIFI_FLAG, flag);
  EEPROM.writeString(EEPROM_ADDR_WIFI_CREDENTIAL, flag == 1 ? ssidpw : "");
  EEPROM.commit();
}

void beginWIFITask(void *pvParameters) {

  unsigned long startingTime = millis();
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  vTaskDelay(100);

  //delay(100);  // Thêm thời gian chờ để Wi-Fi tắt đúng cách

  // Kiểm tra SSID và mật khẩu trước khi bắt đầu
  // if (ssidName.length() == 0 || ssidPW.length() == 0) {
  //     LV_LOG_USER("SSID or Password is empty!");
  //     return;
  // }

LV_LOG_USER("%s",ssidName.c_str());
//  LV_LOG_USER("%s",ssidPW);

  WiFi.begin(ssidName.c_str(), ssidPW.c_str());
  while (WiFi.status() != WL_CONNECTED && (millis() - startingTime) < networkTimeout) {
    vTaskDelay(250);
  }

  if (WiFi.status() == WL_CONNECTED) {
    networkStatus = NETWORK_CONNECTED_POPUP;
    saveWIFICredentialEEPROM(1, ssidName + " " + ssidPW);
  } else {
    networkStatus = NETWORK_CONNECT_FAILED;
    saveWIFICredentialEEPROM(0, "");
  }

  vTaskDelete(NULL);
}

static void networkConnector() {
  xTaskCreate(beginWIFITask,
              "beginWIFITask",
              2048,
              NULL,
              1,
              &ntConnectTaskHandler);
}

static void timerForNetwork(lv_timer_t *timer) {
  LV_UNUSED(timer);

  switch (networkStatus) {

    case NETWORK_SEARCHING:
      showingFoundWiFiList();
      break;

    case NETWORK_CONNECTED_POPUP:
      popupMsgBox("WiFi Connected!", "Now you'll get the current time soon.");
      networkStatus = NETWORK_CONNECTED;
      configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
      break;

    case NETWORK_CONNECTED:

      showingFoundWiFiList();
      updateLocalTime();
      break;

    case NETWORK_CONNECT_FAILED:
      networkStatus = NETWORK_SEARCHING;
      popupMsgBox("Oops!", "Please check your wifi password and try again.");
      break;

    default:
      break;
  }
}
static void networkScanner() {
  xTaskCreate(scanWIFITask,
              "ScanWIFITask",
              4096,
              NULL,
              1,
              &ntScanTaskHandler);
}
static void btn_event_cb(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *btn = lv_event_get_target(e);

  if (code == LV_EVENT_CLICKED) {
    if (btn == settingBtn) {
      lv_obj_clear_flag(settings, LV_OBJ_FLAG_HIDDEN);
    } else if (btn == settingCloseBtn) {
      lv_obj_add_flag(settings, LV_OBJ_FLAG_HIDDEN);
    } else if (btn == mboxConnectBtn) {
      ssidPW = String(lv_textarea_get_text(mboxPassword));
      networkConnector();
      lv_obj_move_background(mboxConnect);
      popupMsgBox("Connecting!", "Attempting to connect to the selected network.");
    } else if (btn == mboxCloseBtn) {
      lv_obj_move_background(mboxConnect);
    } else if (btn == popupBoxCloseBtn) {
      lv_obj_move_background(popupBox);
    }

  } else if (code == LV_EVENT_VALUE_CHANGED) {
    if (btn == settingWiFiSwitch) {

      if (lv_obj_has_state(btn, LV_STATE_CHECKED)) {

        if (ntScanTaskHandler == NULL) {
          networkStatus = NETWORK_SEARCHING;
          networkScanner();
          timer = lv_timer_create(timerForNetwork, 1000, wfList);
          lv_list_add_text(wfList, "WiFi: Looking for Networks...");
        }

      } else {

        if (ntScanTaskHandler != NULL) {
          networkStatus = NONE;
          vTaskDelete(ntScanTaskHandler);
          ntScanTaskHandler = NULL;
          lv_timer_del(timer);
          lv_obj_clean(wfList);
        }

        if (WiFi.status() == WL_CONNECTED) {
          WiFi.disconnect(true);
          lv_label_set_text(timeLabel, "WiFi Not Connected!    " LV_SYMBOL_CLOSE);
        }
      }
    }
  }
}

static void popupMsgBox(String title, String msg) {

  if (popupBox != NULL) {
    lv_obj_del(popupBox);
  }

  popupBox = lv_obj_create(lv_scr_act());
  lv_obj_add_style(popupBox, &popupBox_style, 0);
  lv_obj_set_size(popupBox, gfx->width() * 2 / 3, gfx->height() / 2);
  lv_obj_center(popupBox);

  lv_obj_t *popupTitle = lv_label_create(popupBox);
  lv_label_set_text(popupTitle, title.c_str());
  lv_obj_set_width(popupTitle, gfx->width() * 2 / 3 - 50);
  lv_obj_align(popupTitle, LV_ALIGN_TOP_LEFT, 0, 0);

  lv_obj_t *popupMSG = lv_label_create(popupBox);
  lv_obj_set_width(popupMSG, gfx->width() * 2 / 3 - 50);
  lv_label_set_text(popupMSG, msg.c_str());
  lv_obj_align(popupMSG, LV_ALIGN_TOP_LEFT, 0, 40);

  popupBoxCloseBtn = lv_btn_create(popupBox);
  lv_obj_add_event_cb(popupBoxCloseBtn, btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_align(popupBoxCloseBtn, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
  lv_obj_t *btnLabel = lv_label_create(popupBoxCloseBtn);
  lv_label_set_text(btnLabel, "Okay");
  lv_obj_center(btnLabel);
}

static void scanWIFITask(void *pvParameters) {
  while (1) {
    foundWifiList.clear();
    int n = WiFi.scanNetworks();
    vTaskDelay(10);
    for (int i = 0; i < n; ++i) {
      String item = WiFi.SSID(i) + " (" + WiFi.RSSI(i) + ") " + ((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      foundWifiList.push_back(item);
      vTaskDelay(10);
    }
    vTaskDelay(5000);
  }
}


static void showingFoundWiFiList() {
  if (foundWifiList.size() == 0 || foundNetworks == foundWifiList.size())
    return;

  lv_obj_clean(wfList);
  lv_list_add_text(wfList, foundWifiList.size() > 1 ? "WiFi: Found Networks" : "WiFi: Not Found!");

  for (std::vector<String>::iterator item = foundWifiList.begin(); item != foundWifiList.end(); ++item) {
    lv_obj_t *btn = lv_list_add_btn(wfList, LV_SYMBOL_WIFI, (*item).c_str());
    lv_obj_add_event_cb(btn, list_event_handler, LV_EVENT_CLICKED, NULL);
    delay(1);
  }

  foundNetworks = foundWifiList.size();
}

void updateLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    return;
  }

  char hourMin[6];
  strftime(hourMin, 6, "%H:%M", &timeinfo);
  String hourMinWithSymbol = String(hourMin);
  hourMinWithSymbol += "   ";
  hourMinWithSymbol += LV_SYMBOL_WIFI;
  lv_label_set_text(timeLabel, hourMinWithSymbol.c_str());
}




static void buildStatusBar() {

  static lv_style_t style_btn;
  lv_style_init(&style_btn);
  lv_style_set_bg_color(&style_btn, lv_color_hex(0xC5C5C5));
  lv_style_set_bg_opa(&style_btn, LV_OPA_50);

  lv_obj_t *statusBar = lv_obj_create(lv_scr_act());
  lv_obj_set_size(statusBar, gfx->width(), 30);
  lv_obj_align(statusBar, LV_ALIGN_TOP_MID, 0, 0);

  lv_obj_remove_style(statusBar, NULL, LV_PART_SCROLLBAR | LV_STATE_ANY);

  timeLabel = lv_label_create(statusBar);
  lv_obj_set_size(timeLabel, gfx->width() - 50, 30);

  lv_label_set_text(timeLabel, "WiFi Not Connected!    " LV_SYMBOL_CLOSE);
  lv_obj_align(timeLabel, LV_ALIGN_LEFT_MID, 8, 4);

  settingBtn = lv_btn_create(statusBar);
  lv_obj_set_size(settingBtn, 30, 30);
  lv_obj_align(settingBtn, LV_ALIGN_RIGHT_MID, 0, 0);

  lv_obj_add_event_cb(settingBtn, btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_t *label = lv_label_create(settingBtn); /*Add a label to the button*/
  lv_label_set_text(label, LV_SYMBOL_SETTINGS);  /*Set the labels text*/
  lv_obj_center(label);
}

static void text_input_event_cb(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *ta = lv_event_get_target(e);

  if (code == LV_EVENT_FOCUSED) {
    lv_obj_move_foreground(keyboard);
    lv_keyboard_set_textarea(keyboard, ta);
    lv_obj_clear_flag(keyboard, LV_OBJ_FLAG_HIDDEN);
  }

  if (code == LV_EVENT_DEFOCUSED) {
    lv_keyboard_set_textarea(keyboard, NULL);
    lv_obj_add_flag(keyboard, LV_OBJ_FLAG_HIDDEN);
  }
}



static void buildPWMsgBox() {

  mboxConnect = lv_obj_create(lv_scr_act());
  lv_obj_add_style(mboxConnect, &border_style, 0);
  lv_obj_set_size(mboxConnect, gfx->width() * 2 / 3, gfx->height() / 2);
  lv_obj_center(mboxConnect);

  mboxTitle = lv_label_create(mboxConnect);
  lv_label_set_text(mboxTitle, "Selected WiFi SSID: ThatProject");
  lv_obj_align(mboxTitle, LV_ALIGN_TOP_LEFT, 0, 0);

  mboxPassword = lv_textarea_create(mboxConnect);
  lv_obj_set_size(mboxPassword, gfx->width() / 2, 40);
  lv_obj_align_to(mboxPassword, mboxTitle, LV_ALIGN_TOP_LEFT, 0, 30);
  lv_textarea_set_placeholder_text(mboxPassword, "Password?");
  lv_obj_add_event_cb(mboxPassword, text_input_event_cb, LV_EVENT_ALL, keyboard);

  mboxConnectBtn = lv_btn_create(mboxConnect);
  lv_obj_add_event_cb(mboxConnectBtn, btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_align(mboxConnectBtn, LV_ALIGN_BOTTOM_LEFT, 0, 0);
  lv_obj_t *btnLabel = lv_label_create(mboxConnectBtn);
  lv_label_set_text(btnLabel, "Connect");
  lv_obj_center(btnLabel);

  mboxCloseBtn = lv_btn_create(mboxConnect);
  lv_obj_add_event_cb(mboxCloseBtn, btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_align(mboxCloseBtn, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
  lv_obj_t *btnLabel2 = lv_label_create(mboxCloseBtn);
  lv_label_set_text(btnLabel2, "Cancel");
  lv_obj_center(btnLabel2);
}

static void buildBody() {
  lv_obj_t *bodyScreen = lv_obj_create(lv_scr_act());
  lv_obj_add_style(bodyScreen, &border_style, 0);
  lv_obj_set_size(bodyScreen, gfx->width(), gfx->height() - 34);
  lv_obj_align(bodyScreen, LV_ALIGN_BOTTOM_MID, 0, 0);

  lv_obj_t *label = lv_label_create(bodyScreen);
  lv_label_set_text(label, "Your Contents");
  lv_obj_center(label);
}

static void buildSettings() {
  settings = lv_obj_create(lv_scr_act());
  lv_obj_add_style(settings, &border_style, 0);
  lv_obj_set_size(settings, gfx->width() - 100, gfx->height() - 40);
  lv_obj_align(settings, LV_ALIGN_TOP_RIGHT, -20, 20);

  settinglabel = lv_label_create(settings);
  lv_label_set_text(settinglabel, "Settings " LV_SYMBOL_SETTINGS);
  lv_obj_align(settinglabel, LV_ALIGN_TOP_LEFT, 0, 0);

  settingCloseBtn = lv_btn_create(settings);
  lv_obj_set_size(settingCloseBtn, 30, 30);
  lv_obj_align(settingCloseBtn, LV_ALIGN_TOP_RIGHT, 0, -10);
  lv_obj_add_event_cb(settingCloseBtn, btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_t *btnSymbol = lv_label_create(settingCloseBtn);
  lv_label_set_text(btnSymbol, LV_SYMBOL_CLOSE);
  lv_obj_center(btnSymbol);

  settingWiFiSwitch = lv_switch_create(settings);
  lv_obj_add_event_cb(settingWiFiSwitch, btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_align_to(settingWiFiSwitch, settinglabel, LV_ALIGN_TOP_RIGHT, 60, -10);
  lv_obj_add_flag(settings, LV_OBJ_FLAG_HIDDEN);

  wfList = lv_list_create(settings);
  lv_obj_set_size(wfList, gfx->width() - 140, 210);
  lv_obj_align_to(wfList, settinglabel, LV_ALIGN_TOP_LEFT, 0, 30);
}


void loadWIFICredentialEEPROM() {
  int wifiFlag = EEPROM.readInt(EEPROM_ADDR_WIFI_FLAG);
  String wifiCredential = EEPROM.readString(EEPROM_ADDR_WIFI_CREDENTIAL);

  if (wifiFlag == 1 && wifiCredential.length() != 0 && wifiCredential.indexOf(" ") != -1) {
    char preSSIDName[30], preSSIDPw[30];
    if (sscanf(wifiCredential.c_str(), "%s %s", preSSIDName, preSSIDPw) == 2) {

      lv_obj_add_state(settingWiFiSwitch, LV_STATE_CHECKED);
      lv_event_send(settingWiFiSwitch, LV_EVENT_VALUE_CHANGED, NULL);

      popupMsgBox("Welcome Back!", "Attempts to reconnect to the previously connected network.");
      ssidName = String(preSSIDName);
      LV_LOG_USER("%s",ssidName);
      ssidPW = String(preSSIDPw);
      networkConnector();
    } else {
      saveWIFICredentialEEPROM(0, "");
    }
  }
}



// void tryPreviousNetwork() {

//   if (!EEPROM.begin(EEPROM_SIZE)) {
//     delay(1000);
//     ESP.restart();
//   }

//   loadWIFICredentialEEPROM();
// }

File myFile;
void show_image_from_sd(const char *filename) {
  myFile = SD.open(filename);
  if (!myFile) {
    LV_LOG_USER("Không thể mở file ảnh.");
    return;
  }
 LV_LOG_USER("okok");
  // Đọc kích thước ảnh và các thông tin liên quan
  uint32_t image_size = myFile.size();

  // Đọc dữ liệu ảnh và tạo cấu trúc dữ liệu ảnh cho LVGL
  lv_img_dsc_t img_dsc;
  img_dsc.data = (uint8_t *)malloc(image_size);  // Cấp phát bộ nhớ cho dữ liệu ảnh
  if (img_dsc.data == NULL) {
   LV_LOG_USER("Không đủ bộ nhớ!");
    myFile.close();
    return;
  }

  // Đọc ảnh từ thẻ SD vào bộ nhớ
  // uint32_t bytesRead = myFile.read(img_dsc.data, image_size);
  // if (bytesRead != image_size) {
  //   LV_LOG_USER("Lỗi đọc dữ liệu từ file.");
  //   //free(img_dsc.data);
  //   myFile.close();
  //   return;
  // }

  myFile.close();



  // Giải phóng bộ nhớ
  //free(img_dsc.data);
}

lv_obj_t *screen1;
lv_obj_t *screen2;
lv_coord_t start_x = 0;  // Lưu vị trí x ban đầu của con trỏ
lv_style_t style_opacity;

// Hàm xử lý sự kiện vuốt
static void gesture_event_handler(lv_event_t *e) {
    lv_obj_t *target = lv_event_get_target(e);
    lv_coord_t delta_x;

    // Lấy vị trí của con trỏ khi bắt đầu vuốt
    lv_point_t point;
    lv_indev_get_point(lv_indev_get_act(), &point);

    // Nếu đang vuốt (dưới trạng thái PRESSING), tính sự thay đổi vị trí và di chuyển màn hình 2
    if (lv_event_get_code(e) == LV_EVENT_PRESSING) {
        delta_x = point.x - start_x;  // Tính sự thay đổi về vị trí trên trục X
    int screen2_pos = (delta_x - 700);  // Tăng tốc độ di chuyển của screen2

// Giới hạn vị trí của screen2 không vượt quá 0 và 800
    if (screen2_pos > 0) {
        screen2_pos = 0;  // Giới hạn không để screen2 di chuyển quá bên trái
    } else if (screen2_pos < -800) {
        screen2_pos = -800;  // Giới hạn không để screen2 di chuyển quá bên phải
    }
        // Cập nhật vị trí của màn hình 2 (screen2) theo trục X
        lv_obj_set_pos(screen2, screen2_pos, 0);  // Cộng thêm 800 để điều chỉnh cho phù hợp
        lv_obj_set_pos(screen1, delta_x*1.2, 0);  // Cộng thêm 800 để điều chỉnh cho phù hợp
        lv_obj_move_foreground(screen1);

                      //     lv_opa_t opacity = LV_OPA_COVER - (LV_OPA_COVER * abs(delta_x) / 800);  // Giảm dần opacity
    //    if (opacity < LV_OPA_10) opacity = LV_OPA_60;  // Đảm bảo không quá mờ

       // lv_style_set_bg_opa(&style_opacity, LV_OPA_60);
       // lv_obj_add_style(screen2, &style_opacity, 0);
    // Thêm delay nhỏ để giảm tải CPU
 //   lv_timer_handler();  // Xử lý các tác vụ khác trong LittlevGL
  //  lv_tick_inc(1);    // Tăng tick (5 ms)
    }

    // Cập nhật giá trị start_x mỗi lần sự kiện bắt đầu (khi nhấn xuống)
    if (lv_event_get_code(e) == LV_EVENT_PRESSED) {
        start_x = point.x;  // Lưu vị trí x khi người dùng bắt đầu vuốt
    }
    if(lv_event_get_code(e) == LV_EVENT_RELEASED)
    {
      if(point.x>480)
      {
                lv_obj_set_pos(screen2, 0, 0);  // Cộng thêm 800 để điều chỉnh cho phù hợp
                lv_obj_set_pos(screen1, 800, 0);  // Cộng thêm 800 để điều chỉnh cho phù hợp
// lv_style_set_bg_opa(&style_opacity, LV_OPA_COVER);
//         lv_obj_add_style(screen2, &style_opacity, 0);

      }
      else
      {
        lv_obj_set_pos(screen1, 0, 0);  // Cộng thêm 800 để điều chỉnh cho phù hợp
        lv_obj_set_pos(screen2, 800, 0);  // Cộng thêm 800 để điều chỉnh cho phù hợp
      //  lv_style_set_bg_opa(&style_opacity, LV_OPA_COVER);
      //  lv_obj_add_style(screen2, &style_opacity, 0);
      }
    }
}

// Tạo các màn hình và đăng ký sự kiện vuốt
void create_screens() {
    // Tạo màn hình 1
    screen1 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(screen1, 800, 480);
    lv_obj_set_style_bg_color(screen1, lv_color_hex(0xFFFFFF), 0);  // Màu nền xanh lá
    lv_obj_add_event_cb(screen1, gesture_event_handler, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(screen1, gesture_event_handler, LV_EVENT_PRESSING, NULL);
    lv_obj_add_event_cb(screen1, gesture_event_handler, LV_EVENT_RELEASED, NULL);


// Tạo nút cho màn hình 1
     lv_obj_t *btn1 = lv_btn_create(screen1);
    lv_obj_set_size(btn1, 150, 50);
     lv_obj_set_pos(btn1, 100, 150);  // Vị trí của nút
  //     lv_label_set_text(btn1, "BACK");
  //  // lv_obj_add_event_cb(btn1, button_event_handler, LV_EVENT_CLICKED, NULL);
    
  //   lv_obj_t *btn2 = lv_btn_create(screen1);
  //   lv_obj_set_size(btn2, 150, 50);
  //   lv_obj_set_pos(btn2, 100, 250);  // Vị trí của nút
  //   lv_label_set_text(btn2, "Button 2");
    //lv_obj_add_event_cb(btn2, button_event_handler, LV_EVENT_CLICKED, NULL);


    // Tạo màn hình 2
    screen2 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(screen2, 800, 480);
    lv_obj_set_style_bg_color(screen2, lv_color_hex(0), 0);  // Màu nền xanh dương
    lv_obj_set_pos(screen2, 0, 0);  // Đặt màn hình thứ 2 ngoài màn hình chính ban đầu
    lv_obj_add_event_cb(screen2, gesture_event_handler, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(screen2, gesture_event_handler, LV_EVENT_PRESSING, NULL);
    lv_obj_add_event_cb(screen2, gesture_event_handler, LV_EVENT_RELEASED, NULL);
}



SPIClass hspi = SPIClass(HSPI);


#define HSPI_SCK  12
#define HSPI_MISO 13
#define HSPI_MOSI 11
#define HSPI_CS   10


void setup()
{
  Serial.begin(115200);
 hspi.begin(HSPI_SCK, HSPI_MISO, HSPI_MOSI, HSPI_CS);
if(!SD.begin(HSPI_CS, hspi, 160000000))
{
    LV_LOG_USER("SD CARD FAIL");

}
LV_LOG_USER("SD CARD ok");

// Cấu hình I2S
// i2s_config_t i2s_config = {
//         .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),  // Chế độ Master và truyền dữ liệu
//         .sample_rate = 44100,                                  // Tần số mẫu 44.1kHz
//         .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,           // Sử dụng mẫu 16-bit
//         .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,           // Stereo (2 kênh)
//         .communication_format = I2S_COMM_FORMAT_I2S,            // Định dạng I2S chuẩn
//         .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1                // Cấu hình ngắt
//     };


//Read_Data_User("/hihi.csv");
//Write_Data_User("/hihi.csv","adc");
  Serial.println("LVGL Widgets Demo");
  // Init Display
  gfx->begin();
#ifdef TFT_BL
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  ledcSetup(0, 300, 8);
  ledcAttachPin(TFT_BL, 0);
  ledcWrite(0, 255); 
  
#endif

  lv_init();

    // Init touch device
  pinMode(TOUCH_GT911_RST, OUTPUT);
  digitalWrite(TOUCH_GT911_RST, LOW);
  delay(10);
  digitalWrite(TOUCH_GT911_RST, HIGH);
  delay(10);
  touch_init();
//  touch.setTouch( calData );

  screenWidth = gfx->width();
  screenHeight = gfx->height();
#ifdef ESP32
  disp_draw_buf = (lv_color_t *)heap_caps_malloc(sizeof(lv_color_t) * screenWidth *screenHeight/8  , MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
#else
  disp_draw_buf = (lv_color_t *)malloc(sizeof(lv_color_t) * screenWidth *screenHeight/4);
#endif
  if (!disp_draw_buf)
  {
    Serial.println("LVGL disp_draw_buf allocate failed!");
  }
  else
  {
    lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, NULL, screenWidth *screenHeight/8);

    /* Initialize the display */
    lv_disp_drv_init(&disp_drv);
    /* Change the following line to your display resolution */
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    /* Initialize the (dummy) input device driver */
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);
   // lv_demo_widgets();
    //lv_demo_music(); 
   LV_LOG_USER("Setup done");
   //lvgl_tick_init();  // Khởi tạo timer để gọi lv_tick_inc() mỗi mili giây

    // Tạo task cho LVGL
   // xTaskCreate(lv_task_handler, "lv_task_handler", 4096, NULL, 5, NULL);
   //create_screens();
     //  xTaskCreatePinnedToCore(ui_tick, "UI Task", 16384, NULL, 1, NULL, 1);
lv_split_jpeg_init();
  
     // Tạo đối tượng ảnh LVGL và hiển thị lên màn hình
  lv_obj_t * img = lv_img_create(lv_scr_act());
  lv_img_set_src(img, "S:/sunflower.jpg");
  lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);

   //show_image_from_sd("/demo.bmp");
  //   ui_init();
// setStyle();
//  makeKeyboard();
// buildStatusBar();
// buildPWMsgBox();
// buildBody();
// buildSettings();
//tryPreviousNetwork();
  }

}

void loop()
{
  //lv_tick_inc(millis() - lastTick);  //Update the tick timer. Tick is new for LVGL 9
  //lastTick = millis();
  lv_timer_handler(); /* let the GUI do its work */
//   delay(20);
  // lv_label_set_text(label, "123");


  //Temp_Label
 //ui_tick();

}



// void Read_Data_User(String filename)
// {
//   myFile = SD.open(filename);  // Mở file ở chế độ đọc
// if(myFile)
// {
//         LV_LOG_USER("Reading file : %s",filename.c_str());
//         String header = myFile.readStringUntil('\n');
//         LV_LOG_USER("Header of file : %s", header.c_str());
//         while (myFile.available()) {
//         String line = myFile.readStringUntil('\n');  // Đọc từng dòng dữ liệu
//         if (line.length() > 0) {

//         LV_LOG_USER("Dòng dữ liệu: %s", line.c_str());  // Ghi dòng dữ liệu vào log
//         int firstCommaIndex = line.indexOf(',');
//         int secondCommaIndex = line.indexOf(',', firstCommaIndex + 1);
//         int thirdCommaIndex = line.indexOf(',', secondCommaIndex + 1);
//         int fourthCommaIndex = line.indexOf(',', thirdCommaIndex + 1);
//         int fifthCommaIndex = line.indexOf(',', fourthCommaIndex + 1);
//         String Name = line.substring(0, firstCommaIndex);  // Cột 1: Time
//         String Mode = line.substring(firstCommaIndex + 1, secondCommaIndex);  // Cột 2: Temperature
//         String Start_at = line.substring(secondCommaIndex + 1, thirdCommaIndex);  // Cột 2: Temperature
//         String During_at = line.substring(thirdCommaIndex + 1, fourthCommaIndex);  // Cột 2: Temperature
//         String Temperature = line.substring(fourthCommaIndex+1 , fifthCommaIndex);  // Cột 3: Humidity
//         LV_LOG_USER("Name: %s, Mode: %s, During_at: %s, Start_at: %s, Temperature: %s", 
//                     Name.c_str(), Mode.c_str(), During_at.c_str(), Start_at.c_str(), Temperature.c_str());
// }

// }
//     myFile.close();
//         LV_LOG_USER("Read done file.");

// }
// else {
//         LV_LOG_USER("Don't open file to read.");

// }
// }

 