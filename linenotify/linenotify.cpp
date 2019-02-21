#ifndef __LINENOTIFY_CPP__
#define __LINENOTIFY_CPP__

#include "linenotify.h"

static const char *TAG = "LINENotify";

/*
  DEV By IOXhop : www.ioxhop.com
  Sonthaya Nongnuch : fb.me/maxthai
*/

LINENotify::LINENotify() { }

void LINENotify::init(void) {
	
	
	// set initialized flag
	this->initialized = true;
	// clear error flag
	this->error = false;
}

int LINENotify::prop_count(void) {
	// not supported
	return 0;
}

bool LINENotify::prop_name(int index, char *name) {
	// not supported
	return false;
}

bool LINENotify::prop_unit(int index, char *unit) {
	// not supported
	return false;
}

bool LINENotify::prop_attr(int index, char *attr) {
	// not supported
	return false;
}

bool LINENotify::prop_read(int index, char *value) {
	// not supported
	return false;
}

bool LINENotify::prop_write(int index, char *value) {
	// not supported
	return false;
}

void LINENotify::process(Driver *drv) {
	
}
// --------------------------------------

// Start here
// Method
void LINENotify::setAccessToken(char *token) {
	memset(this->access_token, 0, TOKEN_SIZE);
	strcpy(this->access_token, token);
}

void LINENotify::setMessage(char* message) {
	strcpy(this->message, message);
}

void LINENotify::setMessage(int n) {
	itoa(n, this->message, 10);
}

void LINENotify::setMessage(double n) {
	sprintf(this->message, "%f", n);
	
	// check ending zero
	int i = strlen(this->message) - 1;
	while (i >= 0) {
		if (this->message[i] == '0') {
			this->message[i] = '\x0';
		} else if (this->message[i] == '.') {
			this->message[i] = '\x0';
			break;
		} else {
			break; // first occurence of non-zero or dot
		}
		i--;
	}
}

void LINENotify::setMessage(bool x) {
	this->message[0] = x ? '1' : '0';
	this->message[1] = 0;
}

void LINENotify::setImageThumbnail(char* imageThumbnail) {
	strcpy(this->imageThumbnail, imageThumbnail);
}

void LINENotify::setImageFullsize(char* imageFullsize) {
	strcpy(this->imageFullsize, imageFullsize);
}

void LINENotify::setStickerPackageID(char* stickerPackageId) {
	strcpy(this->stickerPackageId, stickerPackageId);
}

void LINENotify::setStickerPackageID(int n) {
	itoa(n, this->stickerPackageId, 10);
}

void LINENotify::setStickerPackageID(double n) {
	this->setStickerPackageID((int) n);
}

void LINENotify::setStickerID(char* stickerId) {
	strcpy(this->stickerId, stickerId);
}

void LINENotify::setStickerID(int n) {
	itoa(n, this->stickerId, 10);
}

void LINENotify::setStickerID(double n) {
	this->setStickerID((int) n);
}

void LINENotify::notify() {
	char *strAuthorization = (char *)malloc(AUTH_SIZE);
	char *post_data = (char *)malloc(POST_DATA_BUFFER_SIZE);
	
	// Post data
	memset(post_data, 0, POST_DATA_BUFFER_SIZE);
	strcpy(post_data, "message=");
	strcat(post_data, this->message);
	if (strlen(this->imageThumbnail) > 0) {
		strcat(post_data, "&imageThumbnail=");
		strcat(post_data, this->imageThumbnail);
	}
	if (strlen(this->imageFullsize) > 0) {
		strcat(post_data, "&imageFullsize=");
		strcat(post_data, this->imageFullsize);
	}
	if (strlen(this->stickerPackageId) > 0) {
		strcat(post_data, "&stickerPackageId=");
		strcat(post_data, this->stickerPackageId);
	}
	if (strlen(this->stickerId) > 0) {
		strcat(post_data, "&stickerId=");
		strcat(post_data, this->stickerId);
	}
	
	// Authorization
	memset(strAuthorization, 0, AUTH_SIZE);
	sprintf(strAuthorization, "Bearer %s", this->access_token);
	
	// Use esp http api
	esp_http_client_config_t config = {
        .url = "https://notify-api.line.me/api/notify"
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_http_client_set_method(client, HTTP_METHOD_POST);
	esp_http_client_set_header(client, "Authorization", strAuthorization);
    esp_http_client_set_post_field(client, post_data, strlen(post_data));
	
    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK) {
        ESP_LOGI(TAG, "HTTPS Status = %d, content_length = %d",
                esp_http_client_get_status_code(client),
                esp_http_client_get_content_length(client));
    } else {
        ESP_LOGE(TAG, "Error perform http request %s", esp_err_to_name(err));
    }
    esp_http_client_cleanup(client);
	
	free(strAuthorization);
	free(post_data);
	
	memset(message, 0, sizeof message);
	memset(imageThumbnail, 0, sizeof imageThumbnail);
	memset(imageFullsize, 0, sizeof imageFullsize);
	memset(stickerPackageId, 0, sizeof stickerPackageId);
	memset(stickerId, 0, sizeof stickerId);
}

#endif
