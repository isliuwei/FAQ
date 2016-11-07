$(function(){
	$('.orderBtn').on('click',function(){
		$('.orderForm').toggleClass('none');
		$(this).addClass('hidden');	
	});

	$('.orderClose').on('click',function(){
		$('.orderForm').addClass('none');
		$('.orderBtn').removeClass('hidden');
	});

});