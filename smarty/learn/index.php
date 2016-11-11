<?php

	/**
		引入Smarty.class.php文件
	*/
	require('../libs/smarty/Smarty.class.php');

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
	$smarty -> left_delimiter = "{%"; 
	/**
		右定界符
	*/
	$smarty -> right_delimiter = "%}"; 
	/**
		html模板的地址
	*/
	$smarty -> template_dir = "templates";	
	/**
		模板编译生成的文件地址
	*/
	$smarty -> compile_dir = "templates_c";
	/**
		设置缓存
	*/	
	$smarty -> cache_dir = "cache";


	$smarty -> assign('name','lisi');

	$arr = array('name' => 'lisi','age' => 23,'sex' => 'female');

	$marr = array('students' => array('name' => 'lisi','age' => 23,'sex' => 'female'),'teachers' => array('name' => 'lisi','age' => 23,'sex' => 'female'));

	$articleTitle = 'node.js in action';



	$smarty -> assign('info',$arr);

	$smarty -> assign('minfo',$marr);

	$smarty -> assign('articleTitle',$articleTitle);

	$smarty -> assign('time',time());

	$smarty -> assign('nullVal','');

	$smarty -> assign('abc','abc');

	$smarty -> assign('ABC','ABC');

	$smarty -> assign('url','https://www.google.co.jp/');

	$smarty -> assign('content','第一行
		第二行
		第三行');

	$smarty -> assign('longString','L汉o字rem ipsum dolor sit amet, consectetur adipisicing elit. Autem voluptas consectetur dolore doloribus, minima rem! Maiores doloribus enim architecto officia, accusamus, animi, ab sequi atque rerum vel optio corporis non?');

	$smarty -> assign('temp',23);

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

	$bookNone = "";

	$json = json_encode($bookList,JSON_UNESCAPED_UNICODE);

	$smarty -> assign('bookList',$bookList);

	$smarty -> assign('json',$json);






	$smarty -> display('index.tpl');






