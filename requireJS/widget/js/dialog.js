define(['jquery'],function($){


	function Dialog()
	{

	}

	Dialog.prototype.open = function(options)
	{
		var setting = {
			width: 420,
			height: 240,
			title: 'This is a Dialog Demo!',
			url: 'Lorem ipsum dolor sit amet, consectetur adipisicing elit. Fuga harum ut laboriosam tempora placeat voluptatibus atque! Maxime fugit corporis dignissimos similique id deleniti iusto porro voluptas, ullam at nemo exercitationem!',
			rotate: true
		};
		var self = this;

		$.extend(setting,options);

		this.dialogContainer = $('<div class="dialog-container"></div>');
		this.dialogMask = $('<div class="dialog-mask"></div>');
		this.dialogBox = $('<div class="dialog-box"></div>');
		this.dialogHeader = $('<div class="dialog-header"></div>');
		this.dialogTitle = $('<div class="dialog-title"></div>');
		this.dialogCloseButton = $('<div class="dialog-close-btn">❌</div>');
		this.dialogContent = $('<div class="dialog-content"></div>');


		this.dialogBox.css(
			{
				width: setting.width,
				height: setting.height,
				marginLeft: -setting.width/2,
				marginTop: -setting.height/2

			}
		);

		if(setting.rotate)
		{
			this.dialogBox.addClass('rotateShow');
		}
		

		this.dialogTitle.html(setting.title);
		if(setting.url.indexOf('html')!==-1)
		{
			this.dialogContent.load(setting.url);

		}
		else
		{
			this.dialogContent.html(setting.url);
		}

		this.dialogMask.appendTo(this.dialogContainer).on('click',function(){
			self.close();
		});
		this.dialogBox.appendTo(this.dialogContainer);
		this.dialogHeader.appendTo(this.dialogBox);
		this.dialogContent.appendTo(this.dialogBox);
		this.dialogTitle.appendTo(this.dialogHeader);
		this.dialogCloseButton.appendTo(this.dialogHeader).on('click',function(){
			self.close();
		});

		this.dialogContainer.appendTo($(document.body));

	}

	Dialog.prototype.close = function(){
		var self = this;
		self.dialogContainer.fadeOut(1000,function(){
			self.dialogContainer.remove();
		});
	}


	return Dialog;













});