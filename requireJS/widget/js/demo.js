require(['jquery','dialog'],function($,Dialog){



	//var newDialog = new Dialog();
	$('#btn').on('click',function(){
		var newDialog = new Dialog();
		newDialog.open({
			width: 400,
			height: 200,
			title: "My Dialog With Requirejs Demo",
			//content: "welcome to requirejs world"
			url: 'form.html',
			rotate: false
		});


		
	});

	$('#btn-default').on('click',function(){
		var newDialog = new Dialog();
		newDialog.open();
		
	});

	










});