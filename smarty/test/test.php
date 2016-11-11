<?php

	/**
		引入Smarty.class.php文件
	*/
	require('../smarty/Smarty.class.php');

	/**
		实例化Smarty类
	*/
	$smarty = new Smarty();

	/**

		Smarty配置  "五配置两方法"

	*/
	/**
		左定界符
	*/
	$smarty -> left_delimiter = "{"; 
	/**
		右定界符
	*/
	$smarty -> right_delimiter = "}"; 
	/**
		html模板的地址
	*/
	$smarty -> template_dir = "tpl";	
	/**
		模板编译生成的文件地址
	*/
	$smarty -> compile_dir = "template_c";
	/**
		设置缓存
	*/	
	$smarty -> cache_dir = "cache";

	//以下是开启缓存的另两个配置。
	//因为通常不用smarty的缓存机制，所以此项为了解。
	$smarty -> caching = true; //开启缓存
	$smarty -> cache_lifetime = 120; //缓存时间

	/**
		smarty常用的两个方法
		assign 用于在模板被执行时为模板变量赋值.
		$smarty -> assign('变量', '变量的值');
		display 显示模板，需要指定一个合法的模板资源的类型和路径.
		$smarty -> display('模板的地址');
	*/


		$bookList = array(
			array(
				'name' => 'javascript权威指南',
				'price' => 99
			),
			array(
				'name' => 'javascript高级程序设计',
				'price' => 199
			),
			array(
				'name' => 'javascript语法精粹',
				'price' => 199
			)
		);

		$personList = array(); 

		class myObject{
			function fn($arr){
				return $arr[0]." ".$arr[1];
			}
		}

		$obj = new myObject();

	

	//对smarty模板的变量进行赋值
	$smarty -> assign('title', '');
	$smarty -> assign('articletitle', 'hello world');
	$smarty -> assign('time', time());
	$smarty -> assign('url', "http://localhost/smarty/test/test.php");
	$smarty -> assign('html', '<div class="div">html code</div>');
	$smarty -> assign('javascript1', "<script>alert('javascript1 code');</script>");
	$smarty -> assign('javascript2', "alert('haha')");
	$smarty -> assign('content', "第一段换行
		第二段换行
		第三段换行");
	$smarty -> assign('name1','admin');
	$smarty -> assign('name2','guest');
	$smarty -> assign('name3','lisi');
	$smarty -> assign('bookList',$bookList);
	$smarty -> assign('personList',$personList);
	$smarty -> assign('obj',$obj);
	$smarty -> assign('time2',time());
	$smarty -> assign('str','abcdefg');
	

	
	

	
	

	//展示模板
	$smarty -> display('test.tpl');

	/**

	变量调节器

	1、首字母大写 capitalize
	示例：{$articleTitle|capitalize}

	2、字符串连接 cat
	示例：{$articleTitle|cat:" yesterday."}

	3、日期格式化 data_format
	示例：{$yesterday|data_format}
		 {$yesterday|data_format:":"%A,%B %e, %Y %H:%M:%S"}
	4、为未赋值或为空的变量指定默认值default
	示例：{$articleTitle|default:"no title"}

	5、转码 escape
	用于html转码,url转码,在没有转码的变量上转换单引号,十六进制转码,十六进制美化,或者javascript转码。默认是html转码。

	6、小写 lower 大写 upper
	将变量字符串小（大）写
	示例：{$articleTitle|lower} {$articleTitle|upper} 

	7、所有的换行符将被替换成<br /> nl2br功能同php中的nl2br()函数一样
	示例：{$articleTitle|nl2br}

	条件判断句式
	基本句式

	{if $name eq 'admin'}
		welcome admin.
	{elseif $name eq 'guest'}
		welcome guest.
	{else}
		welcome everybody.
	{/if}

	条件修饰符
	eq ( == )
	neq ( != )
	gt ( > )
	lt ( < )
	修饰词时必须和变量或常量用空格隔开


	*/



?>