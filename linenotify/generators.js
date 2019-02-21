// LINE Notify

function removeCharTypeOfGenCode(str) {
	return /^\(char%20\*\)%22(.*)%22$/gm.exec(str)[1];
}

Blockly.JavaScript['linenotify_set_access_token'] = function(block) {
	var value_token = Blockly.JavaScript.valueToCode(block, 'token', Blockly.JavaScript.ORDER_ATOMIC);
	var code = 'DEV_IO.LINENotify().setAccessToken("' + removeCharTypeOfGenCode(encodeURI(value_token)) + '");\n';
	return code;
};

Blockly.JavaScript['linenotify_send_notifications'] = function(block) {
	var value_message = Blockly.JavaScript.valueToCode(block, 'message', Blockly.JavaScript.ORDER_ATOMIC);
	var value_imagethumbnail = Blockly.JavaScript.valueToCode(block, 'imageThumbnail', Blockly.JavaScript.ORDER_ATOMIC);
	var value_imagefullsize = Blockly.JavaScript.valueToCode(block, 'imageFullsize', Blockly.JavaScript.ORDER_ATOMIC);
	var value_stickerpackageid = Blockly.JavaScript.valueToCode(block, 'stickerPackageId', Blockly.JavaScript.ORDER_ATOMIC);
	var value_stickerid = Blockly.JavaScript.valueToCode(block, 'stickerId', Blockly.JavaScript.ORDER_ATOMIC);
	// TODO: Assemble JavaScript into code variable.
	var code = 'DEV_IO.LINENotify().notify(';
	code += '"' + removeCharTypeOfGenCode(encodeURI(value_message)) + '", ';
	code += '"' + removeCharTypeOfGenCode(encodeURI(value_imagethumbnail)) + '", ';
	code += '"' + removeCharTypeOfGenCode(encodeURI(value_imagefullsize)) + '", ';
	code += '"' + removeCharTypeOfGenCode(encodeURI(value_stickerpackageid)) + '", ';
	code += '"' + removeCharTypeOfGenCode(encodeURI(value_stickerid)) + '");';
	return code;
};
