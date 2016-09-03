require(['jquery','ul'],function($,Ul){
	
	var Ul = new Ul();
	
	$('#btn1').on('click',function(){
		Ul.init(
			{
				num: 11,
				odd: '#f60',
				even: '#5cb85c',
				color: '#fff'
			}
		);
	});


	$('#btn2').on('click',function(){
		Ul.init({});
	});
	
});