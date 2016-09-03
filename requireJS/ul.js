define(['jquery'],function($){

	function Ul(){}
	Ul.prototype = {
		init: function(options){

			//设置默认样式
			options = $.extend({
				num: 11,
				odd: '#ccc',
				even: '#aaa',
				color: '#fff' 

			},options);
			

			var $ul = $('<ul style=color:'+options.color+'></ul>');
			for(var i=0;i<options.num;i++){

				if(i%2==0){
					//$li = $("<li class="+options.even+">列表"+(i+1)+"</li>");
					$li = $("<li style=background:"+options.even+">列表"+(i+1)+"</li>");
					

				}else{
					$li = $("<li style=background:"+options.odd+">列表"+(i+1)+"</li>");
					//$li = $("<li class="+options.odd+">列表"+(i+1)+"</li>");
				}

				
				$li.appendTo($ul);

			}
			$('body').append($ul);

		}
	}

	
	return Ul;


});