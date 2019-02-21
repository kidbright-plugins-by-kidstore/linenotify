#ifndef __LINENOTIFY_CPP__
#define __LINENOTIFY_CPP__

#include "linenotify.h"

static const char *TAG = "LINENotify";

/*
  DEV By IOXhop : www.ioxhop.com
  Sonthaya Nongnuch : fb.me/maxthai
*/

#define TOKEN_SIZE 64
#define AUTH_SIZE 100
#define POST_DATA_BUFFER_SIZE 512

LINENotify::LINENotify() {
	this->access_token = (char*) malloc(TOKEN_SIZE);
}

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
void LINENotify::setAccessToken(const char *token) {
	memset(this->access_token, 0, TOKEN_SIZE);
	strcpy(this->access_token, token);
}

void LINENotify::notify(const char *message, const char *imageThumbnail, const char *imageFullsize, const char *stickerPackageId, const char *stickerId) {
	char *strAuthorization = (char *)malloc(AUTH_SIZE);
	char *post_data = (char *)malloc(POST_DATA_BUFFER_SIZE);
	
	// Post data
	memset(post_data, 0, POST_DATA_BUFFER_SIZE);
	strcpy(post_data, "message=");
	strcat(post_data, message);
	if (strlen(imageThumbnail) > 0) {
		strcat(post_data, "&imageThumbnail=");
		strcat(post_data, imageThumbnail);
	}
	if (strlen(imageFullsize) > 0) {
		strcat(post_data, "&imageFullsize=");
		strcat(post_data, imageFullsize);
	}
	if (strlen(stickerPackageId) > 0) {
		strcat(post_data, "&stickerPackageId=");
		strcat(post_data, stickerPackageId);
	}
	if (strlen(stickerId) > 0) {
		strcat(post_data, "&stickerId=");
		strcat(post_data, stickerId);
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
}

#endif
