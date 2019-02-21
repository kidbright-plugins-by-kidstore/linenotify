#ifndef __LINENOTIFY_H__
#define __LINENOTIFY_H__

/*
  DEV By IOXhop : www.ioxhop.com
  Sonthaya Nongnuch : fb.me/maxthai
*/

#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_system.h"
#include "nvs_flash.h"

#include "esp_http_client.h"

#include "driver.h"
#include "device.h"

class LINENotify : public Device {
	private:		
		char *access_token;

	public:
		// constructor
		LINENotify() ;
		
		// override
		void init(void);
		void process(Driver *drv);
		int prop_count(void);
		bool prop_name(int index, char *name);
		bool prop_unit(int index, char *unit);
		bool prop_attr(int index, char *attr);
		bool prop_read(int index, char *value);
		bool prop_write(int index, char *value);
		
		// method
		void setAccessToken(const char *) ;
		void notify(const char *, const char *, const char *, const char *, const char *) ;
		
};

#endif
