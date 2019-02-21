Blockly.Blocks['linenotify_set_access_token'] = {
	init: function() {
		this.appendValueInput("token")
			.setCheck(null)
			.appendField(new Blockly.FieldImage("https://www.line-community.me/awards/uimage/5b46aedf851f74a6af8eaab8", 16, 16, "*"))
			.appendField(Blockly.Msg.LINENOTIFY["Set Access Token to"]);
		this.setPreviousStatement(true, null);
		this.setNextStatement(true, null);
		this.setColour(120);
		this.setTooltip("");
		this.setHelpUrl("https://notify-bot.line.me/doc/en/");
	}
};

Blockly.Blocks['linenotify_send_notifications'] = {
	init: function() {
		this.appendDummyInput()
			.appendField(new Blockly.FieldImage("https://www.line-community.me/awards/uimage/5b46aedf851f74a6af8eaab8", 16, 16, "*"))
			.appendField(Blockly.Msg.LINENOTIFY["Sends notifications"]);
		this.appendValueInput("message")
			.setCheck("String")
			.setAlign(Blockly.ALIGN_RIGHT)
			.appendField(Blockly.Msg.LINENOTIFY["Message"]);
		this.appendValueInput("imageThumbnail")
			.setCheck("String")
			.setAlign(Blockly.ALIGN_RIGHT)
			.appendField("Image thumbnail");
		this.appendValueInput("imageFullsize")
			.setCheck("String")
			.setAlign(Blockly.ALIGN_RIGHT)
			.appendField("Image full size");
		this.appendValueInput("stickerPackageId")
			.setCheck("String")
			.setAlign(Blockly.ALIGN_RIGHT)
			.appendField("Sticker Package Id");
		this.appendValueInput("stickerId")
			.setCheck("String")
			.setAlign(Blockly.ALIGN_RIGHT)
			.appendField("Sticker Id");
		this.setPreviousStatement(true, null);
		this.setNextStatement(true, null);
		this.setColour(120);
		this.setTooltip(Blockly.Msg.LINENOTIFY["Sends notifications to users or groups that are related to an access token"]);
		this.setHelpUrl("https://notify-bot.line.me/doc/en/");
	}
};