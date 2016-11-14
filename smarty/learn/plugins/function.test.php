<?php


	function smarty_function_test($params){//smarty_function_插件名
		// $params  array('参数1'=>'参数1的值','参数2'=>'参数2的值')

		$width = $params['width'];
		$height = $params['height'];

		$area = $width * $height;

		return $area;

	}
?>