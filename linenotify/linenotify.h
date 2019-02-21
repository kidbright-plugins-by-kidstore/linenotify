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

#define TOKEN_SIZE 64
#define MESSAGE_SIZE            200
#define IMAGE_THUMBNAIL_SIZE    100
#define IMAGE_FULLSIZE_SIZE     100
#define STICKER_PACKAGE_ID_SIZE 10
#define STICKER_ID_SIZE         10

#define AUTH_SIZE 100
#define POST_DATA_BUFFER_SIZE 512

class LINENotify : public Device {
	private:		
		char access_token[TOKEN_SIZE];
		char message[MESSAGE_SIZE];
		char imageThumbnail[IMAGE_THUMBNAIL_SIZE];
		char imageFullsize[IMAGE_FULLSIZE_SIZE];
		char stickerPackageId[STICKER_PACKAGE_ID_SIZE];
		char stickerId[STICKER_ID_SIZE];

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
		void setAccessToken(char*) ;
		
		void setMessage(char*) ;
		void setMessage(int) ;
		void setMessage(double) ;
		void setMessage(bool) ;
		
		void setImageThumbnail(char*) ;
		
		void setImageFullsize(char*) ;
		
		void setStickerPackageID(char*);
		void setStickerPackageID(int);
		void setStickerPackageID(double);
		
		void setStickerID(char*);
		void setStickerID(int);
		void setStickerID(double);
		
		void notify() ;
		
};

#endif
