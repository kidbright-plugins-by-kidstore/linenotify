Blockly.Blocks['linenotify_set_access_token'] = {
	init: function() {
		this.appendValueInput("token")
			.setCheck(null)
			.appendField(new Blockly.FieldImage("https://www.line-community.me/awards/uimage/5b46aedf851f74a6af8eaab8", 16, 16, "*"))
			.appendField(Blockly.Msg.LINENOTIFY_SET_ACCESS_TOKEN_MESSAGE);
		this.setPreviousStatement(true, null);
		this.setNextStatement(true, null);
		this.setColour(120);
		this.setTooltip("");
		this.setHelpUrl("https://notify-bot.line.me/doc/en/");
	}
};

Blockly.Blocks['linenotify_send_notifications'] = {
	init: function() {
		this.jsonInit({
			"message0": Blockly.Msg.LINENOTIFY_SEND_NOTIFICATIONS_MESSAGE,
			"args0": [{
				"type": "field_image",
				"src": "https://www.line-community.me/awards/uimage/5b46aedf851f74a6af8eaab8",
				"width": 16,
				"height": 16,
				"alt": "*"
			}, {
				"type": "input_dummy"
			}, {
				"type": "input_value",
				"name": "message",
				"check": [ "String", "Number", "Boolean" ],
				"align": "RIGHT"
			}, {
				"type": "input_value",
				"name": "imageThumbnail",
				"check": "String",
				"align": "RIGHT"
			}, {
				"type": "input_value",
				"name": "imageFullsize",
				"check": "String",
				"align": "RIGHT"
			}, {
				"type": "input_value",
				"name": "stickerPackageId",
				"check": [ "String", "Number" ],
				"align": "RIGHT"
			}, {
				"type": "input_value",
				"name": "stickerId",
				"check": [ "String", "Number" ],
				"align": "RIGHT"
			}],
			"previousStatement": null,
			"nextStatement": null,
			"colour": 120,
			"tooltip": Blockly.Msg.LINENOTIFY_SEND_NOTIFICATIONS_TOOLTIP,
			"helpUrl": "https://notify-bot.line.me/doc/en/"
		});
	}
};