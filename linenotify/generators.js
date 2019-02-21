// LINE Notify

function FilterCode(str) {
	if (/^\(char \*\)"(.*)"$/.test(str)) {
		var text = /^\(char \*\)"(.*)"$/.exec(str)[1];
		return '"' + encodeURI(text) + '"';
	}
	
	return str;
}

Blockly.JavaScript['linenotify_set_access_token'] = function(block) {
	var value_token = Blockly.JavaScript.valueToCode(block, 'token', Blockly.JavaScript.ORDER_ATOMIC) || '""';;
	var code = 'DEV_IO.LINENotify().setAccessToken(' + FilterCode(value_token) + ');\n';
	return code;
};

Blockly.JavaScript['linenotify_send_notifications'] = function(block) {
	var value_message = Blockly.JavaScript.valueToCode(block, 'message', Blockly.JavaScript.ORDER_ATOMIC) || '""';
	var value_imagethumbnail = Blockly.JavaScript.valueToCode(block, 'imageThumbnail', Blockly.JavaScript.ORDER_ATOMIC) || '""';
	var value_imagefullsize = Blockly.JavaScript.valueToCode(block, 'imageFullsize', Blockly.JavaScript.ORDER_ATOMIC) || '""';
	var value_stickerpackageid = Blockly.JavaScript.valueToCode(block, 'stickerPackageId', Blockly.JavaScript.ORDER_ATOMIC) || '""';
	var value_stickerid = Blockly.JavaScript.valueToCode(block, 'stickerId', Blockly.JavaScript.ORDER_ATOMIC) || '""';
	// TODO: Assemble JavaScript into code variable.
	var code = '';
	code += 'DEV_IO.LINENotify().setMessage(' + FilterCode(value_message) + '); ';
	code += 'DEV_IO.LINENotify().setImageThumbnail(' + FilterCode(value_imagethumbnail) + '); ';
	code += 'DEV_IO.LINENotify().setImageFullsize(' + FilterCode(value_imagefullsize) + '); ';
	code += 'DEV_IO.LINENotify().setStickerPackageID(' + FilterCode(value_stickerpackageid) + '); ';
	code += 'DEV_IO.LINENotify().setStickerID(' + FilterCode(value_stickerid) + '); ';
	code += 'DEV_IO.LINENotify().notify();\n';
	return code;
};
