<?php
    $open_id = $this -> session -> userdata('open_id');
?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
	<base href="<?php echo site_url(); ?>">
	<title>orderBar</title>
	<style>
		#orderBar{

			
			width: 100%;
			height: 100%;
			position: fixed;
			right: 0;

		}

		#orderBar .orderBtn{

			width: 40px;
			height: 40px;
			font-size: 14px;
			text-align: center;
			padding: 2px;
			border: 1px solid #f00;
			/*position: absolute;
			left: 421px;*/

			position: fixed;
			bottom: 400px;
			right: 0px;
		}
		#orderBar .orderTitle{

		}

		#orderBar .orderClose{
			display: inline-block;
			float: right;
			padding-right: 10px;
			font-size: 12px;


		}

		#orderBar .orderTopic{
			text-align: center;
		}

		#orderBar .orderForm{
			text-align: center;
			/*width: 400px;*/
			width: 80%;

			padding: 0 10px;
			border: 1px solid #f00;
			/*position: relative;*/
			/*display: none;*/
			position: absolute;
			right: 45px;
			bottom: 114px;

			/*bottom: 229px;
			right: 125px;*/
			

		}
		#orderBar .orderForm label{
			display: inline-block;
			width: 80px;
		}
		#orderBar .orderForm .inputBox{
			width: 200px;
			height: 30px;
			margin-bottom: 10px;
			text-indent: 10px;
		}
		#orderBar .orderForm .textareaBox{
			/*padding: 10px 8px 10px 0;*/
			text-indent: 10px;
		}
		#orderBar .orderForm .submitBtn{
			width: 100px;
			height: 40px;
			margin: 10px 0;
			border-radius: 5px;
			-webkit-appearance: none;
			outline: none;
			border: none;
			color: #fff;
			background: rgb(66,165,230);
			font-size: 14px;

		}

		#orderBar .hidden{
			visibility: hidden;
		}

		#orderBar .none{
			display: none;
		}

		#orderBar .orderTipBar{
			width: 16px;
			height: 140px;
			font-size: 16px;
			border: 1px solid #f00;
			position: absolute;
			top: -1px;
			/*left: 420px;*/
			right: -18px;

		}
	</style>
</head>
<body>

<div id="orderBar">
	<div class="orderBtn">
		<span class="orderTitle">点我预约</span>
	</div>
	<div class="orderForm none">
		<h3 class="orderTopic">填写预约信息<span class="orderClose">关闭</span></h3>
		<form action="welcome/save_order" method="post">
			
			<input id="open_id" name="open_id" type="hidden" value="<?php echo $open_id;?>">
			
			
			<input id="order_color" name="order_color" type="hidden" value="am-active">
			<input id="order_type" name="order_type" type="hidden">

			<input id="order-timestamp" name="order_timestamp" type="hidden" value="<?php echo date("Y-m-d H:i:s") ;?>">
			<input id="order-microtime" name="order_microtime" type="hidden" value="<?php echo microtime() ;?>">


			<label for="name">预约姓名</label>
			<input id="name" class="inputBox" type="text" placeholder="填写预约姓名" name="order_name">
			<br>	
			<label for="tel">预约电话</label>
			<input id="tel" class="inputBox" type="text" placeholder="* 填写预约电话(必填)" name="order_tel" required>
			<br>
			<label for="address">预约地址</label>
			<input id="address" class="inputBox" type="text" placeholder="填写预约地址" name="order_address">
			<br>
			<label for="address" class="hidden">预约信息</label>
			<textarea id="orderDetails" name="" class="textareaBox" cols="33" rows="4" placeholder="填写预约信息"></textarea>
			<br>
			<input class="submitBtn" type="submit" value="提交预约">
		</form>
		<div class="orderTipBar">预约信息填写</div>
	</div>
	
</div>
<script src="js/jquery.js"></script>


<script>

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

	
</script>













	
</body>
</html>