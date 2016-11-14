<?php
	function smarty_modifier_test($utime,$format){//smarty_modifier_插件名
		return date($format,$utime);
	}
?>